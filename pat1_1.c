





/*
日了狗了的德才论
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





