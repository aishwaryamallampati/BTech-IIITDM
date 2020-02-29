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
};

insertionsorter::insertionsorter()
{
	int i,j,index1,key;
	array array1;
	for(j=2;j<=array1.size;j++)
	{
	 key=array1.a[j];
	 i=j-1;
	 while(i>0 && array1.a[i]>key)
	 {
		array1.a[i+1]=array1.a[i];
		i=i-1;
	 }
	 array1.a[i+1]=key;
	}
	cout<<"\nthe sorted array in increasing order is: ";
	for(index1=1;index1<=array1.size;index1++)
	 cout<<array1.a[index1]<<" ";
	 cout<<endl;
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
	


