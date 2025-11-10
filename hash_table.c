/*
Design and implement a hash table of fixed size. 
Use the division method for the hash function 
and resolve collisions using linear probing.
Allow the user to perform the following operations:
• Insert a key • Search for a key • Delete a key • Display the table
*/

#include <stdio.h>
#define SIZE 10


int hash(int key) {
    return key % SIZE;
}


void initialize(int H[]) {
    for (int i = 0; i < SIZE; i++) {
        H[i] = -1;
    }
}

int probe(int H[], int key) {
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != -1) {
        i++;
        if (i == SIZE) return -2; 
    }
    return (index + i) % SIZE;
}

void insert(int H[], int key) {
    int index = hash(key);
    if (H[index] != -1) {
        index = probe(H, key);
        if (index == -2) {
            printf("Hash table full! Cannot insert %d\n", key);
            return;
        }
    }
    H[index] = key;
}

int search(int H[], int key) {
    int index = hash(key);
    int i = 0;
    while (H[(index + i) % SIZE] != -1) {
        if (H[(index + i) % SIZE] == key)
            return (index + i) % SIZE;
        i++;
        if (i == SIZE) break;
    }
    return -1;
}

void deletekey(int H[], int key) {
    int pos = search(H, key);
    if (pos == -1) {
        printf("%d not found!\n", key);
    } else {
        H[pos] = -1; 
        printf("%d deleted from index %d\n", key, pos);
    }
}

void display(int H[]) {
    printf("\nHash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("[%d] : %d\n", i, H[i]);
    }
    printf("\n");
}

int main() {
    int HT[SIZE];
    initialize(HT);

    insert(HT, 10);
    insert(HT, 12);
    insert(HT, 22);

    display(HT);

    int pos = search(HT, 12);
    if (pos != -1) 
        printf("12 found at index %d\n", pos);
    else 
        printf("12 not found!\n");

    deletekey(HT, 12);
    display(HT);

    return 0;
}
