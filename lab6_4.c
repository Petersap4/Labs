#include<stdio.h>
#include<string.h>
void srtarr(char arr[5][11])
{
    for(int i = 0; i<5; i++)
    {
        scanf("%10s", arr[i]);
        char ch;
        while((ch = getchar()) !='\n' && ch!= EOF);
    }
    putchar('\n');
    for(int i = 0; i<5; i++)
    {
        for(int j = 0; j<5; j++)
        {
            char min[11];
            if ((strcmp(arr[i], arr[j]))== -1)
            {
                strcpy(min, arr[i]);
                strcpy(arr[i], arr[j]);
                strcpy(arr[j], min);
            }
        }
    }
}
int main(void)
{
    char lines[5][11];
    srtarr(lines);
    for (int i=0; i<5; i++)
        puts(lines[i]);
}
