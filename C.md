# C学习笔记 #




1. ### `char s1[100]="hello";` 与 `char *s2="hello";` 的区别 ##

	 数组声明的"hello"存储在栈中，所以s1[1]='c'; legal!

	 而指针所指向的"hello"是常量，存储在只读区，所以s2[1]='c'; illegal!
	
	还值得一说的是，s1，数组名，数组名仅仅是“相当”于指针，而并非真的是指针，数组名是只是个常量（一个值为数组首元素地址的常量），所以不能进行++或者--运算，自然也不能s1="world"。

	顺便说一下不同的变量在内存中的位置：
	
		+----------------+
		|  内核虚拟内存	 |
		+----------------+
		|	栈区          |   这个部分保存函数中的局部变量，系统自动回收
		+----------------+
		|共享库的内存映射  |
		+----------------+
		|	堆区	        |	这个部分保存malloc,new出来的变量，需要free,delete
		+----------------+
		|	可读写区      |	保存全局变量和static变量
		+----------------+
		|    只读区       |	保存常量
		+----------------+


1. ### 求两个数的最大公约数 ##

	辗转相除法：用 （前一次的）除数%（前一次的）余数，直到余数为0，输出除数。

		long gys(long n,long m){
			while(n){
				long yu;
				yu=m%n;
				m=n;
				n=yu;
			}
			return m;
		}

1. ### 尾插法可以实现逆序，而且可以保留住头指针 ##

