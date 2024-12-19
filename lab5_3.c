#include<stdio.h>
void *scramble(char *wrd)
{
    char *start = wrd;
    while(*wrd!= '\0')
        wrd++;
    wrd--;
    while(wrd>=start)
    {
        putchar(*wrd);
        putchar(*start);
        wrd--;
        start++;
    }
return 0;
}

int main(void){
    scramble("1234567890");
}
