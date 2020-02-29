#include<iostream>
#include<string>
#include<math.h>
#include<cstdio>
#include<cstdlib>
#include<new>

using namespace std;

void reduce(int *a,int *group,int size);

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
	private:
	linkedhashentry **table;
	public:
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
			 p=log2(n)+1;
			b= new (nothrow) int[p];

			int hash=key%table_size;
			if(table[hash]==NULL)
				return -1;
			else
			{
				cout<<"entered";
				linkedhashentry *entry=table[hash];
				while(entry!=NULL && entry->getkey()==key)
				{
					cout<<entry->getvalue()<<" ";
					int k=entry->getvalue();
					cout<<"k="<<k;
			
					b[i]=k;
					cout<<"b[i]="<<b[i];
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



			
/*class linkedhashentry
{
	private:
	int key;
	int value;
	linkedhashentry *next;
	public:
	linkedhashentry(int key,int value);
	int getkey();
	int getvalue();
	int setvalue(int value);
	linkedhashentry *getnext();
	void setnext(linkedhashentry *next);
};



class hashmap
{
	private:
	linkedhashentry **table;
	public:
		hashmap();
		void get(int key);
		void put(int key,int value);
		
};

linkedhashentry::linkedhashentry(int key,int value)
{
	this->key=key;
	this->value=value;
	this ->next=NULL;
}

int linkedhashentry:: getkey()
{
 	return key;
}

int linkedhashentry:: getvalue()
{
 	return value;
}

int linkedhashentry::setvalue(int value)
{
	 this->value=value;
}

linkedhashentry* linkedhashentry:: getnext()
{
	 return next;
}

void linkedhashentry ::setnext(linkedhashentry *next)
{
		this->next=next;
}




hashmap::hashmap()
{
	table=new linkedhashentry* [table_size];		
	 for(int i=0;i<table_size;i++)
	 {
		table[i]=NULL;
	 }
}

void hashmap:: get(int key)
{
	cout<<"entered"<<endl;
	int temp[100],i=0;
	 p=log2(n)+1;
	b= new (nothrow) int[p];

	int hash=key%table_size;
	/*if(table[hash]==NULL)
		return ;*/
	//else
	//{*/
		/*linkedhashentry *entry=table[hash];
		while(entry!=NULL && entry->getkey()==key)
		{
			cout<<"entered while";
			cout<<entry->getvalue()<<" ";
			int k=entry->getvalue();
			cout<<"k="<<k;
			
			b[i]=k;
			cout<<"b[i]="<<b[i];
			i++;
			entry=entry->getnext();
		}
				
		for(int i=0;i<p;i++)
		 {
			cout<<b[i]<<" ";
	 	}
		 cout<<endl;
		
	
	
}


void hashmap:: put(int key,int value)
{
	int hash=key%table_size;
	if(table[hash]==NULL)
	table[hash]=new linkedhashentry(key,value);
	else
	{
	linkedhashentry *entry=table[hash];
	while(entry->getnext()!=NULL)
	 entry=entry->getnext();
				if(entry->getkey()==key)
					entry->setvalue(value);
				
	entry->setnext(new linkedhashentry(key,value));
	}
}*/

void reduce(int *a,int *group,int size)
{
	hashmap hash1;
	int i=0,j=1,size1;
	if(size==1)
	{
	 max_element=a[0];
	 cout<<"\nthe maximum element is "<<max_element<<endl;
	 int key=group[0];
	 //cout<<key<<endl;;

	 hash1.get(key);
	 for(int i=0;i<p;i++)
	 {
		cout<<b[i]<<" ";
	 }
	 cout<<endl;
	 
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
			//cout<<max[l];
			gr[l]=group[j];
		}
		i=i+2;
		j=j+2;
	 }
	 if(i==(size-1))
	 {
		max[l]=a[i];
		gr[l]=group[i];
		l++;
	 }
	 reduce(max,gr,size1);
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
		  /*case 2: 
			cout<<"\nenter key at which element are to be printed:";
			cin>>key;
			result=hash.get(key);
			cout<<result<<endl;
			 break;*/
		  
		  case 0:break;
		}
	}while(option!=0);
	return 0;
}
