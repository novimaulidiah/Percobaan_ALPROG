#include "pembaca_file.h"   // WAJIB! supaya DataUMKM dikenali
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

vector<DataUMKM> bacaCSV(const string& nama_file) {
    vector<DataUMKM> data;
    ifstream file(nama_file);

    if (!file.is_open()) {
        cout << "Gagal membuka file!" << endl;
        return data;
    }

    string baris;
    getline(file, baris); // lewati header

    while (getline(file, baris)) {
        stringstream ss(baris);
        vector<string> kolom;
        string temp;

        while (getline(ss, temp, ',')) {
            kolom.push_back(temp);
        }

        if (kolom.size() != 6) continue;

        DataUMKM d;
        d.kategori_kbli = (kolom[2]);      
        d.tipe_usaha    = kolom[3];   
        d.tahun         = stoi(kolom[4]);
        d.jumlah        = stod(kolom[5]);

        data.push_back(d);
    }

    return data;
}
