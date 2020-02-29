#include<iostream>
using namespace std;

class node
{
	friend class linked_list;
	private:
		int data;
	public:
		node *next;
		node();
};

node::node()
{
	data=0;
	next=NULL;
}

class linked_list
{
	public:
		node *start=NULL;
		node *ptr;
		node *temp=NULL;
	
		void insert(int item);
		void traverse(node *head);
};


void linked_list::insert(int item)
{
	ptr= new node();
	ptr->data=item;
	if(start==NULL)
	{
		start=ptr;
		ptr->next=NULL;	
		temp=start;
	}
	else
	{
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=ptr;
		ptr->next=NULL;
	}
}

void linked_list::traverse(node *head)
{
	node *trav=head;
	while(trav!=NULL)
	{
		cout<<trav->data<<" ";
		trav=trav->next;
	}
	cout<<endl;
}

int main()
{
	int i,size,value;
	linked_list list1;
	cout<<"\nenter the number of elements in linked list:";
	cin>>size;
	cout<<"\nenter the elements:";
	for(i=1;i<=size;i++)
	{
	 cin>>value;
	 list1.insert(value);
	}
	cout<<"\nthe linked list is :"<<endl;
	list1.traverse(list1.start);
}
