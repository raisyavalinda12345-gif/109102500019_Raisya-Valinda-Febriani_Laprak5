#include <iostream>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.Top = 0;
}

bool isEmpty(Stack S) {
    return S.Top == 0;
}

bool isFull(Stack S) {
    return S.Top == MAX_STACK;
}

// Gagal (false) bila stack penuh; isi dan Top tidak berubah.
bool push(Stack &S, int x) {
    if (isFull(S)) {
        return false;
    }
    S.Top++;
    S.info[S.Top] = x;
    return true;
}

// Gagal (false) bila stack kosong; isi dan Top tidak berubah.
bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    x = S.info[S.Top];
    S.Top--;
    return true;
}

// Menampilkan isi stack mulai dari TOP ke bawah.
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "TOP:";
    for (int i = S.Top; i >= 1; i--) {
        cout << " " << S.info[i];
    }
    cout << endl;
}

// Membalik isi stack memakai SATU stack bantu (H), hanya lewat push/pop.
// Pada langkah ke-i, elemen paling atas diselipkan tepat di atas i-1 elemen
// yang sudah final di dasar stack; sisa elemen dipindah ke H lalu dikembalikan
// (dua kali dibalik = urutan semula). Jumlah elemen dan duplikat tetap.
void balikStack(Stack &S) {
    Stack H;
    createStack(H);
    int n = S.Top;
    int x, y;

    for (int i = 1; i < n; i++) {
        pop(S, x);                 // elemen teratas yang akan diselipkan
        int sisa = n - i;          // banyak elemen yang belum diproses

        for (int k = 0; k < sisa; k++) {   // pindahkan sisa ke stack bantu
            pop(S, y);
            push(H, y);
        }
        push(S, x);                // letakkan di atas bagian yang sudah final
        for (int k = 0; k < sisa; k++) {   // kembalikan sisa ke stack utama
            pop(H, y);
            push(S, y);
        }
    }
}