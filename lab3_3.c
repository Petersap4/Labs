#include<stdio.h>
int main (void){
    unsigned char euro = '\x80';
    int cub;
    int days;
    printf("Εισάγετε τον κυβισμό της μηχανής σε κ.εκ.:\n");
    scanf("%d", &cub);
    printf("Εισάγετε τη διάρκεια της ενοικίασης σε ημέρες:\n");
    scanf("%d", &days);
    float cost = 0;
    if (cub<=1600 && cub>=0){
        if (days<=2 && days>=0)
            cost = days*60;
        if (days>2 && days<=5)
            cost = 60*2 + (days-2)*55;
        if(days>5)
            cost = 60*2 + 55*3 + (days-5)*50;
        printf("Το κόστος ενοικίασης είναι %.2f\n",cost );
    }
    if (cub>1600){
        if (days<=2 && days>=0)
            cost = days*80;
        if (days>2 && days<=5)
            cost = 80*2 + (days-2)*70;
        if(days>5)
            cost = 80*2 + 70*3 + (days-5)*60;
        printf("Το κόστος ενοικίασης είναι %c%.2f\n",euro, cost );
    }



}
