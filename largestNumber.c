#include <stdio.h>

int max_num(int a[], int n);

int main()
{
    int max, i, n;
    int a[50];

    printf("Enter n number: ");
    scanf("%d", &n);

    printf("Enter the numbers:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    max = max_num(a, n);

    printf("The largest number is %d\n", max);

    return 0;
}

int max_num(int a[], int n)
{
    int i, m;

    m = a[0];   // গুরুত্বপূর্ণ পরিবর্তন

    for(i = 1; i < n; i++)
    {
        if(a[i] > m)
        {
            m = a[i];
        }
    }

    return m;
}
