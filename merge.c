#include <stdio.h>

void merge(int a[], int lb, int mid, int ub)
{
    int i = lb, j = mid + 1, k = lb;
    int b[50];

    while(i <= mid && j <= ub)
    {
        if(a[i] <= a[j])
            b[k++] = a[i++];
        else
            b[k++] = a[j++];
    }

    while(i <= mid)
        b[k++] = a[i++];

    while(j <= ub)
        b[k++] = a[j++];

    for(k = lb; k <= ub; k++)
        a[k] = b[k];
}

void mergeSort(int a[], int lb, int ub)
{
    if(lb < ub)
    {
        int mid = (lb + ub) / 2;

        mergeSort(a, lb, mid);
        mergeSort(a, mid + 1, ub);
        merge(a, lb, mid, ub);
    }
}

int main()
{
    int n, a[50];

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter elements:\n");

    for(int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    mergeSort(a, 0, n - 1);

    printf("Sorted Array:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}