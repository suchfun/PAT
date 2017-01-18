/*
编程团体赛的规则为：每个参赛队由若干队员组成；所有队员独立比赛；参赛队的成绩为所有队员的成绩和；成绩最高的队获胜。

现给定所有队员的比赛成绩，请你编写程序找出冠军队。

输入格式：

输入第一行给出一个正整数N（<=10000），即所有参赛队员总数。随后N行，每行给出一位队员的成绩，格式为：“队伍编号-队员编号 成绩”，其中“队伍编号”为1到1000的正整数，“队员编号”为1到10的正整数，“成绩”为0到100的整数。

输出格式：

在一行中输出冠军队的编号和总成绩，其间以一个空格分隔。注意：题目保证冠军队是唯一的。

输入样例：
6
3-10 99
11-5 87
102-1 0
102-3 100
11-9 89
3-2 61
输出样例：
11 176
*/

//char2int方法、getchar,fflush 

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
//如果不加上getchar(),或者fflush(stdin),那么第一个gets()会跳过，
//因为在执行gets时，前面有输入，且是以回车结束的，这个回车被保存在输入缓存，
//gets会读到这个字符，结束读取字符的操作 
//*/
//  //getchar();
//  fflush(stdin);
///*
//gets()函数自动以回车（windows是\r\n,unix是\n)为结束符 ,
//scanf()函数空格和回车都会自动作为字符串的结束符。
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
//      if((str[i][j]!='-')&&flag_team){  //flag的作用：避免将队伍号记录后又将后面的字符放进buf 
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
/*------------------liuchuo的答案，自己答案太傻逼了-----------------------*/
//很好的方法，既然要申请一定数量的数组，那就放开手用，不用count解决问题 
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

