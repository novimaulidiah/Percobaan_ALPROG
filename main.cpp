#include <iostream>
#include <map>
#include "pembaca_file.h"
#include "analisis.h"
#include "laporan.h"
using namespace std;

int main() {
    vector<DataUMKM> data = bacaCSV("data_umkm.csv");

    if (data.empty()) {
        cout << "File kosong atau gagal dibaca.\n";
        return 0;
    }

    cout << "============================================================\n";
    cout << "      SISTEM MONITORING UMKM PER KBLI (INDONESIA)\n";
    cout << "============================================================\n\n";

    cetakRingkasan(data);

    //Total per tahun
    map<int,double> totalTahunan;

    for (auto& d : data) {
        totalTahunan[d.tahun] += d.jumlah;
    }

    cout << "\n";
    cetakTotalTahunan(totalTahunan);

    double awal = totalTahunan.begin()->second;
    double akhir = totalTahunan.rbegin()->second;

    cout << "\n";
    cetakPertumbuhanKBLI(data);

    cout << "\n=== PERTUMBUHAN ===\n";
    cetakPertumbuhan(awal, akhir);

    cout << "\n";
    cetakKategoriTerbesar(data);

    return 0;
}
