#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct TNode{
    string data;
    TNode *next;
    TNode *prev;
};

TNode *head, *tail;

int pil, menu;
char pilihan[1];
string newDat;

void initH();
void initHT();
int isEmptyH();
int isEmptyHT();

void addFrontH();
void addFrontHT();
void addBackH();
void addBackHT();
void showH();
void showHT();
void deleteFrontH();
void deleteFrontHT();
void deleteBackH();
void deleteBackHT();
void clearH();
void clearHT();

int main(){
    menu:
    cout << "Double Linked List Non Circular (DLLNC)" << endl;
    cout << "=======================================" << endl;
    cout << "Silahkan pilih program DLLNC yang ingin dijalankan!" << endl;
    cout << "1. DLLNC dengan Head" << endl;
    cout << "2. DLLNC dengan Head dan Tail" << endl;
    cout << "3. Quit" << endl;
    cout << "=======================================" << endl;
    cout << "Pilihan : ";
    cin >> menu;
    system("cls");

    if(menu == 1){
        do{
            cout << "Double Linked List Non Circular (DLLNC) (Head)" << endl;
            cout << "==============================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Reset" << endl;
            cout << "7. Kembali ke Menu" << endl;
            cout << "==============================================" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);

            switch(pil){
                case 1:
                    addFrontH();
                    break;
                case 2:
                    addBackH();
                    break;
                case 3:
                    showH();
                    break;
                case 4:
                    deleteFrontH();
                    break;
                case 5:
                    deleteBackH();
                    break;
                case 6:
                    clearH();
                    break;
                default:
                    system("cls");
                    goto menu;
            }
            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");
        } while (pil < 7);
    } else if(menu == 2){
        do{
            cout << "Double Linked List Non Circular (DLLNC) (Head dan Tail)" << endl;
            cout << "=======================================================" << endl;
            cout << "1. Tambah Depan" << endl;
            cout << "2. Tambah Belakang" << endl;
            cout << "3. Tampilkan Data" << endl;
            cout << "4. Hapus Depan" << endl;
            cout << "5. Hapus Belakang" << endl;
            cout << "6. Reset" << endl;
            cout << "7. Kembali ke Menu" << endl;
            cout << "=======================================================" << endl;
            cout << "Pilihan : ";
            cin >> pilihan;
            pil = atoi(pilihan);
            switch(pil){
                case 1:
                    addFrontHT();
                    break;
                case 2:
                    addBackHT();
                    break;
                case 3:
                    showHT();
                    break;
                case 4:
                    deleteFrontHT();
                    break;
                case 5:
                    deleteBackHT();
                    break;
                case 6:
                    clearHT();
                    break;
                default:
                    system("cls");
                    goto menu;
            }
            cout << "\npress any key to continue" << endl;
            getch();
            system("cls");
        } while (pil < 7);
    } else{
        cout << "\nTERIMA KASIH" << endl;
        cout << "Program was made by A. Malik Fajar Putra Syamsi (2410817210020)." << endl;
    }
}

void initH(){
    head = NULL;
}

void initHT(){
    head = NULL;
    tail = NULL;
}

int isEmptyH(){
    if(head == NULL) return true;
    else return false;
}

int isEmptyHT(){
    if(tail == NULL) return true;
    else return false;
}

