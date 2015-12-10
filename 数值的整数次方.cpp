/** ��ĿҪ��
 ʵ�ֺ���double Power(double base, int exponent),��base��enponent�η���
 ����ʹ�ÿ⺯��,����Ҫ���Ǵ������⡣
**/
/** ����˼·��
 1.��ֱ�ӵķ�������ѭ���۳ˡ��������ַ���Ч�ʺܵͣ���˸�Ϊ�ݹ����
   ������������˵�ĵݹ�Ч�ʸ�������Ϊ����һ����ѧ��ʽ������ͨ�����
   ��ѭ���ĽⷨҪ�ȵݹ�Ч�ʸ�(����������쳲���������)��
 2.�����������:
	(1)ָ������Ϊ0����(Ϊ����ʱҪ����)
	(2)��������Ϊ0
	(3)������ָ������ͬʱΪ0(��ʱ�м�äĿ����-��ֹ��0����)
	(4)Ϊ�˽�һ�����Ч��,��>>�滻����2,��(n&1)�滻ȡ��
**/
#include<stdio.h>
//�ж������������Ƿ����
bool equal(double num1,double num2)
{
	if(num1-num2 < 1e-7 && num1-num2 > -1e-7)
		return 1;
	return 0;
}
bool gb_InvalidPara = 0;	//��ʶ�����Ƿ�����
//��ȡָ��Ϊ��Ȼ���ĳ˷�
double powerWithUnsignedE(double base,unsigned exponent)
{
	if(exponent==0)
		return 1.0;
	if(exponent==1)
		return base;
	double result = powerWithUnsignedE(base,exponent>>1);
	if((exponent & 1) == 0)	//����ż��,ע�ⲻҪ��������
		return result * result;
	return result * result * base;
}
//��һ������������������
double Power(double base,int exponent)
{
	gb_InvalidPara = 0;
	if(equal(base,0.0)) //����Ϊ0
	{
		if(exponent==0) //ָ��Ϊ0
			gb_InvalidPara = 1;
		return 0.0;
	}
	if(exponent>=0)
		return powerWithUnsignedE(base,exponent);
	return 1.0/powerWithUnsignedE(base,-exponent);
}

int main()
{
	double base;
	unsigned exp;
	puts("�����������ָ����");
	while(scanf("%lf%d",&base,&exp)==2)
		printf("%g ^ %d = %s%.15g\n",base,exp,gb_InvalidPara?"������Ч��0_":"",Power(base,exp));
	return 0;
}
