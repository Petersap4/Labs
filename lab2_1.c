#include<stdio.h>
#include<math.h>

int main(void){
float a, b, c;
printf("Give a,b,c\n");
scanf("%f", &a);
scanf("%f", &b);
scanf("%f", &c);
float d = pow(b, 2) - 4*a*c;
if (d>=0){
    printf("��� ��� ������� %.2fx^2 + %.2fx + %.2f = 0, �� sqrt(�) ����� %f", a,b,c,d);
}
else {
    printf("��� ��� ������� %.2fx^2 + %.2fx + %.2f= 0, �� � ����� ��������", a,b,c);
}
}
