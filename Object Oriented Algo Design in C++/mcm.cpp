#include<iostream>
#include<cstdlib>
#include<time.h>
int n;
int m[50][50];
int s[50][50];

dp_mcm
{
	dp_mcm(int p[100]);
};

dp_mcm::dp_mcm(int p[100])
{
	int m[50][50];
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

}



main()
{
	
	n=20;
	int p[50];
	cout<<"\nthe p array[dimensions] is:"<<endl;
	for(int i=0;i<=n;i++)
	{
	 p[i]=(rand%10)+1;
	 cout<<p[i]<<" ";
	}
	cout<<endl;
	dp_mcp(p);
	greedy_mcm(p,0,n);
}

