#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;

int n;
int m[50][50];
int s[50][50];

class dp_mcm
{
	public:
	dp_mcm(int p[100]);
	void print_parens(int s[50][50],int i,int j);
};

dp_mcm::dp_mcm(int p[100])
{
	int m[50][50];
	int q;
	for(int i=1;i<=n;i++)
		m[i][i]=0;
	for(int l=2;l<=n;l++)
	{
	 for(int i=1;i<=(n-l+1);i++)
	 {
	  int j=i+l-1;
	  m[i][j]=10000000;
	  for(int k=i;k<j;k++)
	  {
		q=m[i][k]+m[k+1][j]+p[i-1]*p[k]*p[j];
		if(q<m[i][j])
		{
			m[i][j]=q;
			s[i][j]=k;
		}
	  }
	 }
	}
	cout<<"\nthe optimal solution using dp is:"<<endl;
	print_parens(s,1,n);
	cout<<"\nthe cost using dp is :"<<m[1][n];
	
}

void dp_mcm:: print_parens(int s[50][50],int i,int j)
{
	if(i==j)
	cout<<"A"<<i;
	else
	{
		cout<<"(";
		print_parens(s,i,s[i][j]);
		print_parens(s,s[i][j]+1,j);
		cout<<")";
	}
}

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
	key=(y-x)/2;//key can be any arbitrary value
	int key_product=1000000;
	 if(x==y)
	cout<<"A"<<x;
	else if(x==y-1)
	cout<<"A"<<y;
	else if(x==y-2)
	cout<<"(A"<<x+1<<" A"<<y<<")";
	else
	{
	 for(int i=x+1;i<=(y-1);i++)
	 {
	  int q=p[x]*p[i]*p[y];
		if(q<key_product)
		{
			key=i;
			key_product=q;
		}
	 }
	 /*if(p[x]!=p[y])
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
	else*/
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
	
	n=20;
	time_t t;
	time(&t);
	srand((unsigned int)t);
	
	for(int j=1;j<=10;j++)
	{
	 int p[50]={0};
	cout<<"\nthe p array[dimensions] for input "<<j<<" is:"<<endl;
	for(int i=0;i<=n;i++)
	{
	 p[i]=(rand()%10)+1;
	 cout<<p[i]<<" ";
	}
	cout<<endl;
	dp_mcm input1(p);
	cout<<endl;
	//cout<<"the cost using dp is :"<<m[1][n];
	cout<<"\nthe solution using greedy is:"<<endl;
	greedy_mcm input2(p);
	cout<<endl;
	}
}

