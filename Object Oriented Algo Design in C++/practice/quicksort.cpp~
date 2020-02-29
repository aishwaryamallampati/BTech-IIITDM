/*sorting the given elements using quick sort*/
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

class quicksorter
{
	public:
		quicksorter();
		void quicksort(int a[1000],int p,int r);
		int partition(int a[1000],int p,int r);
};

quicksorter::quicksorter()
{
	array array1;
	cout<<"\nthe partitions are: "<<endl;
	quicksort(array1.a,1,array1.size);
	cout<<"the sorted array:"<<endl;
	for(int i=1;i<=array1.size;i++)
	 cout<<array1.a[i]<<" ";
	cout<<endl;
}

void quicksorter::quicksort(int a[1000],int p,int r)
{
	int q;	
	if(p<r)
	{
	 q=partition(a,p,r);
	 quicksort(a,p,q-1);
	 quicksort(a,q+1,r);
	}
}

int quicksorter::partition(int a[1000],int p,int r)
{
	int x,i,j,k,temp;
	x=a[r];
	i=p-1;
	for(j=p;j<r;j++)
	{
	 if(a[j]<=x)
	 {
		i=i+1;
		temp=a[i];
		a[i]=a[j];
		a[j]=temp;
	 }
	}
	temp=a[i+1];
	a[i+1]=a[r];
	a[r]=temp;

	for(k=p;k<=r;k++)
	 cout<<a[k]<<" ";
	cout<<endl;
	return i+1;
}

main()
{
	quicksorter quicksorter1;
	return 0;
}	
