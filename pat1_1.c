#include<stdio.h>
#include<string.h>
/*
1001:3n+1
*/ 
//int three(int num,int count);
//int main(){
//	int count;
//	int a;
//	scanf("%d",&a);
//	count=three(a,0);
//	printf("%d",count);
//	return 0;
//}
//
//int three(int num,int count){
//
//	if(num==1||num==0){
//		return count;
//	}
//	else{
//		if(num%2==0){
//			return three(num/2,++count);
//		}else{
//			return three(num*3+1,count);
//		}		
//	}
//}
/*
1002
*/ 
//int main(){
//	int stack[3];
//	int front=-1;
//	char pingyin[10][5]={"ling","yi","er","san","shi","wu","liu","qi","ba","jiu"};
//	char num[101];
//	int sum=0;	
//  	int i,len;
//  	scanf("%s",num);
//  	i=len=0;
//	len=strlen(num);
//	//printf("%d",len);
//	int eachnum[len];
//	for(i=0;i<len;++i){
//		eachnum[i]=num[i]-'0';
//		sum+=eachnum[i];
//	}
//	//printf("%d",sum);
//	while(sum>10){
//		stack[++front]=sum%10;
//		sum=sum/10;
//	}
//	stack[++front]=sum;
//	while(front!=0){
//		printf("%s ",pingyin[stack[front--]]);
//	}
//	printf("%s",pingyin[stack[front]]);
//	return 0;  
//}
/*
1004:成绩排名 
*/
//int main(){
//	char name[10];
//	scanf("%s",name);
//	printf("%s\n",name);
	
//	char *name1;
//	scanf("%s",&name1);
//	printf("%s",&name1);
	
//	char minname[11],maxname[11],minNo[11],maxNo[11],name[11],No[11];
//	int max=-1,min=101,score;
//	int n;
//	int i;
//	scanf("%d",&n);
//	for(i=0;i<n;++i){
//		scanf("%s",name);
//		scanf("%s",No);
//		scanf("%d",&score);
//		if(max<score){
//			max=score;
//			strcpy(maxname,name);
//			strcpy(maxNo,No);
//		}
//		if(min>score){
//			min=score;
//			strcpy(minname,name);
//			strcpy(minNo,No);
//		}
//	}
//	printf("%s %s\n",maxname,maxNo);
//	printf("%s %s\n",minname,minNo);
//	return 0;
//}
/*
1005: 继续（3n+1)猜想 
*/
//int in_num=0; 
//int bypass[100];
//int by_num=0;
//int ins[100];
 /*
 判断数组中是否存在key，
 返回1表示存在
 返回0表示不存在 
 */
//int is_exist(int key,int * bypass,int by_num){
//	int i;
//	for(i=0;i<by_num;++i){
//		if(bypass[i]==key){
//			return 1;
//		}
//	}
//	return 0;
//}
/*执行3n+1,将覆盖的数据写入一个全局数组，
 返回全局数组中的个数 
 */
