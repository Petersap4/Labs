#include <stdio.h>
#include <math.h>
void display_number_to_symbol(int n);
void convert_number_to_symbol(void);
int num;
int main(void){
    convert_number_to_symbol();
}

void display_number_to_symbol(int n){
    printf("%i ", n);
    for(int i=1; i<=n; i++)
        putchar('#');
    printf("\n");
}

void convert_number_to_symbol(void){
    while(1){
    printf("Δώσε ένα μεγαλύτερο του μηδενός ακέραιο αριθμό (Μηδενικός για εγκατάλειψη):");
    scanf("%i", &num);
    if(num==0)
        break;
    while (num>0){
        int d = num % 10;
        display_number_to_symbol(d);
        num/=10;
    }
}
}
