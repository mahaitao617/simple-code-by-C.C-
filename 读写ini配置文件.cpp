#include<stdio.h>	//sprintf
#include<string.h>	//strcpy
#include<windows.h>	//GetPrivateProfileString..
#include<iostream>	//cout
using namespace std;
int main()
{
	char str[50];
	//Get..�ڵ�+����+��ȡʧ��ʱĬ��ֵ+[Ŀ���ַ���+����ַ���]+ini�ļ�λ��(�������\\)
	GetPrivateProfileString("SET_VAR","Name","default",str,50,".\\set.ini");
    cout<<str<<endl;
    int getID = GetPrivateProfileInt("SET_VAR","ID",0,".\\set.ini");
    cout<<getID<<endl;
    strcpy(str,"wenbo");
	//Write..�ڵ�+����+��д����ַ���+�����ļ�Ŀ¼(�������\\)
    WritePrivateProfileString("SET_VAR","Name",str,".\\set.ini");
    sprintf(str,"%d",21);
    WritePrivateProfileString("SET_VAR","Age",str,".\\set.ini");
    cin.get();
    //д��ע�ͣ����д�벻��ɾ����ǰ��
    sprintf(str,"#����\nage=%d%s",21,"");
    WritePrivateProfileString("SET_VAR2","age",str,".\\set.ini");
    memset(str,0,sizeof(str));	//�ҳ���Ҫ
    strcpy(str,"#ѧ��\nstuID=1210313209");
    WritePrivateProfileSection("SET_VAR2",str,".\\set.ini");

	//�������ļ���ȡ���������ò��������û������дĬ��ֵ
	int value1;
	int save=GetPrivateProfileInt("Setting","value1",-1,".\\set.ini");
	if(save<4 || save>50)
	{
		WritePrivateProfileString("Setting","value1","10",".\\set.ini");
		value1 = 10;
	}else
		value1 = save;
    /**
     * ���⻹��д����:
     * WritePrivateProfileStruct
     * WritePrivateProfileSection:�ú����ڶ����������������������ʹ�ã���������
     * WritePrivateProfileString()
     * �����ĵڶ�������Ϊ0ʱ��ɾ���ý�
	 * ����������Ϊ0ʱ��ɾ���ü�����ֵ
     */
}
