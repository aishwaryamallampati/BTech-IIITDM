#include <iostream>
#include <math.h>
using namespace std;

void build_maxheap(int array[1000],int size);
void heapsort(int array[1000],int size);
void max_heapify(int array[1000],int size,int i);
void min_at_end(int array[1000],int size);
void get_maxmin(int array[1000],int size);
void extract_max(int array[1000],int size);
void display(int array[1000],int size);

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

class heap
{
	int array[1000];
	int size;
}

heap::heap()
{
	int index1;
	cout<<"\nenter the size of the array:";
	cin>>size;
	cout<<"\nenter the elements of the array: ";
	for(index1=1;index1<=size;index1++)
	 cin>>array[index1];
	build_maxheap();

}

void build_maxheap(int array[1000],int size)
{
	for(int i=size/2;i>=1;i--)
	 max_heapify(array,size,i);
}

void max_heapify(int array[1000],int size,int i)
{
	int j,temp,k;
	cout<<"size in max heapify "<<size<<endl;
	temp=array[i];
	j=2*i;
	k=j;
	while(j<=size)
	{
	  if(j<size && array[j+1]>array[j])
	   j=j+1;
	  if(temp>array[j])
           break;
	  else if(temp<=array[j])
	  {
	   array[j/2]=array[j];
	   j=2*j;
	  }
	}
	array[j/2]=temp;
	return;
}

void heapsort(int array[1000],int size)
{
	int i,temp;
	for(i=size;i<=2;i--)
	{
		temp=array[i];
		array[i]=array[1];
		array[1]=temp;
		max_heapify(array,i-1,1);
	}
}

void min_at_end(int array[1000],int size)
{
	int i,h,min_index,temp,start,end;
	h=4;
	min_index=1;
	start=pow(2,h)-1;
	end=pow(2,(h-2));
	//start=((2^(h))-1);
	//end=(2^(h-2));
	cout<<"start="<<start<<" "<<"end="<<end<<endl;
	for(i=start;i>=end;i--)
	{
	 if(i<=size&& array[i]<array[min_index])
	 {
	  	min_index=i;
	  cout<<"i="<<i<<endl;
	  cout<<"min index="<<min_index<<endl;
	 }
	}
	temp=array[size];
	array[size]=array[min_index];
	array[min_index]=temp;
}

void get_maxmin(int array[1000],int size)
{
 	if(size<=1)
  	  return;
	else
	{
	 cout<<"\nthe maximum  of the given array is "<<array[1]<<endl;
	 cout<<"\nthe minimum  of the given array is "<<array[size]<<endl;
	}
 
}

void extract_max(int array[1000],int size)
{
	if(size<=0)
	 cout<<"the heap is empty\n";
	else if(size==1)
	{
	 size=size-1;
	 cout<<"\nthe maximum  of the given array is "<<array[1]<<endl;
	}
	else
	{
	 int root=array[1];
	 array[1]=array[size];
	 size=size-1;
	 cout<<"size="<<size<<endl;
	 max_heapify(array,size,1);
	 min_at_end(array,size);
	 cout<<"\nthe maximum  of the given array is "<<root<<endl;
	 cout<<"\nthe heap array:"<<endl;
	 display(array,size);
	}
}
void display(int array[100],int size)
{
	for(int i=1;i<=size;i++)
	 cout<<array[i]<<" ";
	cout<<endl;
}

main()
{
	int option;
	array array1;
	build_maxheap(array1.a,array1.size);
	heapsort(array1.a,array1.size);
	min_at_end(array1.a,array1.size);
	cout<<"\nthe heap array:"<<endl;
	display(array1.a,array1.size);
	do
	{
	 cout<<"1.get max min\n2.extract max\nenter your choice:";
	 cin>>option;
	 switch(option)
	 {
	 case 1:
	  get_maxmin(array1.a,array1.size);
	  break;
	 case 2:
	  extract_max(array1.a,array1.size);
	  break;
	 case 0:
	  break;
	 }
	}while(option!=0);
	
	
}
