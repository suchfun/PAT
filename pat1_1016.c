/*
������A�ġ�DA��Ϊ1λ���������֡�����Ϊ��A������DA��ɵ�������PA�����磺����A = 3862767��DA = 6����A�ġ�6���֡�PA��66����ΪA����2��6��

�ָ���A��DA��B��DB�����д�������PA + PB��

�����ʽ��

������һ�������θ���A��DA��B��DB���м��Կո�ָ�������0 < A, B < 1010��

�����ʽ��

��һ�������PA + PB��ֵ��

��������1��
3862767 6 13530293 3
�������1��
399
��������2��
3862767 1 13530293 8
�������2��
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
