#ifndef DATA_LOADER_H
#define DATA_LOADER_H

#include <string>
#include <vector>
#include <map>

struct Row {
    int id;
    int id_kategori;
    std::string daerah;
    std::string nama_variabel;  // Mikro / Kecil
    int tahun;
    double jumlah;
};

std::vector<Row> loadCSV(const std::string& filename);

#endif
