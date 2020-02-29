#include <iostream>

using namespace std;

class graph
  {
     public:
	graph();
	int pop();
	void push(int);
	void dfs_from_vertex(int);
     private:
	int g[100][100],top,stack[100],visited[100],n,m,level[100],parent[100];
  };

graph::graph()
  {
	int index,index1,u,v,d;
	top=0;
	cout << "\nEnter no: of vertices:";
	cin >> n;
	cout << "\nEnter no: of edges:";
	cin >> m;
	for(index=1;index<=n;index++)
	  for(index1=1;index1<=n;index1++)
		g[index][index1]=0;
	cout << "Graph is directed or undirected(1/0):";
	cin >> d;
	cout << "\nEnter edges(u,v)" << endl;
	if(d==0)
	{ 
	for(index=1;index<=m;index++)
	  {
	     cin >> u >> v;
	     g[u][v]=1;
	     g[v][u]=1;
	  }
	}
	else
	{
	for(index=1;index<=m;index++)
	  {
	     cin >> u >> v;
	     g[u][v]=1;
	  }
	}
	for(index=1;index<=n;index++)
	  visited[index]=0;
	int source;
	cout << "\nEnter source vertex:";
	cin >> source;
	level[source]=1;
	//for(index=1;index<=n;index++)
	  //{
	    // if(visited[index]==0)
	       dfs_from_vertex(source);
	    cout << endl;
	  //}
	for(index=1;index<=n;index++)
	 cout << level[index] << " ";
	int max=1;
	for(index=2;index<=n;index++)
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
	dfs_from_vertex(max);
	cout << endl;
	/*for(index=1;index<=n;index++)
	 cout << level[index] << " ";
	cout << endl;
	
	for(index=1;index<=n;index++)
	 cout << parent[index] << " ";
	cout << endl;*/
	max=1;
	for(index=2;index<=n;index++)
	 {
	    if(level[index]>level[max])
	     max=index;
	 }
	cout << "Path:" << max << " ";
	index=max;
	while(parent[index]!=0)
	  {
	      cout << parent[index] << " ";
	      index=parent[index];
 	  }
	cout << endl;
  }

void graph::dfs_from_vertex(int v)
  {
	push(v);
	while(top!=0)
	 {
	    v=pop();
	    cout << "vertex:" << v << endl;
	    if(visited[v]==0)
	      {
		 visited[v]=1;
		 for(int w=1;w<=n;w++)
	          {
		    if(g[v][w]==1 && visited[w]==0)
		     {
		        push(w);
		        level[w]=level[v]+1;
			parent[w]=v;
		     }
	          }
	      }
	 }
  }

void graph::push(int v)
  {
	top=top+1;
	stack[top]=v;
  }

int graph::pop()
  {
	if(top==0)
	  {
	    cout << "\nStack is empty" << endl;
	  }
	else
	  {
	    int v=stack[top];
	    top=top-1;
	    return v;
	  }
  }

int main()
  {
	graph d1;
	return 0;
  }
