#include <iostream>
#include <limits>
#include "stack.h"
using namespace std;

// Membaca bilangan bulat; mengembalikan false bila input tidak valid / EOF.
static bool bacaInt(int &v) {
    if (cin >> v) {
        return true;
    }
    if (!cin.eof()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return false;
}

int main() {
    Stack S;
    createStack(S);
    int pilihan = -1;

    do {
        cout << "\n=== MENU STACK (POINTER, TERURUT) ===" << endl;
        cout << "1. Tambah Terurut" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Tampilkan" << endl;
        cout << "0. Keluar" << endl;
        cout << "Pilihan: ";

        if (!bacaInt(pilihan)) {
            if (cin.eof()) {
                break;
            }
            cout << "Input harus berupa bilangan bulat." << endl;
            pilihan = -1;
            continue;
        }

        switch (pilihan) {
        case 1: {
            int x;
            cout << "Masukkan bilangan bulat: ";
            if (!bacaInt(x)) {
                cout << "Input tidak valid." << endl;
                break;
            }
            if (pushAscending(S, x)) {
                cout << x << " berhasil ditambahkan." << endl;
                printInfo(S);
            } else {
                cout << "Gagal menambahkan (memori habis)." << endl;
            }
            break;
        }
        case 2: {
            int x;
            if (pop(S, x)) {
                cout << "Nilai yang di-Pop: " << x << endl;
            } else {
                cout << "Stack kosong! Pop ditolak." << endl;
            }
            break;
        }
        case 3:
            printInfo(S);
            break;
        case 0:
            cout << "Program selesai." << endl;
            break;
        default:
            cout << "Pilihan tidak valid." << endl;
        }
    } while (pilihan != 0);

    clearStack(S);
    return 0;
}