void addFrontH(){
    cout << "Masukkan Data : ";
    cin >> newDat;
    TNode *baru;
    baru = new TNode;
    baru->data = newDat;
    baru->next = NULL;
    baru->prev = NULL;

    if(isEmptyH() == true){
        head = baru;
        head->next = NULL;
        head->prev = NULL;
    }
    else{
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout << "Data \""<<newDat<<"\" berhasil dimasukkan di bagian depan.";
}

void addFrontHT(){
    cout << "Masukkan data : ";
    cin >> newDat;
    TNode *baru;
    baru = new TNode;
    baru->data = newDat;
    baru->next = NULL;
    baru->prev = NULL;

    if(isEmptyHT() == true){
        head = baru;
        tail = baru;
    }
    else{
        baru->next = head;
        head->prev = baru;
        head = baru;
    }
    cout << "Data \""<<newDat<<"\" berhasil dimasukkan di bagian depan.";
}

void addBackH(){
    cout << "Masukkan Data : ";
    cin >> newDat;
    TNode *baru, *bantu;
    baru = new TNode;
    baru->data = newDat;
    baru->next = NULL;
    baru->prev = NULL;

    if(isEmptyH() == true){
        head = baru;
    }
    else{
        bantu = head;
        while(bantu->next != NULL){
            bantu = bantu->next;
        }
        bantu->next = baru;
        baru->prev = bantu;
    }
    cout << "Data \""<<newDat<<"\" berhasil dimasukkan di bagian belakang.";
}

void addBackHT(){
    cout << "Masukkan Data : ";
    cin >> newDat;
    TNode *baru;
    baru = new TNode;
    baru->data = newDat;
    baru->next = NULL;
    baru->prev = NULL;

    if(isEmptyHT() == true){
        head = baru;
        tail = baru;
    }
    else{
        tail->next = baru;
        baru->prev = tail;
        tail = baru;
    }
    cout << "Data \""<<newDat<<"\" berhasil dimasukkan di bagian belakang.";
}

void showH(){
    TNode *bantu;
    bantu = head;

    if(isEmptyH() == false){
        while(bantu != NULL){
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "Tidak terdapat data pada Linked List";
    }
}

void showHT(){
    TNode *bantu;
    bantu = head;

    if(isEmptyHT() == false){
        while(bantu != tail->next){
            cout << bantu->data << ' ';
            bantu = bantu->next;
        }
        cout << endl;
    }
    else{
        cout << "Tidak terdapat data pada Linked List";
    }
}

void deleteFrontH(){
    TNode *hapus;
    string data;

    if(isEmptyH() == false){
        hapus = head;
        data = hapus->data;
        if(head->next != NULL){
            head = head->next;
            head->prev = NULL;
        }
        else{
            initH();
        }
        delete hapus;
        cout << "Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    }
    else{
        cout << "Tidak terdapat data pada Linked List";
    }
}

void deleteFrontHT(){
    TNode *hapus;
    string data;

    if(isEmptyHT() == false){
        hapus = head;
        data = hapus->data;
        if(head->next != NULL){
            head = head->next;
            head->prev = NULL;
        }
        else{
            initHT();
        }
        delete hapus;
        cout << "Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    }
    else{
        cout << "Tidak terdapat data pada Linked List";
    }
}

void deleteBackH(){
    TNode *hapus;
    string data;

    if(isEmptyH() == false){
        hapus = head;
        while(hapus->next != NULL){
            hapus = hapus->next;
        }
        data = hapus->data;
        if(head->next != NULL){
            hapus->prev->next = NULL;
        }
        else{
            initH();
        }
        delete hapus;
        cout << "Data \""<<data<<"\" yang berada di belakang telah berhasil dihapus.";
    }
    else{
        cout << "Tidak terdapat data pada Linked List";
    }
}

void deleteBackHT(){
    TNode *hapus;
    string data;

    if(isEmptyHT() == false){
        hapus = tail;
        data = hapus->data;
        if(head->next != NULL){
            tail = tail->prev;
            tail->next = NULL;
        }
        else{
            initHT();
        }
        delete hapus;
        cout << "Data \""<<data<<"\" yang berada di depan telah berhasil dihapus.";
    }
    else{
        cout << "Tidak terdapat data pada Linked List";
    }
}

void clearH(){
    TNode *bantu, *hapus;
    bantu = head;
    while(bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    initH();
    cout << "Seluruh data pada Linked List telah dibersihkan.";
}

void clearHT(){
    TNode *bantu, *hapus;
    bantu = head;
    while(bantu != NULL){
        hapus = bantu;
        bantu = bantu->next;
        delete hapus;
    }
    initHT();
    cout << "Seluruh data pada Linked List telah dibersihkan.";
}