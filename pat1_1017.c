/*
����Ҫ�����A/B������A�ǲ�����1000λ����������B��1λ������������Ҫ�������Q������R��ʹ��A = B * Q + R������

�����ʽ��

������1�������θ���A��B���м���1�ո�ָ���

�����ʽ��

��1�����������Q��R���м���1�ո�ָ���

����������
123456789050987654321 7
���������
17636684150141093474 3
*/

/* liuchuo�Ĵ�,�����Լ����ǰ������븴��   */
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
