/*
现给出两人的交锋记录，请统计双方的胜、平、负次数，并且给出双方分别出什么手势的胜算最大。

输入格式：

输入第1行给出正整数N（<=105），即双方交锋的次数。随后N行，每行给出一次交锋的信息，即甲、乙双方同时给出的的手势。C代表“锤子”、J代表“剪刀”、B代表“布”，第1个字母代表甲方，第2个代表乙方，中间有1个空格。

输出格式：

输出第1、2行分别给出甲、乙的胜、平、负次数，数字间以1个空格分隔。第3行给出两个字母，分别代表甲、乙获胜次数最多的手势，中间有1个空格。如果解不唯一，则输出按字母序最小的解。

输入样例：
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
输出样例：
5 3 2
2 3 5
B B
*/

//注意：在gets前，如果有输入，则需要getchar来清楚输入缓存中的回车 

#include<stdio.h>
int main(){
	int n,i;
	scanf("%d",&n);
	getchar();
	int jia[6]={0,0,0,0,0,0};
	int yi[6]={0,0,0,0,0,0};//分别存储胜、平、负、布、锤子、剪刀的个数
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
