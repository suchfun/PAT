#include<stdio.h>

void select_sort(int *arr,int n){
	int i,k,j,temp;
	for(i=0;i<n-1;i++){
		k=i;
		for(j=i;j<n;j++){
			if(arr[j]<arr[k])	k=j;	
		}
		temp=arr[k];
		arr[k]=arr[i];
		arr[i]=temp;			
	}
}

void quick_sort(int arr[],int low,int high){
	if(low<high){					//û����仰��һֱ�ݹ���ȥ 
	 	int temp;
		temp=arr[low];
		int l=low,h=high;           //֮����Ҫ��䣬��Ϊ�ݹ������Ҫ�õ�low,high,���ܽ�low,high�Լӻ��Լ� 
		while(l<h){
			while(l<h&&arr[h]>=temp){
				h--;
			}
			if(l<h){
				arr[l++]=arr[h];			
			}
			while(l<h&&arr[l]<temp){
				l++;
			}
			if(l<h){
				arr[h--]=arr[l];
			}
		}
		arr[l]=temp;
		quick_sort(arr,low,l-1);
		quick_sort(arr,l+1,high);		
	}
}

void bubble_sort(int * a,int n){
	int i,j;
	int flag=1,temp;
	for(i=0;i<n-1&&flag;++i){
			flag=0;
	 		for(j=0;j<n-i-1;j++){
				if(a[j]>a[j+1]){
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
					flag=1;
				}
			}		

	}
} 

int main(){
	int i,a[5]={5,4,3,2,1};
	//select_sort(a,5);
	//quick_sort(a,0,4);
	bubble_sort(a,5);
	for(i=0;i<5;i++){
		printf("%d",a[i]);
	}
	return 0;
}
