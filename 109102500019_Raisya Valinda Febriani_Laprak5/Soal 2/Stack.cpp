#include <iostream>
#include <new>
#include "stack.h"
using namespace std;

void createStack(Stack &S) {
    S.Top = nullptr;
}

bool isEmpty(Stack S) {
    return S.Top == nullptr;
}

// Membuat node baru; nullptr bila memori habis.
Node *alokasi(int x) {
    Node *P = new (nothrow) Node;
    if (P != nullptr) {
        P->info = x;
        P->next = nullptr;
    }
    return P;
}

void dealokasi(Node *&P) {
    delete P;
    P = nullptr;
}

// Menambah elemen pada TOP.
bool push(Stack &S, int x) {
    Node *P = alokasi(x);
    if (P == nullptr) {
        return false;
    }
    P->next = S.Top;
    S.Top = P;
    return true;
}

// Mengambil nilai TOP lalu melepas node-nya. Stack kosong -> false, tidak berubah.
bool pop(Stack &S, int &x) {
    if (isEmpty(S)) {
        return false;
    }
    Node *P = S.Top;
    x = P->info;
    S.Top = P->next;
    dealokasi(P);
    return true;
}

// Menampilkan isi stack mulai dari TOP ke bawah.
void printInfo(Stack S) {
    if (isEmpty(S)) {
        cout << "Stack kosong." << endl;
        return;
    }
    cout << "TOP:";
    for (Node *P = S.Top; P != nullptr; P = P->next) {
        cout << " " << P->info;
    }
    cout << endl;
}

// Menyisipkan x sehingga urutan menaik dari bawah ke TOP (terbesar di TOP).
// Elemen yang lebih besar dari x dipindah sementara ke stack bantu (H),
// x di-push, lalu semua elemen di H dikembalikan. Duplikat tetap disimpan.
bool pushAscending(Stack &S, int x) {
    Stack H;
    createStack(H);
    int v;

    while (!isEmpty(S) && S.Top->info > x) {
        pop(S, v);
        push(H, v);
    }
    bool ok = push(S, x);
    while (!isEmpty(H)) {
        pop(H, v);
        push(S, v);
    }
    return ok;
}

// Melepas seluruh node; Top kembali nullptr.
void clearStack(Stack &S) {
    int x;
    while (pop(S, x)) {
    }
    S.Top = nullptr;
}