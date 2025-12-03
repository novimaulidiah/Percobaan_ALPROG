#ifndef FORMATTER_H
#define FORMATTER_H

#include "data_loader.h"
#include <vector>
#include <map>

void printHeader();
void printSummary(const std::vector<Row>& rows);
void printRekapTahun(const std::vector<Row>& rows);
void printTotalRingkas(const std::map<int,double>& total);
void printGrowth(const std::map<int,double>& total);
void printKategoriAnalysis(const std::vector<Row>& rows);

#endif
