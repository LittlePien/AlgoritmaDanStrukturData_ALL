#include <iostream>
#include <string>

using namespace std;

struct kdr{
    string no_plat, alamat, jenis, nama, kota;
};

int main(){
    kdr A = {"DA1234MK", "Jl. Kayu Tangi 1", "RUSH", "Andika Hartanto", "Banjarmasin"};
    
    cout << "\n\n----------------------------\n" << endl;
    cout << "a. Plat Nomor Kendaraan    = " << A.no_plat;
    cout << "\nb. Jenis Kendaraan         = " << A.jenis;
    cout << "\nc. Nama Pemilik            = " << A.nama;
    cout << "\nd. Alamat                  = " << A.alamat;
    cout << "\ne. Kota                    = " << A.kota;
    cout << endl;
}
