/*
����n��ѧ����������ѧ�š��ɼ����ֱ�����ɼ���ߺͳɼ����ѧ����������ѧ�š�

�����ʽ��ÿ�������������1��������������ʽΪ

  ��1�У�������n
  ��2�У���1��ѧ�������� ѧ�� �ɼ�
  ��3�У���2��ѧ�������� ѧ�� �ɼ�
  ... ... ...
  ��n+1�У���n��ѧ�������� ѧ�� �ɼ�
����������ѧ�ž�Ϊ������10���ַ����ַ������ɼ�Ϊ0��100֮���һ�����������ﱣ֤��һ�����������û������ѧ���ĳɼ�����ͬ�ġ�
�����ʽ����ÿ�������������2�У���1���ǳɼ����ѧ����������ѧ�ţ���2���ǳɼ����ѧ����������ѧ�ţ��ַ�������1�ո�

����������
3
Joe Math990112 89
Mike CS991301 100
Mary EE990830 95
���������
Mike CS991301
Joe Math990112
*/

//ѧ��ʹ��strcpy():
//char *strcpy(char *dest, const char *src) 

#include<stdio.h> 
#include<string.h>
int main(){
	
	char minname[11],maxname[11],minNo[11],maxNo[11],name[11],No[11];
	int max=-1,min=101,score;
	int n;
	int i;
	scanf("%d",&n);
	for(i=0;i<n;++i){
		scanf("%s",name);
		scanf("%s",No);
		scanf("%d",&score);
		if(max<score){
			max=score;
			strcpy(maxname,name);
			strcpy(maxNo,No);
		}
		if(min>score){
			min=score;
			strcpy(minname,name);
			strcpy(minNo,No);
		}
	}
	printf("%s %s\n",maxname,maxNo);
	printf("%s %s\n",minname,minNo);
	return 0;
}
