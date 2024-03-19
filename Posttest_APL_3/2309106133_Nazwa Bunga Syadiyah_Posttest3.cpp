#include <iostream>
#include <string>

using namespace std;

#define max 10

string BarangAntik[max], loop;
int pos = 0;

int getMenuChoice() {
    int choice;
    system("cls");
    cout << "=====================" << endl;
    cout << "  TOKO BARANG ANTIK  " << endl;
    cout << "=====================" << endl;
    cout << "1. Tambah\n2. Ubah\n3. Hapus\n4. Tampilkan\n5. Keluar" << endl;
    cout << "Pilihan : ";
    cin >> choice;
    return choice;
}

void display() {
    system("cls");
    if (pos != 0) {
        cout << "Data Tersimpan" << endl;
        for (int a = 0; a < pos; a++) {
            cout << a+1 << ". " << BarangAntik[a] << endl;
        }
    } else {
        cout << "=== Data Kosong ===" << endl;
    }
}

void add() {
    do {
        display();
        if (pos < max) {
            cin.ignore();
            cout << "Tambah Data : ";
            getline(cin, BarangAntik[pos]);
            pos++;
            display();
            cout << "ulangi (y/t) : ";
            cin >> loop;
        } else {
            cout << "=== memori penuh ===" << endl;
            cout << "isi t untuk kembali : ";
            cin >> loop;
        }       
    } while(loop == "y");
}

void edit() {
    int y;
    do {
        display();
        cout << "ubah data ke : ";
        cin >> y;
        cin.ignore();
        cout << "ubah menjadi : ";
        getline(cin, BarangAntik[y-1]);
        display();
        cout << "ubah lagi (y/t) : ";
        cin >> loop;
    } while(loop == "y");
}

void recursiveDelete(int x) {
    if (x < pos) {
        BarangAntik[x-1] = BarangAntik[x];
        recursiveDelete(x+1);
    }
}

void del() {
    int x;
    do {
        display();
        if (pos > 0) {
            cout << " hapus data ke : ";
            cin >> x;
            recursiveDelete(x);
            pos--;
            display();
            cout << "hapus lagi (y/t) : ";
            cin >> loop;
        } else {
            cout << "isikan t : ";
            cin >> loop;
        }       
    } while (loop == "y");
}

int main() {
    string username;
    string password;
    int salah = 0;

    do {
        cout << "username: ";
        cin >> username;

        cout << "password: ";
        cin >> password;

        if (username == "Bunga" && password == "2309106133") {
            cout << "Login berhasil" << endl << endl;
            break;
        } else {
            cout << "Username atau password salah. Silakan coba lagi." << endl << endl;
            salah++;
        }

        if (salah == 3) {
            cout << "Anda sudah mencoba 3 kali. Silakan coba lagi nanti." << endl;
            return 0;
        }
    } while (true);

    int pil;
    do {
        pil = getMenuChoice();
        switch (pil) {
            case 1:
                add();
                break;
            case 2:
                edit();
                break;
            case 3:
                del();
                break;
            case 4:
                do {
                    display();
                    cout << "kembali (y) : ";
                    cin >> loop;
                } while (loop != "y");
                break;
            case 5:
                cout << "Keluar" << endl;
                break;
            default:
                cout << "Pilih 1 - 5" << endl;
                break;
        }
    } while (pil != 5);
    cout << "Program selesai";
    return 0;
}