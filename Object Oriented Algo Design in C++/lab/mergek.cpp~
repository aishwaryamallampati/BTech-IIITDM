#include<iostream>
using namespace std;

class array_create
{
public:
	//array_create();

	int a[1000];
	int size;
};

/*array_create::array_create()
{
	int index1;
	cout<<"\nenter the size of the array:";
	cin>>size;
	cout<<"\nenter the elements of the array: ";
	for(index1=1;index1<=size;index1++)
	 cin>>a[index1];
}*/

class heap
{
public:
	heap();
	int array[1000];
	//int size;

	int k;
	int list[100];

	void heapify();
	void build_minheap();
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
	int i=1;
	cout<<"\nenter the number of sorted lists: ";
	cin>>k;
	for(int i=1;i<=k;i++)
	{
	 cout<<"\nfor "<<i<<":"<<endl;
       	 array_create list[i];
	 cout<<"\nenter the size of the array:";
	 cin>>list[i].size;
	 cout<<"\nenter the elements of the array: ";
	 for(index1=1;index1<=list[i].size;index1++)
	  cin>>list[i].a[index1];
	}
	display();
	//heapify();
}

void heap::display()
{
	for(int i=1;i<=k;i++)
	{
	 cout<<"\nfor "<<i<<":"<<endl;
       	 //reate list[i];
	 //cout<<"\nenter the size of the array:";
	 //cin>>list[i].size;
	 //cout<<"\nenter the elements of the array: ";
	 cout<<list[i].size;
	 //for(index1=1;index1<=list[i].size;index1++)
	  //cout<<list[i].a[index1];
	//cout<<endl;
	}
}

main()
{
	heap heap1;
}
