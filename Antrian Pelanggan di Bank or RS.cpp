#include <iostream>
#include <queue>
#include <string>

using namespace std;

class Pelanggan {
    public:
    string nama;
    int nomor;

    Pelanggan(string nama = "", int nomor = 0) : nama(nama), nomor(nomor) {}

        void tampilkan() {
            cout << "nomor : " << nomor << ", nama : " << nama << endl;
        }
    };

class Antrian {
    private:
    queue<Pelanggan> daftarAntrian;
    int nomorBerikutnya;

    public:
    Antrian() : nomorBerikutnya(1) {}

    void Tambah(string nama) {
        daftarAntrian.push(Pelanggan(nama, nomorBerikutnya++));
        cout << "Nomor Anda : " << nomorBerikutnya - 1 << endl;
    }
    
    void Panggil () {
        if(!daftarAntrian.empty()) {
            daftarAntrian.front().tampilkan();
            daftarAntrian.pop();
        } else {
            cout << "Antrian Kosong.\n";
        }
    }

    void lihatAntrian() {
        queue<Pelanggan> temp = daftarAntrian;
        while (!temp.empty()) {
            temp.front().tampilkan();
            temp.pop();
        }
    }
};

int main () {
    Antrian antrian;
    int pilihan;
    string nama;

    while(true) {
        cout << "\n1. Ambil Nomor 2. Panggil Nomor 3. Lihat Antrian 4. Keluar :";
        cin >> pilihan;
        cin.ignore();
        switch (pilihan) {
            case 1:
            cout << "Nama: "; getline(cin >> ws, nama);
                antrian.Tambah(nama);
                break;
                case 2:
                antrian.Panggil();
                break;
            case 3:
                antrian.lihatAntrian();
                break;
            case 4:
                return 0;
            default:
                cout << "Pilihan salah.\n";
        }
    }

    return 0;
}