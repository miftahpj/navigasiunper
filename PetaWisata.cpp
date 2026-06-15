#include <string>

const int JUMLAH_LOKASI = 25;\
const int TAK_TERHUBUNG = -1;

int jarak[JUMLAH_LOKASI + 1][JUMLAH_LOKASI + 1];

std::string namaLokasi[JUMLAH_LOKASI + 1];


void setNamaLokasi(int id, std::string nama) {
    namaLokasi[id] = nama;
}

void tambahJalur(int a, int b, int jarakMeter) {
    jarak[a][b] = jarakMeter;
    jarak[b][a] = jarakMeter;
}

void siapkanPeta() {
    for (int i = 0; i <= JUMLAH_LOKASI; i++) {
        for (int j = 0; j <= JUMLAH_LOKASI; j++) {
            jarak[i][j] = TAK_TERHUBUNG;
        }
        jarak[i][i] = 0;
    }
}

void isiDataLokasi() {

    setNamaLokasi(1,  "Praktek Faperta");
    setNamaLokasi(2,  "Gedung Mashudi");
    setNamaLokasi(3,  "Parkir Motor 1");
    setNamaLokasi(4,  "Gazebo");
    setNamaLokasi(5,  "Kantin");
    setNamaLokasi(6,  "UKM");
    setNamaLokasi(7,  "Saung Unper");
    setNamaLokasi(8,  "Mushola");
    setNamaLokasi(9,  "Hotel Unper");
    setNamaLokasi(10, "Lab Farmasi");
    setNamaLokasi(11, "Gedung PGSD, Farmasi & Faperta");
    setNamaLokasi(12, "Kopma & Ruang Organisasi");
    setNamaLokasi(13, "Parkir Motor 2 (Atas)");
    setNamaLokasi(14, "Parkir Motor 2 (Bundaran)");
    setNamaLokasi(15, "Bundaran");
    setNamaLokasi(16, "Lab Komputer 1");
    setNamaLokasi(17, "Lab Komputer 2");
    setNamaLokasi(18, "Perpustakaan");
    setNamaLokasi(19, "Lab Toufel & Budaya");
    setNamaLokasi(20, "Parkir Mobil");
    setNamaLokasi(21, "Gedung Sholihin");
    setNamaLokasi(22, "Ruang Sajian Perhotelan");
    setNamaLokasi(23, "Lapang Basket & Voli");
    setNamaLokasi(24, "Lapang Unper");
    setNamaLokasi(25, "Pos Satpam");

    tambahJalur(1, 2, 5);
    tambahJalur(2, 3, 5);
    tambahJalur(2, 15, 5);

    tambahJalur(3, 4, 5);
    tambahJalur(4, 5, 5);
    tambahJalur(5, 6, 5);
    tambahJalur(6, 10, 5);
    tambahJalur(10, 11, 5);

    tambahJalur(4, 7, 5);
    tambahJalur(7, 8, 5);
    tambahJalur(8, 9, 5);
    tambahJalur(8, 12, 5);
    tambahJalur(12, 13, 5);
    tambahJalur(12, 15, 5);

    tambahJalur(13, 14, 5);
    tambahJalur(14, 15, 5);
    tambahJalur(15, 25, 5);

    tambahJalur(15, 16, 5);
    tambahJalur(16, 17, 5);
    tambahJalur(17, 18, 5);
    tambahJalur(17, 19, 5);
    tambahJalur(19, 20, 5);
    tambahJalur(20, 25, 5); 

    tambahJalur(14, 21, 5);
    tambahJalur(15, 21, 5);
    tambahJalur(21, 22, 5);
    tambahJalur(21, 23, 5);
    tambahJalur(22, 23, 5);
    tambahJalur(21, 24, 5);
    tambahJalur(24, 25, 5);
}
