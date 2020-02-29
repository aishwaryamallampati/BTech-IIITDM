/*#include<iostream>
#include<cstdlib>
using namespace std;*/

#include "stack.h"


#define MAX 20



class graph
{			
	private:
		int n;
		
		int **g;//to store input edges
		int **gtranspose;
		bool *visited;//to traverse the graph 
		int *dfsnum;//to find articulation pts and bridges
		int *low;
		int *parent;
		int *cut_vertex;
		int *cut_bridge_source;
		int *cut_bridge_dest;
		int *level;

		
		int num;
		int cut_bridges;
	
		
		
		
	public:
		//int edges;		
		
		graph(int n);
		void add_edge(int origin,int destin,int flag=0);
		void display();
		
		void dfs_traversal(stack<int> &int_s1);
		void dfs(int s,stack<int> &int_s1,int f=0);
	
		void print_cutvertices();
		void print_cutbridges();
		void print_ssc();
		void dfs_transpose(int s);
		void tree_longest_path();
		void print_bcc();
};

graph::graph(int n)
{
	this->n=n;
	visited=new bool[n+1];
	g=new int *[n+1];
	gtranspose=new int *[n+1];
	for(int i=1;i<=n;i++)
	{
		//cout<<"entered";
		g[i]=new int[n+1];
		gtranspose[i]=new int[n+1];
		for(int j=1;j<=n;j++)
		{
			g[i][j]=0;
			gtranspose[i][j]=0;
		}
	}
	dfsnum=new int[n+1];
	low=new int[n+1];
	parent=new int[n+1];
	cut_vertex=new int[n+1];
	cut_bridge_dest=new int[100];
	cut_bridge_source=new int[100];
	level=new int[100];
	num=0;
	cut_bridges=0;
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
		gtranspose[destin][origin]=1;
	}
}//adding edge to a graph

void graph::dfs(int s,stack<int> &int_s1,int f)
{
	if(f==1)
	{
	 //cout<<"enter";
	 int v;
	 int ed;
	 int temp1;
	 int temp2;
	 int children;
	 children=0;
	 visited[s]=1;
	 num=num+1;
	 dfsnum[s]=low[s]=num;
	 for(v=1;v<=n;v++)
	 {
	  if(g[s][v]==1)
	  {
	   if(visited[v]==0)
	   {
	   children++;
	   visited[v]=1;
	   parent[v]=s;
	   ed=(s*10)+v;
	   //cout<<ed<<endl;
	   int_s1.push(ed);
	   dfs(v,int_s1,1);
	   if(low[v]<low[s])
		low[s]=low[v];
	   temp2=(10*s)+v;
	   if((dfsnum[s]==1&&children>1) ||(dfsnum[s]>1&&low[v]>=dfsnum[s]))
	   {
		temp1=int_s1.top_value();
		while(temp1!=temp2)
		{
	 	 cout<<(temp1/10)<<"->"<<(temp1%10)<<" ";
		 int_s1.pop();
		 temp1=int_s1.top_value();
		}
		cout<<(temp1/10)<<"->"<<(temp1%10)<<" ";
		int_s1.pop();
		cout<<endl;
		//count++;
	   }
	 }
	 else if(visited[v]==1&&v!=parent[s] && dfsnum[v]<low[s])
	 {
		if(dfsnum[v]<low[s])
			low[s]=dfsnum[v];
	 	int ed=(s*10)+v;
		//cout<<"ed="<<ed<<" ";
		int_s1.push(ed);
	 }
	}
	}
	}		 
	
	else
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
	 if(visited[v]==0)
	 {
	  if(g[s][v]==1)
	  {
	  children++;
	  //visited[v]=1;
	  level[v]=level[s]+1;
	  parent[v]=s;
	  dfs(v,int_s1);
	  
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
	 
	 }
	 else
	 {
	  
	  if(g[s][v]==1&&parent[s]!=v )//(u,v) is a back edge
	 {
	  if(dfsnum[v]<low[s])
		low[s]=dfsnum[v];
	 }
	 }
	
	}
	int_s1.push(s);//to print strongly connected components
	}
	
	 	
		
}//dfs for each vertex

void graph::dfs_traversal(stack<int> &int_s1)
{
	for(int i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
	 if(!visited[i])
	 {
		level[i]=1;
		dfs(i,int_s1);
	 }
	}
	//cout<<"parent[1]="<<parent[1]<<endl;
}// dfs traversal for entire grah and is useful when there are disconnected components

void graph::dfs_transpose(int s)
{
	int v;
	visited[s]=1;
	cout<<s<<" ";
	
	for(v=1;v<=n;v++)
	{
	 if(visited[v]==0&&gtranspose[s][v]==1)
	 {
	  dfs_transpose(v);
	 }
	}
	
}

void graph::display()
{
	int i,j;
	for(int i=1;i<=n;i++)
	{
	 for(int j=1;j<=n;j++)
	 {
		cout<<g[i][j]<<" ";
	 }
	  cout<<endl;
	}
}// to display graph in the form of adjacency matrix

