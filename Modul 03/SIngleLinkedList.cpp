#include <conio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

typedef struct TNode
{
    string data;
    TNode *next;
};

TNode *head, *tail;

int pil;
char pilihan [2];
string newDat, delDat;

void init();
int empty();

void addFront();
void addBack();
void delFront();
void delBack();
void show();
void reset();
void searchData();
void delData();
void insertBefore();
void insertAfter();

int main()
{
    do
    {
        cout<<"Single Linked List Circular (SLLC)"<<endl;
        cout<<"=================================="<<endl;
        cout<<"1. Tambah Depan"<<endl;
        cout<<"2. Tambah Belakang"<<endl;
        cout<<"3. Hapus Depan"<<endl;
        cout<<"4. Hapus Belakang"<<endl;
        cout<<"5. Tampilkan Data"<<endl;
        cout<<"6. Hapus Semua elemen"<<endl;
        cout<<"7. Cari Data"<<endl;
        cout<<"8. Hapus Setiap Data Tertentu"<<endl;
        cout<<"9. Sisipkan Node/Data Baru Sebelum Data Tertentu"<<endl;
        cout<<"10. Sisipkan Node/Data Baru Setelah Data Tertentu"<<endl;
        cout<<"11. Keluar"<<endl;
        cout<<"=================================="<<endl;
        cout<<"Pilihan : ";
        cin>>pilihan;
        pil = atoi(pilihan);

        switch(pil)
        {
        case 1:
            addFront();
            break;
        case 2:
            addBack();
            break;
        case 3:
            delFront();
            cout<<"Data \""<<delDat<<"\" yang berada di depan berhasil dihapus."<<endl;
            break;
        case 4:
            delBack();
            cout<<"Data \""<<delDat<<"\" yang berada di belakang berhasil dihapus."<<endl;
            break;
        case 5:
            show();
            break;
        case 6:
            reset();
            break;
        case 7:
            searchData();
            break;
        case 8:
            delData();
            break;
        case 9:
            insertBefore();
            break;
        case 10:
            insertAfter();
            break;
        default:
            cout<<"\nTERIMA KASIH"<<endl;
            cout<<"Program was made by A. Malik Fajar Putra Syamsi (2410817210020)"<<endl;
        }

        cout<<"\nPress any key to continue!"<<endl;
        getch();
        system("cls");
    }
    while (pil<11);
}

void init()
{
    head = NULL;
    tail = NULL;
}

int empty()
{
    if(head == NULL)
        return true;
    else
        return false;
}

void addFront()
{
    cout<<"Masukkan Data : ";
    TNode *baru;
    baru = new TNode;
    cin>>newDat;
    baru->data = newDat;
    baru->next = baru;

    if(empty() == 1)
    {
        head = baru;
        tail = baru;
    }
    else
    {
        baru->next = head;
        head = baru;
        tail->next = head;
    }
    cout<<"Data \""<<newDat<<"\" telah berhasil dimasukkan di bagian depan."<<endl;
}

void addBack()
{
    cout<<"Masukkan Data : ";
    TNode *baru;
    baru = new TNode;
    cin>>newDat;
    baru->data = newDat;
    baru->next = baru;

    if(empty() == 1)
    {
        head = baru;
        tail = baru;
    }
    else
    {
        tail->next = baru;
        tail = baru;
        tail->next = head;
    }
    cout<<"Data \""<<newDat<<"\" telah berhasil dimasukkan di bagian belakang."<<endl;
}

