//hash.h
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
using namespace std;

class linkedhashentry
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
		int get(int key);
		void put(int key,int value);
		
};
