#include <stdio.h>
#include <stdlib.h>
#define MAX 4

void bfs(int adj[][MAX], int visited[],int start)
{
    int queue[MAX], rear=-1, front=-1, i;
    queue[++rear]=start;
    visited[start]=1;
    while(rear!=front)
    {
        start=queue[++front];
        if(start==4)
        printf("5 \t");
        else
        printf("%c \t",start + 65);
        for(i=0;i<MAX;i++)
        {
            if(adj[start][i]==1 && visited[i]==0)
            {
                queue[++rear]=i;
                visited[i]=1;
            }
        }
    }
}

void dfs(int adj[][MAX],int visited[],int start)
{
    int stack[MAX];
    int top=-1,i;
    printf("%c-",start+65);
    visited[start]=1;
    stack[++top]=start;
    while(top!=-1)
    {
        start=stack[top];
        for(i=0;i<MAX;i++)
        {
            if(adj[start][i]&& visited[i]==0)
            {
                stack[++top]=i;
                printf("%c-",i+65);
                visited[i]=1;
                break;
            }
        }
        if(i==MAX)
        top--;
    }
}

int main(){
    int visited[MAX]={0};
    int adj[MAX][MAX],i,j, startNode, opt;
    printf("\n Enter the adjacency matrix:");
    for(i=0;i<MAX;i++)
        for(j=0;j<MAX;j++)
            scanf("%d",&adj[i][j]);

    
    while(1 == 1){
        printf("----------BFS and DFS Implementation----------\n");
        printf("1.)BFS\n2.)DFS\n3.)Exit\n");
        scanf("%d", &opt);

        switch (opt){
            case 1:
                printf("\nEnter the start node for BFS\n");
                scanf("%d", &startNode);
                bfs(adj, visited, startNode);
                break;
            case 2:
                printf("\nEnter the start node for DFS\n");
                dfs(adj, visited, startNode);
                break;
            case 3:
                exit(0);
            default:
                printf("Please select a valid choice!!\n");
                break;
        }
    }
}