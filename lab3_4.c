#include <stdio.h>
int main(void){
int h;
printf("Δώσε το ύψος του δέντρου σε γραμμές:\n");
scanf("%i", &h);

if (h>=4 && h<=20){
    for(int c=1; c<=h-1; c+=1){
        for (int sp = 2*(h-4); sp>=c-1;sp-=1)
            putchar(' ');
        for (int st = 1; st<=2*(c-1)+1; st+=1)
            putchar('*');

    printf("\n");
    if (c+1==h){
        for (int a=2*(h-4); a>=0;a-=1)
            putchar(' ');
        putchar('*');
        }
    }
}
else{
    printf("Το ύψος είναι εκτός ορίων (από 4 έως 20).");
    }
}
