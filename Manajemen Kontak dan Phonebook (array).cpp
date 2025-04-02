#include <iostream>
#include <string>

using namespace std;

class Kontak {
    public:
    string nama;
    string nomor;
    string email;
};

const int MAX = 10;
Kontak phonebook [MAX];
int jumlah = 0;

void tambah () {
    if (jumlah < MAX){
        cout << "Nama : ";
        getline(cin >> ws, phonebook[jumlah].nama);
        cout << "nomor : ";
        getline(cin >> ws, phonebook[jumlah].nomor);
        cout << "email : ";
        getline(cin >> ws, phonebook[jumlah].email);
        jumlah++;
        cout << "Kontak ditambahkan.\n";
    } else {
        cout << "Phonebook penuh.\n";
    }
}
void cari () {
    string namaCari;
    cout << "Cari nama : ";
    getline(cin >> ws, namaCari);
    for (int i = 0; i < jumlah; i++){
        if (phonebook [i].nama == namaCari){
            cout << "nama: " << phonebook[i].nama << ", nomor: " << phonebook[i].nomor << ", Email: " << phonebook[i].email << endl;
            return;
        }
    }
    cout << "Kontak tidak ditemukan.\n";
}

void tampilkan() {
    for (int i = 0; i < jumlah; i++) {
        cout << "Nama: " << phonebook[i].nama << ", Nomor: " << phonebook[i].nomor << ", Email: " << phonebook[i].email << endl;
    }
}

void hapus (){
    string namaHapus;
    cout << "Hapus nama : ";
    getline(cin >> ws, namaHapus);
        for (int i=0; i<jumlah; i++){
            if (phonebook[i].nama == namaHapus){
                for (int j = i; j < jumlah - 1; j++){
                    phonebook[j] = phonebook[j - 1];
                }
                jumlah --;
                cout << "Kontak dihapus.\n";
                return;
            }
        }
        cout << "Kontak tidak ditemukan.\n";
    }

    int main () {
        int pilihan;
        while (true) {
            cout << "\n1. Tambah 2. Cari 3. Tampil 4. Hapus 5. Keluar: ";
            cin >> pilihan;
            cin.ignore();
            switch(pilihan) {
                case 1: tambah(); break;
                case 2: cari(); break;
                case 3: tampilkan(); break;
                case 4: hapus(); break;
                case 5: return 0;
                default: cout << "Pilihan salah.\n";
            }

        }
        return 0;
    }