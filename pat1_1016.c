/*
正整数A的“DA（为1位整数）部分”定义为由A中所有DA组成的新整数PA。例如：给定A = 3862767，DA = 6，则A的“6部分”PA是66，因为A中有2个6。

现给定A、DA、B、DB，请编写程序计算PA + PB。

输入格式：

输入在一行中依次给出A、DA、B、DB，中间以空格分隔，其中0 < A, B < 1010。

输出格式：

在一行中输出PA + PB的值。

输入样例1：
3862767 6 13530293 3
输出样例1：
399
输入样例2：
3862767 1 13530293 8
输出样例2：
0
*/

#include<string.h>
#include<stdio.h>
int main(){
	char A[10],B[10];
	int A_len,B_len,i,j,DA,DB,PA,PB;
	scanf("%s",A);scanf("%d",&DA);
	scanf("%s",B);scanf("%d",&DB);
	A_len=strlen(A);
	B_len=strlen(B);
	PA=0;PB=0;
	for(i=0;i<A_len;++i){
		if((A[i]-'0')==DA)	PA=10*PA+DA;	
	}
	for(i=0;i<B_len;++i){
		if((B[i]-'0')==DB)	PB=10*PB+DB;	
	}
	printf("%d",PA+PB);
	return 0;
}
