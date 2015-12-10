#include<vector>
#include<iostream>
using namespace std;

//���ֲ���ģ��
template<typename T1,typename T2>
int binarySearch(const T1 &arr,const T2 &value,size_t len)
{
    int low = 0, high = len-1, mid;
    while(low <= high) {
        mid = low + ((high-low)>>1); //˼��Ϊʲô��д��(high+low)/2;
        if(value-arr[mid]<1e-6 && arr[mid]-value<1e-6)//˼��Ϊ�β�д��arr[mid]!=value
            return mid;
        if(value<arr[mid])
            high = mid-1;	//���д��high = mid;������
        else
            low = mid+1;	//���д��low = mid;������
    }
    return -1;
}
int main()
{
    double arr[10] = {1,2,2,2,2,2,5,6,7,8};
    int i;
    //for(i=0; i<10; i++)
    //    arr[i] = i;
    for(i=-1; i<11; i++)
        cout<<"the index of '"<<i<<"': "<<binarySearch(arr,i,10)<<endl;

	cout<<endl;
	vector<int> arr_i(arr,arr+10);
    for(i=-1; i<11; i++)
        cout<<"the index of '"<<i<<"': "<<getPos(arr_i,i,arr_i.size())<<endl;
    return 0;
}
