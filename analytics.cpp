#include "analytics.h"
#include <algorithm>

std::map<int, double> totalPerTahun(const std::vector<Row>& rows) {
    std::map<int, double> result;
    for (const auto& r : rows) {
        result[r.tahun] += r.jumlah;
    }
    return result;
}

double growthPercent(double awal, double akhir) {
    return ((akhir - awal) / awal) * 100.0;
}

std::map<std::string, double> totalKategoriLatest(const std::vector<Row>& rows) {
    std::map<std::string, double> result;
    int max_year = 0;

    for (const auto& r : rows)
        max_year = std::max(max_year, r.tahun);

    for (const auto& r : rows)
        if (r.tahun == max_year)
            result[r.nama_variabel] += r.jumlah;

    return result;
}

std::map<std::string, double> kenaikanKategori(const std::vector<Row>& rows) {
    std::map<std::string, double> awal;
    std::map<std::string, double> akhir;
    std::map<std::string, double> result;

    int min_year = 3000, max_year = 0;

    for (const auto& r : rows) {
        min_year = std::min(min_year, r.tahun);
        max_year = std::max(max_year, r.tahun);
    }

    for (const auto& r : rows) {
        if (r.tahun == min_year) awal[r.nama_variabel] += r.jumlah;
        if (r.tahun == max_year) akhir[r.nama_variabel] += r.jumlah;
    }

    for (auto& a : akhir)
        result[a.first] = a.second - awal[a.first];

    return result;
}