//int three(int num){
//	if(num==1||num==0){
//		return by_num;
//	}
//	else{
//		if(num%2==0){
//			if(num/2!=1){
//				if(!is_exist(num/2,bypass,by_num))
//					bypass[by_num++]=num/2;
//				else{
//					return by_num; 
//				} 
//			}			
//			three(num/2);
//		}else{
//			three(num*3+1);
//		}		
//	}
//}
//void delete_ins(int key,int * ins){
//	int i,j;
//	for(i=0;i<in_num;++i){
//		if(ins[i]==key){
//			for(j=i;j<in_num;++j){
//				ins[j]=ins[j+1];
//			}
//			--in_num;			
//		}
//
//	} 
//}
//void QuickSort(int * ins,int start ,int end){
//	if(start<end){
//		int i,j,temp;
//		i=start;
//		j=end;
//		temp=ins[start];
//		while(i<j){	
//			while(i<j&&ins[j]<=temp) --j;
//			if(i<j)	ins[i++]=ins[j];
//			while(i<j&&ins[i]>temp)	++i;
//			if(i<j)	ins[j--]=ins[i];
//		}
//		ins[i]=temp;
//		QuickSort(ins,start,i-1);
//		QuickSort(ins,i+1,end);
//	}
//}
//int main(){	
//	int i;	
//	scanf("%d",&in_num);
//	for(i=0;i<in_num;++i){
//		scanf("%d",&ins[i]);
//		three(ins[i]);
//	}
//	for(i=0;i<by_num;++i){
//		delete_ins(bypass[i],ins);
//	}
//	QuickSort(ins,0,in_num-1);
//	for(i=0;i<in_num-1;++i){
//		printf("%d ",ins[i]);
//	}
//	printf("%d",ins[in_num-1]);
//	return 0;
//} 
/*
1006:换个格式输出整数 
*/ 
//int main(){
//	int n,i;
//	scanf("%d",&n);
//	int b=n/100;
//	int s=n/10%10;
//	int g=n%10;
//	for(i=0;i<b;++i) printf("B");
//	for(i=0;i<s;++i) printf("S");
//	for(i=1;i<g+1;++i) printf("%d",i);
//	return 0;
//}
/*
1007：利用一个定理——如果一个数是合数，那么它的最小质因数肯定小于等于他的平方根。否则，它就是素数。 
*/ 
//int isPrime(int n){
//	int i;
//	for(i=2;i*i<=n;++i){
//		if(n%i==0)	return 0;
//	}
//	return 1;
//}
//int main(){
//	int n,i,count=0;
//	scanf("%d",&n);
//	for(i=3;i<=n-2;++i){
//		if(isPrime(i+2)&&isPrime(i)){
//			++count;
//			//printf("%d---%d\n",i+2,i);
//		}
//	}
//	printf("%d",count);
//	return 0;
//}
/*
折半查找：找到返回这个数在数组中的位置；失败则返回0
但是如果查找的元素是第一个，则返回位置0.与失败时候返回值相同。
将查找成功时候的返回值改成mid+1 
*/ 
//bool halfSearch(int * array,int low,int high ,int key ){
//	int mid;
//	while(low<=high){
//		mid=(low+high)/2;
//		if(array[mid]>key)	high=mid-1;
//		else if(array[mid]<key)	low=mid+1;
//		else	return mid+1;
//	}
//	return false;
//} 
/*
1008：利用队列实现右循环 
*/
//int main(){	
//	int qu[101];
//	int rear,front,N,M,i;
//	rear=front=0;
//	scanf("%d",&N);
//	scanf("%d",&M);
//	for(i=0;i<N;++i){
//		rear=(rear+1)%100;
//		scanf("%d",&qu[rear]);
//	}
//	int temp;
//	for(i=0;i<N-(M%N);++i){
//		front=(front+1)%100;
//		temp=qu[front];
//		rear=(rear+1)%100;
//		qu[rear]=temp;
//	}
//	for(i=0;i<N-1;++i){
//		front=(front+1)%100;
//		printf("%d ",qu[front]);
//	}
//	printf("%d",qu[rear]);
//	return 0;
//}
/*
1009：说反话   1.利用递归反向输出 2.将一个字符串数组切割 
*/
//void reprint(){
//	char *str=strtok(NULL," ");
//	if(str!=NULL){
//		reprint(str);
//		printf("%s ",str);
//	}
//} 
//int main(){
//	char words[81];
//	gets(words);
//	char * token;
//	token=strtok(words," ");
//	reprint();
//	printf("%s",token);
//	return 0;
//}
/*
1011：A+B>C  注意：1.要用long 2.对应的格式是%ld 
*/
//char * compare(long i,long j,long k){
//	if(i+j>k)	return "true";
//	else	return "false";
//} 
//int main(){
//	int i,n;
//	scanf("%d",&n);
//	long nums[30];
//	for(i=0;i<n*3;++i){
//		scanf("%ld",&nums[i]);
//	}
//	for(i=0;i<n;++i){
//		printf("Case #%ld: %s\n",i+1,compare(nums[i*3],nums[i*3+1],nums[i*3+2]));	
//	}
//	return 0;
//} 
/*
//1012:数字分类   未解决！！！！！！ 
//*/
//int main(){
//	int n,i,j,A1=0,A2=0,A3=0,A5=0;
//	int A1_count=0,A2_count=0,A3_count=0,A4_count=0,A5_count=0;
//	float A4=0.0;
//	int nums[1000];
//	scanf("%d",&n);
//	for(i=0;i<n;++i){
//		scanf("%d",&nums[i]);
//	}
//	for(i=0;i<n;++i){
//		if(nums[i]%10==0){
//			A1+=nums[i];
//			++A1_count;	
//		}	
//		else if(nums[i]%5==1){
//			++A2_count;
//			if(A2_count%2==1){
//				A2+=nums[i];
//			}
//			else A2-=nums[i];
//		}
//		else if(nums[i]%5==2){			
//			++A3;
//			++A3_count;	
//		}
//		else if(nums[i]%5==3){
//			++A4_count;
//			A4+=nums[i];
//			A4/=A4_count;
//		}
//		else if(nums[i]%5==4){
//			++A5_count;
//			if(A5<nums[i]){
//				A5=nums[i];	
//			}
//		}
//	}
//	if(A1_count!=0) printf("%d ",A1);
//	else printf("N ");
//	if(A2_count!=0) printf("%d ",A2);
//	else printf("N ");
//	if(A3_count!=0) printf("%d ",A3);
//	else printf("N ");
//	if(A4_count!=0) printf("%.1f ",A4);
//	else printf("N ");
//	if(A5_count!=0) printf("%d",A5);
//	else printf("N");
//	return 0;
//}
/*
1013：数素数 
*/
//#include<math.h>
////判断一个数是否是素数 
//int isPrime(int n){
//	int i;
//	for(i=2;i<=sqrt(n);++i){
//		if(n%i==0)	return 0;
//	}
//	return 1;
//}
//
//int main(){
//	int M,N;
//	scanf("%d",&M);
//	scanf("%d",&N);
//	int i,num=0,j=0;
//	int a[1000];
//	for(i=2;;++i){                     //将第M个素数装入数组 
//		num+=isPrime(i);
//		if(num==M){
//			a[j++]=i;break;
//		}
//	}
//	while(num<N){
//		if(isPrime(++i)){
//			++num;
//			a[j++]=i;
//		}
//	}
//	for(i=1;i<=j-1;++i){
//		if(i%10!=0)	printf("%d ",a[i-1]);
//		else	printf("%d\n",a[i-1]);
//	}
//	printf("%d",a[j-1]);
//	return 0;
//}	
/*
1014:福尔摩斯的约会 
*/
//int main(){
//	char s1[61];
//	char s2[61];
//	char s3[61];
//	char s4[61];
//	int day,hour,min;
//	gets(s1);gets(s2);gets(s3);gets(s4);
//	char days[7][4]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
//	int i,j;
//	for(i=0;i<61;++i){
//		if(  (s1[i]==s2[i])  &&  'A'<=s1[i]  &&  s1[i]<='G'){
//			day=s1[i]-'A';
//			break;
//		}
//	}
//	for(j=i+1;j<61;++j){
//		//不能写成'0'<=s[i]<='9'!!! 
//		if( (s1[j]==s2[j])  &&  (('0'<=s1[j]&&s1[j]<='9')||('A'<=s1[j]&&s1[j]<='N')) ){
//			if('0'<=s1[j]  &&  s1[j]<='9'){
//				hour=s1[j]-'0';break;
//			}
//			else{
//				hour=s1[j]-'A'+10;break;
//			}
//		}
//	}
//	for(i=0;i<61;++i){
//		if(  (s3[i]==s4[i])  &&  (('A'<=s3[i]&&s3[i]<='Z')  ||  ('a'<=s3[i]&&s3[i]<='z')) ){
//			min=i;break;
//		}
//	}
//	printf("%s %02d:%02d",days[day],hour,min);
//	return 0;
//}
/*
日了狗了的德才论，用C写真TM吃力 
*/
//typedef struct student{
//	int No;
//	int D;
//	int	C;
//	int sum;  //计算公式是sum=2*D+C 
//}student;
//void QuickSort(student * stu,int start ,int end){
//	if(start<end){
//		int i,j;
//		student temp;
//		i=start;
//		j=end;
//		temp=stu[start];
//		while(i<j){	
//			while(i<j&&  (stu[j].sum  <=  temp.sum)  ) --j;
//			if(i<j)	{
//				stu[i++]=stu[j];
////				stu[i].No = stu[j].No;
////				stu[i].C = stu[j].C;
////				stu[i].D = stu[j].D;
////				stu[i].sum = stu[j].sum;
////				++i;
//			}
//			while(i<j&&  (stu[i].sum>temp.sum)  )	++i;
//			if(i<j){
//				stu[j--]=stu[i];
////				stu[j].No = stu[i].No;
////				stu[j].C = stu[i].C;
////				stu[j].D = stu[i].D;
////				stu[j].sum = stu[i].sum;
////				--j;
//				//printf("%d %d %d %d %d\n",j,stu[j].No,stu[j].C,stu[j].D,stu[j].sum);
//			}
//		}
//		stu[i]=temp;
//		QuickSort(stu,start,i-1);
//		QuickSort(stu,i+1,end);
//	}
//}
//int main(){
//	student  stu[10000];
//	int num,L,H,i,j=0;
//	int No_temp,C_temp,D_temp;
//	scanf("%d %d %d",&num,&L,&H);
//	int num0=num;
//	for(i=0;i<num;++i){
//		scanf("%d %d %d",&No_temp,&C_temp,&D_temp);
//		if(C_temp>=L&&D_temp>=L){
//			stu[j].No=No_temp;
//			stu[j].C=C_temp;
//			stu[j].D=D_temp;
//			stu[j].sum=D_temp+C_temp;
//			++j;
//		}else	--num0;
//	}
//	printf("%d\n",num0);
//	return 0;
//} 
/*
1047
*/
//#include<math.h>
//#include<stdio.h>
//#include<string.h>
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
//int main() {
//    int n;
//    scanf("%d",&n);
//    int i,t, num, score;
//    int team[1001] = {0};
//    for (i = 1; i <= n; i++) {
//        scanf("%d-%d %d", &t, &num, &score);
//        team[t] += score;
//    }
//    int max = 0;
//    for (i = 0; i < 1001; i++) {
//        if (team[max] < team[i])
//            max = i;
//    }
//    printf("%d %d",max,team[max]);
//    return 0;
//}
/*1016*/
//#include<string.h>
//int main(){
//	char A[10],B[10];
//	int A_len,B_len,i,j,DA,DB,PA,PB;
//	scanf("%s",A);scanf("%d",&DA);
//	scanf("%s",B);scanf("%d",&DB);
//	A_len=strlen(A);
//	B_len=strlen(B);
//	PA=0;PB=0;
//	for(i=0;i<A_len;++i){
//		if((A[i]-'0')==DA)	PA=10*PA+DA;	
//	}
//	for(i=0;i<B_len;++i){
//		if((B[i]-'0')==DB)	PB=10*PB+DB;	
//	}
//	printf("%d",PA+PB);
//	return 0;
//}
/*1017*/
//char A[1001];
//int B;
//int divide(int i,int j){
//	if(A[j]!='\0'){
//		if(i>=B){
//			printf("%d",i/B);
//			printf("%d",((i-B)*10+(A[j]-'0'))/B);
//			divide(((i-B)*10+(A[j]-'0'))%B,j+1);
//		}
//		else{
//			printf("%d",(i*10+(A[j]-'0'))/B);
//			divide(  (  i*10+(A[j]-'0')  )%B  ,j+1);
//		}	
//	}else{
//		if(i>B)
//			printf("%d",i/B);
//		return i%B;
//	}
//}
//int main(){
//	char shang[1001];
//	int yushu=0;
//	scanf("%s",A);
//	scanf("%d",&B);	
//	if(A[1]!='\0'){
//		if((A[0]-'0')>=B){
//			printf("%d",(A[0]-'0')/B);
//			printf("%d",((A[0]-'0'-B)*10+(A[1]-'0'))/B);
//			yushu=divide(((A[0]-'0'-B)*10+(A[1]-'0'))%B,2);
//		}
//		else{
//			printf("%d",((A[0]-'0')*10+(A[1]-'0'))/B,((A[0]-'0')*10+(A[1]-'0'))%B,2);
//			yushu=divide(((A[0]-'0')*10+(A[1]-'0'))%B,2);
//		}	
//	}else{	
//		printf("%d",(A[0]-'0')/B);
//		yushu=(A[0]-'0')%B;
//	}
//	printf(" %d",yushu);
//	return 0;
//}
/* liuchuo的答案,发现自己总是把事情想复杂   */
//int main() {
//    char s[1001];
//    scanf("%s",s);
//    int a,i;
//    scanf("%d",&a);
//    int len ;
//	len = strlen(s);
//    int t = 0;
//    int temp = 0;
//    t = (s[0] - '0') / a;
//    if (t != 0 || len == 1) {    
//		printf("%d",t);
//    }
//    temp = (s[0] - '0') % a;
//    for (i = 1; i < len; i++) {
//        t = (temp * 10 + s[i] - '0') / a;
//        printf("%d",t);
//        temp = (temp * 10 + s[i] - '0') % a;
//    }
//    printf(" %d",temp);
//    return 0;
//}

