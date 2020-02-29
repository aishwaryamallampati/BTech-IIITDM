#include "queue.h"
#include<math.h>
#include<stdlib.h>
#include<time.h>
using namespace std;
int k=0;


#define MAX 20

class graph
{			
	public:
		int n;
		int good;
		int **g;//to store input edges
		bool *visited;//to traverse the graph 
		int *indeg;
		int *outdeg;
		int max_deg;
		int max_deg_vertex;
		int visited_vertices;
		int leaf_node;
	
		int edges;

		graph(int n);
		void add_edge(int origin,int destin,int flag=0);
		void display();
		//void power_set(int set_size);
		void dfs(int s);
		void generate();
		void generate_degree();
		void check();
		void bfs(int s);
};

graph::graph(int n)
{
	this->n=n;
	visited=new bool[n+1];
	indeg=new int[n+1];
	outdeg=new int[n+1];
	g=new int *[n+1];
	for(int i=1;i<=n;i++)
	{
	 g[i]=new int[n+1];
	 for(int j=1;j<=n;j++)
   	 {
		g[i][j]=0;
	 }
	}
}//initializing an adjacnecy matrix

void graph::add_edge(int origin,int destin,int flag)
{
	//cout<<"origin="<<origin<<"destin="<<destin<<endl;
	if(origin>(n) ||destin>(n)||origin<0||destin<0)
	{
		cout<<"\ninvalid edge\n";
	}
	else if(flag==0)
	{
		g[origin][destin]=1;
		g[destin][origin]=1;
	}
	else if(flag==1)
	{
		g[origin][destin]=1;
		//gtranspose[destin][origin]=1;
	}
}//adding edge to a grap

void graph::generate()
{
	visited_vertices=0;
	for(int i=1;i<=n;i++)
	{
	 visited[i]=0;
	 for(int j=1;j<=n;j++)
	 {
	 	if(i<j)
		{
		 g[i][j]=rand()%1;
		 cout<<g[i][j];
		 g[j][i]=g[i][j];
		}
	 }
	}
}

void graph::check()
{
	dfs(1);
	if(visited_vertices==n)
	{
	 good=1;
	}
	else
	{
	 good=0;
	}
}

void graph::dfs(int s)
{
	int v;
	if(visited[s]==0)
	{
	visited[s]=1;
	//cout<<s<<" ";
	visited_vertices++;
	}
	for(v=1;v<=n;v++)
	{
	 if(visited[v]==0&&g[s][v]==1)
	 {
	  visited[v]=1;
	  visited_vertices++;
	  dfs(v);
	 }
	}
	
}//dfs for each vertex

void graph::bfs(int s)
{
	int v;
	queue<int> int_q1(50);
	int_q1.enqueue(s);
	while(!int_q1.isempty())
	{
	 s=int_q1.dequeue();
	 while(s!=max_deg_vertex)
	 {
	  s=int_q1.dequeue();
	 }
	 cout<<s<<" ";
	 visited[s]=1;
	 max_deg=0;
	 max_deg_vertex=0;
	 for(v=1;v<=n;v++)
	 {
	  if(visited[v]==0&&g[s][v]==1)
	  {
		int_q1.enqueue(v);
		indeg[v]=indeg[v]-1;
		if(indeg[v]==0)
			leaf_node++;
		if(indeg[v]>max_deg)
		{
		 	max_deg=indeg[v];
			max_deg_vertex=v;
		}
		visited[v]=1;
	  }
	 }
	}
}


void graph::generate_degree()
{
	for(int i=1;i<=n;i++)
	{
	 indeg[i]=0;
	 outdeg[i]=0;
	}
	max_deg=0;
	max_deg_vertex=1;
	for(int i=1;i<=n;i++)
	{
	 for(int j=1;j<=n;j++)
	 {
		indeg[i]=g[j][i]+indeg[i];
		outdeg[i]=g[i][j]+outdeg[i];
		if(indeg[i]>max_deg)
		{
			max_deg=indeg[i];
			max_deg_vertex=i;
		}
	 }
	}
}

main()
{
	int size,i,c=0,nodes,origin,destin,edges;
	size=20;
	time_t t;
	time(&t);
	srand((unsigned int)t);
	int count;
	/*
	for(count=0;count<100;count++)
	{
	 graph g1(size);
	 g1.visited_vertices=0;
	 g1.generate();
	 g1.check();
	 if(g1.good==1)
	 {
	  cout<<"\nthe graph is connected\n";
	  g1.generate_degree();
	  for(i=1;i<=size;i++)
	  	g1.visited[i]=0;
	  g1.leaf_node=0;
	  g1.bfs(g1.max_deg_vertex);
	  cout<<"\nthe number of leaves is:"<<g1.leaf_node<<endl;
	 }
	 else
	 {
	  cout<<"\nthe graph is not connected\n";
	  c++;
	 }
	 
	}
	cout<<c<<endl;*/

		cout<<"\nenter the number of nodes in the graph:";
		cin>>nodes;
		graph g1(nodes);
		cout<<"\nenter the number of edges:";
		cin>>edges;
		//max_nodes=nodes*(nodes-1);
		for(int i=1;i<=edges;i++)
		{
	 	 cout<<"\nenter edge(-1 -1 to exit):"<<endl;
	 	 cin>>origin;
	 	 cin>>destin;
	 	 //cout<<"origin="<<origin<<"destin="<<destin;
	         if(origin==-1 && destin==-1)
	 	 break;
	  	 g1.add_edge(origin,destin);
		}
	 //if(g1.good==1)
	 {
	  cout<<"\nthe graph is connected\n";
	  g1.generate_degree();
	  for(i=1;i<=size;i++)
	  	g1.visited[i]=0;
	  g1.leaf_node=0;
	  cout<<g1.max_deg_vertex<<endl;
	  g1.bfs(g1.max_deg_vertex);
	  cout<<"\nthe number of leaves is:"<<g1.leaf_node<<endl;
	 }
	 /*else
	 {
	  cout<<"\nthe graph is not connected\n";
	  c++;
	 }*/
}
