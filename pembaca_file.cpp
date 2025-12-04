#include "pembaca_file.h"
#include <fstream>
#include <sstream>
#include <iostream>

std::vector<DataUMKM> bacaCSV(const std::string& namaFile) {
    std::vector<DataUMKM> data;
    std::ifstream file(namaFile);

    if (!file.is_open()) {
        std::cout << "Gagal membuka file!\n";
        return data;
    }

    std::string baris;
    getline(file, baris); // skip header

    while (getline(file, baris)) {
        std::stringstream ss(baris);
        std::string item;

        DataUMKM d;

        getline(ss, item, ','); // id
        getline(ss, item, ','); // id kategori
        getline(ss, d.kbli, ','); 
        getline(ss, d.kategori, ',');
        getline(ss, item, ','); d.tahun = stoi(item);
        getline(ss, item, ','); d.jumlah = stod(item);

        data.push_back(d);
    }

    return data;
}
