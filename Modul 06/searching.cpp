#include <iostream>
#include <conio.h>
#include <random>
#include <vector>
#include <algorithm>

using namespace std;

void sequentialSearch(const vector<int> &nums, int target){
    vector<int> indices;

    for (auto i = 0; i < nums.size(); i++){
        if (nums[i] == target) indices.push_back(i);
    }
    if (indices.empty()) cout << "angka " << target << " tidak ditemukan pada array" << endl;
    else {
        cout << "Angka " << target << " terdapat pada array sebanyak " << indices.size() << " Kali" << endl;
        cout << "Angka " << target << " ditemukan pada indeks: ";
        for (auto i = 0; i < indices.size(); i++){
            cout << indices[i];
            if (i != indices.size() - 1) cout << ", ";
        }
        cout << "." << endl;
    }
}

void binarySearch(const vector<int> &nums, int target){
    int high = nums.size() - 1;
    int low = 0;
    int index = -1;

    while (low <= high){
        int mid = low + (high - low) / 2;

        if (nums[mid] == target){
            index = mid;
            break;
        }
        if (nums[mid] < target) low = mid + 1;
        else high = mid - 1;
    }

    if (index == -1) cout << "angka " << target << " tidak ditemukan pada array" << endl;
    else cout << "angka " << target << " ditemukan pada indeks ke " << index << endl;
}

void clearScreen(){
    system("cls");
}

void explain(){
    cout << "\nPERBEDAAN SEQUENTIAL SEARCH DENGAN BINARY SEARCH" << endl;
    cout << "SEQUENTIAL SEARCH: " << endl;
    cout << "Sequential search adalah metode pencarian yang dilakukan dengan" << endl;
    cout << "memeriksa setiap elemen dalam sebuah daftar satu per satu, mulai dari" << endl;
    cout << "elemen pertama hingga elemen terakhir, sampai elemen yang dicari ditemukan" << endl;
    cout << "atau seluruh elemen telah diperiksa." << endl;
    cout << "> Sequential search tidak memerlukan array harus tersortir." << endl;
    cout << "> Array multidimensi dapat diguanakan." << endl;
    cout << "> Kompleksitas Waktu: O(n)" << endl;
    cout << "> Kompleksitas Ruang: O(1)" << endl;
    cout << endl;
    cout << "BINARY SEARCH" << endl;
    cout << "Binary search adalah metode pencarian yang jauh lebih efisien," << endl;
    cout << "tetapi membutuhkan data yang sudah terurut terlebih dahulu. Algoritma ini" << endl;
    cout << "bekerja dengan membagi daftar menjadi dua bagian dan membandingkan elemen" << endl;
    cout << "tengah dengan elemen yang dicari. Jika elemen yang dicari lebih kecil dari" << endl;
    cout << "elemen tengah, pencarian dilanjutkan pada bagian kiri, dan sebaliknya pada" << endl;
    cout << "bagian kanan. Proses ini berulang hingga elemen ditemukan atau tidak ada" << endl;
    cout << "lagi bagian yang dapat diperiksa." << endl;
    cout << "> Binary search memerlukan array yang telah tersortir." << endl;
    cout << "> Hanya dapat menggunakan array satu dimensi." << endl;
    cout << "> Kompleksitas Waktu: O(log n)" << endl;
    cout << "> Kompleksitas Ruang: O(1)" << endl;
    cout << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
    cout << "|                     |         Kelebihan         |         Kekurangan         |" << endl;
    cout << "|Sequential Search    | Algoritma sederhana dan   | Waktu pencarian lama jika  |" << endl;
    cout << "|                     | mudah diimplementasikan.  | data banyak (O(n)).        |" << endl;
    cout << "|                     | Tidak memerlukan data     | Tidak efisien untuk dataset|" << endl;
    cout << "|                     | dalam kondisi terurut.    | besar.                     |" << endl;
    cout << "|                     | Bisa digunakan di semua   | Performa buruk jika elemen |" << endl;
    cout << "|                     | jenis struktur data.      | yang dicari ada di akhir.  |" << endl;
    cout << "================================================================================" << endl;
    cout << "|Binary Search        | Sangat cepat untuk        | Data harus dalam kondisi   |" << endl;
    cout << "|                     | dataset besar (O(log n)). | terurut terlebih dahulu.   |" << endl;
    cout << "|                     | Mengurangi jumlah         | Implementasi lebih kompleks|" << endl;
    cout << "|                     | perbandingan dibanding    | dibanding dengan sequential|" << endl;
    cout << "|                     | sequential search.        | search.                    |" << endl;
    cout << "|                     | Efisien untuk pencarian   | Tidak cocok untuk struktur |" << endl;
    cout << "|                     | berulang pada data statis.| data yang dinamis.         |" << endl;
    cout << "--------------------------------------------------------------------------------" << endl;
}

int main() {
    int opt, target;
    do {
        cout << "Pilih menu" << endl;
        cout << "1. Sequential Searching" << endl;
        cout << "2. Binary Searching" << endl;
        cout << "3. Jelaskan Perbedaan Sequential Searching dan Binary Searching!" << endl;
        cout << "4. Exit" << endl;
        cout << "Pilih: ";
        cin >> opt;

        switch (opt) {
            case 1: {
                vector<int> nums (100);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 50);

                for (auto &val: nums) {
                    val = dist(rng);
                }

                cout << "Generating 100 numbers..." << endl;
                for (auto i = 0; i < nums.size(); i++){
                    cout << nums[i] << "[" << i << "]" << " ";
                }
                cout << endl;
                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                sequentialSearch(nums, target);
                break;
            }

            case 2: {
                int size;
                cout << "Masukkan ukuran vector: ";
                cin >> size;
                if (size < 1){
                    cout << "Error: Mohon masukkan bilangan di atas 0" << endl;
                    break;
                }

                vector<int> nums(size);
                mt19937_64 rng(random_device{}());
                uniform_int_distribution<int> dist(1, 100);

                for (auto &val: nums) {
                    val = (dist(rng));
                }

                sort(nums.begin(), nums.end());

                cout << "Generating " << size << " numbers..." << endl;
                for (auto i = 0; i < nums.size(); i++){
                    cout << nums[i] << "[" << i << "]" << " ";
                }
                cout << endl;
                cout << "Masukkan angka yang ingin dicari: "; cin >> target;

                binarySearch(nums, target);
                break;
            }

            case 3:
                explain();
                break;

            case 4:
                cout << "\nTERIMA KASIH\n";
                cout << "Programme was made by A. Malik Fajar Putra Syamsi (2410817210020)" << endl;
                break;

            default:
                cout << "Opsi tidak terdefinisi, mohon masukkan ulang opsi" << endl;
                break;
        }

        if (opt != 4) {
            cout << "\nTekan sembarang tombol untuk melanjutkan...";
            getch();
            clearScreen();
        }

    } while (opt != 4);

    return 0;
}
