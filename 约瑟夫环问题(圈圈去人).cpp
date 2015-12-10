/** ����˳���Ĵ洢�ṹ�Լ����������ʵ�֡�
 * Լɪ�����⣺����Ϊ1��2��3��������n��n(n>0)���˰�˳ʱ�뷽��Χ��һȦ��mΪ����һ����������
 * �ӵ�һ���˿�ʼ˳ʱ�뷽����1��˳����������mʱֹͣ���ұ�m���˳��У��ٴ�������һ���˿�ʼ���´�1������
 * ����mʱֹͣ���ұ�m���˳��С������ȥ��ֱ��������ȫ������Ϊֹ��Ҫ�����һ������ģ��˹��̣�
 * �����������m��n��������б�����С�
 */

#include<stdio.h>
#include<malloc.h>
#define MaxSize 50
typedef int ElemType;
typedef struct {
    ElemType data[MaxSize];
	int length;
}SqList;
void InitList(SqList *&L){      //��ʼ��˳���
	L=(SqList *)malloc(sizeof(SqList));
	L->length=0;
}
void CreateList(SqList *&L,int n){      //����˳���
	for(int i=0;i<n;i++)
		L->data[i]=i+1;
	L->length=n;
}
void DispList(SqList *L){            //���˳���������ⴴ����˳����Ƿ����Ҫ��
	int i;
	for(i=0;i<L->length;i++)
		printf("%d  ",L->data[i]);
	printf("\n");
}
bool GetElem(SqList *L,int i,ElemType &e){     //��˳����е�i��Ԫ��ֵ
	if(i<0||i>L->length-1)
		return false;
	e=L->data[i];
	return true;
}
bool ListDelete(SqList *&L,int i,ElemType &e){     //ɾ����i��Ԫ��
	int j;
	if(i<0||i>L->length-1)
		return false;
	e=L->data[i];
	for(j=i;j<L->length-1;j++)
		L->data[j]=L->data[j+1];
	L->length--;
	return true;
}

int main(){
	int m,n,i,j,t=0;
	SqList *L;
	ElemType e;
	printf("����n��ֵ: ");
	scanf("%d",&n);
	printf("��ʼ��˳���...\n");
	InitList(L);
	printf("����һ����Ԫ�ص�˳���...\n");
	CreateList(L,n);
	printf("\n���˳���:\n");
	DispList(L);
	printf("\n����m��ֵ: ");
	scanf("%d",&m);
	puts("����������Ϊ��");
	for(i=n;i>=1;i--){
		t=(t+m-1)%i;
		GetElem(L,t,e);
		printf("%d  ",e);
        ListDelete(L,t,e);
	}
	printf("\n");
	return 0;
}
