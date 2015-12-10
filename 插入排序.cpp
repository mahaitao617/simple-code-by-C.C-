void insertSort1(int a[], int n)
{
    int i, j, k;
    for (i = 1; i < n; i++) {
        //Ϊa[i]��ǰ���a[0...i-1]������������һ�����ʵ�λ��
        for (j = i - 1; j >= 0; j--)
            if (a[j] < a[i])
                break;
        if (j != i - 1) {		//���ҵ���һ�����ʵ�λ��
            int temp = a[i];	//����a[i]������������
            for (k = i - 1; k > j; k--)
                a[k + 1] = a[k];
            a[k + 1] = temp;	//��a[i]�ŵ���ȷλ����
        }
    }
}

void insertSort2(int a[], int n)
{
    int i, j;
    for (i = 1; i < n; i++)
        if (a[i] < a[i - 1]) {
            int temp = a[i];
            for (j = i - 1; j >= 0 && a[j] > temp; j--)
                a[j + 1] = a[j];
            a[j + 1] = temp;
        }
}

void insertSort3(int a[], int n)
{
    for (int i = 1; i < n; i++)
        for (int j = i - 1; j >= 0 && a[j] > a[j + 1]; j--)
            Swap(a[j], a[j + 1]);
}
