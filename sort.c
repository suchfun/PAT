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
	if(low<high){					//没有这句话将一直递归下去 
	 	int temp;
		temp=arr[low];
		int l=low,h=high;           //之所以要这句，因为递归调用需要用到low,high,不能讲low,high自加或自减 
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