void delFront()
{
    if(empty() == 0)
    {
        TNode *hapus;
        hapus = head;
        delDat = hapus->data;

        if(head != tail)
        {
        head = head->next;
        tail->next = head;
        }
        else
        {
            init();
        }

        delete hapus;
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void delBack()
{
    if(empty() == 0)
    {
        TNode *hapus, *newTail;
        hapus = tail;
        delDat = hapus->data;

        if(head != tail)
        {
            newTail = head;
            while(newTail->next != tail)
            {
                newTail = newTail->next;
            }
            tail = newTail;
            tail->next = head;
        }
        else
        {
            init();
        }
        delete hapus;
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void show()
{
    if(empty() == 0)
    {
        TNode *bantu;
        bantu = head;

        do
        {
            cout<<bantu->data<<' ';
            bantu = bantu->next;
        }
        while (bantu != head);
        cout<<endl;
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void reset()
{
    if(empty() == 0)
    {
        TNode *bantu, *hapus;
        bantu = head;

        do
        {
            hapus = bantu;
            bantu = bantu->next;
            delete hapus;
        }
        while (bantu != head);
        init();
        cout<<"Seluruh elemen pada Linked List telah dibersihkan."<<endl;
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void searchData()
{
    if(empty() == 0)
    {
        string cari;
        cout<<"Masukkan data yang ingin dicari : ";
        cin>>cari;

        TNode *bantu, *hapus, *newTail, *bantuTampilkan;
        bool apaDitemukan = false;

        bantu = head;

        do
        {
            if(cari == bantu->data)
            {
                cout<<"Setiap data yang berada di dalam tanda kurung siku ([...]) "
                    <<"merupakan data yang anda cari."<<endl;
                cout<<"Linked List : ";
                bantuTampilkan = head;

                do
                {
                    if(cari == bantuTampilkan->data)
                    {
                        cout<<"["<<bantuTampilkan->data<<"] ";
                    }
                    else
                    {
                        cout<<bantuTampilkan->data<<' ';
                    }
                    bantuTampilkan = bantuTampilkan->next;
                }
                while (bantuTampilkan != head);

                apaDitemukan = true;
                cout<<endl;
                break;
            }
            bantu = bantu->next;
        }
        while (bantu != head);

        if(apaDitemukan == false)
        {
            cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;
        }
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void delData()
{
    if(empty() == 0)
    {
        string cari;
        cout<<"Masukkan data yang ingin dihapus : ";
        cin>>cari;

        TNode *bantu, *sebelum, *hapus[255], *bantu2;
        int hitung = 0;
        bool apaDitemukan = false;

        bantu = head;

        do
        {
            bantu2 = bantu;
            if(cari == bantu->data)
            {
                hapus[hitung++] = bantu;
                apaDitemukan = true;
                if(bantu != head && bantu != tail)
                {
                    sebelum->next = bantu->next;
                    bantu2 = sebelum;
                }
            }
            sebelum = bantu2;
            bantu = bantu->next;
        }
        while (bantu != head);

        if(apaDitemukan == true)
        {
            for(int i=0; i<hitung; i++)
            {
                if(hapus[i] == head)
                {
                    delFront();
                }
                else if(hapus[i] == tail)
                {
                    delBack();
                }
                else
                {
                    delete hapus[i];
                }
            }
            cout<<"Setiap data \""<<cari<<"\" yang terdapat pada Linked List telah dihapus."<<endl;
        }
        else
        {
            cout<<"Data \""<<cari<<"\" tidak ditemukan pada Linked List."<<endl;
        }
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void insertBefore()
{
    if(empty() == 0)
    {
        TNode *bantu, *sebelum;
        string nextData;
        bool apaAda;

        bantu = head;
        sebelum = tail;

        cout<<"Sisipkan data baru sebelum data : ";
        cin>>nextData;

        do
        {
            if(nextData == bantu->data)
            {
                apaAda = true;
                break;
            }
            else
            {
                sebelum = bantu;
                bantu = bantu->next;
            }
        }
        while (bantu != head);

        if(apaAda == true)
        {
            cout<<"Masukkan data yang ingin ditambahkan : ";
            cin>>newDat;

            TNode *baru;
            baru = new TNode;

            baru->data = newDat;
            baru->next = bantu;

            sebelum->next = baru;

            if(bantu == head)
            {
                head = baru;
            }
            cout<<"Data \""<<newDat<<"\" berhasil disisipkan sebelum data \""<<nextData<<"\"."<<endl;
        }
        else
        {
            cout<<"Tidak terdapat data \""<<nextData<<"\" pada Linked List."<<endl;
        }
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}

void insertAfter()
{
    if(empty() == 0)
    {
        TNode *bantu;
        string prevData;
        bool apaAda;

        bantu = head;

        cout<<"Sisipkan data baru setelah data : ";
        cin>>prevData;

        do
        {
            if(prevData == bantu->data)
            {
                apaAda = true;
                break;
            }
            else
            {
                bantu = bantu->next;
            }
        }
        while (bantu != head);

        if(apaAda == true)
        {
            cout<<"Masukkan data yang ingin ditambahkan : ";
            cin>>newDat;

            TNode *baru;
            baru = new TNode;

            baru->data = newDat;
            baru->next = bantu->next;

            bantu->next = baru;

            if(bantu == tail)
            {
                tail = baru;
            }
            cout<<"Data \""<<newDat<<"\" berhasil disisipkan sebelum data \""<<prevData<<"\"."<<endl;
        }
        else
        {
            cout<<"Tidak terdapat data \""<<prevData<<"\" pada Linked List."<<endl;
        }
    }
    else
    {
        cout<<"Tidak terdapat data pada Linked List."<<endl;
    }
}