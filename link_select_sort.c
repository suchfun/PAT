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
/*----------�����ǳ�ʼ������----------*/
	Node * newhead;
	newhead=(Node *)malloc(sizeof(Node));
	newhead->data=0;
	newhead->next=NULL;
	Node * LL=newhead;
	
	Node * min=head->next;
	Node * premin=head;
	Node * p,*q;
/*�����ǣ�ѡ����������С�ģ�Ȼ��ӵ�һ���µ������У���ɾ����С�����Node����Ȼ���治����ѡ���ڶ�С��ֵ��*/
	for(i=0;i<5;i++){
		q=L;	//��Ϊ����Ҫɾ���ڵ㣬���Ա�������Ҫɾ���ڵ�Ķ�ǰһ���ڵ� 
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
		LL=LL->next;    //��Ŀǰ��������Сֵβ�巨���������� 
		premin->next=min->next;   //ɾ�������С��Node 
		min=L->next;	//���½���С��ָ��ָ��ԭ������ͷ���Ķ���һ���ڵ� 
	}
	LL->next=NULL;
//	while(newhead!=NULL){
//		printf("%d-",newhead->data);
//		newhead=newhead->next;
//	}	
}
