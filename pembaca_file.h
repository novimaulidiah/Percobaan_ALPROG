#ifndef PEMBACA_FILE_H
#define PEMBACA_FILE_H

#include <string>
#include <vector>

struct DataUMKM {
    int tahun;
    std::string kbli;
    std::string kategori;
    double jumlah;
};

std::vector<DataUMKM> bacaCSV(const std::string& namaFile);

#endif
