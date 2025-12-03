#ifndef ANALYTICS_H
#define ANALYTICS_H

#include "data_loader.h"
#include <map>
#include <string>

std::map<int, double> totalPerTahun(const std::vector<Row>& rows);
double growthPercent(double awal, double akhir);
std::map<std::string, double> totalKategoriLatest(const std::vector<Row>& rows);
std::map<std::string, double> kenaikanKategori(const std::vector<Row>& rows);

#endif
