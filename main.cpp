#include <iostream>
#include "Navigasi.cpp"

using namespace std;

int main() {

    siapkanPeta();
    isiDataLokasi();

    cout << "=== SISTEM NAVIGASI UNIVERSITAS PERJUANGAN ===\n\n";
    cout << "Daftar Lokasi:\n";
    for (int i = 1; i <= JUMLAH_LOKASI; i++) {
        cout << "[" << i << "] " << namaLokasi[i] << "\n";
    }

    int lokasiAwal, lokasiTujuan;

    cout << "\nMasukkan Angka Lokasi Anda Saat Ini : ";
    cin >> lokasiAwal;
    cout << "Masukkan Angka Destinasi Tujuan     : ";
    cin >> lokasiTujuan;

    bool inputValid = (lokasiAwal   >= 1 && lokasiAwal   <= JUMLAH_LOKASI) &&
                       (lokasiTujuan >= 1 && lokasiTujuan <= JUMLAH_LOKASI);

    if (!inputValid) {
        cout << "\n[!] Kode lokasi tidak dikenali program!\n";
        return 1;
    }

    cout << "\nMengkalkulasi rute terbaik untuk perjalanan Anda...";
    cariRuteTerpendek(lokasiAwal, lokasiTujuan);

    return 0;
}