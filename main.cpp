#include <iostream>
#include <map>
#include <sstream>

#include "pembaca_file.h"
#include "analisis.h"
#include "laporan.h"

int main() {
    std::vector<DataUMKM> data = bacaCSV("data_umkm.csv");

    if (data.empty()) {
        std::cout << "File kosong atau gagal dibaca.\n";
        return 0;
    }

    std::cout << "============================================================\n";
    std::cout << "      SISTEM MONITORING UMKM PER KBLI (INDONESIA)\n";
    std::cout << "============================================================\n\n";

    cetakRingkasan(data);

    std::map<int,double> totalTahunan;
    hitungTotalPerTahun(data, totalTahunan);

    std::cout << "\n=== TOTAL UMKM PER TAHUN ===\n";
    cetakTotalTahunan(totalTahunan);

    double awal = totalTahunan.begin()->second;
    double akhir = totalTahunan.rbegin()->second;

    std::cout << "\n=== PERTUMBUHAN ===\n";
    cetakPertumbuhan(awal, akhir);

    std::cout << "\n=== KATEGORI TERBESAR TAHUN TERBARU ===\n";
    cetakKategoriTerbesar(data);

    return 0;
}
