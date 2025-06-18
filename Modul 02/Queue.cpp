#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct Queue{
    int data[MAX];
    int depan, belakang, besar;
};

Queue line;

int isFull(){
    if((line.belakang + 1) % line.besar == line.depan){
        return true;
    }
    else{
        return false;
    }
}

int isEmpty(){
    if(line.depan == line.belakang){
        return true;
    }
    else{
        return false;
    }
}

void insert(int x){
    if(isFull() == true){
        cout << "Queue Penuh" << endl;
    }
    else{
        line.data[line.belakang] = x;
        cout << "Data: " << line.data[line.belakang] << " Masuk ke dalam Queue " << endl;
        line.belakang = (line.belakang + 1) % line.besar;
    }
}

void DELETE(){
    if (isEmpty() == true){
        cout << "Queue kosong" << endl;
    }
    else{
        cout << "Data yang dihapus: " << line.data[line.depan] << endl;
        line.depan = (line.depan + 1) % line.besar;
    }
}

void show(){
    if(isEmpty() == true){
        cout << "Queue kosong" << endl;
    }
    else{
        int i = line.depan;
        while(i != line.belakang){
            cout << "Queue ke " << i << " = " << line.data[i] << endl;
            i = (i + 1) % line.besar;
        }
    }
}

void reset(){
    line.depan = 0;
    line.belakang = 0;
    cout << "Queue telah di-reset" << endl;
}

void inisialisasi(){
    line.depan = 0;
    line.belakang = 0;
    line.besar = MAX;
}

int PIL;
char PILIHAN[2];

int main(){
    inisialisasi();
    do{
        cout << "\nQueue" << endl;
        cout << "==============" << endl;
        cout << "1. ENQUEUE" << endl;
        cout << "2. DEQUEUE" << endl;
        cout << "3. CETAK QUEUE" << endl;
        cout << "4. BERSIHKAN QUEUE" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : "; cin >> PILIHAN;
        PIL = atoi(PILIHAN);
        switch(PIL){
            case 1:
                int x;
                cout << "Masukkan Nilai: "; cin >> x;
                insert(x);
                break;

            case 2:
                DELETE();
                break;

            case 3:
                show();
                break;

            case 4:
                reset();
                break;

            defaul:
                cout << "TERIMA KASIH" << endl;
                break;
        }
        cout << " Tekan tombol apa saja untuk melanjutkan";
        getch();
        system("cls");
    }
    while (PIL < 5);
    return 0;
}
