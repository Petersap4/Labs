#include <stdio.h>
#include<math.h>
int main(void){
    int ch;
    printf("1-Τύπωσε τη λέξη \"Καλημέρα\". \n");
    printf("2-Τύπωσε την τετραγωνική ρίζα του 2.\n");
    printf("3-Μην κάνεις τίποτα.\n");
    printf("Επίλεξε:\n");
    scanf("%i", &ch);
    if (ch == 1){
        printf("Καλημέρα");
    }
    else if (ch == 2){
        printf("%f", sqrt(2));
    }
    else if (ch == 3){

    }
    else{
        printf("Προσοχη! Εσφαλμένη επιλογή.");
    }
}
