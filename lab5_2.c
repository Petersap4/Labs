#include<stdio.h>
int main(void)
{
    float arr[10], upl, lwl;
    puts("���� 10 �������, ��� 0 ��� 10.");
        for(int c = 0; c<10; c++)
        {
            again:
            printf("���� ��� ����� %i:\n", c+1);
            scanf("%f", &arr[c]);
            if(arr[c]>=0 && arr[c]<=10)
                continue;
            else{
                puts("��������� ��������!");
                goto again;
            }
        }
        while(1)
        {
            puts("���� �� ���� ��� �� ��� ���� ��� ����������� (0 ��� 0 ��� �����������):");
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
                printf("�� ������ ��� ������ ��� �������� [%.1f, %.1f] �����: %i\n", lwl, upl, ctr);
        }
}
