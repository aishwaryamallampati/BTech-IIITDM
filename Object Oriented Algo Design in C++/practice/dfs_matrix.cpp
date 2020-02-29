#include<iostream>
#include<cstdlib>
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
		void add_edge(int origin,int destin,int flag=0);
		void display();
		
		void dfs_traversal();
		void dfs(int s);
		
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

void adjacency_matrix::add_edge(int origin,int destin,int flag)
{
	//cout<<"origin="<<origin<<"destin="<<destin<<endl;
	if(origin>(n) ||destin>(n)||origin<0||destin<0)
	{
		cout<<"\ninvalid edge\n";
	}
	else if(flag==0)
	{
		adj[origin][destin]=1;
		adj[destin][origin]=1;
	}
	else if(flag==1)
	{
		adj[origin][destin]=1;
	}
}//adding edge to a graph

void adjacency_matrix::dfs(int s)
{
	int v;
	visited[s]=1;
	cout<<s<<" ";
	for(v=1;v<=n;v++)
	{
	 if(visited[v]==0&&adj[s][v]==1)
	 {
	  visited[v]=1;
	  dfs(v);
	 }
	}
	
}//dfs for each vertex

void adjacency_matrix::dfs_traversal()
{
	for(int i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
	 if(!visited[i])
		dfs(i);
	}
}// dfs traversal for entire grah and is useful when there are disconnected components

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
	int option;
	do
	{
	 cout<<"1.undirected graph\n2.directed graph\n0.exit\nchoose your option:";
	 cin>>option;
	 switch(option)
	 {
	  case 1:
		{
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
		cout<<"\nthe dfs traversal of the graph is :\n";
		am1.dfs_traversal();
		//am1.display();
		}
		break;
	 case 2:
		{
		cout<<"\nenter the number of nodes in the graph:";
		cin>>nodes;
		adjacency_matrix am2(nodes);
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
	  	 am2.add_edge(origin,destin,1);
		}
		cout<<"\nthe dfs traversal of the graph is :\n";
		am2.dfs_traversal();
		//am1.display();
		}
		break;
	case 0:
		break;
	}
	}while(!option);		
		
}
