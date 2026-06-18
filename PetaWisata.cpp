#include <string>

using namespace std;

const int JUMLAH_LOKASI = 25;
const int TAK_TERHUBUNG = -1;

int jarak[JUMLAH_LOKASI + 1][JUMLAH_LOKASI + 1];

string namaLokasi[JUMLAH_LOKASI + 1];

void setNamaLokasi(int id, string nama) {
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

    // -------------------------------------------------------
    // ZONA A: Faperta & Mashudi (pojok kiri atas)
    // -------------------------------------------------------
    tambahJalur(1, 2,  80);   // Praktek Faperta -> Gedung Mashudi (cukup jauh, beda sisi)
    tambahJalur(2, 3,  70);   // Gedung Mashudi  -> Parkir Motor 1

    // -------------------------------------------------------
    // ZONA B: Area atas (Parkir Motor 1 -> Kantin -> UKM -> Lab Farmasi -> Gedung PGSD)
    // Ini jalur koridor atas yang lurus ke kanan
    // -------------------------------------------------------
    tambahJalur(3, 4,  20);   // Parkir Motor 1 -> Gazebo (sangat dekat)
    tambahJalur(4, 5,  25);   // Gazebo -> Kantin
    tambahJalur(5, 6,  20);   // Kantin -> UKM (bersebelahan)
    tambahJalur(6, 10, 35);   // UKM -> Lab Farmasi
    tambahJalur(10, 11, 30);  // Lab Farmasi -> Gedung PGSD/Farmasi/Faperta

    // -------------------------------------------------------
    // ZONA C: Area tengah (Gazebo -> Saung -> Mushola -> Hotel -> Kopma)
    // Jalur menurun dari area atas ke bundaran
    // -------------------------------------------------------
    tambahJalur(4, 7,  30);   // Gazebo -> Saung Unper
    tambahJalur(7, 8,  20);   // Saung Unper -> Mushola (sangat dekat)
    tambahJalur(8, 9,  25);   // Mushola -> Hotel Unper
    tambahJalur(8, 12, 30);   // Mushola -> Kopma & Ruang Organisasi

    // -------------------------------------------------------
    // ZONA D: Kopma & Parkir Motor 2 -> Bundaran
    // -------------------------------------------------------
    tambahJalur(12, 13, 25);  // Kopma -> Parkir Motor 2 (Atas)
    tambahJalur(13, 14, 20);  // Parkir Motor 2 (Atas) -> Parkir Motor 2 (Bundaran)
    tambahJalur(12, 15, 35);  // Kopma -> Bundaran (jalur langsung)
    tambahJalur(14, 15, 20);  // Parkir Motor 2 (Bundaran) -> Bundaran

    // -------------------------------------------------------
    // Mashudi -> Bundaran (jalur utama kiri kampus)
    // -------------------------------------------------------
    tambahJalur(2, 15, 90);   // Gedung Mashudi -> Bundaran (jalan utama panjang)

    // -------------------------------------------------------
    // ZONA E: Bundaran -> area kiri bawah (Lab Komputer, Perpus, Lab Toufel)
    // -------------------------------------------------------
    tambahJalur(15, 16, 25);  // Bundaran -> Lab Komputer 1
    tambahJalur(16, 17, 20);  // Lab Komputer 1 -> Lab Komputer 2 (bersebelahan)
    tambahJalur(17, 18, 30);  // Lab Komputer 2 -> Perpustakaan
    tambahJalur(17, 19, 25);  // Lab Komputer 2 -> Lab Toufel & Budaya
    tambahJalur(18, 19, 20);  // Perpustakaan -> Lab Toufel & Budaya (dekat)
    tambahJalur(19, 20, 30);  // Lab Toufel -> Parkir Mobil

    // -------------------------------------------------------
    // ZONA F: Bundaran -> area kanan bawah (Sholihin, Lapangan, Satpam)
    // -------------------------------------------------------
    tambahJalur(14, 21, 40);  // Parkir Motor 2 (Bundaran) -> Gedung Sholihin
    tambahJalur(15, 21, 50);  // Bundaran -> Gedung Sholihin
    tambahJalur(21, 22, 25);  // Sholihin -> Ruang Sajian Perhotelan
    tambahJalur(21, 23, 30);  // Sholihin -> Lapang Basket & Voli
    tambahJalur(22, 23, 20);  // Ruang Sajian -> Lapang Basket (bersebelahan)
    tambahJalur(21, 24, 40);  // Sholihin -> Lapang Unper (agak jauh ke bawah)
    tambahJalur(23, 24, 30);  // Lapang Basket -> Lapang Unper

    // -------------------------------------------------------
    // ZONA G: Menuju Pos Satpam (gerbang/exit bawah)
    // -------------------------------------------------------
    tambahJalur(20, 25, 40);  // Parkir Mobil -> Pos Satpam
    tambahJalur(24, 25, 35);  // Lapang Unper -> Pos Satpam
    tambahJalur(15, 25, 80);  // Bundaran -> Pos Satpam (jalur utama vertikal)
}