void graph::print_cutvertices()
{
	cout<<"\nfor the given graph the cut vertices are:";
	for(int i=1;i<=n;i++)
	{
	 if(cut_vertex[i]==1)
	 cout<<i<<" ";
	}
	cout<<endl;
}

void graph::print_cutbridges()
{
	cout<<"\nfor the given graph the cut bridges are:";
	for(int i=1;i<=cut_bridges;i++)
	{
	 cout<<"("<<cut_bridge_source[i]<<","<<cut_bridge_dest[i]<<") ";
	}
	cout<<endl;
	
}

void graph::print_ssc()
{
	stack<int> int_s1(50);
	dfs_traversal(int_s1);
	cout<<"\nthe strongly connected components are:\n";
	for(int i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	/*while(!int_s1.isempty())
	{
	 cout<<int_s1.pop()<<" ";
	}
	cout<<endl;*/
	while(!int_s1.isempty())
	{
	 //cout<<"enter";
	 int value=int_s1.pop();
	 if(visited[value]==0)
	 {
	  dfs_transpose(value);
	  cout<<endl;
	 }
	 
	}
	
	
}

void graph::print_bcc()
{
	cout<<"\nthe biconnected components are:\n";
	stack<int> int_s1(50);
	for(int i=1;i<=n;i++)
	{
		visited[i]=0;
	}
	for(int i=1;i<=n;i++)
	{
	 if(!visited[i])
	 {
		parent[i]=0;
		level[i]=1;
		dfs(i,int_s1,1);
	 }
	 int j=0;
	/* while(!int_s1.isempty())
	{
	 cout<<int_s1.pop()<<" ";
	}
	cout<<endl;*/
	/*for(int i=1;i<=n;i++)
	{
	 cout<<i<<" parent="<<parent[i]<<" ";
	}*/
	 while(!int_s1.isempty())
	 {
	  j=1;
	  int temp1=int_s1.pop();
	  cout<<(temp1/10)<<"->"<<(temp1%10)<<" ";
	 }
	 if(j=1)
	 {
	  cout<<endl;
	  //count++;
	 }
	}
	
}

void graph::tree_longest_path()
{
	int index;
	stack<int> int_s1(50);
	dfs_traversal(int_s1);
	cout<<endl;

	int max=1;
	for( index=2;index<=n;index++)
	 {
	    if(level[index]>level[max])
	     max=index;
	 }
	for(index=1;index<=n;index++)
	 {
	   visited[index]=0;
	   parent[index]=0;
	   level[index]=0;
	 }
	level[max]=1;
	parent[max]=0;
	dfs(max,int_s1);
	cout << endl;

	max=1;
	for(index=2;index<=n;index++)
	 {
	    if(level[index]>level[max])
	     max=index;
	 }
	cout << "Longest Path:" << max << " ";
	index=max;
	while(parent[index]!=0)
	  {
	      cout << parent[index] << " ";
	      index=parent[index];
 	  }
	cout << endl;
}

int main()
{
	int nodes,max_nodes,origin,destin,edges;
	int option;
	do
	{
	 cout<<"1.articulation points\n2.bridges\n3.biconnected components\n4.strongly connected componets\n5.tree longest path\n0.exit\nchoose your option:";
	 cin>>option;
	 switch(option)
	 {
	  case 1:
		{
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
		stack<int> int_s1(50);
		cout<<"\nthe dfs traversal of the graph is :\n";
		g1.dfs_traversal(int_s1);
		g1.print_cutvertices();
		//am1.print_cutbridges();
		//am1.display();*/
		}
		break;
	 case 2:
		{
		cout<<"\nenter the number of nodes in the graph:";
		cin>>nodes;
		graph g2(nodes);
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
	  	 g2.add_edge(origin,destin);
		}
		stack<int> int_s1(50);
		cout<<"\nthe dfs traversal of the graph is :\n";
		g2.dfs_traversal(int_s1);
		//g1.print_cutvertices();
		g2.print_cutbridges();
		//am1.display();*/
		}
		break;
	 case 3:
		{
		cout<<"\nenter the number of nodes in the graph:";
		cin>>nodes;
		graph g3(nodes);
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
	  	 g3.add_edge(origin,destin);
		}
		//stack<int> int_s1(50);
		//cout<<"\nthe dfs traversal of the graph is :\n";
		//g2.dfs_traversal(int_s1);
		//g1.print_cutvertices();
		//g2.print_cutbridges();
		//am1.display();*/
		g3.print_bcc();
		}
		break;
	 case 4:
		{
		cout<<"\nenter the number of nodes in the graph:";
		cin>>nodes;
		graph g4(nodes);
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
	  	 g4.add_edge(origin,destin,1);
		}
		cout<<"\nthe dfs traversal of the graph is :\n";
		g4.print_ssc();
		//am1.display();
		}
		break;
	case 5:
		{
		cout<<"\nenter the number of nodes in the graph:";
		cin>>nodes;
		graph g5(nodes);
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
	  	 g5.add_edge(origin,destin);
		}
		stack<int> int_s1(50);
		cout<<"\nthe dfs traversal of the graph is :\n";
		g5.tree_longest_path();
		}
		break;
	case 0:
		break;
	}
	}while(!option);		
		
}
