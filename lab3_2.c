#include<stdio.h>
int main(void){
int num;
int c;
int sum;
printf("Δώσε έναν αριθμό μεταξύ 1 και 100:");
scanf("%i", &num);
if (num < 50 && num >=1){
    for (c = 1;c <= num; c +=2){
        printf("%i ", c);
        sum = sum + c;
        }
    printf("\nΑποτέλεσμα: %i", sum);
}
else if (num<=100 && num >=50){
    for (c=100; c>=num; c-=3){
        printf("%i ", c);
        sum = sum +c;
    }
    printf("\nΑποτέλεσμα: %i", sum);
}
else
    printf("Σφάλμα!");
}
