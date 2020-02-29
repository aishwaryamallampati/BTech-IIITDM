//function template to find max
#include<iostream>
#include<string>
using namespace std;

template<class t>
t get_max(t a,t b)
{
	t result;
	if (a>b)
	result=a;
	else
	result=b;
	return result;
}

int main()
{
	int option;	
	do
	 {
	    cout<<"\n1.integers\n2.float\n3.strings\nenter your choice:";
	    cin>>option;
	    switch(option)
		{
		  case 1: 
			int i,j,k;
			cout<<"\nenter the 1st number:";
			cin>>i;
			cout<<"\nenter the 2nd number:";
			cin>>j;
			k=get_max<int>(i,j);
			cout<<k<<endl;
			 break;
		  case 2:
			float l,m,n;
			cout<<"\nenter the 1st number:";
			cin>>l;
			cout<<"\nenter the 2nd number:";
			cin>>m;
			n=get_max<float>(l,m);
			cout<<n<<endl;
		   	 break;
		  case 3:
			{
			 string o;
			 string p;
			 string q;
			 cout<<"\nenter the 1st string:";
			 cin>>o;
			 cout<<"\nenter the 2nd string:";
			 cin>>p;
			 q=get_max<string>(o,p);
			 cout<<q<<endl;
			}
			 break;

		case 0:break;
		}
	 }while(option!=0);
        return 0;	
	
}




	




