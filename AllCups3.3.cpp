#include <stdio.h>
#include <stdlib.h>

struct Pair
{
    int sym;
    int num;
};
struct HashTable
{
    size_t       capacity;
    size_t       size;
    struct Pair* data;
};

int HashFunction (int* elem, int m);
int Insert (struct HashTable* ht, int* elem, int* maxElem);

int main ()
{
    struct HashTable ht = {};
    ht.capacity = 30;
    ht.data = (struct Pair*) calloc (ht.capacity, sizeof (struct Pair));

    scanf ("%d", &(ht.size));
    int elem = 0;
    int maxElem = -1;
    for (int i = 0; i < ht.size; i++)
    {
        scanf ("%d", &elem);
        Insert (&ht, &elem, &maxElem);
    }

    printf ("%d", maxElem);
    //printf ("--%d--", 1 / 2);
    free (ht.data);
    return 0;
}

int Insert (struct HashTable* ht, int* elem, int* maxElem)
{
    int index = HashFunction (elem, ht->capacity);

   /* if (index > ht->capacity)
    {
        ht->data = (Pair*) realloc (ht->data, ht->capacity * 2 * sizeof(Pair));
        (ht->capacity) *= 2;
    }   */

    ht->data[index].num += 1;
    ht->data[index].sym = *elem;

    if (ht->data[index].num > ht->size / 2)
        *maxElem = ht->data[index].sym;
    //printf ("elem %d\n", ht->data[index].sym);
    //printf ("index %d\n", index);

    return 0;
}

int HashFunction (int* elem, int m)
{
    return *elem % m;
}
