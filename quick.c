#include <stdio.h>

void display(int a[], int n)
{
    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);
    printf("\n");
}

int partition(int a[], int lb, int ub)
{
    int pivot = a[lb];
    int start = lb, end = ub, temp;

    while(start < end)
    {
        while(a[start] <= pivot && start < ub)
            start++;

        while(a[end] > pivot)
            end--;

        if(start < end)
        {
            temp = a[start];
            a[start] = a[end];
            a[end] = temp;
        }
    }

    temp = a[lb];
    a[lb] = a[end];
    a[end] = temp;

    return end;
}

void quicksort(int a[], int lb, int ub)
{
    if(lb < ub)
    {
        int loc = partition(a, lb, ub);

        quicksort(a, lb, loc - 1);
        quicksort(a, loc + 1, ub);
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

    quicksort(a, 0, n - 1);

    printf("Sorted Array:\n");

    for(int i = 0; i < n; i++)
        printf("%d ", a[i]);

    return 0;
}