#include <iostream>
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
