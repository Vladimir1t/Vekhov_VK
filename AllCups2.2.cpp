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

    int l = 0, r = size - 1, mid = (l + r) / 2;
    while (array[mid] != element)
    {
        if (array[mid] < element)
        {
            l = mid + 1;
        }

        if (array[mid] > element)
        {
            r = mid - 1;
        }

        mid = (l + r) / 2;

        if (r < 0 || l > size)
            return 0;
    }
    printf ("true");

    return 0;
}
