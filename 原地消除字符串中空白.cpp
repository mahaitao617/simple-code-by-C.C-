/**��Ŀ��ʵ��ԭ�������ַ����Ŀհף�����"aa   c    d e " => "aacde"��
   ��չ��ԭ�������ַ������ظ��հף�����"aa  c  d e " => "aa c d e"��
 **/

#include<stdio.h>

//ɾ���ַ�����str�е�����ĳ���ض��ַ�del
char * delChar(char* str, char del = ' ')
{
	//��ֹ������Ч����-��ָ��
	if(str==0 || *str==0 || del==0)
		return str;
	char *pLeft=str, *pRight=str;
	while(*pRight!=0 && *pRight!=del)
		++pRight;
	pLeft = pRight;//��һ��Ҫɾ��λ��
	while(*pRight==del) //����Ҫɾ����Ԫ��
		++pRight;
	//��ǰpRightָ���һ��Ҫ��ǰ�ƶ���Ԫ��
	for(;*pRight!=0;++pRight) {
		//*pRight����Ҫɾ������ǰ����Ԫ��
		if(*pRight!=del) {
			*pLeft = *pRight;
			++pLeft;
		}
	}
	//���һλ��0������β����������һ�εĲ����ַ�
	*pLeft = 0;
	return str;
}
//ɾ���ַ�����str�е�����ĳ���ض��ַ�del
char * delChar2(char* str, char del = ' ')
{
	//��ֹ������Ч����-��ָ��
	if(str==0 || *str==0 || del==0)
		return str;
	char *pLeft=str, *pRight=str;
	//һֱ�������ַ���β��
	for(;*pRight!=0;++pRight) {
		//*pRight�����һ������Ҫɾ����Ԫ��
		if(*pRight!=del) {
			//��ָ��ͬһԪ��
			if(pLeft!=pRight)
				*pLeft = *pRight;
			++pLeft;
		}
	}
	//���һλ��0������β����������һ�εĲ����ַ�
	*pLeft = 0;
	return str;
}
//ɾ���ַ�����str�е����������ظ���ĳ���ض��ַ�del
char * delRepeatedChar(char* str, char del = ' ')
{
	//��ֹ������Ч����-��ָ��
	if(str==0 || *str==0 || del==0)
		return str;
	char *pLeft=str, *pRight=str;
	while(*pRight!=0 && *pRight!=del)
		++pRight;
	pLeft = pRight;//��һ�� ��ָԪ����Ҫɾ�����ַ�
	for(; *pRight!=0; ++pLeft, ++pRight) {
		//pRight��ָԪ����Ҫɾ�����ַ�
		if(*pRight==del) {
			//��һ��Ԫ��Ҳ��Ҫɾ�����ַ�����ɾ����һ���ַ�
			if(*(pRight+1)==del){
				*pLeft++ = *pRight;
				//�ƶ�����ǰ��Ҫ��ǰ���Ƶ�λ��
				while(*pRight==del)
					++pRight;
				//����Ԫ��
				*pLeft = *pRight;
				continue;
			}
		}
		//����Ԫ��
		*pLeft = *pRight;
	}
	//���һλ��0������β����������һ�εĲ����ַ�
	*pLeft = 0;
	return str;
}

int main()
{
	char str[128] = "   a c b  cccd f  ghh jk lmnnn qr     st ";
	char del = 'c';
	printf("������һ��Դ�ַ���:");
	while(gets(str)) {	//һ��Ҫ��gets������scanf,��Ϊ���ܰ����ո�
		printf("������һ��Ҫɾ�����ַ�:");
		del = getchar();
		printf("<%s> ɾ���������ַ�'%c'��:\n",str,del);
		printf("<%s>\n\n������һ��Դ�ַ���:",delRepeatedChar(str,del));
		getchar();
	}
	return 0;
}
