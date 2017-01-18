/*
大侦探福尔摩斯接到一张奇怪的字条：“我们约会吧！ 3485djDkxh4hhGE 2984akDfkkkkggEdsb s&hgsfdk d&Hyscvnm”。大侦探很快就明白了，字条上奇怪的乱码实际上就是约会的时间“星期四 14:04”，因为前面两字符串中第1对相同的大写英文字母（大小写有区分）是第4个字母'D'，代表星期四；第2对相同的字符是'E'，那是第5个英文字母，代表一天里的第14个钟头（于是一天的0点到23点由数字0到9、以及大写字母A到N表示）；后面两字符串第1对相同的英文字母's'出现在第4个位置（从0开始计数）上，代表第4分钟。现给定两对字符串，请帮助福尔摩斯解码得到约会的时间。

输入格式：

输入在4行中分别给出4个非空、不包含空格、且长度不超过60的字符串。

输出格式：

在一行中输出约会的时间，格式为“DAY HH:MM”，其中“DAY”是某星期的3字符缩写，即MON表示星期一，TUE表示星期二，WED表示星期三，THU表示星期四，FRI表示星期五，SAT表示星期六，SUN表示星期日。题目输入保证每个测试存在唯一解。

输入样例：
3485djDkxh4hhGE 
2984akDfkkkkggEdsb 
s&hgsfdk 
d&Hyscvnm
输出样例：
THU 14:04
*/

#include<stdio.h>
int main(){
	char s1[61];
	char s2[61];
	char s3[61];
	char s4[61];
	int day,hour,min;
	gets(s1);gets(s2);gets(s3);gets(s4);
	char days[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
	int i,j;
	for(i=0;i<61;++i){
		if(  (s1[i]==s2[i])  &&  'A'<=s1[i]  &&  s1[i]<='G'){
			day=s1[i]-'A';
			break;
		}
	}
	for(j=i+1;j<61;++j){
		//不能写成'0'<=s[i]<='9'!!! 
		if( (s1[j]==s2[j])  &&  (('0'<=s1[j]&&s1[j]<='9')||('A'<=s1[j]&&s1[j]<='N')) ){
			if('0'<=s1[j]  &&  s1[j]<='9'){
				hour=s1[j]-'0';break;
			}
			else{
				hour=s1[j]-'A'+10;break;
			}
		}
	}
	for(i=0;i<61;++i){
		if(  (s3[i]==s4[i])  &&  (('A'<=s3[i]&&s3[i]<='Z')  ||  ('a'<=s3[i]&&s3[i]<='z')) ){
			min=i;break;
		}
	}
	printf("%s %02d:%02d",days[day],hour,min);
	return 0;
}
