/*
读入一个自然数n，计算其各位数字之和，用汉语拼音写出和的每一位数字。

输入格式：每个测试输入包含1个测试用例，即给出自然数n的值。这里保证n小于10100。

输出格式：在一行内输出n的各位数字之和的每一位，拼音数字间有1 空格，但一行中最后一个拼音数字后没有空格。

输入样例：
1234567890987654321123456789
输出样例：
yi san wu
*/

//利用栈可以实现倒序输出 

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
