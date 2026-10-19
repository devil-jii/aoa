#include <stdio.h>
#define MAX 20

int set[MAX];
int selected[MAX];
int n, target;

void waitForEnter()
{
    printf("\nPress ENTER to continue...");
    getchar();
}

void printSubset(int length)
{
    int i;
    printf("Subset = { ");
    for (i = 0; i < length; i++)
        printf("%d ", selected[i]);
    printf("}\n");
}

void sumOfSubset(int index, int currentSum, int length)
{
    if (currentSum == target)
    {
        printf("\nTarget sum %d reached!\n", target);
        printSubset(length);
        return;
    }

    if (index == n || currentSum > target)
        return;

    waitForEnter();
    printf("\nConsidering element %d", set[index]);

    if (currentSum + set[index] <= target)
    {
        printf("\nInclude %d", set[index]);
        selected[length] = set[index];
        printf("\nCurrent Sum = %d", currentSum + set[index]);

        sumOfSubset(index + 1, currentSum + set[index], length + 1);

        printf("\nBacktracking: Exclude %d", set[index]);
    }
    else
    {
        printf("\nCannot include %d because sum exceeds target.", set[index]);
    }

    sumOfSubset(index + 1, currentSum, length);
}

int main()
{
    int i;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter the elements:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &set[i]);

    printf("Enter target sum: ");
    scanf("%d", &target);
    getchar();

    printf("\nSUM OF SUBSET PROBLEM");
    printf("\nTarget = %d\n", target);

    sumOfSubset(0, 0, 0);

    return 0;
}