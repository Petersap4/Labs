#include<stdio.h>
#include<stdlib.h>

void populate_arr(int nor, int noc, int arr[nor][noc])
{
    for(int i=0; i<nor; i++)
    {
        for(int j=0;j<noc; j++)
            arr[i][j] = rand()%10;
    }
}

void print_arr(int nor, int noc, int arr[nor][noc])
{
    for(int i=0; i<nor; i++)
    {
        for(int j=0;j<noc; j++)
            printf("%2i", arr[i][j]);
    }
}

void process()
{
    int nor, noc;
    printf("give dim\n");
    scanf("%i %i", &nor, &noc);
    int arr[nor][noc];
    double mb = (nor*noc*4)/(1024.0*1024.0);
    populate_arr(nor, noc, arr);
    printf("mem %.3f MB\n", mb);
    print_arr(nor, noc, arr);
}

int main(void)
{
    process();
}
