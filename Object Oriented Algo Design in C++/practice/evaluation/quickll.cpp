//quick sort using single linked list
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
		node* get_tail(node *cur);
		
		void  quick_sort(node **head_ref);
		node* quick_sort_rec(node *head,node *end);
		node* partition(node *head,node *end,node **new_head,node **new_end);
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

void linked_list:: quick_sort(node **head_ref)
{
	(*head_ref)=quick_sort_rec(*head_ref,get_tail(*head_ref));
	return;
}//quick sort

node* linked_list::get_tail(node *cur)
{
	while(cur!=NULL&&cur->next!=NULL)
	{
	 cur=cur->next;
	}
	return cur;
}//to get end of a linked list

node* linked_list:: quick_sort_rec(node *head,node *end)
{
	if(!head|| head==end)
		return head;
	node *new_head=NULL,*new_end=NULL;
	node *pivot=partition(head,end,&new_head,&new_end);
	if(new_head!=pivot)
	{
		node *temp1=new_head;
		while(temp1->next!=pivot)
			temp1=temp1->next;
		temp1->next=NULL;
		new_head=quick_sort_rec(new_head,temp1);
		temp1=get_tail(new_head);
		temp1->next=pivot;
	}
	pivot->next=quick_sort_rec(pivot->next,new_end);
	return new_head;
}// quick sort to recursively sort 2 parts of the linked list

node* linked_list::partition(node *head,node *end,node **new_head,node **new_end)
{
	node *pivot=end;
	node *prev=NULL,*cur=head,*tail=pivot;
	
	while(cur!=pivot)
	{
	 if(cur->data<pivot->data)
	 {
	  if(*new_head==NULL)
		(*new_head)=cur;
          prev=cur;
	  cur=cur->next;	 
	 }
	 else
	 {
	  if(prev)
		prev->next=cur->next;
	  node *temp1=cur->next;
	  cur->next=NULL;
	  tail->next=cur;
	  tail=cur;
	  cur=temp1;		
	 }
	}
	if((*new_head)==NULL)
		(*new_head)=pivot;
	(*new_end)=tail;
	return pivot;
}//to find pivot for a linked list


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
	list1.quick_sort(&list1.start);
	cout<<"the linked list in increasing order using quick sort:"<<endl;
	list1.traverse(list1.start);
}
