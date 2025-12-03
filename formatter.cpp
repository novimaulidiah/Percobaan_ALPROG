#include "formatter.h"
#include "analytics.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <algorithm>

// Sudah kamu punya
std::string formatNumber(double value) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(0);

    std::string s = std::to_string((long long)value);
    int count = 0;

    for (int i = s.size() - 1; i >= 0; i--) {
        ss << s[s.size() - 1 - count];
        count++;
        if (count % 3 == 0 && i != 0) {
            ss << ",";
        }
    }

    std::string result = ss.str();
    std::reverse(result.begin(), result.end());
    return result;
}

void printSeparator() {
    std::cout << "===========================================================\n";
}

/* ===================== HEADER ===================== */
void printHeader() {
    printSeparator();
    std::cout << " ANALISIS DATA UMKM INDONESIA \n";
    printSeparator();
}

/* ===================== SUMMARY ===================== */
void printSummary(const std::vector<Row>& rows) {
    std::cout << "Total baris data: " << rows.size() << "\n";
    printSeparator();
}

/* ===================== REKAP PER TAHUN ===================== */
void printRekapTahun(const std::vector<Row>& rows) {
    auto total = totalPerTahun(rows);

    std::cout << "REKAP TOTAL UMKM PER TAHUN\n";
    for (auto& t : total) {
        std::cout << "Tahun " << t.first << " : " << formatNumber(t.second) << "\n";
    }
    printSeparator();
}

/* ===================== TOTAL RINGKAS ===================== */
void printTotalRingkas(const std::map<int,double>& total) {
    std::cout << "RINGKASAN TOTAL UMKM PER TAHUN:\n";
    for (auto& t : total) {
        std::cout << "- " << t.first << " : " << formatNumber(t.second) << "\n";
    }
    printSeparator();
}

/* ===================== PERTUMBUHAN ===================== */
void printGrowth(const std::map<int,double>& total) {
    if (total.size() < 2) {
        std::cout << "Data tidak cukup untuk menghitung pertumbuhan.\n";
        return;
    }

    auto it = total.begin();
    int tahun_awal = it->first;
    double val_awal = it->second;

    it = total.end();
    --it;
    int tahun_akhir = it->first;
    double val_akhir = it->second;

    double percent = growthPercent(val_awal, val_akhir);

    std::cout << "PERTUMBUHAN dari " << tahun_awal << " ke " << tahun_akhir << " : "
              << std::fixed << std::setprecision(2) << percent << "%\n";

    printSeparator();
}

/* ===================== ANALISIS PER KATEGORI ===================== */
void printKategoriAnalysis(const std::vector<Row>& rows) {
    std::cout << "ANALISIS KATEGORI (Mikro / Kecil)\n";

    auto latest = totalKategoriLatest(rows);
    auto naik = kenaikanKategori(rows);

    for (auto& r : latest) {
        std::cout << r.first << " (tahun terbaru) : " << formatNumber(r.second) << "\n";
    }

    std::cout << "\nKENAIKAN KATEGORI DARI TAHUN AWAL → AKHIR:\n";
    for (auto& r : naik) {
        std::cout << r.first << " : +" << formatNumber(r.second) << "\n";
    }

    printSeparator();
}
