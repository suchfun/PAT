#include<stdio.h>
#include<string.h>

//再次熟悉了冒泡排序 

//flag=1:升序排列，反之降序排列
int sort(int flag,int  str){ 
	int buf[4];
	buf[0]=str/1000;buf[1]=str/100%10;buf[2]=str/10%10;buf[3]=str%10;
	//printf("输入数字的各位数：%d-%d-%d-%d\n",buf[0],buf[1],buf[2],buf[3]);
	int i,j,bubble_flag=0;
	int temp;
	if(flag){
		for(i=0;i<4;++i){
			for(j=0;j<3-i;++j){
				if(buf[j]>buf[j+1]){
					temp=buf[j];
					buf[j]=buf[j+1];
					buf[j+1]=temp;
					bubble_flag=1;
				}
			}
			//printf("第%d次:%d-%d-%d-%d\n",i+1,buf[0],buf[1],buf[2],buf[3]);
			if(!bubble_flag)	break;
		}
	}
	else{
		for(i=0;i<4;++i){
			for(j=0;j<3-i;++j){
				if(buf[j]<buf[j+1]){
					temp=buf[j];
					buf[j]=buf[j+1];
					buf[j+1]=temp;
					bubble_flag=1;
				}
			}
			//printf("第%d次:%d-%d-%d-%d\n",i+1,buf[0],buf[1],buf[2],buf[3]);
			if(!bubble_flag)	break;
		}	
	}
	return buf[0]*1000+buf[1]*100+buf[2]*10+buf[3];
}
int main(){
	int num;
	int i,A,B,n=1;
	scanf("%d",&num);
	//sort(1,num);
	if(num/1000==num/100%10&&num/100%10==num/10%10&&num/10%10==num%10)
		printf("%d - %d = 0000",num,num);
	else{
		while(num!=6174||n==1){
			A=sort(0,num);
			B=sort(1,num);
			printf("%04d - %04d = %04d\n",A,B,A-B);
			num=A-B;
			++n;
		}
	}
	return 0;
} 
