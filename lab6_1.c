#include <stdio.h>
#include<string.h>
int process(void)
{
    char wrd[10][11];
    puts("���� 10 ������:");
    for(int i = 0; i<10; i++)
    {
        printf("���� %i:\n", i+1);
        scanf("%10s", wrd[i]);
        char c;
        while((c=getchar()) != '\n' && c != EOF);
    }
    for(int i = 0; i<10 ; i++)
        if(i != 9)
            printf("%s,", wrd[i]);
        else
            printf("%s", wrd[i]);


    return 0;
}
int main(void)
{
    process();
}
