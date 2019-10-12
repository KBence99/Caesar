#include "std_lib_facilities.h"



double ert(double sz, string mert)

{

double v=0;

	if(mert=="cm"){v=sz/100; cout<<v<<"m\n";}

else	if(mert=="m"){v=sz; cout<<v<<"m\n";}

else	if(mert=="in"){v=(sz*2.54)/100; cout<<v<<"m\n";}

else	if(mert=="ft"){v=((sz*12)*2.54)/100; cout<<v<<"m\n";}	

else{simple_error("invalid measurement!");}

	return v;

}



int main()

{

	char t;

	double a=0,b=0, l=0, s=0, sum=0, db=0;

	vector <double > v;	

	string m;

	cout<<"A:";

	cin >> a;

	cout<<"Mértékegység:";

	cin >> m;

	a=ert(a,m);

	cout<<"largest so far\n";

	cout<<"smallest so far\n";

	sum+=a; db++;

	l=a; s=a;

	v.push_back(a);

	int counter=-1;

	while(t!='|')

	{

	if(counter==1)

	{

		cout<<"A:";

		cin >> a;

		cout<<"Mértékegység:";

		cin >> m;

		a=ert(a,m);

		db++; sum+=a;		

		if(a>l){l=a;cout<<"largest so far\n";}

		if(a<s){s=a;cout<<"smallest so far\n";}

		v.push_back(a);

	}

	if(counter==-1)

	{

		cout<<"B:";

		cin >> b;

		cout<<"Mértékegység:";

		cin >> m;

		b=ert(b,m);

		db++; sum+=b;		

		if(b>l){l=a;cout<<"largest so far\n";}

		if(b<s){s=a;cout<<"smallest so far\n";}

		v.push_back(b);

	}	

		

		if(a>b and a!=b)

		{

		cout<<"the smaller value is: "<<b;		

		cout<<", the larger value is: "<<a;

		}

		if(a<b and a!=b)

		{		

			cout<<"the smaller value is: "<<a;		

			cout<<", the larger value is: "<<b;

		}		

		if(a==b)

		{

			cout<<"the numbers are equal";

		}

		if(a-b <=0.01 and a-b > 0.001 or b-a<=0.01 and b-a>0.001)

		{

			cout<<"\n";

			cout<<"the numbers are almost equal";

		}		

		cout<<"\n";

		cout<<"if you want to end the program input '|', if not input anything else";

		cin >> t;

		counter=counter*-1;

	}

	cout<<"The number of values: "<<db<<"\n";

	cout<<"The sum of the values: "<<sum<<"\n";

	cout<<"The largest values: "<<l<<"\n";

	cout<<"The smallest values: "<<s<<"\n";

	sort(v.begin(),v.end());

	for (int i = 0;i<v.size();i++){

   	cout<<v[i]<<" ";

	cout<<"\n";

 }

}