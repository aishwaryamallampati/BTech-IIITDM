#include<iostream>
#include<math.h>
using namespace std;
static int count=0;

class point
{
public:
	point();
	int combination[100];
	
	int array[100];
	int x[100],y[100];
	int xi[100],yi[100];
	int size;
	int l;
	void symmetric();
	int search(int start,int keyx,int keyy);
	void combinations(int depth,int combination[100],int start,int a[100],int len);
};



point::point()
{
	int i=0,j=0,half;
	float lmin,rmin,min,min2;
	l=1;
	cout<<"\nenter the number of points: ";
	cin>>size;
	cout<<"\nenter the points:";
	for(i=1;i<=size;i++)
		cin>>array[i];
	combinations(1,combination,1,array,size);
	
}

void point::symmetric()
{
	int i,j,result;
	for(i=1;i<l;i++)
	{
	 xi[i]=y[i];
	 yi[i]=x[i];
	if(xi[i]!=yi[i])
	{
	 for(j=i+1;j<l;j++)
	 {
		result=search(j,xi[i],yi[i]);
		if(result==1)
		{
			cout<<"\n"<<"("<<x[i]<<","<<y[i]<<") and ("<<xi[i]<<","<<yi[i]<<")form a symmetric pair\n";
			count++;
		}	  	
	 }
	} 
	else if(xi[i]==yi[i])
	{
	 cout<<"\n"<<"("<<x[i]<<","<<y[i]<<") and ("<<xi[i]<<","<<yi[i]<<")form a symmetric pair\n";
			count++;
	}
	}
	
}

int point::search(int start,int keyx,int keyy)
{
	for(int p=start;p<l;p++)
	{
	 if(x[p]==keyx&&y[p]==keyy)
		return 1;
	 else
	 	return 0;
	}
}

void point::combinations(int depth,int combination[100],int start,int a[100],int len)
{
	l=1;
	int j,i;
	unsigned int pow_set_size=pow(2,len);
	for(int counter=start;counter<=pow_set_size;counter++)
	{
	 for(int m=start;m<=len;m++)
	 {
	  	if(counter&(1<j))
		 	combination[depth]=a[m];
		for(i=1;i<=depth;i++)
		{	
	 	for(j=1;j<=depth;j++)
	 	{	
		x[l]=combination[i];
		y[l]=combination[j];
		l++;
	 	}	
		}
		cout<<"\ngiven input:";
		for(j=1;j<l;j++)
		{
	 	cout<<"("<<x[j]<<","<<y[j]<<")"<<" ";
		}
		cout<<endl;
		symmetric();
		cout<<"the total no of symmetric pairs is "<<count<<endl;
		
		cout<<combination<<endl;
		depth++;
	 }
	}
	
}

main()
{
	point point1;
	return 0;
}

