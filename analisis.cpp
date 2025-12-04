#include "analisis.h"

void hitungTotalPerTahun(const std::vector<DataUMKM>& data,
                         std::map<int, double>& total)
{
    for (auto &d : data)
        total[d.tahun] += d.jumlah;
}

double hitungPertumbuhan(double awal, double akhir) {
    return ((akhir - awal) / awal) * 100.0;
}

void hitungKenaikanKategori(const std::vector<DataUMKM>& data,
                            std::map<std::string, double>& kenaikan)
{
    std::map<std::string, double> awal;
    std::map<std::string, double> akhir;

    int minTahun = 9999, maxTahun = 0;
    for (auto &d : data) {
        if (d.tahun < minTahun) minTahun = d.tahun;
        if (d.tahun > maxTahun) maxTahun = d.tahun;
    }

    for (auto &d : data) {
        if (d.tahun == minTahun) awal[d.kbli + " (" + d.kategori + ")"] = d.jumlah;
        if (d.tahun == maxTahun) akhir[d.kbli + " (" + d.kategori + ")"] = d.jumlah;
    }

    for (auto &p : awal) {
        std::string key = p.first;
        kenaikan[key] = akhir[key] - awal[key];
    }
}
