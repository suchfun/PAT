/*
�ָ������˵Ľ����¼����ͳ��˫����ʤ��ƽ�������������Ҹ���˫���ֱ��ʲô���Ƶ�ʤ�����

�����ʽ��

�����1�и���������N��<=105������˫������Ĵ��������N�У�ÿ�и���һ�ν������Ϣ�����ס���˫��ͬʱ�����ĵ����ơ�C�������ӡ���J������������B������������1����ĸ����׷�����2�������ҷ����м���1���ո�

�����ʽ��

�����1��2�зֱ�����ס��ҵ�ʤ��ƽ�������������ּ���1���ո�ָ�����3�и���������ĸ���ֱ����ס��һ�ʤ�����������ƣ��м���1���ո�����ⲻΨһ�����������ĸ����С�Ľ⡣

����������
10
C J
J B
C B
B B
B C
C C
C B
J B
B C
J J
���������
5 3 2
2 3 5
B B
*/

//ע�⣺��getsǰ����������룬����Ҫgetchar��������뻺���еĻس� 

#include<stdio.h>
int main(){
	int n,i;
	scanf("%d",&n);
	getchar();
	int jia[6]={0,0,0,0,0,0};
	int yi[6]={0,0,0,0,0,0};//�ֱ�洢ʤ��ƽ�������������ӡ������ĸ���
	char result[100001][4];
	for(i=0;i<n;++i){
		gets(result[i]);
	}
	for(i=0;i<n;++i){
		if((result[i][0]=='B'&&result[i][2]=='B')||(result[i][0]=='C'&&result[i][2]=='C')||(result[i][0]=='J'&&result[i][2]=='J')){
			++jia[1];
			++yi[1];	
		}
		else if(result[i][0]=='B'&&result[i][2]=='C'){
			++jia[0];++jia[3];
			++yi[2];			
		}
		else if(result[i][0]=='B'&&result[i][2]=='J'){
			++jia[2];
			++yi[0];++yi[5];			
		}
		else if(result[i][0]=='C'&&result[i][2]=='B'){
			++jia[2];
			++yi[0];++yi[3];			
		}
		else if(result[i][0]=='C'&&result[i][2]=='J'){
			++jia[0];++jia[4];
			++yi[2];			
		}
		else if(result[i][0]=='J'&&result[i][2]=='B'){
			++jia[0];++jia[5];
			++yi[2];			
		}
		else if(result[i][0]=='J'&&result[i][2]=='C'){
			++jia[2];
			++yi[0];++yi[4];			
		}
	}
	printf("%d %d %d\n",jia[0],jia[1],jia[2]);
	printf("%d %d %d\n",yi[0],yi[1],yi[2]);
	char BCM[4]={'B','C','J'};
	int max=0;
	max=jia[3];
	int index=3;
	for(i=4;i<6;++i){
		if(max<jia[i]){
			max=jia[i];
			index=i;
		}
	}
	printf("%c ",BCM[index-3]);
	for(i=4,index=3,max=yi[3];i<6;++i){
		if(max<yi[i]){
			max=yi[i];
			index=i;
		}
	}
	printf("%c",BCM[index-3]);
	return 0;	
}
