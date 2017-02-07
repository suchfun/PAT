#include<stdio.h>
#include <stdlib.h>
#define maxSize 10



typedef struct ArcNode{
	int adjvex;//该边所指向的节点的位置 
	struct ArcNode *nextarc;//指向下一条边的指针 
}ArcNode;

typedef struct VNode{
	ArcNode *firstarc;
}VNode;

typedef struct AGraph{
	VNode adjlist[maxSize];
	int n,e;
}AGraph;
/*
邻接表：
0->1->3->4 
1->4->2
2->0
3->2
4
*/
int visit[maxSize];
AGraph *agraph;  //注意，定义了指针一定要给一个地址，不然这个指针就不知道指向哪里了 
ArcNode arcs[7];	//不需要给arcs一个地址，只需要初始化，如果没有初始化，编译器会随意赋值 
void initAGraph(){
	int *j;
	int i;
	for(i=0;i<maxSize;i++)	visit[i]=0;
	agraph=(AGraph*)malloc(sizeof(AGraph));
	arcs[0].adjvex=1;arcs[0].nextarc=&arcs[1];
	arcs[1].adjvex=3;arcs[1].nextarc=&arcs[2];
	arcs[2].adjvex=4;arcs[2].nextarc=NULL;
	arcs[3].adjvex=4;arcs[3].nextarc=&arcs[4];
	arcs[4].adjvex=2;arcs[4].nextarc=NULL;
	arcs[5].adjvex=0;arcs[5].nextarc=NULL;
	arcs[6].adjvex=2;arcs[6].nextarc=NULL;
		
	agraph->adjlist[0].firstarc=&arcs[0];
	agraph->adjlist[1].firstarc=&arcs[3];
	agraph->adjlist[2].firstarc=&arcs[5];
	agraph->adjlist[3].firstarc=&arcs[6];
	agraph->adjlist[4].firstarc=NULL;
	agraph->e=7;
	agraph->n=5;

}
int i=0;
void DFS(AGraph *G, int v){
	
	ArcNode *p;
	visit[v]=1;printf("%d  ",v);
	p=G->adjlist[v].firstarc;
	while(p!=NULL){
		if(visit[p->adjvex]==0)	DFS(G,p->adjvex);
		p=p->nextarc;
	}
}
void main(){

	initAGraph();
	DFS(agraph,0);
}
