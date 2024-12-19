#include<stdio.h>
#include<stdlib.h>


void populate_arr(int nor, int noc, long long int *arr)
{
    for(int i=0; i<nor; i++)
    {
        for(int j=0; j<noc; j++)
            arr[i*noc+j] = rand()%10;
    }
}

void print_arr(int nor, int noc, long long int *arr)
{
    for(int i =0; i<nor; i++)
    {
        if(i==0||i==nor-1)
        {
            for(int j =0; j<noc; j++)
                printf("%3lld", arr[i*noc+j]);
            putchar('\n');
        }
    }

}

void process()
{
    int nor, noc;
    printf("Δώσε τις δύο διαστάσεις της συστοιχίας:\n");
    scanf("%i %i", &nor, &noc);
    long long int *arr = calloc(nor*noc, sizeof(long long int ));
    double mb = (nor*noc*sizeof(int))/(1024.0*1024.0);
    if(arr == NULL)
        exit(0);
    populate_arr(nor, noc, arr);
    printf("Απαιτούμενη μνήμη: %.3f MB\n", mb);
    print_arr(nor, noc, arr);
    free(arr);

}

int main(void)
{
    process();
}
