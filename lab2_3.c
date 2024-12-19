#include<stdio.h>

int main(void){

printf("type:\n");
char a = getchar();
char b = getchar();
char c = getchar();
if ((((a>='A' && a<='Z') || (a>='a' && a<='z')))
    && (((b >= 'A' && b<='Z') || (b>='a' && b<= 'z')) || ((b>='0' && b<='9') || b!='-'))
    && (((c>='A' && c<= 'Z') || (c >= 'a' && c<='z')) || ((c >='0' && c<='9') || c!='-'))){
printf("%c%c%c", a, b, c);
}
else
    printf("error");


}
