#include <stdio.h>
#define SIZE 10

int hashTable[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) hashTable[i] = -1;
}

int hash(int key) {
    return key % SIZE;
}

void insert(int key) {
    int index = hash(key);
    int i = 0;
    while (hashTable[(index + i) % SIZE] != -1)
        i++;
    hashTable[(index + i) % SIZE] = key;
}

void display() {
    for (int i = 0; i < SIZE; i++)
        printf("%d -> %d\n", i, hashTable[i]);
}

int main() {
    init();
    insert(23);
    insert(43);
    insert(13);
    insert(27);

    printf("Hash Table:\n");
    display();
    return 0;
}
