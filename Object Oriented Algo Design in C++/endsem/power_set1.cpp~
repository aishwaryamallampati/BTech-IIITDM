#include<iostream>
#include<cstdlib>
#include<math.h>
#include<stdlib.h>
using namespace std;
void print_powerset(int *d,int *c,int set_size);

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
print_powerset(d,c,edges);

}

void print_powerset(int  *d,int *c,int set_size)
{
unsigned int power_set_size=pow(2,set_size);
int counter,j;
for(counter=0;counter<power_set_size;counter++)
{
for(j=0;j<set_size;j++)
{
	if(counter&1<<j)
		cout<<"("<<d[j]<<","<<c[j]<<")";
}
cout<<endl;
}
}
