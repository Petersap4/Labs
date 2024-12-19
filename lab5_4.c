#include<stdio.h>
#include<stdlib.h>
float arr[20];

void populate_array(int dig)
{
    int max =1;
    for (int i =0 ; i<dig; i++)
    {
        max*=10;
    }
    for(int i = 0; i<20; i++)
    {
        arr[i] = rand()%max;
        if (arr[i]<max/10)
           arr[i]+=max/10;
    }
}

void print_array()
{
    for(int i = 0; i<20; i++)
        printf("%i ", (int)arr[i]);
}

long long int accum_sum_array(int low, int up)
{
    long long int sum =0;
    for(int i = 0; i<up - low; i++)
        sum += arr[i+low];
    return sum;
}

int main(void)
{
    populate_array(2);
    print_array();
    printf("\n%lli",accum_sum_array(0,10));
}
