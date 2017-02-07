#include<stdio.h>

#define N 5
#define INF 100

typedef struct MGraph{
	int edges[N][N];
	int n,e;
}MGraph;

MGraph G; 

void initMGraph(){
	G.e=8;G.n=N;
	G.edges[0][0]=INF;G.edges[0][1]=5;G.edges[0][2]=1;G.edges[0][3]=2;G.edges[0][4]=INF;
	G.edges[1][0]=5;G.edges[1][1]=INF;G.edges[1][2]=3;G.edges[1][3]=INF;G.edges[1][4]=4;
	G.edges[2][0]=1;G.edges[2][1]=3;G.edges[2][2]=INF;G.edges[2][3]=6;G.edges[2][4]=2;
	G.edges[3][0]=2;G.edges[3][1]=INF;G.edges[3][2]=6;G.edges[3][3]=INF;G.edges[3][4]=3;
	G.edges[4][0]=INF;G.edges[4][1]=4;G.edges[4][2]=2;G.edges[4][3]=3;G.edges[4][4]=INF;
}

int	prime(MGraph G,int v0){
	int sum=0;
	int cost[N],visit[N];
	int i,j,min,temp;
	for(i=0;i<N;i++){
		visit[i]=0;
		cost[i]=G.edges[v0][i];
	}
	visit[v0]=1;printf("%d  ",v0);
	for(i=1;i<N;i++){
		min=INF;
		for(j=0;j<N;j++){
			if(visit[j]==0&&cost[j]<min){
				min=cost[j];
				temp=j;
			}
		}
		visit[temp]=1;printf("%d  ",temp);
		sum+=min;
		for(j=0;j<N;j++){
			if(visit[j]==0&&G.edges[temp][j]<cost[j])
				cost[j]=G.edges[temp][j];
		}
	}
	printf("\n%d",sum);
}

void main(){
	initMGraph(G);
	prime(G,0);
	getchar();
} 
