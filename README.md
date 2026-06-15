# Navigasi Universitas Perjuangan (Unper)


## Pembagian Tugas

| File             | Tugas                          | Member |
|------------------|---------------------------------|--------|
| `PetaWisata.cpp` | Wadah data: nama lokasi & jarak antar lokasi | FASYA |
| `Navigasi.cpp`   | Algoritma pencarian rute terpendek  | ARFYN |
| `main.cpp`       | Tampilan menu & interaksi pengguna | IFAN |


## Catatan Penting
- Semua jarak di `PetaWisata.cpp` masih PERKIRAAN (placeholder 5 meter).
  Member 1 perlu mengukur & mengisi jarak sebenarnya.
- Beberapa koneksi jalur (terutama di sekitar Bundaran, Parkir Motor 2, dan
  Gedung Sholihin) masih pendekatan berdasarkan posisi visual pada denah —
  cek ulang sebelum dipakai resmi.
.

## Cara Kerja Program (ringkas)
1. `main.cpp` memanggil `siapkanPeta()` dan `isiDataLokasi()` dari
   `PetaWisata.cpp` untuk menyiapkan data (25 lokasi + jalur).
2. Pengguna memasukkan lokasi awal & tujuan (nomor 1-25).
3. `main.cpp` memanggil `cariRuteTerpendek()` dari `Navigasi.cpp`.
4. Fungsi tersebut menjalankan algoritma Dijkstra menggunakan data
   `jarak[][]` dan `namaLokasi[]`, lalu menampilkan jarak total dan
   urutan rute terpendek.
