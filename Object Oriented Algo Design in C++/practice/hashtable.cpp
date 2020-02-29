//creating and inserting elements into a hash table
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

const int table_size=1000;

class hashnode
{
	public:
		int key;
		int value;
		hashnode(int key,int value)
		{
		 this->key=key;
		 this->value=value;
		}
	

};

class hashmap
{
	private:
		hashtable **htable;
	public:
		hashmap()
		{
		 htable=new hashnode* [table_size];
		 for(int i=0;i<table_size;i++)
		 {
			htable[i]=NULL;
		 }
		}
		~hashmap()
		{
		 for(int i=0;i<table_size;i++)
		 {
			if(htable[i]!=NULL && htable[[i]!=deletenode ::getnode()
				delete htable[i];
		 }
		 delete[] htable;
		}
	        int hashfunc(int key)
	 	{
			return key%table_size;
		}
		void insert(int key,int value)
		{
			int hash_val=hashfunc(key);
			int init=-1;
			int deletedindex=-1;
			while 
		}
}
