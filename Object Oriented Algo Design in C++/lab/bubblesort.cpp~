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
	for(index1=0;index1<size;index1++)
	 cin>>a[index1];
}

class bubblesorter
{
	public:
		bubblesorter();
};

bubblesorter::bubblesorter()
{
	int pass,index1,hold;
	array array1;
	for(pass=1;pass<array1.size;pass++)
	{
	 for(index1=0;index1<array1.size-1;index1++)
	 {
	  if(array1.a[index1]>array1.a[index1+1])
	       {	
	  	hold=array1.a[index1];
		array1.a[index1]=array1.a[index1+1];
		array1.a[index1+1]=hold;
	       }
 	 }
	}
	cout<<"\nthe sorted array in increasing order is: ";
	for(index1=0;index1<array1.size;index1++)
	 cout<<array1.a[index1]<<" ";
	 cout<<endl;
}

main()
{
	double total_time;
	clock_t start,end;
	start=clock();
	bubblesorter bsorter1;
	end=clock();
	total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	cout<<"time taken for bubble sort:"<<total_time<<endl;
	return 0;
}
	
