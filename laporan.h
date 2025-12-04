#ifndef LAPORAN_H
#define LAPORAN_H

#include "pembaca_file.h"
#include <map>

void cetakRingkasan(const std::vector<DataUMKM>& data);
void cetakTotalTahunan(const std::map<int,double>& total);
void cetakPertumbuhan(double awal, double akhir);
void cetakKategoriTerbesar(const std::vector<DataUMKM>& data);
void simpanLaporan(const std::string& namaFile, const std::string& isi);

#endif
