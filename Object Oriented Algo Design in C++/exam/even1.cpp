/*given an array count the no of even numbers by using divide and conquer*/
#include<iostream>
using namespace std;

static int count=0;
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

class even
{
	public:
		even();
		void check(int array[1000],int start,int end);
};

even::even()
{
	array array1;
	check(array1.a,1,array1.size);
	cout<<"\nthe total number of even numbers in the given array is: "<<count;
	cout<<endl;
}

void even::check(int array[100],int start,int end)
{
	if(start==end)
	{
	 if((array[start]%2)==0)
		count++;
	 
	 
	}
	else if(start<end)
	{
	 
	 int mid=(start+end)/2;
	 
	 check(array,start,mid);
	 
	 check(array,mid+1,end);
	}
}

main()
{
	even even1;
	return 0;
}
