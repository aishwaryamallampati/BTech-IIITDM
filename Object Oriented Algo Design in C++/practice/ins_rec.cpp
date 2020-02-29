/*to sort the given array using recursive insertion sort*/
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

class insertionsorter
{
	public:
		insertionsorter();
		void insertion1(int array1[1000],int size,int n);
};

insertionsorter::insertionsorter()
{
	int index1;
	array array1;
	insertion1(array1.a,array1.size,2);
	cout<<"\nthe sorted array in increasing order is: ";
	for(index1=1;index1<=array1.size;index1++)
	 cout<<array1.a[index1]<<" ";
	 cout<<endl;
}

void insertionsorter::insertion1(int array1[1000],int size,int n)
{
	int i,j,index1,key;
	
	if(n>size)
	{
	 cout<<"\nthe sorted array in increasing order using recursive-insertion sort is: ";
	 for(int index1=1;index1<=size;index1++)
	 cout<<array1[index1]<<" ";
	 cout<<endl;
	}
	 
	else
	{
	 
	  key=array1[n];
	  cout<<"key="<<key<<" ";
	  i=n-1;
	  while(i>0 && array1[i]>key) 
	  {
		array1[i+1]=array1[i];
		i=i-1;
	  }
	  array1[i+1]=key;
	  insertion1(array1,size,n+1);
	}
	
	
}

main()
{
	double total_time;
	clock_t start,end;
	start=clock();
	insertionsorter isorter1;
	end=clock();
	total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	cout<<"time taken by insertion sort:"<<total_time<<endl;
	return 0;
}
	


