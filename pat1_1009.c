/*
����һ��Ӣ�Ҫ�����д���򣬽��������е��ʵ�˳��ߵ������

�����ʽ�������������һ��������������һ���ڸ����ܳ��Ȳ�����80���ַ������ַ��������ɵ��ʺ����ɿո���ɣ����е�������Ӣ����ĸ����Сд�����֣���ɵ��ַ���������֮����1���ո�ֿ������뱣֤����ĩβû�ж���Ŀո�

�����ʽ��ÿ���������������ռһ�У���������ľ��ӡ�

����������
Hello World Here I Come
���������
Come I Here World Hello
*/

//  1.���õݹ鷴����� 2.��һ���ַ��������и� 

#include<stdio.h>
#include<string.h>
void reprint(){
	char *str=strtok(NULL," ");
	if(str!=NULL){
		reprint(str);
		printf("%s ",str);
	}
} 
int main(){
	char words[81];
	gets(words);
	char * token;
	token=strtok(words," ");
	reprint();
	printf("%s",token);
	return 0;
}
