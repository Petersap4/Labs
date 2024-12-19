#include<stdio.h>
#include<stdlib.h>
void poparr(int arr[10][10])
{
    for(int i = 0; i<10; i++)
    {
        for (int j=0; j<10; j++)
            arr[i][j] = rand()%10;
    }
}
void prnarr(int arr[10][10])
{
    for(int i = 0; i<10; i++)
    {
        for(int j = 0; j<10; j++)
            printf("%3i", arr[i][j]);
        putchar('\n');
    }
}
void calarr(int arr1[10][10], int arr2[10][10], int arr3[10][10])
{
    for(int i = 0; i<10; i++)
    {
        for(int j = 0; j<10; j++)
        {
            if(i+j<=9)
                arr3[i][j] = arr1[i][9-i-j] * arr2[i][i+j];
            else
                arr3[i][j] = 0;
        }
    }
}
void process(void)
{
    int arr1[10][10], arr2[10][10], arr3[10][10];
    poparr(arr1);
    poparr(arr2);
    calarr(arr1, arr2,arr3);
    puts("1\n");
    prnarr( arr1);
    puts("2\n");
    prnarr(arr2);
    puts("3\n");
    prnarr(arr3);
}
int main(void)
{
    process();
}
