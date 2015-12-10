#include<stdio.h>
#include<string.h>
char* formatString(char *sourceString) {
    //��ֹ������Ч����-��ָ��
    if(sourceString==0 || *sourceString==0)
        return sourceString;
    char *pLeft=sourceString, *pRight=sourceString, del = ' ';
    while(*pLeft!=0 && *pLeft==del) //�ҵ���һ����Ϊ�ո��λ��
        ++pLeft;
    if(*pLeft==0) //�����ַ������ǿո�
        return "";
    int len = strlen(sourceString);
    pRight = sourceString + len - 1;
    while(*pRight==del) //�ҵ����һ���ǿո��λ��
        --pRight;
    for(int i=0;i<pRight-pLeft+1;++i) //����β�ո�ȥ������м���ַ��ƶ����ַ�����ͷλ��
        sourceString[i] = sourceString[i+pLeft-sourceString];
    sourceString[pRight-pLeft+1] = '\0';
    //����ɾ�������Ŀո�
    pRight=sourceString;
    while(*pRight!=0 && *pRight!=del)
        ++pRight;
    pLeft = pRight;//��һ����ָԪ����Ҫɾ�����ַ�
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
    return sourceString;
}
char * delRepeatedChar(char* str, char del);
int main()
{
    char str[128] = "   a c b  cccd f  ghh jk lmnnn qr     st ";
    char del = 'c';
    printf("������һ��Դ�ַ���:");
    while(gets(str)) {    //һ��Ҫ��gets������scanf,��Ϊ���ܰ����ո�
        printf("������һ��Ҫɾ�����ַ�:");
        printf("<%s>\n",formatString(str));
        //del = getchar();
        //printf("<%s> ɾ���������ַ�'%c'��:\n",str,del);
        //printf("<%s>\n\n������һ��Դ�ַ���:",delRepeatedChar(str,del));
        getchar();
    }
    return 0;
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
