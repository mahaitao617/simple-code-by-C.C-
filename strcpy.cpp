/**
 ��֪strcpy������ԭ���ǣ�
 char *strcpy(char *dst, const char *src);

 ʵ��strcpy����
 ����ΪʲôҪ����char *
 ���翼��dst��src�ڴ��ص��������strcpy����ôʵ��
 **/
#include<stdio.h>
#include<assert.h>

char * Strcpy(char *dst,const char *src)   //[1]
{
    assert(dst != NULL && src != NULL);    //[2]
    char *ret = dst;  //[3]
    while ((*dst++=*src++)!='\0'); //[4]
    return ret;
}
int main()
{
    char s1[128],s2[128];
    gets(s1);
    Strcpy(s2,s1);
    puts(s2);
    return 0;
}
/**
[1]const����
Դ�ַ���������const���Σ���ֹ�޸�Դ�ַ�����

[2]��ָ����
(A)�����ָ�����Ч�ԣ���ʹ���벻���н�׳�ԡ�
(B)���ָ�����Ч��ʱ��ʹ��assert(!dst && !src);
char *ת��Ϊbool����������ʽת�������ֹ�����Ȼ����������ǵ��³�����������ά���ɱ����ߡ�
(C)���ָ�����Ч��ʱʹ��assert(dst != 0 && src != 0);
ֱ��ʹ�ó������籾���е�0������ٳ���Ŀ�ά���ԡ���ʹ��NULL����0���������ƴд���󣬱������ͻ��������

[3]����Ŀ���ַ
(A)���뱣��ԭʼ��dstֵ��

[4]'\0'
(A)ѭ����д��while (*dst++=*src++);����ʽ����ת��������ȫ��ά���ɱ��ߡ�
(B)ѭ����д��while (*src!='\0') *dst++=*src++;
ѭ���������dst�ַ�����ĩβû����ȷ�ؼ���'\0'��

2.ΪʲôҪ����char *��
����dst��ԭʼֵʹ�����ܹ�֧����ʽ���ʽ��
��ʽ���ʽ����ʽ�磺
int len=strlen(strcpy(strA,strB));
���磺
char * strA=strcpy(new char[10],strB);

3.���翼��dst��src�ڴ��ص��������strcpy����ôʵ��
char s[10]="hello";
strcpy(s, s+1); //Ӧ����ello��
//strcpy(s+1, s); //Ӧ����hhello����ʵ�ʻᱨ����Ϊdst��src�ص��ˣ���'\0'������
��ν�ص�������srcδ����Ĳ����Ѿ���dst�������ˣ�ֻ��һ�������src<=dst<=src+strlen(src)
C����memcpy�Դ��ڴ��ص���⹦�ܣ��������memcpy��ʵ��my_memcpy��

char *my_memcpy(char *dst, const char* src, int cnt)
{
    assert(dst != NULL && src != NULL);
    char *ret = dst;
    if (dst >= src && dst <= src+cnt-1) { //�ڴ��ص����Ӹߵ�ַ��ʼ����
        dst = dst+cnt-1;
        src = src+cnt-1;
        while (cnt--)
            *dst-- = *src--;
    } else { //����������ӵ͵�ַ��ʼ����
        while (cnt--)
            *dst++ = *src++;
    }
    return ret;
}

char * strcpy(char *dst,const char *src)
{
    assert(dst != NULL && src != NULL);
    char *ret = dst;
    my_memcpy(dst, src, strlen(src)+1);
    return ret;
}

*/
