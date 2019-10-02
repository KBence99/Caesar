#include "std_lib_facilities.h"
int main()
{
	int a=5;
	int b=7;
	cout<<"A értéke: "<<a<<"\nB értéke: "<<b<<"\n";
	cout<<"\n";
	a = a^b;
	b = a^b;
	a = a^b;
	cout<<"A értéke: "<<a<<"\nB értéke: "<<b<<"\n";
}