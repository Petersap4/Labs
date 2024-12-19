#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void poparr(char arr[5][11])
{
    puts("Δώσε 5 αριθμούς:\n");
    for(int i = 0; i<5; i++)
    {
        printf("Δώσε τον αριθμό %i:\n", i+1);
        scanf("%10s", arr[i]);
        char c;
        while((c=getchar())!= '\n' && c!= EOF);
    }
}

void cnvarr(char arr1[5][11],float arr2[5])
{
    for(int i = 0; i<5; i++)
    {
        arr2[i]=atof(arr1[i]);
    }
}

void prnarr(char arr1[5][11],float arr2[5])
{
    for(int i = 0; i<5; i++)
    {
        printf("Στοιχείο %i: %10s %10.2llf\n", i+1, arr1[i], arr2[i]);
    }
}

void process()
{
    char arr1[5][11];
    float arr2[5];
    poparr(arr1);
    cnvarr(arr1, arr2);
    prnarr(arr1, arr2);
}

int main(void)
{
   process();
}
