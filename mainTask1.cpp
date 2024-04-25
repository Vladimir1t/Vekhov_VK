#include <stdio.h>
#include <stdlib.h>

struct sNode
{
    struct sNode* next;  // pointer on next node
    int data;            // data of a node
};

struct allNode
{
    struct sNode* begin;
    struct sNode* tail;
    size_t size;
};

int RemoveNode (const int element, allNode allN);

int main ()
{
    sNode sixth  = {.next = NULL,    .data = 60};
    sNode fifth  = {.next = &sixth,  .data = 50};
    sNode fouth  = {.next = &fifth,  .data = 40};
    sNode third  = {.next = &fouth,  .data = 30};
    sNode second = {.next = &third,  .data = 20};
    sNode first  = {.next = &second, .data = 10};

    allNode allN = {.begin = &first, .tail = &sixth, .size = 6};

    int element = 0;
    printf ("write data of Node, which you want remove\n");
    scanf ("%d", &element);

    sNode* pointer = &first;
    while (pointer != NULL)
    {
        printf ("%d\t", pointer->data);
        pointer = pointer->next;
    }
    putchar ('\n');

    if (RemoveNode (element, allN) != 1)
        printf ("Error\n");

    pointer = &first;
    while (pointer != NULL)
    {
        printf ("%d\t", pointer->data);
        pointer = pointer->next;
    }
    return 0;
}

int RemoveNode (const int element, allNode allN)
{
    sNode* pointer = allN.begin;
    sNode* prevPointer = allN.begin;
    int count = 1;

    while (pointer != NULL)
    {
        if (pointer->data == element)
        {
            prevPointer->next = pointer->next;
            printf ("< number of removed Node: %d  address: %d >\n",count, pointer);
            pointer->next = NULL;
            pointer->data = 0;
            return 1;
        }
        prevPointer = pointer;
        pointer = pointer->next;
        count++;
    }
    return 1;
}





