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
1009：说反话 
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


