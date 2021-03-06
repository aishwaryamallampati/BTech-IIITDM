//using bfs to test for a cycle:graph is cyclic if e[n]==0
//#include<iostream>
//#include<cstdlib>
#include "queue.h"

using namespace std;

#define MAX 20



class adjacency_matrix
{			
	private:
		int n;
		int **graph_edge;
		int **tree_edge;
		int **non_tree_edge;
		bool *visited;
	public:
		adjacency_matrix(int n);
		void add_edge(int origin,int destin);
		void display();
		
		void bfs_traversal();
		void bfs(int s);

		int graph_edges,tree_edges;
		void test_cycle();
		//template <class t> queue<t>::queue(int n);
};

adjacency_matrix::adjacency_matrix(int n)
{
	this->n=n;
	visited=new bool[n+1];
	graph_edge=new int *[n+1];
	tree_edge=new int *[n+1];
	non_tree_edge=new int *[n+1];
	for(int i=1;i<=n;i++)
	{
		//cout<<"entered";
		graph_edge[i]=new int[n+1];
		tree_edge[i]=new int[n+1];
		non_tree_edge[i]=new int[n+1];
		for(int j=1;j<=n;j++)
		{
			graph_edge[i][j]=0;
			tree_edge[i][j]=0;
			non_tree_edge[i][j]=0;
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
		graph_edge[origin][destin]=1;
		graph_edge[destin][origin]=1;
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
	  if(visited[v]==0&&graph_edge[s][v]==1)
	  {
		int_q1.enqueue(v);
		visited[v]=1;
		tree_edge[s][v]=1;
		tree_edge[v][s]=1;
		tree_edges++;
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
	test_cycle();
}

void adjacency_matrix::test_cycle()
{
	if(graph_edges>tree_edges)
	cout<<"\nthe graph contains cycles"<<endl;
	else
	cout<<"\nthe graph does not contain cycles"<<endl;
}

void adjacency_matrix::display()
{
	int i,j;
	for(int i=1;i<=n;i++)
	{
	 for(int j=1;j<=n;j++)
	 {
		cout<<graph_edge[i][j]<<" ";
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
	am1.graph_edges=edges;
	am1.tree_edges=0;
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
