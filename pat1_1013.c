/*
令Pi表示第i个素数。现任给两个正整数M <= N <= 104，请输出PM到PN的所有素数。

输入格式：

输入在一行中给出M和N，其间以空格分隔。

输出格式：

输出从PM到PN的所有素数，每10个数字占1行，其间以空格分隔，但行末不得有多余空格。

输入样例：
5 27
输出样例：
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/

#include<math.h>
#include<stdio.h>
//判断一个数是否是素数 
int isPrime(int n){
	int i;
	for(i=2;i<=sqrt(n);++i){
		if(n%i==0)	return 0;
	}
	return 1;
}

int main(){
	int M,N;
	scanf("%d",&M);
	scanf("%d",&N);
	int i,num=0,j=0;
	int a[1000];
	for(i=2;;++i){                     //将第M个素数装入数组 
		num+=isPrime(i);
		if(num==M){
			a[j++]=i;break;
		}
	}
	while(num<N){
		if(isPrime(++i)){
			++num;
			a[j++]=i;
		}
	}
	for(i=1;i<=j-1;++i){
		if(i%10!=0)	printf("%d ",a[i-1]);
		else	printf("%d\n",a[i-1]);
	}
	printf("%d",a[j-1]);
	return 0;
}	
