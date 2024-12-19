#include<stdio.h>
#include<stdlib.h>

void populate_arr(int nor, int noc, long long int **arr)
{
    for(int i=0; i<nor; i++)
    {
        for(int j=0;j<noc; j++)
            arr[i][j] = rand()%10;
    }
}

void print_arr(int nor, int noc, long long int **arr)
{
    for(int i = 0; i<nor; i++)
    {
            for(int j=0; j<noc; j++)
                printf("%3lld", arr[i][j]);
    }
    putchar('\n');
}

void process()
{
    int nor, noc;
    printf("Δώσε τις δύο διαστάσεις της συστοιχίας:\n");
    scanf("%i %i", &nor, &noc);
    long long int **arr;
    arr = calloc(nor, sizeof(long long int *));
    if(arr == NULL)
    {
        exit(0);
    }
    for(int k = 0; k<noc; k++)
    {
        arr[k] = calloc(noc, sizeof(long long int));
        if(arr[k]==NULL)
            exit(0);
    }
    populate_arr(nor, noc, arr);
    double mb = (nor*noc*sizeof(int))/(1024.0*1024.0);
    printf("Απαιτούμενη μνήμη: %.3f MB\n", mb);
    print_arr(nor, noc, arr);
    for(int i = 0; i<noc; i++)
        free(arr[i]);
    free(arr);
    exit(0);
}

int main(void)
{
    process();
}
