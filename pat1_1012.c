/*
����һϵ�����������밴Ҫ������ֽ��з��࣬���������5�����֣�

A1 = �ܱ�5����������������ż���ĺͣ�
A2 = ����5������1�����ְ�����˳����н�����ͣ�������n1-n2+n3-n4...��
A3 = ��5������2�����ֵĸ�����
A4 = ��5������3�����ֵ�ƽ��������ȷ��С�����1λ��
A5 = ��5������4��������������֡�
�����ʽ��

ÿ���������1������������ÿ�����������ȸ���һ��������1000��������N��������N��������1000�Ĵ�����������������ּ��Կո�ָ���

�����ʽ��

�Ը�����N��������������ĿҪ�����A1~A5����һ����˳����������ּ��Կո�ָ�������ĩ�����ж���ո�

������ĳһ�����ֲ����ڣ�������Ӧλ�������N����

��������1��
13 1 2 3 4 5 6 7 8 9 10 20 16 18
�������1��
30 11 2 9.7 9
��������2��
8 1 2 4 5 6 7 9 16
�������2��
N 11 2 N 9
*/

//δ��� 

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
