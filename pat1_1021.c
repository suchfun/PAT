/*
����һ��kλ����N = dk-1*10k-1 + ... + d1*101 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)�����д����ͳ��ÿ�ֲ�ͬ�ĸ�λ���ֳ��ֵĴ��������磺����N = 100311������2��0��3��1����1��3��

�����ʽ��

ÿ���������1��������������һ��������1000λ��������N��

�����ʽ��

��N��ÿһ�ֲ�ͬ�ĸ�λ���֣���D:M�ĸ�ʽ��һ���������λ����D������N�г��ֵĴ���M��Ҫ��D�����������

����������
100311
���������
0:2
1:3
3:1
*/ 
#include<stdio.h>
#include<string.h>
int main(){
	int nine[10];
	int i;
	for(i=0;i<10;i++){
		nine[i]=0;
	}
	char s[1000];//Ϊʲô����дchar *s�Ͳ����أ� 
	gets(s);
	int len;
	len=strlen(s);
	for(i=0;i<len;i++){
		if(s[i]=='0')	nine[0]++;
		else if(s[i]=='1')	nine[1]++;
		else if(s[i]=='2')	nine[2]++;
		else if(s[i]=='3')	nine[3]++;
		else if(s[i]=='4')	nine[4]++;
		else if(s[i]=='5')	nine[5]++;
		else if(s[i]=='6')	nine[6]++;
		else if(s[i]=='7')	nine[7]++;
		else if(s[i]=='8')	nine[8]++;
		else if(s[i]=='9')	nine[9]++;
	}
	for(i=0;i<10;i++){
		if(nine[i]!=0){
			printf("%d:%d\n",i,nine[i]);
		}
	}
	return 0;
}
