#include<iostream>
#include<cstdlib>
using namespace std;

#define MAX 20



class adjacency_matrix
{			
	private:
		int n;
		
		int **adj;//to store input edges
		bool *visited;//to traverse the graph 
		int *dfsnum;//to find articulation pts and bridges
		int *low;
		int *parent;
		int *cut_vertex;
		int *cut_bridge_source;
		int *cut_bridge_dest;

		
		int num;
		int cut_bridges;
		
		
	public:
		//int edges;		

		adjacency_matrix(int n);
		void add_edge(int origin,int destin,int flag=0);
		void display();
		
		void dfs_traversal();
		void dfs(int s,int [],int []);
	
		void print_cutvertices();
		void print_cutbridges();
		
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
	dfsnum=new int[n+1];
	low=new int[n+1];
	parent=new int[n+1];
	cut_vertex=new int[n+1];
	cut_bridge_dest=new int[100];
	cut_bridge_source=new int[100];
	num=0;
	cut_bridges=0;
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

void adjacency_matrix::dfs(int s, int dfsnum[100],int low[100])
{
	int v;
	int children;
	children=0;
	num=num+1;
	dfsnum[s]=low[s]=num;
	visited[s]=1;
	cout<<s<<" ";//(dfsnum="<<dfsnum[s]<<" l="<<low[s]<<") ";
	for(v=1;v<=n;v++)
	{
	 if(visited[v]==0&&adj[s][v]==1)
	 {
	  children++;
	  //visited[v]=1;
	  parent[v]=s;
	  dfs(v,dfsnum,low);
	  //cout<<"enter="<<v<<" "<<low[v]<<" "<<dfsnum[v]<<" "<<dfsnum[s]<<" ";
	  if(low[v]>=dfsnum[s])
	  {
		//cout<<"\nenter\n";
		cut_vertex[s]=1;
		//cout<<"\ncut vertex="<<s<<endl;
		
		if(low[v]>dfsnum[s])
		{
		 cut_bridges=cut_bridges+1;
		 cut_bridge_source[cut_bridges]=s;
		 cut_bridge_dest[cut_bridges]=v;
		}
	  }
	  if(low[v]<low[s])
		low[s]=low[v];

	  if(parent[s]==0&&children>1)
	  	cut_vertex[s]=1;
	  else if(parent[s]==0&&children<=1)
		cut_vertex[s]=0;//conditions for root to be a cut vertex
	 }
	 else if(adj[s][v]==1&&parent[s]!=v )//(u,v) is a back edge
	 {
	  if(dfsnum[v]<low[s])
		low[s]=dfsnum[v];
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
		dfs(i,dfsnum,low);
	}
	//cout<<"parent[1]="<<parent[1]<<endl;
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

void adjacency_matrix::print_cutvertices()
{
	cout<<"\nfor the given graph the cut vertices are:";
	for(int i=1;i<=n;i++)
	{
	 if(cut_vertex[i]==1)
	 cout<<i<<" ";
	}
	cout<<endl;
}

void adjacency_matrix::print_cutbridges()
{
	cout<<"\nfor the given graph the cut bridges are:";
	for(int i=1;i<=cut_bridges;i++)
	{
	 cout<<"("<<cut_bridge_source[i]<<","<<cut_bridge_dest[i]<<") ";
	}
	cout<<endl;
	
}

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
		am1.print_cutvertices();
		am1.print_cutbridges();
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
