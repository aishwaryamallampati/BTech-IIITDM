//using adjacency matrix and performing bfs travesal
//#include<iostream>
//#include<cstdlib>
#include "queue.h"

using namespace std;

#define MAX 20



class adjacency_matrix
{			
	private:
		int n;
		int **adj;
		bool *visited;
	public:
		adjacency_matrix(int n);
		void add_edge(int origin,int destin);
		void display();
		
		void bfs_traversal();
		void bfs(int s);
		//template <class t> queue<t>::queue(int n);
};

adjacency_matrix::adjacency_matrix(int n)
{
	this->n=n;
	visited=new bool[n+1];
	adj=new int *[n+1];
	for(int i=1;i<=n;i++)
	{
		//cout<<"entered";
		adj[i]=new int[n+1];
		for(int j=1;j<=n;j++)
		{
			adj[i][j]=0;
		}
	}
}//initializing an adjacnecy matrix

void adjacency_matrix::add_edge(int origin,int destin)
{
	//cout<<"origin="<<origin<<"destin="<<destin<<endl;
	if(origin>(n) ||destin>(n)||origin<0||destin<0)
	{
		cout<<"\ninvalid edge\n";
	}
	else
	{
		adj[origin][destin]=1;
		adj[destin][origin]=1;
	}
}//adding edge to a graph

void adjacency_matrix::bfs(int s)
{
	int v;
	queue<int> int_q1(50);
	int_q1.enqueue(s);
	while(!int_q1.isempty())
	{
	 s=int_q1.dequeue();
	 cout<<s<<" ";
	 visited[s]=1;
	 for(v=1;v<=n;v++)
	 {
	  if(visited[v]==0&&adj[s][v]==1)
	  {
		int_q1.enqueue(v);
		visited[v]=1;
	  }
	 }
	}
}

void adjacency_matrix::bfs_traversal()
{
	for(int i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
	 if(!visited[i])
		bfs(i);
	}
}

void adjacency_matrix::display()
{
	int i,j;
	for(int i=1;i<=n;i++)
	{
	 for(int j=1;j<=n;j++)
	 {
		cout<<adj[i][j]<<" ";
	 }
	  cout<<endl;
	}
}// to display graph in the form of adjacency matrix

int main()
{
	int nodes,max_nodes,origin,destin,edges;
	cout<<"\nenter the number of nodes in the graph:";
	cin>>nodes;
	adjacency_matrix am1(nodes);
	cout<<"\nenter the number of edges:";
	cin>>edges;
	max_nodes=nodes*(nodes-1);
	for(int i=1;i<=edges;i++)
	{
	 cout<<"\nenter edge(-1 -1 to exit):"<<endl;
	 cin>>origin;
	 cin>>destin;
	 //cout<<"origin="<<origin<<"destin="<<destin;
	 if(origin==-1 && destin==-1)
	 break;
	 am1.add_edge(origin,destin);
	}
	cout<<"\nthe bfs traversal of the graph is :\n";
	am1.bfs_traversal();
	//am1.display();
}
