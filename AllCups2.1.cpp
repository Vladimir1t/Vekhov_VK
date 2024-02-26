#include <stdio.h>
#include <stdlib.h>

struct Stack
{
    size_t capacity;
    size_t size;
    char*  data;
};

void StackCtor (struct Stack* stP, const int capacity);
void StackPush (struct Stack* stP, const int numberPush);
void StackPop  (struct Stack* stP);
void StackDtor (struct Stack* stP);

int main ()    //  gyuuyh - gh
{
    Stack St = {};
    StackCtor (&St, 1);

    char element = '\0';
    while (1)
    {
        element = getchar ();
        if (element == '\n' || element == EOF)
            break;
        else if (element == St.data[St.size - 1])
        {
            StackPop (&St);
            continue;
        }
        StackPush (&St, element);
    }

    for (int i = 0; i < St.size; i++)
        printf ("%c", St.data[i]);

    StackDtor (&St);

    return 0;
}

void StackCtor (struct Stack* stP, const int capacity)
{

    stP->capacity = capacity;
    stP->data = (char*) calloc (stP->capacity, sizeof(char));
}

void StackPush (struct Stack* stP, const int numberPush)
{
    if (stP->size == stP->capacity)
    {
        stP->data = (char*) realloc (stP->data, (stP->size * 2) * sizeof(char));
        stP->capacity *= 2;
    }

    stP->data[stP->size] = numberPush;

    stP->size++;
}

void StackPop (struct Stack* stP)
{
    if (stP->size == 0)
    {
        printf ("there are no numbers to be popped\n");
    }
    if (stP->size < stP->capacity)
    {
        stP->data = (char*) realloc (stP->data, (stP->capacity / 2) * sizeof (char));
    }
    stP->data[stP->size - 1] = 0;

    stP->size--;
}

void StackDtor (struct Stack* stP)
{
    stP->capacity = 0;

    for (size_t i = 0; i < stP->size; i++)
        stP->data[i] = '\0';

    stP->size = 0;

    free (stP->data);

    stP->data = NULL;
}

