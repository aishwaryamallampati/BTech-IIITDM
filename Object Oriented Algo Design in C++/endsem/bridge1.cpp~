//given a graph finding the edges to be removed to make it disconnected
#include "stack.h"
#include<math.h>
#include<stdlib.h>
using namespace std;
int k=0;


#define MAX 20

class graph
{			
	private:
		int n;
		
		int **g;//to store input edges
		int **g1;
		bool *visited;//to traverse the graph 
		int *d;
		int *c;
		int visited_vertices;
	public:
		int edges;

		graph(int n);
		void add_edge(int origin,int destin,int flag=0);
		void display();
		void power_set(int set_size);
		void dfs(int s);
};

graph::graph(int n)
{
	this->n=n;
	visited=new bool[n+1];
	d=new int[n+1];
	c=new int[n+1];
	g=new int *[n+1];
	g1=new int *[n+1];
	for(int i=1;i<=n;i++)
	{
	 g[i]=new int[n+1];
	 g1[i]=new int[n+1];
	 for(int j=1;j<=n;j++)
   	 {
		g[i][j]=0;
		g1[i][j]=0;
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
		d[k]=origin;
		c[k]=destin;
		k++;
		g[destin][origin]=1;
	}
	else if(flag==1)
	{
		g[origin][destin]=1;
	}
}//adding edge to a graph

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
	for(int i=1;i<=edges;i++)
	{
	 cout<<"("<<d[i]<<","<<c[i]<<") ";
	}
	
}// to display graph in the form of adjacency matrix

void graph::power_set(int set_size)
{
	stack<int> int_s1(50);
 	int r=0,index,index1,ed;
        unsigned int power_set_size=pow(2,set_size);
	int counter,j;
	cout<<"\nthe bridges are:\n";
	for(counter=0;counter<power_set_size;counter++)
	{
	 visited_vertices=0;
	 for(index=1;index<=n;index++)
	 {
		visited[index]=0;
	  for(index1=1;index1<=n;index1++)
	  {
		 g1[index][index1]=g[index][index1];
		 g1[index1][index]=g[index1][index];
	  }
	 }
	for(j=0;j<set_size;j++)
	{
	 if(counter&1<<j)
	 {
		//cout<<"("<<d[j]<<","<<c[j]<<")";
		ed=((d[j])*10)+c[j];
		int_s1.push(ed);
		g1[d[j]][c[j]]=0;
		g1[c[j]][d[j]]=0;
	 }
	}
	dfs(1);
	if(visited_vertices<n)
	{
	 while(!int_s1.isempty())
	 {
	  int temp1=int_s1.pop();
	  cout<<"("<<(temp1/10)<<","<<(temp1%10)<<") ";
	 }
	}
	else if(visited_vertices==n)
	{
	 while(!int_s1.isempty())
	 {
	  int temp1=int_s1.pop();
	  //cout<<(temp1/10)<<"->"<<(temp1%10)<<" ";
	 }
	}
	 cout<<endl;
	}
 
}

void graph::dfs(int s)
{
	int v;
	if(visited[s]==0)
	{
	visited[s]=1;
	visited_vertices++;
	}
	//cout<<s<<" ";
	for(v=1;v<=n;v++)
	{
	 if(visited[v]==0&&g1[s][v]==1)
	 {
	  visited[v]=1;
	  visited_vertices++;
	  dfs(v);
	 }
	}
	
}//dfs for each vertex





int main()
{
	int nodes,max_nodes,origin,destin,edges;
	int option;
	cout<<"\nenter the number of nodes in the graph:";
	cin>>nodes;
	graph g1(nodes);
	cout<<"\nenter the number of edges:";
	cin>>edges;
	g1.edges=edges;
	
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
	g1.power_set(edges);
}
