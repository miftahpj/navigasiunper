#include <iostream>
#include <climits>
#include "PetaWisata.cpp"

using namespace std;

void cariRuteTerpendek(int titik_awal, int titik_tujuan) {

    int jarakTerpendek[JUMLAH_LOKASI + 1];
    bool sudahDikunjungi[JUMLAH_LOKASI + 1];
    int lokasiSebelumnya[JUMLAH_LOKASI + 1]; 

    for (int i = 1; i <= JUMLAH_LOKASI; i++) {
        jarakTerpendek[i] = INT_MAX;
        sudahDikunjungi[i] = false;
        lokasiSebelumnya[i] = -1;
    }
    jarakTerpendek[titik_awal] = 0;

    for (int hitung = 1; hitung <= JUMLAH_LOKASI - 1; hitung++) {
        int lokasiTerpilih = -1;
        int jarakMin = INT_MAX;
        for (int v = 1; v <= JUMLAH_LOKASI; v++) {
            if (!sudahDikunjungi[v] && jarakTerpendek[v] <= jarakMin) {
                jarakMin = jarakTerpendek[v];
                lokasiTerpilih = v;
            }
        }

        if (lokasiTerpilih == -1) break;
        sudahDikunjungi[lokasiTerpilih] = true;

        for (int v = 1; v <= JUMLAH_LOKASI; v++) {
            int bobot = jarak[lokasiTerpilih][v];

            bool adaJalur   = (bobot != TAK_TERHUBUNG);
            bool belumFinal = !sudahDikunjungi[v];
            bool lebihDekat = (jarakTerpendek[lokasiTerpilih] + bobot < jarakTerpendek[v]);

            if (adaJalur && belumFinal && jarakTerpendek[lokasiTerpilih] != INT_MAX && lebihDekat) {
                jarakTerpendek[v] = jarakTerpendek[lokasiTerpilih] + bobot;
                lokasiSebelumnya[v] = lokasiTerpilih;
            }
        }
    }

    if (jarakTerpendek[titik_tujuan] == INT_MAX) {
        cout << "\n[!] Rute tidak dapat diakses!\n";
        return;
    }

    cout << "\n=========================================\n";
    cout << "Estimasi Jarak Tempuh : " << jarakTerpendek[titik_tujuan] << " meter\n";
    cout << "Panduan Rute          : ";

    int urutan[JUMLAH_LOKASI + 1];
    int jumlahLangkah = 0;
    int posisi = titik_tujuan;

    while (posisi != -1) {
        urutan[jumlahLangkah] = posisi;
        jumlahLangkah++;
        posisi = lokasiSebelumnya[posisi];
    }

    for (int i = jumlahLangkah - 1; i >= 0; i--) {
        cout << namaLokasi[urutan[i]];
        if (i > 0) cout << " -> ";
    }
    cout << "\n=========================================\n";
}