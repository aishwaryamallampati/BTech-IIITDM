#include<iostream>
using namespace std;

class array
{
public:
	array();

	int a[1000];
	int size;
};

class maxheap1
{
public:
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


maxheap1 maxheap;

class heapsort
{
public:
	heapsort();
	void build_max_heap(int array[1000],int size);
	void max_heapify(int array[1000],int size,int i);
};

heapsort::heapsort()
{
	int temp;	
	array array1;
	build_max_heap(array1.a,array1.size);
	while(maxheap.size>2)
	{
		temp=maxheap.a[1];
		maxheap.a[1]=maxheap.a[maxheap.size-1];
		maxheap.a[maxheap.size-1]=temp;
		maxheap.size=(maxheap.size)-1;
		max_heapify(maxheap.a,maxheap.size,1);
	}
	
}

void heapsort::build_max_heap(int array[1000],int size)
{
	maxheap.size=size;
	for(int j=1;j<=size;j++)
	 	maxheap.a[j]=array[j];
	for(int i=(size-1)/2;i>=1;i--)
		max_heapify(maxheap.a,maxheap.size,i);

}

void heapsort::max_heapify(int array[1000],int size,int i)
{
	int l,r,largest,temp;
	largest=i;
	l=2*i;
	r=(2*i)+1;
	if(l<=size&&array[l]>array[i])
		largest=l;
	
	if(r<=size&&array[r]>array[largest])
		largest=r;

	if(largest!=i)
	{
	 temp=array[i];
	 array[i]=array[largest];
	 array[largest]=temp;
	 max_heapify(array,size,largest);
	}
}

main()
{		
	double total_time;
	clock_t start,end;
	start=clock();
	heapsort heapsort1;
	cout<<"the sorted array:"<<endl;
	for(int index2=1;index2<=5;index2++)
	 	cout<<maxheap.a[index2]<<" ";
	cout<<endl;
	end=clock();
	
	total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	cout<<"time taken for calculating no of posiibilites for given no of steps:"<<total_time<<endl;
	return 0;
}
