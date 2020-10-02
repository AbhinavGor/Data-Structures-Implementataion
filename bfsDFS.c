#include<stdio.h>
#include<stdlib.h>
 
#define MAX 100  
 
#define initial 1
#define waiting 2
#define visited 3
 
int n;   
int G[MAX][MAX];
int visit[MAX];
int adj[MAX][MAX];
int state[MAX]; 
void createGraph();
void BF_Traversal();
void BFS(int v);
 
int queue[MAX], front = -1,rear = -1;
void insertQueue(int vertex);
int delete_queue();
int isEmpty();
void DFS(int i)
{
    int j;
	printf("\n%d",i);
    visit[i]=1;
	
	for(j=0;j<n;j++)
       if(!visit[j]&&G[i][j]==1)
            DFS(j);
}
 
int main()
{
    int i,j, ch;
    while(1) {
        printf("----------BFS and DFS----------\n");
        printf("1.)BFS\n2.)DFS\n3.)Exit\n");
        scanf("%d", &ch);
        switch(ch) {
        case 1:
            createGraph();
	        BF_Traversal();      
            break;
        case 2:
            printf("Enter number of vertices:");
   
            scanf("%d",&n);
    
            printf("\nEnter adjecency matrix of the graph:");
        
            
            for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                    scanf("%d",&G[i][j]);
    
        for(i=0;i<n;i++)
                visit[i]=0;
        
            DFS(0);
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice, enter correct choice...");
        }
    }
	
	return 0;
}
 
void BF_Traversal()
{
	int v;
	
	for(v=0; v<n; v++) 
		state[v] = initial;
	
	printf("Enter Start Vertex for BFS: \n");
	scanf("%d", &v);
	BFS(v);
}
 
void BFS(int v)
{
	int i;
	
	insertQueue(v);
	state[v] = waiting;
	
	while(!isEmpty())
	{
		v = delete_queue( );
		printf("%d ",v);
		state[v] = visited;
		
		for(i=0; i<n; i++)
		{
			if(adj[v][i] == 1 && state[i] == initial) 
			{
				insertQueue(i);
				state[i] = waiting;
			}
		}
	}
	printf("\n");
}
 
void insertQueue(int vertex)
{
	if(rear == MAX-1)
		printf("Queue Overflow\n");
	else
	{
		if(front == -1) 
			front = 0;
		rear = rear+1;
		queue[rear] = vertex ;
	}
}
 
int isEmpty()
{
	if(front == -1 || front > rear)
		return 1;
	else
		return 0;
}
 
int delete_queue()
{
	int delete_item;
	if(front == -1 || front > rear)
	{
		printf("Queue Underflow\n");
		exit(1);
	}
	
	delete_item = queue[front];
	front = front+1;
	return delete_item;
}
 
void createGraph()
{
	int count,maxEdge,origin,destin;
 
	printf("Enter number of vertices : ");
	scanf("%d",&n);
	maxEdge = n*(n-1);
 
	for(count=1; count<=maxEdge; count++)
	{
		printf("Enter edge %d( -1 -1 to quit ) : ",count);
		scanf("%d %d",&origin,&destin);
 
		if((origin == -1) && (destin == -1))
			break;
 
		if(origin>=n || destin>=n || origin<0 || destin<0)
		{
			printf("Invalid edge!\n");
			count--;
		}
		else
		{
			adj[origin][destin] = 1;
		}
	}
}