1. ### 内存对齐 ##

	讲道理，计算机的内存地址的单位是字节（一个地址对应的是1字节的内存），这样CPU可以访问到任何数据。但是这样不是很高效，想想，C语言中一个int型变量占4字节，那CPU要读取这个整型就需要4次读取，比说麻烦不。
	
	所以，就有了字节对齐。编译器是怎么处理字节对齐的呢：     						
	
	对于标准数据类型，它的地址只要是它的长度的整数倍就行了。

	而非标准数据类型按下面的原则对齐： 

	- 数组：按照基本数据类型对齐，第一个对齐了后面的自然也就对齐了。 	
	- 联合：按其包含的长度最大的数据类型对齐。 
	- 结构体：结构体中每个数据类型都要对齐。

	关于结构体与联合的区别：[http://blog.csdn.net/maopig/article/details/6772171](http://blog.csdn.net/maopig/article/details/6772171 "maopig的专栏")

		typedef struct Node{
			char c;
			int i;
			char a[10];
		}Node;
	上诉结构体，sizeof(Node) 返回值是20。
	所以结构体中变量的声明顺序会影响结构体所占的内存大小：
	
		typedef struct A{
			char a;
			int i;
			char c;
		}A;
		typedef struct B{
			char a;
			char c;
			int i;
		}B;
	经测试，sizeof(A) 返回值是12，sizeof(B) 返回值是8。

				**A**                     **B**
		+----+----+----+----+    +----+----+----+----+    
		|  a |    |    |    |    |  a |  c |    |    |
		+----+----+----+----+    +----+----+----+----+
		|         i         |    |         i         |
		+----+----+----+----+    +----+----+----+----+
		|  c |    |    |    |
		+----+----+----+----+	
	有上面这张图就清楚了。
	
	当然也可以自己设置编译器字节对齐的规则：

		#pragma pack(1)
		typedef struct B{
			char a;
			char c;
			int i;
		}B;	
	这时，sizeof(B) 返回值是6。

	关于更多关于字节对齐:[http://blog.csdn.net/hbuxiaofei/article/details/9491953](http://blog.csdn.net/hbuxiaofei/article/details/9491953 "beachboyy的博客")

1. ### 判断素数的方法 ##
	如果一个数，不能被所有 小于这个数开根号 的数整除，那么它就是素数，否则是合数。
	
		int isPrime(int n){
			int i;
			for(i=2;i*i<n;i++){
				if(n%i==0) return 0;
			}
			return 1;
		}

1. ### 用栈实现符号匹配 ##

	如果是'('则入栈，')'则出栈：
		
		int main(){
			FILE *in;
			if(!(in=fopen(".\\suchfun.c","r"))){
				printf("open error");
			}
			char stack[1000];
			int top=-1;
			 
			while(!feof(in)){
				char ch=fgetc(in);
				if(ch=='('){
					stack[++top]='(';
				}
				if(ch==')'){
					if(top==-1){
						--top;  //这里之所以加上这句。是因为避免与while循环外面输出success 的条件重复 
						break;
					}
					--top;  
				} 
			}
			if(top==-1)	printf("success");
			else	printf("fail"); 
			return 0;
		} 

1. ### 说一说递归 ###

	说废话，先看代码：

		void MinMax(int *a,int n,int *min,int *max){
			if(n==0) return;
			if(a[n-1]>*max) *max=a[n-1];
			if(a[n-2]<*min) *min=a[n-1];
			MinMax(a,n-1,min,max);	
		} 
	上面是一个递归求最大值最小值的函数。下面是累加和阶乘的代码：

		int LJ(int n){   //累加 
			if(n>=0){
				if(n==0)	return 0;
				if(n==1)	return 1;
				else{
					return n+JC(n-1);
				}		
			}
		}
		int JC(int n){  //阶乘 
			if(n>=0){
				if(n==0||n==1)	return 1;
				else{
					return n*JC(n-1);
				}
			}
			
		}
	这是我理解的典型的两种递归：进入递归(the fomer)，返回递归(the later)。（我自个根据理解编造的名字）

	我打个比方来形容一下这两种递归的区别:
	
	递归是用栈来实现的，我们可以想象成，调用一个函数就开一扇门，这样一扇一扇嵌套着。而第一种递归就好比每次进入一扇门就捡一颗糖，到达终点的时候糖就捡完了，从一扇扇门返回来的时候基本什么都没做。第二种就好比，先闯进一扇扇的门，闯入的过程基本什么都没做，返回的时候，开一扇门捡一颗糖，回到终点任务完成。

1. ###奇数幻方问题 ##
	所谓N阶幻方就是，将1-N^2填到N*N的正方形中，使其行，列，对角线的和相等。
	
		const int n=5;//定义待幻方的阶次，按题目要求，应该为奇数，暂定为5
		void main()
		{
			int a[5][5]={0};//定义数组并初始化，表示该幻方
			int k=1;//定义赋值的数，从1 到25
			int i=0;
			int j=n/2;
			int iold,jold;//存储旧的行号和列标
			int maxk=n*n;//定义循环的结束值
			for(k=1;k<=maxk;k++)//对每一个要赋值的数循环
			{
				a[i][j]=k;
				iold=i;
				jold=j;
				i=i-1; //向上移一行
				j=j+1; //向右移一列，以上两语句实现移到右上格
				if(i>=0&&j>=n)//从右边超出
					j=0;
				else if(i<0&&j<n)//从上面超出
					i=n-1;
				else if(i<0&&j>=n)//从右和上同时超出
				{
					i=1;
					j=n-1;
				}
				if(a[i][j]>0)//右上格已经被填充
				{
					i=iold+1;
					j=jold;
				}
			}
			for(i=0;i<n;i++)//输出
			{
				for(j=0;j<n;j++)
					printf("%d\t",a[i][j]);
				printf("\n");
			}
		}
	没什么好说的，算法就是这样：

	将 1 填在第一行的中间一列，然后依次将数字填在之前所填数字的右上角，若顶超过顶端，则折向底端，列数还是加一。若超出右边界，则折回到最左边，行数还是减一。如果右上角已经填了数字，则在本身的下面填数字。如果又超过顶，又超过右边界，也是在本身下面一个格子填数字。

	至于算法为什么是这样：[https://www.zhihu.com/question/30498489](https://www.zhihu.com/question/30498489 "知乎")
	
1. ###判断一个浮点数的值是否为0  ##

	`if(f==0)` 这样判断是不精确的，应该 `if(fabs(f)<1e^-7)`

	为什么这样做呢？这篇博文我看了一大半，没看完：[http://www.cnblogs.com/kubixuesheng/p/4107309.html](http://www.cnblogs.com/kubixuesheng/p/4107309.html "dashuai的博客")

1. ###约瑟夫环  ##

	简单说一下什么是约瑟夫环问题：

	比如现在有50人站成一个圈，编号从1-50，我规定从1开始报数，每次数到3的人退出，下一个人重新从1开始报数，直到最后一个人退出。

	编程思路就是考虑三种情况：
	
	- 数到这个人时，他已经被淘汰，则跳到下一个人，报数不增加。
	- 数到这个人时，他还未被淘汰，且刚好数到三，则将该数组元素值置为0，继续数下一个人且报数从0开始。
	- 数到这个人实，他还未被淘汰，但还未数到三，则继续数下一个人，报数增加1。
	
			int main(){
				int sum[100]={0};
				int n;  //people number
				int m=1;  //count number
				int remain; //people remained
				int i;
				scanf("%d",&n);
				remain=n;
				for(i=0;i<n;i++){
					sum[i]=i+1;
				}
				i=0;
				while(remain!=1){
					if( sum[i%n]==0  ){  		//如果这个人已经被淘汰了，那么不计数
						i=(i+1)%n;
					}
					else if(m==3){  		//如果数到三，且这个人未被淘汰
						sum[i%n]=0;
						remain--;
						m=1;
						i=(i+1)%n;
					}else{  				//如果这个人未被淘汰，但没数到3，则 m++,i=(i+1)%n 
						m++;
						i=(i+1)%n;
					}
				}
				for(i=0;i<n;i++){
					if(sum[i]) break;
				}
				printf("last winner: %d",i+1);
				return 0;
			} 

1. ### 给结构体数组排序的时候碰到的坑

	冒泡排序的核心代码：
	
		for(i=0 ; i<n-1 && flag ; i++){
			flag=0;
			for(j=0;j<n-1-i;j++){
				if(a[j]>a[j+1]){
					temp=a[j];
					a[j]=a[j+1];
					a[j+1]=temp;
					flag=1;
				}
			}
		}
		因为a[j]等价于*(a+j),所以结构体数组的冒泡排序很容易写成：
		for(i=0 ; i<n && flag ; ++i){
			flag=0;
			for(j=0;j<n-1-i;j++){
				if( *(p+j+1).score < *(p+j).score ）{
					temp=*(p+j);
					*(p+j)=*(p+j+1);
					*(p+j+1)=temp;
				}
				flag=1;
			}
		}

	但是总是报错：
	`[Error] request for member 'score' in something not a structure or union`，就是说score这个成员不在某个结构体或联合里面。
	如果改成`(p+j+1)->score < (p+j)->score)`程序当然就顺理成章了，但是原来那种写法为什么会出错？

	最后我将那句错误代码改成：`（*(p+j+1)）.score < （*(p+j)）.score`，程序就对了。所以呀，是因为' * ' 与 ' . ' 这两个运算符的优先级是不一样的，成员取值运算符（.或->）的优先级比取值运算符(*)的优先级要高。

	![C语言运算符优先级表](https://timgsa.baidu.com/timg?image&quality=80&size=b9999_10000&sec=1488523019342&di=a791157ebe2a4a6ee845abbb774425a4&imgtype=0&src=http%3A%2F%2Fimage64.360doc.com%2FDownloadImg%2F2013%2F09%2F0516%2F34997693_1.jpg)
	
	
	