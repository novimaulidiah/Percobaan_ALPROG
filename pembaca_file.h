#ifndef PEMBACA_FILE_H
#define PEMBACA_FILE_H

#include <string>
#include <vector>
using namespace std;

struct DataUMKM {
    int tahun;
    string kategori_kbli;
    string tipe_usaha;
    double jumlah;
};

vector<DataUMKM> bacaCSV(const string& namaFile);
#endif
