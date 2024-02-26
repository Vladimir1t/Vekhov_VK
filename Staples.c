#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef char elem_t;
const elem_t POISON = '\0';

struct Stack
{
    int  capacity;
    int  size;
    elem_t* data;
};

void StackCtor (struct Stack* stk, const size_t capacity);

void StackPush (struct Stack* stk, const elem_t value);

void StackPop  (struct Stack* stk, elem_t* element);

void StackDtor (struct Stack* stk);

int StackReallocIncrease (struct Stack* stk);

int StackReallocDecrease (struct Stack* stk);

int main()
{
    struct Stack stk = {0};
    StackCtor (&stk, 2);
    elem_t sym = POISON, sym2 = POISON;

    sym = getchar ();
    //printf ("%c\n", sym);
    while (sym != '\n' && sym != EOF)
    {
        if (sym == '(')
        {
            StackPush (&stk, sym);
        }
        else
        {
            StackPop (&stk, &sym2);
            if (sym2 != '(')
            {
                printf ("NO");
                return 0;
            }
        }
        sym = getchar ();
    }
    printf ("YES");
    StackDtor (&stk);
    return 0;
}
void StackPush (struct Stack* stk, const elem_t value)
{
    if (stk->size == stk->capacity)
        StackReallocIncrease (stk);

    stk->data[stk->size] = value;
    //printf ("StackPush(): element = %d\n", stP->data[stP->size]);

    stk->size++;
    //printf ("StackPush(): number has been pushed successfully\n");
}

void StackPop (struct Stack* stk, elem_t* element)
{
    if (stk->size == 0)
        *element = POISON;

    if (stk->size * 4 < stk->capacity)
        StackReallocDecrease (stk);

    *element = stk->data[stk->size - 1];
    stk->data[stk->size - 1] = POISON;
    //printf ("StackPop(): popped number = %d\n", *element);
    stk->size--;
}

void StackDtor (struct Stack* stk)
{
    for (size_t i = 0; i < stk->size; i++)
        stk->data[i] = POISON;

    stk->capacity = 0;
    stk->size = 0;

    free (stk->data);

    stk->data = NULL;

    //printf ("Stack has been destructed\n");
}

int StackReallocIncrease (struct Stack* stk)
{
    elem_t* pointer = stk->data;
    stk->data = (elem_t*) realloc (stk->data, (stk->capacity / 2) * sizeof(elem_t));

    if (stk->data == NULL)
    {
        stk->data = pointer;
        // printf ("Realloc increase error\n");
        return 0;
    }
    for (int i = stk->capacity; i < stk->capacity * 2; i++)
        stk->data[i] = POISON;

    stk->capacity *= 2;
    return 0;
}

int StackReallocDecrease (struct Stack* stk)
{
    elem_t* pointer = stk->data;
    stk->data = (elem_t*) realloc (stk->data, (stk->capacity / 2) * sizeof(elem_t));
    if (stk->data == NULL)
    {
        stk->data = pointer;
        // printf ("Realloc decrease error\n");
        return 0;
    }
    stk->capacity /= 2;

    return 0;
}
void StackCtor (struct Stack* stk, const size_t capacity)
{
    stk->size = 0;
    stk->capacity = capacity;
    stk->data = (elem_t*) calloc (stk->capacity, sizeof(elem_t));

    for (int i = 0; i < capacity; i++)
        stk->data[i] = POISON;
    //printf ("Stack is constructed\n");
}



