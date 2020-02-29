/*sorting the given elements using merge sort*/
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

class mergesorter
{
	public:
		mergesorter();
		void mergesort(int a[1000],int p,int r);
		void merge(int a[1000],int p,int q,int r);
};

mergesorter::mergesorter()
{
	array array1;
	
	mergesort(array1.a,1,array1.size);
	cout<<"the sorted array:"<<endl;
	for(int i=1;i<=array1.size;i++)
	 cout<<array1.a[i]<<" ";
	cout<<endl;
}

void mergesorter::mergesort(int a[1000],int p,int r)
{
	int q;	
	if(p<r)
	{
	 q=(p+r)/2;
	 mergesort(a,p,q);
	 mergesort(a,q+1,r);
	 merge(a,p,q,r);
	}
}

void mergesorter::merge(int a[1000],int p,int q,int r)
{
	int n1,n2,i,j,k;
	int l[500],ri[500];
	n1=q-p+1;
	n2=r-q;
	for(i=1;i<=n1;i++)
		l[i]=a[p+i-1];

	cout<<"leftarray: ";
	for(i=1;i<=n1;i++)
		cout<<l[i]<<" ";
	cout<<endl;
	
	for(j=1;j<=n2;j++)
		ri[j]=a[q+j];

	cout<<"right array:";
	for(j=1;j<=n2;j++)
		cout<<ri[j]<<" ";
	cout<<endl;

	l[n1+1]=1000;
	ri[n2+1]=1000;
	i=1;
	j=1;
	for(k=p;k<=r;k++)
	{
	 if(l[i]<=ri[j])
	 {
		a[k]=l[i];
		i=i+1;
	 }
	 else
	 {
	  a[k]=ri[j];
	  j=j+1;
	 }
	}

	cout<<"array:";
	for(k=p;k<=r;k++)
	 cout<<a[k]<<" ";
	cout<<endl;
}

main()
{
	mergesorter mergesorter1;
	return 0;
}	
