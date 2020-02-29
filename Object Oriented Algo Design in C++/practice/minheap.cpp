#include <iostream>
#include <math.h>
using namespace std;



class heap
{
public:
	heap();
	int array[1000];
	int size;
	void heapify();
	void build_maxheap();
	void max_heapify(int size,int i);
	void heapsort();
	void display();
	void get_maxmin();
	void extract_min();
	void extract_max();
};

heap::heap()
{
	int index1;
	cout<<"\nenter the size of the array:";
	cin>>size;
	cout<<"\nenter the elements of the array: ";
	for(index1=1;index1<=size;index1++)
	 cin>>array[index1];
	heapify();
}

void heap::heapify()
{
	build_maxheap();
	heapsort();
	cout<<"\nthe heap array:"<<endl;
	 display();
}

void heap::build_maxheap()
{
	for(int i=size/2;i>=1;i--)
	 max_heapify(size,i);
	return;
}

void heap::max_heapify(int size,int i)
{
	int j,temp;
	temp=array[i];
	j=2*i;
	while(j<=size)
	{
	  if(j<size && array[j+1]<array[j])
	   j=j+1;
	  if(temp<array[j])
           break;
	  else if(temp>=array[j])
	  {
	   array[j/2]=array[j];
	   j=2*j;
	  }
	}
	array[j/2]=temp;
	return;
}

void heap::heapsort()
{
	int i,temp;
	for(i=size;i>=2;i--)
	{
		temp=array[i];
		array[i]=array[1];
		array[1]=temp;
		max_heapify(i-1,1);
	}
}

void heap::get_maxmin()
{
 	if(size<=1)
  	  return;
	else
	{
	 cout<<"\nthe maximum  of the given array is "<<array[1]<<endl;
	 cout<<"\nthe minimum  of the given array is "<<array[size]<<endl;
	}
 
}

void heap::extract_max()
{
	if(size<=0)
	 cout<<"the heap is empty\n";
	else if(size==1)
	{
	 size=size-1;
	 cout<<"\nthe maximum  extracted is "<<array[1]<<endl;
	}
	else
	{
	 int root=array[1];
	 array[1]=array[size];
	 size=size-1;
         cout<<"\nthe maximum  extracted is "<<root<<endl;
	}
}

void heap::extract_min()
{
	if(size<=0)
	 cout<<"the heap is empty\n";
	else if(size==1)
	{
	 size=size-1;
	 cout<<"\nthe minimum  extracted is "<<array[1]<<endl;
	}
	else
	{
	 cout<<"\nthe minimum extracted is "<<array[size]<<endl;
	 size=size-1;
	}
}


void heap::display()
{
	if(size<1)
	cout<<"the array is empty"<<endl;
	else
	{	
	 for(int i=1;i<=size;i++)
	  cout<<array[i]<<" ";
	 cout<<endl;
	}
}

main()
{
	int option;
	heap heap1;
	do
	{
	 cout<<"1.get max min\n2.extract min\n3.extract max\nenter your choice:";
	 cin>>option;
	 switch(option)
	 {
	 case 1:
	  heap1.get_maxmin();
	  break;
	 case 2:
	  heap1.extract_min();
	  cout<<"the heap array is:"<<endl;
	  heap1.display();
	  break;
	 case 3:
	  heap1.extract_max();
	  heap1.heapify();
	  break;
	 case 0:
	  break;
	 }
	}while(option!=0);
	
	
}#include <iostream>
using namespace std;

void build_maxheap(int array[1000],int size);
void heapsort(int array[1000],int size);
void max_heapify(int array[1000],int size,int i);

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

void build_maxheap(int array[1000],int size)
{
	for(int i=size/2;i>=1;i--)
	 max_heapify(array,size,i);
}

void max_heapify(int array[1000],int size,int i)
{
	int j,temp;
	temp=array[i];
	j=2*i;
	while(j<=size)
	{
	  if(j<size && array[j+1]<array[j])
	   j=j+1;
	  if(temp<array[j])
           break;
	  else if(temp>=array[j])
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

void display(int array[100],int size)
{
	for(int i=1;i<=size;i++)
	 cout<<array[i]<<" ";
	cout<<endl;
}

main()
{
	array array1;
	build_maxheap(array1.a,array1.size);
	heapsort(array1.a,array1.size);
	cout<<"\nthe heap array:"<<endl;
	display(array1.a,array1.size);
}
