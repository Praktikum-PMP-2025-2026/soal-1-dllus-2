/* Praktikum PMP EL2008 Modul 4: Dynamic Structures
* Nama: Adlu Naafi Firdaus
* NIM: 13224029
* Jadwal Praktikum: Senin, 4 Mei 2026
* Soal: 1
*/


#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
};

struct Node *head = NULL;

void push_front(int x) {
    struct Node *baru = (struct Node*)malloc(sizeof(struct Node));
    baru->data = x;
    baru->next = head; 
    head = baru;       
}

void push_back(int x) {
    struct Node *baru = (struct Node*)malloc(sizeof(struct Node));
    baru->data = x;
    baru->next = NULL;

    if (head == NULL) {
        head = baru;
        return;
    }

    struct Node *temp = head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = baru;
}

void delete_node(int x) {
    if (head == NULL) return; 

    if (head->data == x) {
        struct Node *buang = head;
        head = head->next;
        free(buang);
        return;
    }

    struct Node *temp = head;
    struct Node *prev = NULL;

    while (temp != NULL && temp->data != x) {
        prev = temp;
        temp = temp->next;
    }

    if (temp != NULL) {
        prev->next = temp->next;
        free(temp);
    }
}

void find_node(int x) {
    int posisi = 0;
    struct Node *temp = head;

    while (temp != NULL) {
        if (temp->data == x) {
            printf("FOUND %d\n", posisi);
            return;
        }
        temp = temp->next;
        posisi++;
    }
    printf("NOT FOUND\n");
}

int main() {
    int Q;
    
    if (scanf("%d", &Q) != 1) return 0; 

    for (int i = 0; i < Q; i++) {
        int op, x;
        scanf("%d %d", &op, &x);

        if (op == 1) {
            push_front(x);
        } else if (op == 2) {
            push_back(x);
        } else if (op == 3) {
            delete_node(x);
        } else if (op == 4) {
            find_node(x);
        }
    }

    if (head == NULL) {
        printf("LIST EMPTY\n");
    } else {
        printf("LIST");
        struct Node *temp = head;
        while (temp != NULL) {
            printf(" %d", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }

    struct Node *hapus_sisa;
    while (head != NULL) {
        hapus_sisa = head;
        head = head->next;
        free(hapus_sisa);
    }

    return 0;
}
