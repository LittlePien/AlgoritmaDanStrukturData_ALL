#include <iostream>
#include <conio.h>
#include <stdlib.h>

#define MAX 20

using namespace std;

struct Stack{
    int data[MAX];
    int atas;
};

Stack Tumpuk;

int penuh(){
    if(Tumpuk.atas == MAX-1){
        return true;
    }
    else{
        return false;
    }
}

int kosong(){
    if(Tumpuk.atas == -1){
        return true;
    }
    else{
        return false;
    }
}

void push(int data){
    if(kosong() == true){
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack";
    }
    else if(penuh() == false){
        Tumpuk.atas++;
        Tumpuk.data[Tumpuk.atas] = data;
        cout << "Data " << Tumpuk.data[Tumpuk.atas] << " Masuk Ke Stack";
    }
    else{
        cout << "Tumpukan Penuh";
    }
}

void pop(){
    if(kosong() == false){
        cout << "Data Teratas Sudah Terambil";
        //int data = Tumpuk.data[Tumpuk.atas];
        Tumpuk.atas--;
    }
    else{
        cout << "Data Kosong";
    }
}

void show(){
    if(kosong() == false){
        for(int i = Tumpuk.atas; i >= 0; i--){
            cout << "\nTumpukan Ke " << i << " = " << Tumpuk.data[i];
        }
    }
    else{
        cout << "Tumpukan Kosong";
    }
}

void reset(){
    Tumpuk.atas = -1;
    cout << "Tumpukan Kosong !";
}

void init(){
    Tumpuk.atas = -1;
}

int ch;
char choice[2];

int main(){
    init();
    do{
        cout << "\nStack" << endl;
        cout << "==============" << endl;
        cout << "1. PUSH" << endl;
        cout << "2. POP" << endl;
        cout << "3. CETAK STACK" << endl;
        cout << "4. BERSIHKAN STACK" << endl;
        cout << "5. QUIT" << endl;
        cout << "PILIHAN : "; cin >> choice;
        ch = atoi(choice);
        switch(ch){
            case 1:
                int data;
                cout << "Masukkan Nilai: "; cin >> data;
                push(data);
                break;

            case 2:
                pop();
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
    while (ch < 5);
    return 0;
}
