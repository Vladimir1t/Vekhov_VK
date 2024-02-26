#include <stdio.h>
#include <stdlib.h>

struct Pair
{
    char   sym;
    size_t number;
};

struct HashTable
{
    struct Pair* data;
    size_t capacity;
    size_t size;
};

int HashFunction (char* elem);
int Insert (struct HashTable* ht, char* elem, int* maxNum);

int main ()
{
    struct HashTable ht = {};
    ht.data = (Pair*) calloc (60, sizeof(Pair));
    ht.capacity = 60;

    int maxNum = 0;
    char elem = getchar ();
    while (elem != '\n' && elem != EOF)
    {
        Insert (&ht, &elem, &maxNum);
        (ht.size)++;
        elem = getchar ();
    }

    printf ("%d\n", maxNum);
    free (ht.data);

    return 0;
}

int Insert (struct HashTable* ht, char* elem, int* maxNum)
{
    int index = HashFunction (elem);

    if (index > ht->capacity)
    {
        ht->data = (Pair*) realloc (ht->data, ht->capacity * 2 * sizeof(Pair));
        (ht->capacity) *= 2;
    }

    ht->data[index].number += 1;

    if (ht->data[index].sym == *elem)
    {
        if (ht->data[index].number > *maxNum)
            *maxNum = ht->data[index].number;
        return 0;
    }
    if (ht->data[index].number > *maxNum)
            *maxNum = ht->data[index].number;

    ht->data[index].sym = *elem;
    return 0;
}

int HashFunction (char* elem)
{
    int number = (int) *elem;
    return number % 60;
}
