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
	
		node* insert_beg(node *start);
		node* insert_end(node* start);
		node* insert_pos(node* start);
		node* delete_pos(node* start);
		node* delete_value(node* start);
		void search(node* start);
		void traverse(node *head);
};

node* linked_list::insert_beg(node *start)
{
	int value;
	cout<<"\nenter the value to inserted at the beginning:";
	cin>>value;
	ptr= new node();
	ptr->data=value;
	node *p;
	if(start==NULL)
	{
		start=ptr;
		start->next=NULL;	
	}
	else
	{
		p=start;
		start=ptr;
		start->next=p;
	}
	return start;
}

node* linked_list::insert_end(node* start)
{
	int value;
	cout<<"\nenter the value to inserted at the end:";
	cin>>value;
	node * s;
	ptr= new node();
	ptr->data=value;
	s=start;
	while(s->next!=NULL)
	{
	 s=s->next;
	}
	s->next=ptr;
	ptr->next=NULL;
	return start;
}

node* linked_list::insert_pos(node* start)
{
	int value,pos,counter=0;
	cout<<"\nenter the position:";
	cin>>pos;
	cout<<"\nenter the value to inserted at the position:";
	cin>>value;
	ptr= new node();
	ptr->data=value;
	node *s,*temp1;
	
	s=start;
	while(s!=NULL)
	{
		s=s->next;
		counter++;
	}
	if(pos==1)
	{
		if(start==NULL)
		{
		 start=ptr;
		 start->next=NULL;
		}
		else
		{
		 temp1=start;
		 start=ptr;
		 start->next=temp1;
		}
	}
	else if(pos>1 && pos<=counter)
	{
	 s=start;
	 for(int i=1;i<pos;i++)
	 {
		temp1=s;
		s=s->next;
	 }
	 temp1->next=ptr;
	 ptr->next=s;
	}
	else
	{
	 cout<<"\nposition out of range"<<endl;
	}
	return start;
}

node* linked_list::delete_pos(node* start)
{
	int value,pos,counter=0;
	if(start==NULL)
	{
	 cout<<"\nlist is empty"<<endl;
	}
	cout<<"\nenter the position to deleted:";
	cin>>pos;
	node *s,*temp1;
	s=start;
	if(pos==1)
	{
	 start=s->next;
	}
	else
	{
	 while(s!=NULL)
	 {
		s=s->next;
		counter++;
	 }
	 if(pos>0 && pos<=counter)
	 {
	  s=start;
	  for(int i=1;i<pos;i++)
	  {
		temp1=s;
		s=s->next;
	  } 
	  temp1->next=s->next;
	 }
	 else
	 {
	   cout<<"\nposition out of range"<<endl;
	 }
	}
	return start;
}

node* linked_list::delete_value(node* start)
{
	int pos,counter=0,value;
	if(start==NULL)
	{
	 cout<<"\nlist is empty"<<endl;
	}
	cout<<"\nenter the value to be deleted:";
	cin>>value;
	node *s,*temp1;
	s=start;
	if(s->data==value)
	{
	 start=s->next;
	}
	else
	{
	 while(s!=NULL && s->data!=value)
	 {
	  temp1=s;
	  s=s->next;
	 }
	 if(s==NULL)
	 {
	  cout<<"\n the element not found in the linked list."<<endl;
	 }
	 else
	 {
	  temp1->next=s->next;
	 }
	}
	return start;
}

void linked_list::search(node* start)
{
	int value,counter=0;
	if(start==NULL)
	{
	 cout<<"\nlist is empty"<<endl;
	}
	cout<<"\nenter the value to searched:";
	cin>>value;
	node *s;
	s=start;
	while(s!=NULL && s->data!=value)
	{
	 s=s->next;
	 counter++;
	}
	if(s==NULL)
	{
	 cout<<"\nelement not found in the linked list.\n";
	}
	else
	{
	 cout<<"\nthe element is present at position "<<counter+1<<endl;
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
	int option;
	linked_list list1;
	do
	{
	 cout<<"\n1.insert_beg\n2.insert_end\n3.insert at a given position\n4.delete given value\n5.delete node at  given position\n6.search for an element\n7.display\n0.exit\nenter your choice:";
	 cin>>option;
	 switch(option)
	 {
	  case 1:
		list1.start=list1.insert_beg(list1.start);
		break;
	  case 2:
		list1.start=list1.insert_end(list1.start);
		break;
	  case 3:
		list1.start=list1.insert_pos(list1.start);
		break;
	  case 4:
		list1.start=list1.delete_value(list1.start);
		break;
	  case 5:
		list1.start=list1.delete_pos(list1.start);
		break;
	  case 6:
		list1.search(list1.start);
		break;
	  case 7:
		cout<<"\nthe linked list is:"<<endl;
		list1.traverse(list1.start);
		break;
	  case 0:
		break;
	 
	 }
	}while(option!=0);
	
}
