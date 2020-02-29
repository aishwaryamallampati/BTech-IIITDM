#include<iostream>
#include<new>
using namespace std;

int main()
{
	int i,n;
	int *p,*q;
	cout<<"\nenter the size of the array:";
	cin>>n;
	p=new (nothrow) int[n];
	for(i=0;i<n;i++)
	{
		cout<<"\nenter number:";
		cin>>p[i];
	}
	for(i=0;i<n;i++)
	{
		cout<<p[i];
	}
	cout<<endl;
	q=new (nothrow) int[2];
	for(i=0;i<2;i++)
	{
	 q[i]=p[i];
	}
	//q[2]=p[n];
	for(i=0;i<2;i++)
	{
		cout<<q[i];
	}
	cout<<endl;
	delete[] p;
	delete[] q;
	return 0;
}
