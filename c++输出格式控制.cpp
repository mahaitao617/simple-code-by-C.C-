#include<iostream>
#include<iomanip>

using namespace std;

int main()
{
	cout<<setprecision(4)<<3.14159<<endl;
	cout<<setw(30)<<'a'<<endl;
	cout<<setw(30)<<setfill('%')<<3.14159<<endl; //�������õľ�������������Ч
	cout<<setfill(' ')<<3.14159<<"$"<<endl; //�������õĿ����������ʧЧ
	cout<<setw(30)<<setiosflags(ios::right)<<3.14159<<endl;//�����ʧЧ
	cout<<setw(30)<<3.14159<<endl; //�������õĶ����־��ʧЧ
	return 0;
}
/*	ͷ�ļ�Ϊ iomanip
setprecision(n)		����С������� n-1 λ
setw(m)				���������Ϊm (����С����)
*/
