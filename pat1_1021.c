/*
给定一个k位整数N = dk-1*10k-1 + ... + d1*101 + d0 (0<=di<=9, i=0,...,k-1, dk-1>0)，请编写程序统计每种不同的个位数字出现的次数。例如：给定N = 100311，则有2个0，3个1，和1个3。

输入格式：

每个输入包含1个测试用例，即一个不超过1000位的正整数N。

输出格式：

对N中每一种不同的个位数字，以D:M的格式在一行中输出该位数字D及其在N中出现的次数M。要求按D的升序输出。

输入样例：
100311
输出样例：
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
	char s[1000];//为什么这里写char *s就不行呢？ 
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
