#include "laporan.h"
#include <iostream>
#include <fstream>
#include <algorithm>

void cetakRingkasan(const std::vector<DataUMKM>& data) {
    std::map<std::string, bool> kategori, tipe;

    int minTahun = 9999, maxTahun = 0;

    for (auto &d : data) {
        kategori[d.kbli] = true;
        tipe[d.kategori] = true;
        if (d.tahun < minTahun) minTahun = d.tahun;
        if (d.tahun > maxTahun) maxTahun = d.tahun;
    }

    std::cout << "Jumlah baris data    : " << data.size() << "\n";
    std::cout << "Jumlah tahun dicatat : " << (maxTahun - minTahun + 1)
              << " (" << minTahun << " - " << maxTahun << ")\n";
    std::cout << "Jumlah kategori KBLI : " << kategori.size() << "\n";
    std::cout << "Jumlah tipe usaha    : " << tipe.size() << "\n";
}

void cetakTotalTahunan(const std::map<int,double>& total) {
    for (auto &t : total)
        std::cout << t.first << " : " << (long long)t.second << "\n";
}

void cetakPertumbuhan(double awal, double akhir) {
    std::cout << "Pertumbuhan : " << akhir - awal
              << " (" << hitungPertumbuhan(awal, akhir) << "%)\n";
}

void cetakKategoriTerbesar(const std::vector<DataUMKM>& data) {
    std::map<std::string, double> jumlah;

    int maxTahun = 0;
    for (auto &d : data)
        if (d.tahun > maxTahun) maxTahun = d.tahun;

    for (auto &d : data)
        if (d.tahun == maxTahun)
            jumlah[d.kbli + " (" + d.kategori + ")"] += d.jumlah;

    std::vector<std::pair<std::string,double>> v(jumlah.begin(), jumlah.end());
    std::sort(v.begin(), v.end(), [](auto &a, auto &b){ return a.second > b.second; });

    for (int i = 0; i < 3 && i < v.size(); i++)
        std::cout << i+1 << ". " << v[i].first << " : " << (long long)v[i].second << "\n";
}

void simpanLaporan(const std::string& namaFile, const std::string& isi) {
    std::ofstream f(namaFile);
    f << isi;
    f.close();
}
