#include <stdio.h>

void mm(int a[], int l, int h, int *min, int *max)
{
    int mid;
    int min1, max1, min2, max2;

    if (l == h)
    {
        *min = a[l];
        *max = a[l];
    }
    else if (l == h - 1)
    {
        if (a[l] < a[h])
        {
            *min = a[l];
            *max = a[h];
        }
        else
        {
            *min = a[h];
            *max = a[l];
        }
    }
    else
    {
        mid = (l + h) / 2;

        mm(a, l, mid, &min1, &max1);
        mm(a, mid + 1, h, &min2, &max2);

        *min = (min1 < min2) ? min1 : min2;
        *max = (max1 > max2) ? max1 : max2;
    }
}

int main()
{
    int n, i, min, max;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];

    printf("Enter array elements:\n");

    for (i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mm(a, 0, n - 1, &min, &max);

    printf("\nMinimum Element = %d", min);
    printf("\nMaximum Element = %d", max);

    return 0;
}