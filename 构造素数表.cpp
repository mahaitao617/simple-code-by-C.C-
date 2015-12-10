#include<stdio.h>
#include<cmath>	//sqrt()
#include<ctime>	//clock()

int prime[670000];	//1000�����ڵ���������Ϊ66��+;
//����ϴ���Ҫ����Ϊȫ�֣��������ջ���

int getPrimeNum(int N=1000000)
{
    prime[0]=2;
    int m,c=1,i,j;//c��¼��ǰ��������
    for(i=3; i<=N; i+=2)//����ֻ�ж�����������ż��
    {
        m=(int)sqrt(i+0.1);//��0.1��Ϊ�˷�ֹ���ֱ�������sqrt()�����ĵ��ñ�������ȷ�Ĵ���
        for(j=0; prime[j]<=m; ++j)
            if(i%prime[j]==0)
                break;
        if(prime[j]>m)
            prime[c++]=i;
    }
    return c;
}
int main()
{
    int count,N[4]= {100000,1000000,5000000,10000000};
    for(int i=0; i<4; i++)
    {
        clock_t start = clock();//���濪ʼ����ʱ��ʱ��
        count = getPrimeNum(N[i]);	//�õ�N[i]���ڵ�������������������
        printf("%4d ����������������%6d, ������ʱ��%4d����\n",
               N[i]/10000, count, clock()-start);
    }
    return 0;
}
