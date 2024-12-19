#include <stdio.h>
#include<math.h>
float func_1(float x)
{
    if (x>0)
        return 2*x+3;
    else
        return 3*pow(x, 2) + 3;
}

float func_2(float y)
{
    if (y>=3)
        return 5*y +1;
    else
        return 2*pow(y, 3) -38;
}

void process(float z,float *p1,float *p2)
{
    *p1 = func_1(z)+func_2(z);
    *p2 = func_1(z)*func_2(z);
}

int main(void){
        float n, p1, p2;
        scanf("%f", &n);
        process(n, &p1, &p2);
        printf("’θροισμα func_1(%.2f) και func_2(%.2f): %.2f\nΓινόμενο func_1(%.2f) και func_2(%.2f): %.2f", n, n,p1, n, n, p2);


}
