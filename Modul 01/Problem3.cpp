#include <iostream>
#include <string>

using namespace std;

struct show{
    char hrf;
    string kt;
    int ngk;
};

int main(){
    show data;

    cout << "\n\n----------------------------\n" << endl;
    cout << "a. Masukkan sebuah huruf    = "; cin >> data.hrf;
    cout << "b. Masukkan sebuah kata     = "; cin >> data.kt;
    cout << "c. Masukkan Angka           = "; cin >> data.ngk;
    cout << "d. Huruf yang Anda masukkan adalah " << data.hrf;
    cout << "\ne. Kata yang Anda masukkan adalah " << data.kt;
    cout << "\nf. Angka yang Anda masukkan adalah " << data.ngk;
    cout << endl;
}
