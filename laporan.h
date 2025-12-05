#ifndef LAPORAN_H
#define LAPORAN_H

#include "pembaca_file.h"
#include <map>
#include <string>
#include <vector>
using namespace std;

    void cetakRingkasan(const vector<DataUMKM>& data);
    void cetakTotalTahunan(const map<int,double>& totalTahunan);
    void cetakPertumbuhanKBLI(const vector<DataUMKM>& data);
    void cetakPertumbuhan(double awal, double akhir);
    void cetakKategoriTerbesar(const vector<DataUMKM>& data);
    void simpanLaporan(const string& namaFile, const string& isi);

#endif
