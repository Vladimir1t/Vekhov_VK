#include <stdio.h>
#include <stdlib.h>

int main ()
{
    size_t size = 0;
    scanf ("%d", &size);

    int* array = (int*) calloc (size, 4);
    for (int i = 0; i < size; i++)
    {
        scanf ("%d", &array[i]);
    }
    int element = 0;
    scanf ("%d", &element);

    int l = 0;
    int r = size - 1;
    int mid = (l + r) / 2;
    while (array[(l + r) / 2] != element)
    {
        if (array[mid] < element)
        {
            l = (l + r) / 2;
        }

        if (array[mid] > element)
        {
            r = (l + r) / 2;
        }

        mid = (l + r) / 2;
        if (r - l == 1)
        {
            if (element < array[r])
                mid = r;
            if (element > array[r])
                mid = size;
            break;
        }
    }
    printf ("%d", mid);
    return 0;
}
