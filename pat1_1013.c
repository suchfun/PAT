/*
��Pi��ʾ��i�����������θ�����������M <= N <= 104�������PM��PN������������

�����ʽ��

������һ���и���M��N������Կո�ָ���

�����ʽ��

�����PM��PN������������ÿ10������ռ1�У�����Կո�ָ�������ĩ�����ж���ո�

����������
5 27
���������
11 13 17 19 23 29 31 37 41 43
47 53 59 61 67 71 73 79 83 89
97 101 103
*/

#include<math.h>
#include<stdio.h>
//�ж�һ�����Ƿ������� 
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
	for(i=2;;++i){                     //����M������װ������ 
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
