/*
给定任一个各位数字不完全相同的4位正整数，如果我们先把4个数字按非递增排序，再按非递减排序，然后用第1个数字减第2个数字，将得到一个新的数字。一直重复这样做，我们很快会停在有“数字黑洞”之称的6174，这个神奇的数字也叫Kaprekar常数。

例如，我们从6767开始，将得到

7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
7641 - 1467 = 6174
... ...

现给定任意4位正整数，请编写程序演示到达黑洞的过程。

输入格式：

输入给出一个(0, 10000)区间内的正整数N。

输出格式：

如果N的4位数字全相等，则在一行内输出“N - N = 0000”；否则将计算的每一步在一行内输出，直到6174作为差出现，输出格式见样例。注意每个数字按4位数格式输出。

输入样例1：
6767
输出样例1：
7766 - 6677 = 1089
9810 - 0189 = 9621
9621 - 1269 = 8352
8532 - 2358 = 6174
输入样例2：
2222
输出样例2：
2222 - 2222 = 0000
*/ 
#include<stdio.h>
#include<string.h>

//再次熟悉了冒泡排序 

//flag=1:升序排列，反之降序排列
int sort(int flag,int  str){ 
	int buf[4];
	buf[0]=str/1000;buf[1]=str/100%10;buf[2]=str/10%10;buf[3]=str%10;
	//printf("输入数字的各位数：%d-%d-%d-%d\n",buf[0],buf[1],buf[2],buf[3]);
	int i,j,bubble_flag=0;
	int temp;
	if(flag){
		for(i=0;i<4;++i){
			for(j=0;j<3-i;++j){
				if(buf[j]>buf[j+1]){
					temp=buf[j];
					buf[j]=buf[j+1];
					buf[j+1]=temp;
					bubble_flag=1;
				}
			}
			//printf("第%d次:%d-%d-%d-%d\n",i+1,buf[0],buf[1],buf[2],buf[3]);
			if(!bubble_flag)	break;
		}
	}
	else{
		for(i=0;i<4;++i){
			for(j=0;j<3-i;++j){
				if(buf[j]<buf[j+1]){
					temp=buf[j];
					buf[j]=buf[j+1];
					buf[j+1]=temp;
					bubble_flag=1;
				}
			}
			//printf("第%d次:%d-%d-%d-%d\n",i+1,buf[0],buf[1],buf[2],buf[3]);
			if(!bubble_flag)	break;
		}	
	}
	return buf[0]*1000+buf[1]*100+buf[2]*10+buf[3];
}
int main(){
	int num;
	int i,A,B,n=1;
	scanf("%d",&num);
	//sort(1,num);
	if(num/1000==num/100%10&&num/100%10==num/10%10&&num/10%10==num%10)
		printf("%d - %d = 0000",num,num);
	else{
		while(num!=6174||n==1){
			A=sort(0,num);
			B=sort(1,num);
			printf("%04d - %04d = %04d\n",A,B,A-B);
			num=A-B;
			++n;
		}
	}
	return 0;
} 
