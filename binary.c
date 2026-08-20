#include <stdio.h>

int binarySearch(int a[], int n, int data)
{
    int l = 0;
    int r = n - 1;
    int mid;

    while (l <= r)
    {
        mid = (l + r) / 2;

        printf("\nCurrent Range: %d to %d", l, r);
        printf("\nMiddle Element = %d", a[mid]);

        if (a[mid] == data)
            return mid;

        else if (data < a[mid])
            r = mid - 1;

        else
            l = mid + 1;
    }

    return -1;
}

int main()
{
    int n, i, data, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter sorted elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter element to search: ");
    scanf("%d", &data);

    pos = binarySearch(a, n, data);

    if (pos != -1)
        printf("\n\nElement found at index %d", pos);
    else
        printf("\n\nElement not found");

    return 0;
}