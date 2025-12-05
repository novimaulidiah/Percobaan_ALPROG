#include "laporan.h"
#include "analisis.h"
#include <iostream>
using namespace std;

//Ringkasan Data UMKM
void cetakRingkasan(const vector<DataUMKM>& data) {

    int jumlahBaris = data.size();
    int tahunAwal = data.front().tahun;
    int tahunAkhir = data.back().tahun;

    // mencari kategori unik
    vector<string> kategoriUnik;

    for (const auto& d : data) {
        bool sudahAda = false;
        for (const auto& k : kategoriUnik) {
            if (k == d.kategori_kbli) {
                sudahAda = true;
                break;
            }
        }

        if (!sudahAda) {
            kategoriUnik.push_back(d.kategori_kbli);
        }
    }

    cout << "Jumlah baris data    : " << jumlahBaris << endl;
    cout << "Jumlah tahun dicatat : " 
         << tahunAwal << " - " << tahunAkhir 
         << " (" << (tahunAkhir - tahunAwal + 1) << " tahun)\n";
    cout << "Jumlah kategori KBLI : " << kategoriUnik.size() << endl;
    cout << "Jumlah tipe usaha    : 2 (Mikro dan Kecil)\n";
}

//Total UMKM Per Tahun
void cetakTotalTahunan(const map<int,double>& totalTahunan) {
    cout << "\n=== TOTAL UMKM PER TAHUN ===\n";

    for (auto& t : totalTahunan) {
        cout << t.first << " : " << t.second << endl;
    }
}

//Pertumbuhan Total
void cetakPertumbuhan(double awal, double akhir) {
    double persen = hitungPertumbuhan(awal, akhir);
    double selisih = akhir - awal;

    cout << "Pertumbuhan : " << selisih 
         << " (" << persen << "%)\n";
}

//Kategori Terbesar Pada Tahun Terbaru
void cetakKategoriTerbesar(const vector<DataUMKM>& data) {

    int tahunTerbaru = data.back().tahun;

    vector<string> kategori;
    vector<double> total;

    for (const auto& d : data) {

        if (d.tahun != tahunTerbaru) continue;

        bool ada = false;
        for (int i = 0; i < kategori.size(); i++) {
            if (kategori[i] == d.kategori_kbli) {
                total[i] += d.jumlah;
                ada = true;
                break;
            }
        }

        if (!ada) {
            kategori.push_back(d.kategori_kbli);
            total.push_back(d.jumlah);
        }
    }

    if (kategori.empty()) {
        cout << "(Tidak ada data untuk tahun terbaru)\n";
        return;
    }

    //sorting manual
    for (int i = 0; i < kategori.size(); i++) {
        for (int j = i + 1; j < kategori.size(); j++) {
            if (total[j] > total[i]) {
                swap(total[i], total[j]);
                swap(kategori[i], kategori[j]);
            }
        }
    }

    cout << "\n=== KATEGORI TERBESAR TAHUN TERBARU ===\n";
    for (int i = 0; i < kategori.size(); i++) {
        cout << i+1 << ". " << kategori[i] 
             << " : " << total[i] << endl;
    }
}

//PERTUMBUHAN PER KBLI
void cetakPertumbuhanKBLI(const vector<DataUMKM>& data) {

    vector<string> kbli;
    vector<double> awal;
    vector<double> akhir;

    for (const auto& d : data) {
        bool ada = false;

        for (int i = 0; i < kbli.size(); i++) {
            if (kbli[i] == d.kategori_kbli) {
                akhir[i] = d.jumlah;
                ada = true;
                break;
            }
        }

        if (!ada) {
            kbli.push_back(d.kategori_kbli);
            awal.push_back(d.jumlah);
            akhir.push_back(d.jumlah);
        }
    }

    int n = kbli.size();
    double* growth = new double[n];

    for (int i = 0; i < n; i++) {
        growth[i] = hitungPertumbuhan(awal[i], akhir[i]);
    }

    int idxMax = 0, idxMin = 0;
    for (int i = 1; i < n; i++) {
        if (growth[i] > growth[idxMax]) idxMax = i;
        if (growth[i] < growth[idxMin]) idxMin = i;
    }

    cout << "\n=== ANALISIS PERTUMBUHAN KBLI ===\n";

    cout << "\nKBLI Pertumbuhan Tertinggi :\n";
    cout << kbli[idxMax] << " : " << growth[idxMax] << "%\n";

    cout << "\nKBLI Pertumbuhan Terendah :\n";
    cout << kbli[idxMin] << " : " << growth[idxMin] << "%\n";

    delete[] growth;
}
