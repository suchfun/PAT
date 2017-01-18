/*
让我们定义 dn 为：dn = pn+1 - pn，其中 pi 是第i个素数。显然有 d1=1 且对于n>1有 dn 是偶数。“素数对猜想”认为“存在无穷多对相邻且差为2的素数”。

现给定任意正整数N (< 105)，请计算不超过N的满足猜想的素数对的个数。

输入格式：每个测试输入包含1个测试用例，给出正整数N。

输出格式：每个测试用例的输出占一行，不超过N的满足猜想的素数对的个数。

输入样例：
20
输出样例：
4
*/

//利用一个定理——如果一个数是合数，那么它的最小质因数肯定小于等于他的平方根。否则，它就是素数。
 
#include<stdio.h>
int isPrime(int n){
	int i;
	for(i=2;i*i<=n;++i){
		if(n%i==0)	return 0;
	}
	return 1;
}
int main(){
	int n,i,count=0;
	scanf("%d",&n);
	for(i=3;i<=n-2;++i){
		if(isPrime(i+2)&&isPrime(i)){
			++count;
			//printf("%d---%d\n",i+2,i);
		}
	}
	printf("%d",count);
	return 0;
}
