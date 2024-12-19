#include "serangan.h"
#include <iostream>
#include <string>
using namespace std;

int serangan(string namaJob, int& cd){
    int serangan;
    string blank;
    if (namaJob == "Ksatria") {
        cout << "1. Super Slash (50 Damage)" << endl;
        cout << "2. Normal Attack (25 Damage)" << endl;
    }

    if (namaJob == "Penyihir") {
        cout << "1. Hollow Purple (75 Damage)" << endl;
        cout << "2. Normal Attack (50 Damage)" << endl;
    }
    
    if (namaJob == "Pemanah") {
        cout << "1. Piercing Attack (65 Damage)" << endl;
        cout << "2. Normal Attack (35 Damage)" << endl;
    }

    cout << "Pilih serangan (1/2) >> ";
    cin >> serangan;

    if (namaJob == "Ksatria") {
        switch (serangan) {
            case 1 : 
                cd = 3;
                return 50;
            case 2 :
                return 25;
            default :
                cout << "Pilihan tidak valid\n Menggunakan Normal Attack\n";
                return 25;
            }
        }
    
    if (namaJob == "Penyihir") {
        switch (serangan) {
            case 1 : 
                cd = 3;
                return 75;
            case 2 :
                return 50;
            default :
                cout << "Pilihan tidak valid\n Menggunakan Normal Attack\n";
                return 50;
            }
        }

    if (namaJob == "Pemanah") {
        switch (serangan) {
            case 1 : 
                cd = 3;
                return 65;
            case 2 :
                return 35;
            default :
                cout << "Pilihan tidak valid\n Menggunakan Normal Attack\n";
                return 35;
            }
        }
};