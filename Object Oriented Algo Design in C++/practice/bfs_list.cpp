#include<iostream>
#include<list>
using namespace std;

class graph
{
	int v;
	list<int> *adj;
	public:
		graph(int v);
		void add_edge(int x,int y);
		void bfs(int s);
};

graph::graph(int v)
{
	this->v=v;
	adj=new list<int>[v+1];
}

graph::add_edge(int x,int y)
{
	adj[x].push_back(y);
}

void graph::bfs(int s)
{
	bool *visited=new bool[v+1];
	for(int i=1;i<=v;i++)
		visited[i]=false;
	list<int> queue;
	visited[s]=true;
	queue.push_back
}
