#include "data_loader.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<Row> loadCSV(const std::string& filename) {
    std::vector<Row> rows;
    std::ifstream file(filename);

    if (!file.is_open()) {
        std::cerr << "ERROR: File tidak ditemukan!\n";
        return rows;
    }

    std::string line;
    bool skipHeader = true;

    while (std::getline(file, line)) {
        if (skipHeader) { skipHeader = false; continue; }

        std::stringstream ss(line);
        std::string token;

        Row r;

        std::getline(ss, token, ','); r.id = std::stoi(token);
        std::getline(ss, token, ','); r.id_kategori = std::stoi(token);
        std::getline(ss, r.daerah, ',');
        std::getline(ss, r.nama_variabel, ',');
        std::getline(ss, token, ','); r.tahun = std::stoi(token);
        std::getline(ss, token, ','); r.jumlah = std::stod(token);

        rows.push_back(r);
    }

    return rows;
}
