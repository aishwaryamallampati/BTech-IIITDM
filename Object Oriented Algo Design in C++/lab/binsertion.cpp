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


class insertionsort
{
	public:
		insertionsort();
		int binsearch(int a[1000],int item,int low,int high);
		void display(int a[1000],int size);
};

insertionsort::insertionsort()
{
	int index1,index2,key,location;
	array array1;
	for(index2=2;index2<=array1.size;index2++)
	{
	 key=array1.a[index2];
	 index1=index2-1;
	 location=binsearch(array1.a,key,1,index1);
	 while(index1>=location)
	 {
 	  array1.a[index1+1]=array1.a[index1];
	  index1--;
	 }
	 array1.a[index1+1]=key;
	}
	display(array1.a,array1.size);
}

int insertionsort::binsearch(int a[1000],int item,int low,int high)
{
	int mid;	
	if(low>=high)
	{
	 if(item>a[low])
	 return low+1;
	 else
	 return low;
	}
	mid=(low+high)/2;
	if(item==a[mid])
	 return mid+1;
	else if(item<a[mid])
	 binsearch(a,item,low,mid-1);
	else if(item>a[mid])
	 binsearch(a,item,mid+1,high);
} 

void insertionsort::display(int a[1000],int size)
{
	int index1;
	cout<<"\nthe sorted array using binary search insertion sort is: ";
	for(index1=1;index1<=size;index1++)
	 	cout<<a[index1]<<" ";
	cout<<endl;
}
	
main()
{		
	double total_time;
	clock_t start,end;
	start=clock();
	insertionsort sorter1;
	end=clock();
	
	total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	cout<<"time taken for sort using binary search insertionsort:"<<total_time<<endl;
	return 0;
}
