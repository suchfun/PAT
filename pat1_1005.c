/*
卡拉兹(Callatz)猜想已经在1001中给出了描述。在这个题目里，情况稍微有些复杂。

当我们验证卡拉兹猜想的时候，为了避免重复计算，可以记录下递推过程中遇到的每一个数。例如对n=3进行验证的时候，我们需要计算3、5、8、4、2、1，则当我们对n=5、8、4、2进行验证的时候，就可以直接判定卡拉兹猜想的真伪，而不需要重复计算，因为这4个数已经在验证3的时候遇到过了，我们称5、8、4、2是被3“覆盖”的数。我们称一个数列中的某个数n为“关键数”，如果n不能被数列中的其他数字所覆盖。

现在给定一系列待验证的数字，我们只需要验证其中的几个关键数，就可以不必再重复验证余下的数字。你的任务就是找出这些关键数字，并按从大到小的顺序输出它们。

输入格式：每个测试输入包含1个测试用例，第1行给出一个正整数K(<100)，第2行给出K个互不相同的待验证的正整数n(1<n<=100)的值，数字间用空格隔开。

输出格式：每个测试用例的输出占一行，按从大到小的顺序输出关键数字。数字间用1个空格隔开，但一行中最后一个数字后没有空格。

输入样例：
6
3 5 6 7 8 11
输出样例：
7 6
*/ 


//***重要***快速查找，折半查找 

#include<stdio.h>
int in_num=0; 
int bypass[100];
int by_num=0;
int ins[100];
 /*
 判断数组中是否存在key，
 返回1表示存在
 返回0表示不存在 
 */
int is_exist(int key,int * bypass,int by_num){
	int i;
	for(i=0;i<by_num;++i){
		if(bypass[i]==key){
			return 1;
		}
	}
	return 0;
}
/*执行3n+1,将覆盖的数据写入一个全局数组，
 返回全局数组中的个数 
 */
int three(int num){
	if(num==1||num==0){
		return by_num;
	}
	else{
		if(num%2==0){
			if(num/2!=1){
				if(!is_exist(num/2,bypass,by_num))
					bypass[by_num++]=num/2;
				else{
					return by_num; 
				} 
			}			
			three(num/2);
		}else{
			three(num*3+1);
		}		
	}
}
void delete_ins(int key,int * ins){
	int i,j;
	for(i=0;i<in_num;++i){
		if(ins[i]==key){
			for(j=i;j<in_num;++j){
				ins[j]=ins[j+1];
			}
			--in_num;			
		}

	} 
}
void QuickSort(int * ins,int start ,int end){
	if(start<end){
		int i,j,temp;
		i=start;
		j=end;
		temp=ins[start];
		while(i<j){	
			while(i<j&&ins[j]<=temp) --j;
			if(i<j)	ins[i++]=ins[j];
			while(i<j&&ins[i]>temp)	++i;
			if(i<j)	ins[j--]=ins[i];
		}
		ins[i]=temp;
		QuickSort(ins,start,i-1);
		QuickSort(ins,i+1,end);
	}
}
int main(){	
	int i;	
	scanf("%d",&in_num);
	for(i=0;i<in_num;++i){
		scanf("%d",&ins[i]);
		three(ins[i]);
	}
	for(i=0;i<by_num;++i){
		delete_ins(bypass[i],ins);
	}
	QuickSort(ins,0,in_num-1);
	for(i=0;i<in_num-1;++i){
		printf("%d ",ins[i]);
	}
	printf("%d",ins[in_num-1]);
	return 0;
} 
/*
折半查找：找到返回这个数在数组中的位置；失败则返回0
但是如果查找的元素是第一个，则返回位置0.与失败时候返回值相同。
将查找成功时候的返回值改成mid+1 
*/ 
//int halfSearch(int * array,int low,int high ,int key ){
//	int mid;
//	while(low<=high){
//		mid=(low+high)/2;
//		if(array[mid]>key)	high=mid-1;
//		else if(array[mid]<key)	low=mid+1;
//		else	return mid+1;
//	}
//	return false;
//} 

