/*
����һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵ��ַ������뽫�ַ����µ���˳�򣬰���PATestPATest....��������˳������������������ַ�����Ȼ�������ַ��ĸ�����һ����һ����ģ���ĳ���ַ��Ѿ�����꣬�����µ��ַ��԰�PATest��˳���ӡ��ֱ�������ַ����������

�����ʽ��

������һ���и���һ�����Ȳ�����10000�ġ�����Ӣ����ĸ���ɵķǿ��ַ�����

�����ʽ��

��һ���а���ĿҪ������������ַ�������Ŀ��֤����ǿա�

����������
redlesPayBestPATTopTeePHPereatitAPPT
���������
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




