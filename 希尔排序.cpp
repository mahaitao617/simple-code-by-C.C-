#include<cstdlib>
#include<iostream>
using namespace std;

#define LEN(arr) (sizeof(arr)/sizeof(arr[0]))
//int a[5]= {3,2,5,4,1};
int a[9] = {25,84,21,47,15, 27,68,35,20};

//�������a��ÿһ��ֵ
void output(int arr[], int n)
{
    for(int i=0; i<n; i++)
        cout<<arr[i]<<"  ";
    cout<<endl;
}

//��������������ֵ���������ô��ݲ���
template <typename T>
void inline swapT(T& n1,T& n2)
{
    T temp = n1;
    n1 = n2;
    n2 = temp;
}
//c++��ʽ��ϣ�������������Խ��ܸ������͵�����
template <typename T>
void shellSort(T arr[],int arrSize)	//���������ϣ������
{
    for(int gap = arrSize/2; gap>0; gap/=2)
        for(int i=0; i<arrSize-gap; i++)
            for(int j=i; j>=0 && arr[j]>arr[j+gap]; j-=gap)
                swapT(arr[j],arr[j+gap]);
}
//��:c���԰��ϣ����������ֻ������int����
void shellSort_c(int arr[],int arrSize)	//���������ϣ������
{
    for(int gap = arrSize/2; gap>0; gap/=2) //������Ϊǰһ�ε�һ��
        for(int i=0; i<arrSize-gap; i++)
            for(int j=i; j>=0 && arr[j]>arr[j+gap]; j-=gap) { //��������˼��
                int temp = arr[j];
                arr[j] = arr[j+gap];
                arr[j+gap] = temp;
            }
}
//����������ض�����������Ϊstep����һ��ϣ������
void shellSort_OneStep_c(int arr[],int arrSize,int step)
{
    int gap = step;
    for(int i=0; i<arrSize-gap; i++)
        for(int j=i; j>=0 && arr[j]>arr[j+gap]; j-=gap) {
            int temp = arr[j];
            arr[j] = arr[j+gap];
            arr[j+gap] = temp;
        }
}

int main()
{
    shellSort(a,LEN(a));
    cout<<"ϣ���������������Ϊ��"<<endl;
    output(a,LEN(a));

    cout<<"\n�������������һ�˹̶�������ϣ�������"<<endl;
	int arr[] = {49,38,65,97,76, 13,27,49,55,04};
    output(arr,LEN(arr));
    shellSort_OneStep_c(arr,LEN(arr),5);
    output(arr,LEN(arr));
    return 0;
}
