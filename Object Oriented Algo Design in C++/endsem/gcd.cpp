//given an array of n elements finding gcd of the array using 2 way divide and conquer
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

class find_gcd
{
	public:
		find_gcd();
		int a_gcd(int p,int q);
		int array_gcd(int a[1000],int first,int last);
};

find_gcd::find_gcd()
{
	array array1;
	
	int result=array_gcd(array1.a,1,array1.size);
	cout<<"\nthe gcd of the given array is: "<<result<<endl;
}

int find_gcd::array_gcd(int a[100],int first,int last)
{
	int x=0,y=0,gcd=0;
	if(first==last)
	{
		gcd=a[first];
		return gcd;
	}
	else if(first+1==last)
	{
	 gcd=a_gcd(a[first],a[last]);
	 return gcd;
	}
	else
	{
	 int m=((first+last)/2);
	 x=array_gcd(a,first,m);
	 y=array_gcd(a,(m+1),last);

	 gcd=a_gcd(x,y);
	 return gcd;
	}
}

int find_gcd::a_gcd(int p,int q)
{
	if(p==0)
		return q;
	else
	return a_gcd(q%p,p);
}

int main()
{
	find_gcd find1;
}
