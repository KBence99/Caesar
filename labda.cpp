#include "../std_lib_facilities.h"

const int sx = 25;

const int sy = 45;

int lx/*  = 5*/;

int ly/*  = 2*/;

int dx = 1;

int dy = 1;

char table [sx][sy];

//----------------------------------------------

void clear(char (&t) [sx][sy])

{

	for(int i=1; i<sx+1; i++)

	{

		for(int j=1; j<sy+1; j++)

		{

			t[i][j]=' ';

		}

	}

}

void point(int lx,int ly, char (&t) [sx][sy])

{

	t[lx][ly]='X';

}

void print(char (&t) [sx][sy])

{

	for(int i=1; i<sy+3; i++) cout<<'_';	

	for(int i=1; i<sx+1; i++)

	{

		cout<<"\n";

		cout<<'|';

		for(int j=1; j<sy+1; j++)

		{

			cout<<t[i][j];

		}

		cout<<'|';

	}

	cout<<"\n";

	for(int i=1; i<sy+3; i++) cout<<'-';

	cout<<"\n";



}

//----------------------------------------------

void directiony(int& d, int l)

{	

	switch(l){

	case(sy):{d=-1;}}

	switch(l){	

	case(1):{d=1;}}

}

void directionx(int& d, int l)

{	

	switch(l){

	case(sx):{d=-1;}}

	switch(l){	

	case(1):{d=1;}}

}

void move(int d, int& l)

{

	l = l + d;

}

//----------------------------------------------

int main()

{

	

	int c=0;

	int l;	

	cout<<"Adja meg a labda helyét:\n";

	cout<<"X: "; cin>>ly;

	cout<<"Y: "; cin>>lx;

	cout<<"Meddig pattogjon a labda?\n";

	cin>>l;

	while(c!=l)

//	for(int i=0; i<30; i++)

	{

		system("clear");		

		directionx(dx, lx);

		directiony(dy, ly);



		move(dx, lx);

		move(dy, ly);



		clear(table);

		point(lx, ly, table);

		print(table);

		//keep_window_open();

		system("sleep 0.1");

		c++;

	}

	cout<<"\n";

}

