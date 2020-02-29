/* given n identifiers, objective is to find the minimum bst that can be formed with the given identifiers*/
#include<iostream>
using namespace std;

class opt_bst
{
	public:	
		opt_bst();
		string iden[100];
		float p[100],q[100];
		int n;
		float w[100][100],c[100][100];
		int r[100][100];//to store k value
		void find_bst();
		int find_k(int i,int j);
		void print_preorder(int i,int j);
		void print_inorder(int i,int j);
};

opt_bst::opt_bst()
{
	cout<<"\nenter the number of identifiers:";
	cin>>n;
	cout<<"\nenter the identifiers:";
	for(int index=1;index<=n;index++)
	{
	 cin>>iden[index];
	}
	cout<<"\nenter the values of p respectively:";
	for(int index1=1;index1<=n;index1++)
	{
	 cin>>p[index1];
	}
	cout<<"\nenter the values of q respectively:";
	for(int index1=0;index1<=n;index1++)
	{
	 cin>>q[index1];
	}
	find_bst();
	cout<<"\nthe optimal bst in preorder is:";
	print_preorder(0,n);
	cout<<endl;
	cout<<"\nthe optimal bst in inorder is:";
	print_inorder(0,n);
	cout<<endl;
}

void opt_bst::find_bst()
{
	for(int i=0;i<n;i++)
	{
		w[i][i]=q[i];
		r[i][i]=0;
		c[i][i]=0;
		w[i][i+1]=q[i]+q[i+1]+p[i+1];
		r[i][i+1]=i+1;
		c[i][i+1]=q[i]+q[i+1]+p[i+1];
	}
	w[n][n]=q[n];
	r[n][n]=0;
	c[n][n]=0;
	for(int m=2;m<=n;m++)
	{
	 for(int i=0;i<=n-m;i++)
	 {
	  int j=i+m;
	  w[i][j]=w[i][j-1]+p[j]+q[j];
	  int k=find_k(i,j);//to find minimum for k ranging from i+1 to j
	  r[i][j]=k;
	  c[i][j]=w[i][j]+c[i][k-1]+c[k][j];
	 }
	}
}

int opt_bst::find_k(int i,int j)
{
	float min=1000000;
	int m,l;
	
	for(m=i+1;m<=j;m++)
	{
	 if(c[i][m-1]+c[m][j]<min)
	 {
		min=c[i][m-1]+c[m][j];
		l=m;
	 }
	}
	return l;
}

void opt_bst::print_preorder(int i,int j)
{
	if(i<j)
	 cout<<iden[r[i][j]]<<" ";
	else
	 return;
	print_preorder(i,r[i][j]-1);
	print_preorder(r[i][j],j);
}

void opt_bst::print_inorder(int i,int j)
{
	print_preorder(i,r[i][j]-1);
	if(i<j)
	 cout<<iden[r[i][j]]<<" ";
	else
	 return;
	print_preorder(r[i][j],j);
}

main()
{
	opt_bst bst1;
	return 0;
}

