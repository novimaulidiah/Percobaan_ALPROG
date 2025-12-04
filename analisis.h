#ifndef ANALISIS_H
#define ANALISIS_H

#include "pembaca_file.h"
#include <map>

void hitungTotalPerTahun(const std::vector<DataUMKM>& data,
                         std::map<int, double>& total);

double hitungPertumbuhan(double awal, double akhir);

void hitungKenaikanKategori(const std::vector<DataUMKM>& data,
                            std::map<std::string, double>& kenaikan);

#endif
