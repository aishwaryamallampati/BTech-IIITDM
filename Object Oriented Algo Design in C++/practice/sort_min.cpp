#include<iostream>
#include<time.h>

using namespace std;


class array
{
public:
	array();

	int a[100];
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

class sorter
{
	public:
		sorter();
		int findmax(int a[100],int start,int size);
};

sorter::sorter()
{
	int index1,result,start,hold;
	array array1;
	for(index1=0;index1<array1.size;index1++)
		array1.a[index1]=-(array1.a[index1]);
	for(start=0;start<array1.size;start++)
	{
	 result=findmax(array1.a,start,array1.size);	
	 hold=array1.a[start];
	 array1.a[start]=array1.a[result];
	 array1.a[result]=hold;
	}
	for(index1=0;index1<array1.size;index1++)
		array1.a[index1]=-(array1.a[index1]);
	cout<<"\nthe sorted array using min is: ";
	for(index1=0;index1<array1.size;index1++)
	 cout<<array1.a[index1]<<" ";
	 cout<<endl;
}

int sorter::findmax(int a[100],int start,int size)
{
	int index1,max,max_i;
	max=a[start];
	max_i=start;
	for(index1=start+1;index1<size;index1++)
	{
	 if(max<a[index1])
	  {
	   max=a[index1];
	   max_i=index1;
	  }
	}
	return max_i;
}

		

int main()
{
	double total_time;
	clock_t start,end;
	start=clock();
	sorter sorter1;
	end=clock();
	total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	cout<<"time taken:"<<total_time<<endl;
	return 0;
}

