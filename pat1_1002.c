/*
����һ����Ȼ��n���������λ����֮�ͣ��ú���ƴ��д���͵�ÿһλ���֡�

�����ʽ��ÿ�������������1��������������������Ȼ��n��ֵ�����ﱣ֤nС��10100��

�����ʽ����һ�������n�ĸ�λ����֮�͵�ÿһλ��ƴ�����ּ���1 �ո񣬵�һ�������һ��ƴ�����ֺ�û�пո�

����������
1234567890987654321123456789
���������
yi san wu
*/

//����ջ����ʵ�ֵ������ 

#include<stdio.h>
#include<string.h>
int main(){
	int stack[3];
	int front=-1;
	char pingyin[10][5]={"ling","yi","er","san","shi","wu","liu","qi","ba","jiu"};
	char num[101];
	int sum=0;	
  	int i,len;
  	scanf("%s",num);
  	i=len=0;
	len=strlen(num);
	int eachnum[len];
	for(i=0;i<len;++i){
		eachnum[i]=num[i]-'0';
		sum+=eachnum[i];
	}
	while(sum>10){
		stack[++front]=sum%10;
		sum=sum/10;
	}
	stack[++front]=sum;
	while(front!=0){
		printf("%s ",pingyin[stack[front--]]);
	}
	printf("%s",pingyin[stack[front]]);
	return 0;  
}
