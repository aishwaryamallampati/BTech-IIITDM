//given an array of integers or floating numbers or strings, program to find max and second max in n+logn-2 comparisons using function templates, hashing and dynamic arrays
#include<iostream>
#include<string>
#include<math.h>
#include<cstdio>
#include<cstdlib>
#include<new>

using namespace std;
int n;//size
int p;

//creating and inserting elements into a hash table

const int table_size=100;

template <class t>
class linkedhashentry
{
	private:
	int key;
	t value;
	linkedhashentry *next;
	public:
	linkedhashentry(int key,t value)
	{
		this->key=key;
		this->value=value;
		this ->next=NULL;
	}
	int getkey()
	{
	 return key;
	}
	t getvalue()
	{
	 return value;
	}
	t setvalue(t value)
	{
	 this->value=value;
	}
	linkedhashentry<t> *getnext()
	{
	 return next;
	}
	void setnext(linkedhashentry *next)
	{
		this->next=next;
	}
};

template <class t>
class hashmap
{
	
	public:
		t *b;
		void find_secmax(t *a,int size);
		linkedhashentry<t> **table;
		hashmap()
		{
		 table=new linkedhashentry<t>* [table_size];		
		 for(int i=0;i<table_size;i++)
		 {
			table[i]=NULL;
		 }
		}
		void get(int key)
		{
			int i=0;
			
			if(n%2==0)
			 p=log2(n);
			else
			 p=log2(n)+1;

			b= new (nothrow) t[100];

			int hash=key%table_size;
			if(table[hash]==NULL)
				return ;
			else
			{
				//cout<<"entered";
				linkedhashentry<t> *entry=table[hash];
				while(entry!=NULL && entry->getkey()==key)
				{
					//cout<<entry->getvalue()<<" ";
					t k=entry->getvalue();
					//cout<<"k="<<k<<" ";
			
					b[i]=k;
					//cout<<"b[i]="<<b[i]<<" ";
					i++;
					entry=entry->getnext();
				}
				find_secmax(b,i);
				/*if(entry==NULL)
					return -1;
				else
					return entry->getvalue();*/
				
			}
		}
		void put(int key,t value)
		{
			int hash=key%table_size;
			if(table[hash]==NULL)
				table[hash]=new linkedhashentry<t>(key,value);
			else
			{
			 linkedhashentry<t> *entry=table[hash];
				while(entry->getnext()!=NULL)
					entry=entry->getnext();
				/*if(entry->getkey()==key)
					entry->setvalue(value);*/
				
					entry->setnext(new linkedhashentry<t>(key,value));
			}
		}
		
};


//to find max and sec max
template <class t>
class max_secmax
{
 public:
	hashmap<t>  t_hash1;
	t *b;
	void findmax(t *a,int *group,int size);
	
};

// to find max
template <class t>
void max_secmax<t>:: findmax(t *a,int *group,int size)
{
	
	int i=0,j=1,size1;
	if(size==1)
	{
	  t max_element=a[0];
	 cout<<"\nthe maximum element is "<<max_element<<endl;
	 int key=group[0];
	 //cout<<key<<endl;;

	 t_hash1.get(key);//get the lost elements with the max from hash table
	 /*for(int i=0;i<p;i++)
	 {
		cout<<b[i]<<" ";
	 }
	 cout<<endl;*/
	 
	}
	else
	{
	 
	 t *max;
	 int *gr,l=0;
	 if(size%2==0)
	 {
		size1=size/2;
		max=new (nothrow) t[size1];
		gr=new (nothrow) int[size1];
	 }
	 else
	 {
		size1=size/2+1;
		max=new (nothrow) t[size1];
		gr=new (nothrow) int[size1];
	}
	 while(i<size&&j<size)
	 {
		if(a[i]>=a[j])
	        {
			int key=group[i];
			t value=a[j];
			t_hash1.put(key,value);//storing loosers in hashtable
			max[l]=a[i];
			//cout<<max[l];
			gr[l]=group[i];
			l++;
		}
		else
		{
			int key=group[j];
			t value=a[i];
			t_hash1.put(key,value);//storing loosers
			max[l]=a[j];
			//cout<<max[l]<<" ";
			gr[l]=group[j];
			l++;
		}
		i=i+2;
		j=j+2;
	 }
	 if(i==(size-1))
	 {
		//cout<<"enter";
		max[l]=a[i];
		gr[l]=group[i];
		l++;
	 }
	 cout<<endl;
	 /*for(int i=0;i<l;i++)
	 {
	 cout<<max[i]<<" ";
	 }*/
	 cout<<endl;
	 delete[] a;
	 delete[] group;
	 findmax(max,gr,size1);//resursively calling the function to reduce to size of 1
	}
	
}

//to find sec max
template <class t>
void hashmap<t>::find_secmax(t *a,int size)
{
	int i=0,j=1,size1;
	/*for(int i=0;i<size;i++)
	 {
		cout<<a[i]<<" ";
	 }
	 cout<<endl;*/
	if(size==1)
	{
	 t sec_max=a[0];
	 cout<<"\nthe second maximum element is "<<sec_max<<endl;	 
	}
	else
	{
	 t *max;
	 int l=0;
	 if(size%2==0)
	 {
		size1=size/2;
		max=new (nothrow) t[size1];
	 }
	 else
	 {
		size1=size/2+1;
		max=new (nothrow) t[size1];
	 }
	 while(i<size&&j<size)
	 {
		if(a[i]>=a[j])
	        {
			max[l]=a[i];
			l++;
		}
		else
		{
			max[l]=a[j];
			l++;
		}
		i=i+2;
		j=j+2;
	 }
	 if(i==(size-1))
	 {
		max[l]=a[i];
		l++;
	 }
	 delete[] a;
	 find_secmax(max,size1);
	}
	
}

int main()
{
	//hashmap hash;
	int size;
	int key,value,result;
	int option;
	cout<<"\nprogram to find max and second max in a given array"<<endl;	
	do
	 {
	    cout<<"\n1.integers\n2.flaoting numbers\n3.strings \n0.exit\nenter your choice:";

	    cin>>option;
	    switch(option)
		{
		  case 1: 
			{
			cout<<"\nenter the number of elements in the array:";
			cin>>size;
			n=size;
			int *a,*group;
			a=new (nothrow)int[size];
			group=new (nothrow)int[size];
			cout<<"\nenter numbers:";
			for(int i=0;i<size;i++)
			{
				cin>>a[i];
				group[i]=i/2;
			}
			max_secmax<int> int_obj1;
			int_obj1.findmax(a,group,size);
			}
			 break;
		  case 2:
			{ 
			cout<<"\nenter the number of elements in the array:";
			cin>>size;
			n=size;
			int *group2;
			double *a2;
			a2=new (nothrow) double[size];
			group2=new (nothrow) int[size];
			cout<<"\nenter floating numbers:";
			for(int i=0;i<size;i++)
			{
				cin>>a2[i];
				group2[i]=i/2;
			}
			max_secmax<double> double_obj2;
			double_obj2.findmax(a2,group2,size);
			
			 break;
		  	}
		case 3: 
			{
			cout<<"\nenter the number of elements in the array:";
			cin>>size;
			n=size;
			string *a;
			int *group;
			a=new (nothrow)string[size];
			group=new (nothrow)int[size];
			cout<<"\nenter strings:";
			for(int i=0;i<size;i++)
			{
				cin>>a[i];
				group[i]=i/2;
			}
			max_secmax<string> string_obj3;
			string_obj3.findmax(a,group,size);
			}
		  case 0:break;
		}
	}while(option!=0);
	return 0;
}
