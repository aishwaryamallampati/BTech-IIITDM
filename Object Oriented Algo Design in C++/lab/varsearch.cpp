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

class search
{
	public:
		search();
		int findkey(int a[1000],int key,int position);		
};

search::search()
{
	int index1,result,start,hold,end,key;
	array array1;
	end=(array1.size);
	cout<<"\nenter the element to be searched: ";
	cin>>key;
	 for(start=1;start<=((array1.size)/2)+1;start++)
	 {
	
		result=findkey(array1.a,key,start);
		if(result!=0)
		 break;
	 
	 	result=findkey(array1.a,key,end);
		if(result!=0)
		 break;

		end--;
	 }
	
	if(result!=0)
	cout<<"\nthe key is present in the array at position:"<<result;
	else
	cout<<"\nthe key is not present in the array";
}

int search::findkey(int a[1000],int key,int position)
{
	if(key==a[position])
	 return position;
	else
	 return 0;
}

main()
{
	double total_time;
	clock_t start,end;
	start=clock();
	search search1;
	end=clock();
	total_time=((double)(end-start))/(CLOCKS_PER_SEC);
	cout<<"\ntime taken for searching an element in the given array:"<<total_time<<endl;
	return 0;
} 
