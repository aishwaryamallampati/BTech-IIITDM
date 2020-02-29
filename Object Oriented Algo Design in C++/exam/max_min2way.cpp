#include<iostream>
using namespace std;

static int min1=1000000;
static int max1=-10000000;
int used[1000]={0};

class array
{
public:
	array();

	int a[1000];
	int size;
};

array::array()
{
	int index1;
	cout<<"\nenter the size of the array:";
	cin>>size;
	cout<<"\nenter the elements of the array: ";
	for(index1=1;index1<=size;index1++)
	 cin>>a[index1];
}

class maxmin
{
	public:
		maxmin();
		void find(int array[1000],int start,int end);
};

maxmin::maxmin()
{
	array array1;
	find(array1.a,1,array1.size);
	cout<<"\nmax="<<max1;
	cout<<"\nmin="<<min1;
}

void maxmin::find(int array[100],int start,int end)
{
	if(start==end)
	{
	 if(max1<array[start])
		max1=array[start];
	 if(min1>array[start])
		min1=array[start];
	}
	else if(start<end)
	{
	 
	 int mid=(start+end)/2;
	 
	 find(array,start,mid);
	 
	 find(array,mid+1,end);
	
	}
}

main()
{
	maxmin maxmin1;
	return 0;
}

