#include <stdio.h>
#include<math.h>
int main(void){
    int ch;
    printf("1-������ �� ���� \"��������\". \n");
    printf("2-������ ��� ����������� ���� ��� 2.\n");
    printf("3-��� ������ ������.\n");
    printf("�������:\n");
    scanf("%i", &ch);
    if (ch == 1){
        printf("��������");
    }
    else if (ch == 2){
        printf("%f", sqrt(2));
    }
    else if (ch == 3){

    }
    else{
        printf("�������! ��������� �������.");
    }
}
