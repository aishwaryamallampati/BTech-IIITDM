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

class sorter
{
	public:
		sorter();
		void sort_max(int a[1000],int start,int size);
		void sort_min(int a[1000],int start,int size);
		int findmax(int a[1000],int start,int size);
};

sorter::sorter()
{
	int index1,result,start,hold,end;
	array array1;
	end=(array1.size)-1;
	
	 for(start=0;start<((array1.size)/2);start++)
	 {
	
		sort_max(array1.a,start,end+1);
	 
	 	sort_min(array1.a,start+1,end+1);
		end--;
	 }
	
	
	cout<<"\nthe sorted array using max and min alternatively is: ";
	for(index1=0;index1<array1.size;index1++)
	 cout<<array1.a[index1]<<" ";
	 cout<<endl;
}

void sorter::sort_max(int a[1000],int start,int size)
{
	int result,hold;
	result=findmax(a,start,size);	
	  hold=a[start];
	  a[start]=a[result];
	  a[result]=hold;
}

void sorter::sort_min(int a[1000],int start,int size)
{
	int result,hold,index1;
	for(index1=start;index1<size;index1++)
		a[index1]=-(a[index1]);
	result=findmax(a,start,size);	
	  hold=a[size-1];
	  a[size-1]=a[result];
	  a[result]=hold;
	for(index1=start;index1<size;index1++)
		a[index1]=-(a[index1]);
}

int sorter::findmax(int a[1000],int start,int size)
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

		

main()
{
	double total_time;
	clock_t start,end;
	start=clock();
	sorter sorter1;
	end=clock();
	total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	cout<<"time taken for sort using max and min:"<<total_time<<endl;
	return 0;
}

