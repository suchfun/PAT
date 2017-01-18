/*
宋代史学家司马光在《资治通鉴》中有一段著名的“德才论”：“是故才德全尽谓之圣人，才德兼亡谓之愚人，德胜才谓之君子，才胜德谓之小人。凡取人之术，苟不得圣人，君子而与之，与其得小人，不若得愚人。”

现给出一批考生的德才分数，请根据司马光的理论给出录取排名。

输入格式：

输入第1行给出3个正整数，分别为：N（<=105），即考生总数；L（>=60），为录取最低分数线，即德分和才分均不低于L的考生才有资格被考虑录取；H（<100），为优先录取线——德分和才分均不低于此线的被定义为“才德全尽”，此类考生按德才总分从高到低排序；才分不到但德分到线的一类考生属于“德胜才”，也按总分排序，但排在第一类考生之后；德才分均低于H，但是德分不低于才分的考生属于“才德兼亡”但尚有“德胜才”者，按总分排序，但排在第二类考生之后；其他达到最低线L的考生也按总分排序，但排在第三类考生之后。

随后N行，每行给出一位考生的信息，包括：准考证号、德分、才分，其中准考证号为8位整数，德才分为区间[0, 100]内的整数。数字间以空格分隔。

输出格式：

输出第1行首先给出达到最低分数线的考生人数M，随后M行，每行按照输入格式输出一位考生的信息，考生按输入中说明的规则从高到低排序。当某类考生中有多人总分相同时，按其德分降序排列；若德分也并列，则按准考证号的升序输出。

输入样例：
14 60 80
10000001 64 90
10000002 90 60
10000011 85 80
10000003 85 80
10000004 80 85
10000005 82 77
10000006 83 76
10000007 90 78
10000008 75 79
10000009 59 90
10000010 88 45
10000012 80 100
10000013 90 99
10000014 66 60
输出样例：
12
10000013 90 99
10000012 80 100
10000003 85 80
10000011 85 80
10000004 80 85
10000007 90 78
10000006 83 76
10000005 82 77
10000002 90 60
10000014 66 60
10000008 75 79
10000001 64 90
*/

#include<stdio.h>
typedef struct student{
	int No;
	int D;
	int	C;
	int sum;  //计算公式是sum=2*D+C 
}student;
void QuickSort(student * stu,int start ,int end){
	if(start<end){
		int i,j;
		student temp;
		i=start;
		j=end;
		temp=stu[start];
		while(i<j){	
			while(i<j&&  (stu[j].sum  <=  temp.sum)  ) --j;
			if(i<j)	{
				stu[i++]=stu[j];
//				stu[i].No = stu[j].No;
//				stu[i].C = stu[j].C;
//				stu[i].D = stu[j].D;
//				stu[i].sum = stu[j].sum;
//				++i;
			}
			while(i<j&&  (stu[i].sum>temp.sum)  )	++i;
			if(i<j){
				stu[j--]=stu[i];
//				stu[j].No = stu[i].No;
//				stu[j].C = stu[i].C;
//				stu[j].D = stu[i].D;
//				stu[j].sum = stu[i].sum;
//				--j;
				//printf("%d %d %d %d %d\n",j,stu[j].No,stu[j].C,stu[j].D,stu[j].sum);
			}
		}
		stu[i]=temp;
		QuickSort(stu,start,i-1);
		QuickSort(stu,i+1,end);
	}
}
int main(){
	student  stu[10000];
	int num,L,H,i,j=0;
	int No_temp,C_temp,D_temp;
	scanf("%d %d %d",&num,&L,&H);
	int num0=num;
	for(i=0;i<num;++i){
		scanf("%d %d %d",&No_temp,&C_temp,&D_temp);
		if(C_temp>=L&&D_temp>=L){
			stu[j].No=No_temp;
			stu[j].C=C_temp;
			stu[j].D=D_temp;
			stu[j].sum=D_temp+C_temp;
			++j;
		}else	--num0;
	}
	printf("%d\n",num0);
	return 0;
} 
