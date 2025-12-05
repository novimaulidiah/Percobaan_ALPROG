#include "analisis.h"

// Hitung total array
double hitungTotal(double data[], int jumlah) {
    double total = 0;
    for (int i = 0; i < jumlah; i++) {
        total += data[i];
    }
    return total;
}

double hitungRataRata(double data[], int jumlah) {
    if (jumlah == 0) return 0;
    return hitungTotal(data, jumlah) / jumlah;
}

double hitungPertumbuhan(double awal, double akhir) {
    if (awal == 0) return 0;
    return ((akhir - awal) / awal) * 100.0;
}
