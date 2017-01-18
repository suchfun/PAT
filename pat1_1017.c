/*
本题要求计算A/B，其中A是不超过1000位的正整数，B是1位正整数。你需要输出商数Q和余数R，使得A = B * Q + R成立。

输入格式：

输入在1行中依次给出A和B，中间以1空格分隔。

输出格式：

在1行中依次输出Q和R，中间以1空格分隔。

输入样例：
123456789050987654321 7
输出样例：
17636684150141093474 3
*/

/* liuchuo的答案,发现自己总是把事情想复杂   */
#include<string.h>
#include<stdio.h>
int main() {
    char s[1001];
    scanf("%s",s);
    int a,i;
    scanf("%d",&a);
    int len ;
	len = strlen(s);
    int t = 0;
    int temp = 0;
    t = (s[0] - '0') / a;
    if (t != 0 || len == 1) {    
		printf("%d",t);
    }
    temp = (s[0] - '0') % a;
    for (i = 1; i < len; i++) {
        t = (temp * 10 + s[i] - '0') / a;
        printf("%d",t);
        temp = (temp * 10 + s[i] - '0') % a;
    }
    printf(" %d",temp);
    return 0;
}
