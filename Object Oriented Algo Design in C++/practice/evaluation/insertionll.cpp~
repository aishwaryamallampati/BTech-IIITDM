//inserrion sort using single linked list
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
		node* insertion(node *head);
		node* insertion_sort(node *head,node *new_node);
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

node* linked_list::insertion(node *head)
{
	if(head==NULL || head->next==NULL)
		return head;
	node *ptr1=head->next;
	node *result=head;
	result->next=NULL;
	
	while(ptr1)
	{
	 node *temp1=ptr1;
	 ptr1=ptr1->next;
	 result=insertion_sort(result,temp1);
	}
	return result;
}//sorting elements

node* linked_list::insertion_sort(node *head,node* new_node)
{
	if(head==NULL || head->data>=new_node->data)
	{
		new_node->next=head;
		head=new_node;
		return head;
	}
	node *ptr1=head;
	node *prev=NULL;
	while(ptr1!=NULL&&ptr1->data<new_node->data)
	{
		prev=ptr1;
		ptr1=ptr1->next;
	}
	new_node->next=ptr1;
	prev->next=new_node;
	return head;

}//inserting new element into the sorted list

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
	node *result=NULL;
	result=list1.insertion(list1.start);
	cout<<"the sorted list in increasing order using insertion sort:"<<endl;
	list1.traverse(result);
}
