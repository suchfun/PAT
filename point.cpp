#include<stdio.h>

int main(){
	char *s;
	char a[50];
	s=a;
	gets(s);
	printf("%c",s[2]);
	return 0;
} 
