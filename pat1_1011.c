/*
��������[-231, 231]�ڵ�3������A��B��C�����ж�A+B�Ƿ����C��

�����ʽ��

�����1�и���������T(<=10)���ǲ��������ĸ�����������T�����������ÿ��ռһ�У�˳�����A��B��C���������Կո�ָ���

�����ʽ��

��ÿ�������������һ���������Case #X: true�����A+B>C�����������Case #X: false��������X�ǲ��������ı�ţ���1��ʼ����

����������
4
1 2 3
2 3 4
2147483647 0 2147483646
0 -2147483648 -2147483647
���������
Case #1: false
Case #2: true
Case #3: true
Case #4: false
*/

//A+B>C  ע�⣺1.Ҫ��long 2.��Ӧ�ĸ�ʽ��%ld 

#include<stdio.h>
char * compare(long i,long j,long k){
	if(i+j>k)	return "true";
	else	return "false";
} 
int main(){
	int i,n;
	scanf("%d",&n);
	long nums[30];
	for(i=0;i<n*3;++i){
		scanf("%ld",&nums[i]);
	}
	for(i=0;i<n;++i){
		printf("Case #%ld: %s\n",i+1,compare(nums[i*3],nums[i*3+1],nums[i*3+2]));	
	}
	return 0;
} 
