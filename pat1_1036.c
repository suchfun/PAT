/*
������ͳ�°����������������˶�ѧϰ��̣��������������д���룬��Ϊ������ʷ����λ��д������������ͳ��2014��ף�Ϊ��ף���������ѧ�����ܡ���ʽ�������°�����д�˺ܼ򵥵ļ�������룺����Ļ�ϻ�һ�������Ρ�������Ҳ����һ�𻭰ɣ�

�����ʽ��

������һ���и��������α߳�N��3<=N<=20������������αߵ�ĳ���ַ�C�����һ���ո�

�����ʽ��

����ɸ����ַ�C�����������Ρ�����ע�⵽�м����м�������Ϊ���ý������ȥ���������Σ��������������ʵ������������50%����������ȡ������

����������
10 a
���������
aaaaaaaaaa
a        a
a        a
a        a
aaaaaaaaaa
*/
#include<stdio.h>

int main(){
	int n;
	char c;
	scanf("%d %c",&n,&c);
	//scanf("%c",&c);
	int half;
	if(n%2==0)	half=n/2;
	else	half=n/2+1;
	
	char s1[21],s2[21];
	s1[0]=s2[0]=c;s1[n-1]=s2[n-1]=c;
	int i,j;
	for(i=1;i<n-1;++i){
		s2[i]=' ';
		s1[i]=c;
	}
	
	s1[n]=s2[n]=' ';//ע��һ��Ҫ������䣬���������ʱ��������������ĳ�ֵ���ǡ�\0��,��һֱ��Ϊ�ַ���δ������ 
	
	printf("%s\n",s1);
	for(i=0;i<half-2;++i){
		printf("%s\n",s2);
	}
	printf("%s",s1);
	return 0;
}


