#include <stdio.h>
int sum(int x,int y);
int prd(int x, int y);
int run();
int k, m;

int main(){
    loop: printf("���� ��� ��������� �������� (�������� ��� �����������):");
    scanf("%i %i", &k, &m);
    while(!run()){
    printf("��������: %i\n", sum(k, m));
    printf("��������: %i\n", prd(k, m));
    goto loop;
    }
    return 1;
}
int sum(int x,int y){
    return x+y;
}

int prd(int x, int y){
    return x*y;
}

int run(){
    if (k==0 && m==0)
        return 1;
    return 0;
}


