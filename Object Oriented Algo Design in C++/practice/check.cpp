#include<iostream>
#include<string>
#include<math.h>
#include<cstdio>
#include<cstdlib>
#include<new>

using namespace std;


int p;
int n;

int *b;

int max_element;
int sec_max;


//creating and inserting elements into a hash table

const int table_size=100;

class linkedhashentry
{
	private:
	int key;
	int value;
	linkedhashentry *next;
	public:
	linkedhashentry(int key,int value)
	{
		this->key=key;
		this->value=value;
		this ->next=NULL;
	}
	int getkey()
	{
	 return key;
	}
	int getvalue()
	{
	 return value;
	}
	int setvalue(int value)
	{
	 this->value=value;
	}
	linkedhashentry *getnext()
	{
	 return next;
	}
	void setnext(linkedhashentry *next)
	{
		this->next=next;
	}
};


class hashmap
{
	
	public:
		linkedhashentry **table;
		hashmap()
		{
		 table=new linkedhashentry* [table_size];		
		 for(int i=0;i<table_size;i++)
		 {
			table[i]=NULL;
		 }
		}
		int get(int key)
		{
			int i=0;
			if(n%2==0)
			 p=log2(n);
			else
			 p=log2(n)+1;
			int *b;
			b= new (nothrow) int[p];

			int hash=key%table_size;
			if(table[hash]==NULL)
				return -1;
			else
			{
				//cout<<"entered";
				linkedhashentry *entry=table[hash];
				while(entry!=NULL && entry->getkey()==key)
				{
					//cout<<entry->getvalue()<<" ";
					int k=entry->getvalue();
					//cout<<"k="<<k<<" ";
			
					b[i]=k;
					//cout<<"b[i]="<<b[i]<<" ";
					i++;
					entry=entry->getnext();
				}
				
				/*if(entry==NULL)
					return -1;
				else
					return entry->getvalue();*/
			}
		}
		void put(int key,int value)
		{
			int hash=key%table_size;
			if(table[hash]==NULL)
				table[hash]=new linkedhashentry(key,value);
			else
			{
			 linkedhashentry *entry=table[hash];
				while(entry->getnext()!=NULL)
					entry=entry->getnext();
				/*if(entry->getkey()==key)
					entry->setvalue(value);*/
				
					entry->setnext(new linkedhashentry(key,value));
			}
		}
};

hashmap hash1;

void reduce(int *a,int *group,int size)
{
	
	int i=0,j=1,size1;
	if(size==1)
	{
	 max_element=a[0];
	 cout<<"\nthe maximum element is "<<max_element<<endl;
	 int key=group[0];
	 //cout<<key<<endl;;

	 t temp=hash1.get(key);
	
	 /*for(int i=0;i<p;i++)
	 {
		cout<<b[i]<<" ";
	 }
	 cout<<endl;*/
	 find_secmax(b,p);
	}
	else
	{
	 
	 int *max,*gr,l=0;
	 if(size%2==0)
	 {
		size1=size/2;
		max=new (nothrow) int[size1];
		gr=new (nothrow) int[size1];
	 }
	 else
	 {
		size1=size/2+1;
		max=new (nothrow) int[size1];
		gr=new (nothrow) int[size1];
	}
	 while(i<size&&j<size)
	 {
		if(a[i]>=a[j])
	        {
			int key=group[i];
			int value=a[j];
			hash1.put(key,value);
			max[l]=a[i];
			//cout<<max[l];
			gr[l]=group[i];
			l++;
		}
		else
		{
			int key=group[j];
			int value=a[i];
			hash1.put(key,value);
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
	/* for(int i=0;i<l;i++)
	 {
	 cout<<max[i]<<" ";
	 }
	 cout<<endl;*/
	 delete[] a;
	 delete[] group;
	 reduce(max,gr,size1);
	}
	
}

void find_secmax(int *a,int size)
{
	int i=0,j=1,size1;
	if(size==1)
	{
	 sec_max=a[0];
	 cout<<"\nthe second maximum element is "<<sec_max<<endl;	 
	}
	else
	{
	 int *max,*gr,l=0;
	 if(size%2==0)
	 {
		size1=size/2;
		max=new (nothrow) int[size1];
	 }
	 else
	 {
		size1=size/2+1;
		max=new (nothrow) int[size1];
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
	    cout<<"\n1.integers\n2.flaoting numbers\n3.strings \n4.delete hash table\nenter your choice:";

	    cin>>option;
	    switch(option)
		{
		  case 1: 
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
			reduce(a,group,size);
			 break;
		  case 2: 
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
			reduce(a,group,size);
			 break;
		  
		  case 0:break;
		}
	}while(option!=0);
	return 0;
}
