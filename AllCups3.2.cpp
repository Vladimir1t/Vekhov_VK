#include <stdio.h>
#include <stdlib.h>

struct Pair
{
    char sym;
    size_t number;
};

struct HashTable
{
    struct Pair* data;
    size_t capacity;
    size_t size;
};

int HaschFunction (char elem, const int m);
int Insert (struct HashTable* ht, const char elem);
void Remove (struct HashTable* ht, const char elem, int* mod);

int main ()
{
    struct HashTable ht = {};
    ht.data = (Pair*) calloc (60, sizeof(Pair));
    ht.capacity = 60;

    char string1[40] = {};
    char string2[40] = {};
    int mod = 0;

    scanf ("%s %s", string1, string2);
    /*char symb = getchar ();
    int count1 = 0;
    while (symb != ',' && symb != EOF && symb != '\n')
    {
        if (symb != '"' && symb != ' ')
        {
            string1[count1] = symb;
            count1++;
        }
        symb = getchar ();
    }
    int count2 = 0;
    symb = getchar ();
    while (symb != ',' && symb != EOF && symb != '\n')
    {
        if (symb != '"' && symb != ' ')
        {
            string2[count2] = symb;
            count2++;
        }
       symb = getchar ();
    }
    //printf ("%s\n%s\n", string1, string2);

    int size1 = count1;
    int size2 = count2;      */

    int size1 = sizeof (string1);
    int size2 = sizeof (string2);
    if (size1 != size2)
    {
        //printf ("false");
        return 0;
    }

    for (int i = 0; i < size1; i++)
        Insert (&ht, string1[i]);

    for (int j = 0; j < size2; j++)
    {
        Remove (&ht, string2[j], &mod);
        if (mod == -1)
        {
            //printf ("false");
            return 0;
        }
    }

    printf ("true");
    free (ht.data);

    return 0;
}

int Insert (struct HashTable* ht, char elem)
{
    int index = HaschFunction (elem, ht->capacity);

    if (index > ht->capacity)
    {
        ht->data = (Pair*) realloc (ht->data, ht->capacity * 2 * sizeof(Pair));
        (ht->capacity) *= 2;
    }

    ht->data[index].number += 1;

    if (ht->data[index].sym == elem)
        return 0;

    ht->data[index].sym = elem;
    return 0;
}

void Remove (struct HashTable* ht, const char elem, int* mod)
{
    int index = HaschFunction (elem, ht->capacity);

    if (ht->data[index].number == 0)
        *mod = -1;
    ht->data[index].number -= 1;
}

int HaschFunction (char elem, const int m)
{
    int number = (int) elem;
    return number % m;
}
