#include <stdio.h>
#include<stdbool.h>
int isbouncy();
int err;
int num;
int main(void){
        isbouncy();
    return 0;
}

int isbouncy(){
        while(1){
            int d1, d;
            scanf("%i", &num);
            if (num<100){
                break;
            }
            d1 = num%10;
            num/=10;
            while (num>0){
                d = num%10;
                num/=10;

                if(d1>d && d1<d)
                    err = 1;
                else
                    err = 0;
                d1=d;
            }


            printf("%i\n", err);
        }

   return 0;
}


