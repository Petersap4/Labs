
#include <stdio.h>

int main(void) {
    float r;
    const float pi = 3.14;
    printf("���� ������:\n");
    scanf("%f", &r);
    float a = pi *r*r;
    float l = 2* pi* r;
    printf("���������� ������: %.2f\n������� ������: %.2f\n", l, a);
    }
