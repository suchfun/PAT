/*
����������Ĺ���Ϊ��ÿ�������������ɶ�Ա��ɣ����ж�Ա���������������ӵĳɼ�Ϊ���ж�Ա�ĳɼ��ͣ��ɼ���ߵĶӻ�ʤ��

�ָ������ж�Ա�ı����ɼ��������д�����ҳ��ھ��ӡ�

�����ʽ��

�����һ�и���һ��������N��<=10000���������в�����Ա���������N�У�ÿ�и���һλ��Ա�ĳɼ�����ʽΪ����������-��Ա��� �ɼ��������С������š�Ϊ1��1000��������������Ա��š�Ϊ1��10�������������ɼ���Ϊ0��100��������

�����ʽ��

��һ��������ھ��ӵı�ź��ܳɼ��������һ���ո�ָ���ע�⣺��Ŀ��֤�ھ�����Ψһ�ġ�

����������
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61
���������
11 176
*/

//char2int������getchar,fflush 

#include<math.h>
#include<stdio.h>
#include<string.h>
//int char2int(char * str,int n){
//  int num=n,i,x=0;
//  for(i=0;i<n;++i){
//    x=x+(str[i]-'0')*pow(10,--num);
//  }
//  return x;
//}
//int main(){
//  int i,j,n,count_team,len,flag_team=1,flag_score=1,count_score,score_len;
//  int info[10000][2];
//  int team,score;
//  char buf[5];
//  scanf("%d",&n);
///*
//���������getchar(),����fflush(stdin),��ô��һ��gets()��������
//��Ϊ��ִ��getsʱ��ǰ�������룬�����Իس������ģ�����س������������뻺�棬
//gets���������ַ���������ȡ�ַ��Ĳ��� 
//*/
//  //getchar();
//  fflush(stdin);
///*
//gets()�����Զ��Իس���windows��\r\n,unix��\n)Ϊ������ ,
//scanf()�����ո�ͻس������Զ���Ϊ�ַ����Ľ�������
//*/
//  char str[10000][20];
//  for(i=0;i<n;i++){
//    gets(str[i]);
//    count_team=0;
//    count_score=0;
//    flag_team=1;
//    flag_score=1;
//    len=strlen(str[i]);
//    for(j=0;j<len;++j){
//      if((str[i][j]!='-')&&flag_team){  //flag�����ã����⽫����ż�¼���ֽ�������ַ��Ž�buf 
//        buf[count_team++]=str[i][j];
//        continue;
//      }
//      else if(flag_team){
//        info[i][0]=char2int(buf,count_team);
//        flag_team=0;  
//        continue;
//      }
//      if((str[i][j]!=' ')&&(flag_score)){
//        score_len=len-2-j;
//        continue;
//      }
//      flag_score=0;  
//      buf[count_score++]=str[i][j+1];
//      if(count_score==score_len){
//        info[i][1]=char2int(buf,count_score);
//        break;
//      }    
//    }
//  }
//  int max_score=0;
//  for(i=0;i<n;++i){
//    score=0;
//    for(j=0;j<n;++j){
//      if(info[j][0]==info[i][0]){
//        score+=info[j][1];
//      }
//    }
//    if(max_score<score){
//      team=info[i][0];
//      max_score=score;
//    }
//  }
//  printf("%d %d",team,max_score);  
//  return 0;
//} 
/*------------------liuchuo�Ĵ𰸣��Լ���̫ɵ����-----------------------*/
//�ܺõķ�������ȻҪ����һ�����������飬�Ǿͷſ����ã�����count������� 
int main() {
    int n;
    scanf("%d",&n);
    int i,t, num, score;
    int team[1001] = {0};
    for (i = 1; i <= n; i++) {
        scanf("%d-%d %d", &t, &num, &score);
        team[t] += score;
    }
    int max = 0;
    for (i = 0; i < 1001; i++) {
        if (team[max] < team[i])
            max = i;
    }
    printf("%d %d",max,team[max]);
    return 0;
}

