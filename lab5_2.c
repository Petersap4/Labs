#include<stdio.h>
int main(void)
{
    float arr[10], upl, lwl;
    puts("Δώσε 10 βαθμούς, από 0 έως 10.");
        for(int c = 0; c<10; c++)
        {
            again:
            printf("Δώσε τον βαθμό %i:\n", c+1);
            scanf("%f", &arr[c]);
            if(arr[c]>=0 && arr[c]<=10)
                continue;
            else{
                puts("Εσφαλμένη εισαγωγή!");
                goto again;
            }
        }
        while(1)
        {
            puts("Δώσε το κάτω και το άνω όριο του διαστήματος (0 και 0 για εγκατάλειψη):");
            scanf("%f %f", &lwl, &upl);
                int ctr = 0;
                if (lwl ==0 && upl==0)
                    break;
                for(int i=0; i<10; i++)
                {
                    if(arr[i]>=lwl && arr[i] <=upl)
                        ctr+=1;
                    else{};
                }
                printf("Το πλήθος των βαθμών στο διάστημα [%.1f, %.1f] είναι: %i\n", lwl, upl, ctr);
        }
}
