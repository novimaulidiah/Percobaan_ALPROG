#include <iostream>
#include "data_loader.h"
#include "analytics.h"
#include "formatter.h"

int main() {
    // 1. Load data CSV
    std::string filename = "Data ALPROG.csv";
    std::vector<Row> rows = loadCSV(filename);

    if (rows.empty()) {
        std::cout << "Gagal membaca file CSV!" << std::endl;
        return 1;
    }

    // 2. Hitung statistik dasar
    auto stats = computeBasicStats(rows);

    printSeparator();
    std::cout << "              ANALISIS DATA UMKM INDONESIA\n";
    printSeparator();
    std::cout << "Jumlah baris data terbaca : " << stats.totalRows << "\n";
    std::cout << "Jumlah tahun tercatat     : " << stats.yearCount
              << " (" << stats.minYear << " - " << stats.maxYear << ")\n";
    std::cout << "Jumlah kategori unik      : " << stats.uniqueCategories << "\n";
    std::cout << "Jumlah variabel nilai     : " << stats.uniqueVariables << "\n";
    std::cout << "-----------------------------------------------------------\n\n";

    // 3. Rekap per tahun
    printSeparator();
    std::cout << "                REKAP DETAIL UMKM PER TAHUN\n";
    printSeparator();
    printYearlyDetails(rows);
    std::cout << "\n";

    // 4. Total ringkas per tahun
    printSeparator();
    std::cout << "                 TOTAL UMKM PER TAHUN (RINGKAS)\n";
    printSeparator();
    printYearSummary(rows);
    std::cout << "\n";

    // 5. Analisis pertumbuhan
    printSeparator();
    std::cout << "                 ANALISIS PERTUMBUHAN UMKM\n";
    printSeparator();
    printGrowth(rows);
    std::cout << "\n";

    // 6. kategori terbesar & kenaikan tercepat
    printSeparator();
    std::cout << "        KATEGORI TERBESAR & KENAIKAN TERPECEPAT\n";
    printSeparator();
    printCategoryRanking(rows);
    std::cout << "\n";

    printSeparator();
    std::cout << "                   PROSES ANALISIS SELESAI\n";
    printSeparator();

    return 0;
}
