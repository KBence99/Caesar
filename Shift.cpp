#include "std_lib_facilities.h"
int main()
{
	int a=5, db = 0;
	while(a!=0)
	{
		a=a<<1;
		db++;
		cout<<"A= "<<a<<" DB= "<<db<<"\n";
	}
	cout<<db<<"\n";
}
