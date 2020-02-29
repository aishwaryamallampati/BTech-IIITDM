#include<iostream>
#include<cstdlib>
#include<math.h>
#include<stdlib.h>
#include "queue.h"
queue<int> int_q1(50);
using namespace std;
void print_powerset(int *d,int *c,int set_size,int start);

int main()
{
int d[100],c[100],edges,i,origin,dest;
cout<<"\nenter the number of edges:";
cin>>edges;
for(i=0;i<edges;i++)
{
	cout<<"\nenter edge:";
	cin>>origin;
	cin>>dest;
	d[i]=origin;
	c[i]=dest;
}
print_powerset(d,c,edges,0);

}

void print_powerset(int  *d,int *c,int set_size,int start)
{
	int ed;
if(start>=set_size)
{
	while(!int_q1.isempty())
	{
	 int temp=int_q1.dequeue();
	}
	return;
}
else
{
for(int j=0;j<=set_size;j++)
{
	int_q1.display();
	cout<<"("<<d[j]<<","<<c[j]<<")";
	ed=((d[j])*10)+c[j];
	int_q1.enqueue(ed);
	print_powerset(d,c,set_size,start+1);
}
	
}


}
