/*
������(Callatz)�����Ѿ���1001�и������������������Ŀ������΢��Щ���ӡ�

��������֤�����Ȳ����ʱ��Ϊ�˱����ظ����㣬���Լ�¼�µ��ƹ�����������ÿһ�����������n=3������֤��ʱ��������Ҫ����3��5��8��4��2��1�������Ƕ�n=5��8��4��2������֤��ʱ�򣬾Ϳ���ֱ���ж������Ȳ������α��������Ҫ�ظ����㣬��Ϊ��4�����Ѿ�����֤3��ʱ���������ˣ����ǳ�5��8��4��2�Ǳ�3�����ǡ����������ǳ�һ�������е�ĳ����nΪ���ؼ����������n���ܱ������е��������������ǡ�

���ڸ���һϵ�д���֤�����֣�����ֻ��Ҫ��֤���еļ����ؼ������Ϳ��Բ������ظ���֤���µ����֡������������ҳ���Щ�ؼ����֣������Ӵ�С��˳��������ǡ�

�����ʽ��ÿ�������������1��������������1�и���һ��������K(<100)����2�и���K��������ͬ�Ĵ���֤��������n(1<n<=100)��ֵ�����ּ��ÿո������

�����ʽ��ÿ���������������ռһ�У����Ӵ�С��˳������ؼ����֡����ּ���1���ո��������һ�������һ�����ֺ�û�пո�

����������
6
3 5 6 7 8 11
���������
7 6
*/ 


//***��Ҫ***���ٲ��ң��۰���� 

#include<stdio.h>
int in_num=0; 
int bypass[100];
int by_num=0;
int ins[100];
 /*
 �ж��������Ƿ����key��
 ����1��ʾ����
 ����0��ʾ������ 
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
/*ִ��3n+1,�����ǵ�����д��һ��ȫ�����飬
 ����ȫ�������еĸ��� 
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
�۰���ң��ҵ�����������������е�λ�ã�ʧ���򷵻�0
����������ҵ�Ԫ���ǵ�һ�����򷵻�λ��0.��ʧ��ʱ�򷵻�ֵ��ͬ��
�����ҳɹ�ʱ��ķ���ֵ�ĳ�mid+1 
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

