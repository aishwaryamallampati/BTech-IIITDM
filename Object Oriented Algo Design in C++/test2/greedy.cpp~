#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int n;

class greedy_mcm
{
	public:
	greedy_mcm(int p[50]);
	void g_mcm(int p[50],int x,int y);
};

greedy_mcm::greedy_mcm(int p[50])
{
	g_mcm(p,0,n);
}

void greedy_mcm::g_mcm(int p[50],int x,int y)
{
	int key;
	key=x+y/2;//key can be any arbitrary value
	if(x==y-1)
	cout<<"A"<<y;
	else if(x==y-2)
	cout<<"(A"<<x+1<<" A"<<y<<")";
	else
	{
	 for(int i=x+1;i<=(y-1);i++)
	 {
		if(p[key]>p[i])
		{
			key=i;
		}
	 }
	 if(p[x]!=p[y])
	 {
		if(p[x]<p[key])
		{
			key=x;		
		}
	}
	 if(p[y]<p[key])
	 {
		key=y;
	 }
	
	if(key==x)
	{
	 cout<<"(";
	g_mcm(p,x,y-1);
	cout<<" ";
	g_mcm(p,y-1,y);
	cout<<")";
	}
	if(key==y)
	 {
	 cout<<"(";
	 g_mcm(p,x,x+1);
	 cout<<" ";
	 g_mcm(p,x+1,y);
	 cout<<")";
	}	
	else
	 {
	 cout<<"(";
	 g_mcm(p,x,key);
	 cout<<" ";
	 g_mcm(p,key,y);
	 cout<<")";
	 }		
	 
	}
}

main()
{
	
	n=10;
	int p[50];
	cout<<"\nthe p array[dimensions] is:"<<endl;
	for(int i=0;i<=n;i++)
	{
	 p[i]=(rand()%10)+1;
	 cout<<p[i]<<" ";
	}
	cout<<endl;
	//dp_mcm input1(p);
	greedy_mcm input2(p);
}
