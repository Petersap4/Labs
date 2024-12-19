#include<stdio.h>

int main(void){
float f;
printf("fahr:");
scanf("%f", &f);
float k = 5 *(f + 459.67) / 9;
if (f >=-300 && f<=100){
    printf("T = %.1f F = %.1f K", f, k);
}
else {
    printf("Error");
}
}
