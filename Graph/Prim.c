#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

int visited[100]={0}, cost[100][100], min, mincost=0;
int input(int);
int display(int);
int prims(int);

int input(int num)
{
	int i, j;
	for(i=1; i<=num; i++)
	{
		for(j=1; j<=num; j++)
		{
			printf("Enter the Weight of edge from [%d] to [%d] : ",i,j);
			scanf("%d", &cost[i][j]);
		}
	}
	return 0;
}
int display(int num)
{
	int i, j;
	printf("\nAdjacency matrix :\n\n");
	for(i=1; i<=num; i++)
	{
		for(j=1; j<=num; j++)
		{
			printf("%d", cost[i][j]);
			printf("\t");
		}
		printf("\n");
	}
	return 0;
}

int prims(int num)
{
	int i, j, ne=1, a, b, u, v;
	for(i=1; i<=num; i++)
	{
		for(j=1; j<=num; j++)
		{
			if(cost[i][j]==0)
			cost[i][j]=999;
		}
	}
	visited[1]=1; 
    printf("\nNo. of edges(nodes - 1): %d\n",num-1);
	while(ne < num) 
	{
		for(i=1,min=999;i<=num;i++)
		for(j=1;j<=num;j++)
		if(cost[i][j]< min)
		if(visited[i]!=0)
		{
			min=cost[i][j];
			a=u=i; 
			b=v=j;
		}
		printf("\n Edge %d: [%d] -> [%d]  weight : %d",ne++,a,b,min);
 		mincost=mincost+min;
 		visited[b]=1;
		cost[a][b]=cost[b][a]=999;
	}
	printf("\n\n\n Minimun weight : %d",mincost);
    exit(0);
}
int main()
{
	int num;
	printf("\n\t\t\tPrim's Algorithm");
	printf("\n\nEnter the number of nodes : ");
	scanf("%d", &num);
	input(num);
	display(num);
	prims(num);
	getch();
	return 0;
}
