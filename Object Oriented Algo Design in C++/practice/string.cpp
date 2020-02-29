#include<iostream>
#include<cstring>

using namespace std;

class sentence
{
	public:
		void entersentence();
		int stringlen();
	private:
		char a[100];
};

void sentence::entersentence()
{
	cout<<"\nenter the text:";
	cin.getline(a,100);
}

int sentence::stringlen()
{

main()
{
	sentence sentence1;
	sentence1.entersentence();
	return 0;
}
	
