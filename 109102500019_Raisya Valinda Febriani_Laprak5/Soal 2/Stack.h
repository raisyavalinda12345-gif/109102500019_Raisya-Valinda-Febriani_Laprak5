#ifndef STACK_H
#define STACK_H

// Stack berbasis singly linked list. Stack kosong: Top = nullptr.
struct Node {
    int info;
    Node *next;
};

struct Stack {
    Node *Top;
};

void createStack(Stack &S);
bool isEmpty(Stack S);
Node *alokasi(int x);
void dealokasi(Node *&P);
bool push(Stack &S, int x);
bool pop(Stack &S, int &x);
void printInfo(Stack S);
bool pushAscending(Stack &S, int x);
void clearStack(Stack &S);

#endif