//merge sort using single linked list
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
};//class to create node for a linked list

node::node()
{
	data=0;
	next=NULL;
}//constructor for initializing node

class linked_list
{
	public:
		node *start=NULL;
		node *ptr;
		node *temp=NULL;
	
		void insert(int item);
		void traverse(node *head);
		void merge_sort(node **head_ref);
		void split(node *source,node **front_ref,node **back_ref);
		node* merge(node *a,node *b);
};//class for linked list

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
}//insert an element into the linked list

void linked_list::merge_sort(node **head_ref)
{
	node *head=*head_ref;
	node *a;
	node *b;
	if(head==NULL||head->next==NULL)
		return;
	split(head,&a,&b);
	merge_sort(&a);
	merge_sort(&b);
	*head_ref=merge(a,b);
}//using divide and conquer to split and sort using merge

void linked_list::split(node *source,node **front_ref,node **back_ref)
{
	node *fast;
	node *slow;
	if(source==NULL || source->next==NULL)
	{
		*front_ref=source;
		*back_ref=NULL;
	}
	else
	{
		slow=source;
		fast=source->next;
		while(fast!=NULL)
		{
		 fast=fast->next;
		 if(fast!=NULL)
		 {
		  slow=slow->next;
		  fast=fast->next;	
		 }
		}
		*front_ref=source;
		*back_ref=slow->next;
		slow->next=NULL;
	}
}//to split single linked list into two parts

node * linked_list::merge(node *a,node *b)
{
	node *result=NULL;
	if(a==NULL)
	{
		return b;
	}
	else if(b==NULL)
	{
		return a;
	}
	if(a->data<b->data)
	{
	 result=a;
	 result->next=merge(a->next,b);
	}
	else
	{
	 result=b;
	 result->next=merge(a,b->next);
	}
	return result;
}//merge 2 sorted linked lists

void linked_list::traverse(node *head)
{
	node *trav=head;
	while(trav!=NULL)
	{
		cout<<trav->data<<" ";
		trav=trav->next;
	}
	cout<<endl;
}//to display th elinked list


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
	list1.merge_sort(&list1.start);
	cout<<"\nthe linked list in increasing order using merge sort:"<<endl;
	list1.traverse(list1.start);
}
