#include "std_lib_facilities.h"
int main()
{
	string first_name;
	string friend_name;
	int age;
	char friend_sex = 0;

	cout << "Please enter your first name:";
	cin >> first_name;

	cout << "Please enter your age:";
	cin >> age;

	cout << "Please enter a friends name:";
	cin >> friend_name;

	cout << "Please enter the gender of that friend ('F' for female, 'M' for male):";
	cin >> friend_sex;
	cout << "\n";

	if(age<1 or age>119)
	{
		simple_error("You're kidding!");
	}

	cout << "Hello, " << first_name << "! How are you?\n";
	cout << "It sure has been a long time, hasn't it?\n";
	cout << "Have you seen " << friend_name << " lately?\n";
	
	if(friend_sex=='M')
	{
		cout <<"I lost touch with him.\n";
		cout <<"If you see "<< friend_name <<" please ask him to call me."<<"\n";
	}
	if(friend_sex=='F')
	{
		cout <<"I lost touch with her.\n";
		cout <<"If you see "<< friend_name <<" please ask her to call me."<<"\n";
	}	
	cout <<"I hear you just had a birthday and you are " << age <<" years old.\n"; 
	cout <<"Time realy does fly by, huh?\n";

	if(age<12)
	{
		cout<<"Next year you will be "<<age+1<< " years old!\n";
	}

	if(age==17)
	{
		cout<<"Next year you will be able to vote.\n";
	}

	if(age>70)
	{
		cout<<"I hope you are enjoying retirement.\n";
	}

	cout<<"Anyways, it's good to hear from you. Call me soon.\n";
	cout<<"Yours sincerely\n";
	cout<<"\n";
	cout<<"\n";
	cout<<"\n";
	cout<<first_name<<"\n";
}
