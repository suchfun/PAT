/*
给定一系列正整数，请按要求对数字进行分类，并输出以下5个数字：

A1 = 能被5整除的数字中所有偶数的和；
A2 = 将被5除后余1的数字按给出顺序进行交错求和，即计算n1-n2+n3-n4...；
A3 = 被5除后余2的数字的个数；
A4 = 被5除后余3的数字的平均数，精确到小数点后1位；
A5 = 被5除后余4的数字中最大数字。
输入格式：

每个输入包含1个测试用例。每个测试用例先给出一个不超过1000的正整数N，随后给出N个不超过1000的待分类的正整数。数字间以空格分隔。

输出格式：

对给定的N个正整数，按题目要求计算A1~A5并在一行中顺序输出。数字间以空格分隔，但行末不得有多余空格。

若其中某一类数字不存在，则在相应位置输出“N”。

输入样例1：
13 1 2 3 4 5 6 7 8 9 10 20 16 18
输出样例1：
30 11 2 9.7 9
输入样例2：
8 1 2 4 5 6 7 9 16
输出样例2：
N 11 2 N 9
*/

//未解决 

#include<stdio.h>
int main(){
	int n,i,j,A1=0,A2=0,A3=0,A5=0;
	int A1_count=0,A2_count=0,A3_count=0,A4_count=0,A5_count=0;
	float A4=0.0;
	int nums[1000];
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%d",&nums[i]);
	}
	for(i=0;i<n;++i){
		if(nums[i]%10==0){
			A1+=nums[i];
			++A1_count;	
		}	
		else if(nums[i]%5==1){
			++A2_count;
			if(A2_count%2==1){
				A2+=nums[i];
			}
			else A2-=nums[i];
		}
		else if(nums[i]%5==2){			
			++A3;
			++A3_count;	
		}
		else if(nums[i]%5==3){
			++A4_count;
			A4+=nums[i];
			A4/=A4_count;
		}
		else if(nums[i]%5==4){
			++A5_count;
			if(A5<nums[i]){
				A5=nums[i];	
			}
		}
	}
	if(A1_count!=0) printf("%d ",A1);
	else printf("N ");
	if(A2_count!=0) printf("%d ",A2);
	else printf("N ");
	if(A3_count!=0) printf("%d ",A3);
	else printf("N ");
	if(A4_count!=0) printf("%.1f ",A4);
	else printf("N ");
	if(A5_count!=0) printf("%d",A5);
	else printf("N");
	return 0;
}
