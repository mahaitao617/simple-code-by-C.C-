/**
 Ҫ�󣺲�ʹ���ַ�������⺯��ʵ��strlen��strcpy��strcat��strcmp�Ĺ���
 **/
#include<stdio.h>
//���ַ����ĳ���
unsigned strlen(const char* src)
{
    if(src==0 || *src=='\0')
        return 0;
    char *ptr = (char*)src;
    while(*ptr != '\0')
        ++ptr;
    return ptr - src;
}

//strcpy�������ļ�

//���������ַ���
char* strcat ( char * dst , const char * src )
{
    if(dst==0 || src==0)
        return dst;
    char *pszOrigDst = dst;
    while( *dst !='\0')
        dst++;
    while( (*dst++ = *src++)!='\0' )
        ;
    return pszOrigDst;
}
/*���dest > source,�򷵻�ֵ����0��
  ���dest = source,�򷵻�ֵ����0��
  ���dest < source,�򷵻�ֵС��0��*/
int strcmp(const char *dst, const char *src)
{
    if(NULL==dst || NULL==src)
        return 0;
    while (*dst && *src && (*dst == *src)) {
        ++dst;
        ++src;
    }
    return *dst - *src;
}
//���ַ���src���ҵ���һ��c��λ�ò�����
const char* strchr(const char* src,char c)
{
    if(src==0 || c=='\0')
        return 0;
    while(*src!='\0') {
        if(*src==c)
            return src;
        ++src;
    }
    return 0; //û���ҵ����ַ�
}

int main()
{
    char aa[128] = "123", bb[11] = "456";
    char *pStr = strcat(aa,bb);
    puts(pStr);
    printf("strlen(aa)=%d,strcmp(aa,bb)=%d\n%s\n",strlen(aa),strcmp(aa,bb),strchr(aa,'5'));
    return 0;
}
