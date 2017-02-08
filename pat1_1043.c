/*
给定一个长度不超过10000的、仅由英文字母构成的字符串。请将字符重新调整顺序，按“PATestPATest....”这样的顺序输出，并忽略其它字符。当然，六种字符的个数不一定是一样多的，若某种字符已经输出完，则余下的字符仍按PATest的顺序打印，直到所有字符都被输出。

输入格式：

输入在一行中给出一个长度不超过10000的、仅由英文字母构成的非空字符串。

输出格式：

在一行中按题目要求输出排序后的字符串。题目保证输出非空。

输入样例：
redlesPayBestPATTopTeePHPereatitAPPT
输出样例：
PATestPATestPTetPTePePee
*/ 
#include<stdio.h>
#include<string.h>
int main(){
	char s[10001];
	gets(s);
	
	int Pcount=0,Acount=0,Tcount=0,ecount=0,scount=0,tcount=0;
	int i;
	for(i=0;i<strlen(s);i++){
		if(s[i]=='P')	++Pcount;
		else if(s[i]=='A')	++Acount;
		else if(s[i]=='T')	++Tcount;
		else if(s[i]=='e')	++ecount;
		else if(s[i]=='s')	++scount;
		else if(s[i]=='t')	++tcount;
	}
	for(i=0;i<strlen(s);i++){
		if(Pcount!=0){
			printf("P");--Pcount;
		}
		if(Acount!=0){
			printf("A");--Acount;
		}
		if(Tcount!=0){
			printf("T");--Tcount;
		}
		if(ecount!=0){
			printf("e");--ecount;
		}
		if(scount!=0){
			printf("s");--scount;
		}
		if(tcount!=0){
			printf("t");--tcount;
		}
	} 
	return 0;
}




