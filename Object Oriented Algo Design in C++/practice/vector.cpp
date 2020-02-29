#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int>vec;//creating a  vector to store integers
	int i,n,value;
	cout<<"vector size="<<vec.size()<<endl;
	cout<<"enter the number of elements to be inserted in the vector:";
	cin>>n;
	cout<<"\nenter the elements:";
	for(i=1;i<=n;i++)//we have to store from i=0 if we want to print using for loop
	{
	 cin>>value;
	 vec.push_back(value);
	}
	cout<<"\nthe stored elements are:";
	for(i=1;i<=n;i++)
	{
	 cout<<"\nthe value of vec["<<i<<"]="<<vec[i]<<endl;
	}
	vector<int>::iterator v=vec.begin();//using iterator to traverse through the array is best as it exactly gives out all the elements
	while(v!=vec.end())
	{
	 cout<<"\nthe value of vec="<<*v<<endl;
	 v++;
	}
}
