#include <stdio.h>
#include <stdbool.h>
char next_char();
char previous_char();
bool reset = false;

int main(void){
    for (int i=0; i<60; i++)
        printf("%c", next_char());
    printf("\n");
    for (int i=0; i<60; i++)
        printf("%c", previous_char());


}

char next_char(){
    static char c='a'-1;
    if(c== 'z' )
        c='a';
    else
        c++;
    return c;
}

char previous_char(){
    static char c='z'+1;
    if(c=='a')
        c='z';
    else
        c--;
    return c;
}
