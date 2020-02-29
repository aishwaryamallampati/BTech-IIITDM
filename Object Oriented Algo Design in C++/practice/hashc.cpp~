//creating and inserting elements into a hash table
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

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
			int hash=key%table_size;
			if(table[hash]==NULL)
				return -1;
			else
			{
				linkedhashentry *entry=table[hash];
				while(entry!=NULL && entry->getkey()!=key)
					entry=entry->getnext();
				if(entry==NULL)
					return -1;
				else
					return entry->getvalue();
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
				if(entry->getkey()==key)
					entry->setvalue(value);
				else
					entry->setnext(new linkedhashentry(key,value));
			}
		}
		void remove(int key)
		{
		 int hash=key%table_size;
		 if(table[hash]!=NULL)
		 {
			 linkedhashentry *preventry=NULL;
			 linkedhashentry *entry =table[hash];
			while(entry!=NULL && entry->getkey()!=key)
			 {
				preventry=entry;
				entry=entry->getnext();
			 }
			if(entry->getkey()==key)
			{
			 	if(preventry==NULL)
				{
					linkedhashentry *nextentry=entry->getnext();
					delete entry;
					table[hash]=nextentry;
				}
				else
				{
					linkedhashentry *next=entry->getnext();
					delete entry;
					preventry->setnext(next);
				}
			}

			}
		 }
		

		~hashmap()
		{
		 for(int i=0;i<table_size;i++)
		 {
			if(table[i]!=NULL)
			{
			 linkedhashentry *preventry=NULL;
			 linkedhashentry *entry =table[i];
			 while(entry!=NULL)
			 {
				preventry=entry;
				entry=entry->getnext();
				delete preventry;
			 }

			}
			
		 }
		 delete[] table;
		}
	
};


int main()
{
	hashmap hash;
	int key,value,result;
	int option;	
	do
	 {
	    cout<<"\n1.insertion\n2.get values in a block\n3.remove \n4.delete hash table\nenter your choice:";
	    cin>>option;
	    switch(option)
		{
		  case 1: 
			cout<<"\nenter the value to be inserted:";
			cin>>value;
			cout<<"\nenter key at which element to be inserted:";
			cin>>key;
			hash.put(key,value);
			 break;
		  case 2: 
			cout<<"\nenter key at which element are to be printed:";
			cin>>key;
			result=hash.get(key);
			cout<<result<<endl;
			 break;
		  case 3:
			cout<<"\nenter key at which element has to be removed:";
			cin>>key;
			hash.remove(key);
			break;
		  case 0:break;
		}
	}while(option!=0);
	return 0;
}

