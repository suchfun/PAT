#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
typedef struct Node{
	int data;
	struct Node *next;
}Node; 
void main(){
	Node * head;
	head=(Node *)malloc(sizeof(Node));
	head->data=0;
 	head->next=NULL;
 	Node *L=head;
	 int i;
	 for(i=0;i<5;i++){
	 	Node *p;
	 	p=(Node *)malloc(sizeof(Node));
	 	p->data=5-i;
	 	p->next=NULL;
	 	
	 	L->next=p;
	 	L=L->next;
	 }
	 L=head;
//	while(L!=NULL){
//		printf("%d-",L->data);
//		L=L->next;
//	}
//	printf("\n");
//	L=head;
/*----------以上是初始化链表----------*/
	Node * newhead;
	newhead=(Node *)malloc(sizeof(Node));
	newhead->data=0;
	newhead->next=NULL;
	Node * LL=newhead;
	
	Node * min=head->next;
	Node * premin=head;
	Node * p,*q;
/*方法是：选出链表中最小的，然后加到一个新的链表中，并删除最小的这个Node（不然后面不好再选出第二小的值）*/
	for(i=0;i<5;i++){
		q=L;	//因为后面要删除节点，所以保存了所要删除节点的额前一个节点 
		p=L->next;
		while(p!=NULL){
			if(p->data<min->data){
				min=p;
				premin=q;
			}
			p=p->next;
			q=q->next;
		}		
		LL->next=min;
		LL=LL->next;    //将目前连标点额最小值尾插法插入新链表 
		premin->next=min->next;   //删除这个最小的Node 
		min=L->next;	//重新将最小的指针指向原先链表头结点的额下一个节点 
	}
	LL->next=NULL;
//	while(newhead!=NULL){
//		printf("%d-",newhead->data);
//		newhead=newhead->next;
//	}	
}
