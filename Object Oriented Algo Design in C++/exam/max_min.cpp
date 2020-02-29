#include<iostream>
using namespace std;

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
	divide(int array[1000],int start,int end);
};

maxmin::maxmin()
{
	array array1;
	divide(array1.a,1,array1.size);
	findmax(
}

void maxmin::divide(int array[1000],int start,int end)
{
	if(start==end)
	{
	 max=a[start];
	 min=a[start];
	}
	else
	{
		mid=end/2;
		divide(array,start,mid);
		
		divide(array,mid+1,end);
		findmax(array,start,end,max,min);
	}
}

void findmax(int max1,int max2,int min1,int min2)
{
	if(start>end)
	max=max;
	min=min;
	
}
