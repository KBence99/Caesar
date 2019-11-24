

/*

	calculator08buggy.cpp



	Helpful comments removed.



	We have inserted 3 bugs that the compiler will catch and 3 that it won't.

*/



#include "../std_lib_facilities.h"



struct Token {

	char kind; //what kind of Token is this?

	double value; //what's the value?

	string name; //if it's a variable, what is the name?

	Token(char ch) :kind(ch), value(0) { } //operation token

	Token(char ch, double val) :kind(ch), value(val) { } //number token
	Token(char ch, string n): kind(ch), name(n) {} //variable token

};



class Token_stream {
	bool full; //is the stream full?

	Token buffer;

public:

	Token_stream() :full(0), buffer(0) { }



	Token get(); //read a token from the stream.

	void unget(Token t) { buffer=t; full=true; } //put a token back to the stream.



	void ignore(char);

};



const char let = '#'; //Token declaration

const char quit = 'Q'; //Exit the program

const char print = ';'; //Print the value of the equation

const char number = '8'; //Number token kind

const char name = 'a'; //Variable token kind
const char sroot = 's'; //square root
const char power = 'p'; //power



Token Token_stream::get()

{

	if (full) { full=false; return buffer; } //after the stream is initialized

	char ch; //initializing the sream

	cin >> ch;

	switch (ch) {

	case '(':

	case ')':

	case '+':

	case '-':

	case '*':

	case '/':

	case '%':

	case print:

	case '=':
	case ',':

		return Token(ch);

	case '.':

	case '0':

	case '1':

	case '2':

	case '3':

	case '4':

	case '5':

	case '6':

	case '7':

	case '8':

	case '9':

	{	cin.unget();

		double val;

		cin >> val;

		return Token(number,val);

	}

	default:

		if (isalpha(ch) || ch =='#') { //variable Token
			if (ch == let) return Token(let);	

			if (ch == quit) return Token(quit);

			string s;

			s += ch;

			while(cin.get(ch) && (isalpha(ch) || isdigit(ch))) s += ch;	

			if (s == "quit") return Token(quit);
			if(s=="sqrt")return Token(sroot);
			if(s=="pow")return Token(power);

			cin.unget();

			return Token(name,s);

		}

		error("Bad token");

	}

}



void Token_stream::ignore(char c)

{

	if (full && c==buffer.kind) {

		full = false;

		return;

	}

	full = false;



	char ch;

	while (cin>>ch)

		if (ch==c) return;

}



struct Variable {

	string name;

	double value;

	Variable(string n, double v) :name(n), value(v) { }

};



vector<Variable> names;



double get_value(string s) //get a variable value from the variable vector

{

	for (int i = 0; i<names.size(); ++i)

		if (names[i].name == s) return names[i].value;

	error("get: undefined name ",s);

}

/*

void set_value(string s, double d) //set the value of a variable

{

	for (int i = 0; i<=names.size(); ++i)

		if (names[i].name == s) {

			names[i].value = d;

			return;

		}

	error("set: undefined name ",s);

}

*/

bool is_declared(string s) //Is there already a variable like that?

{

	for (int i = 0; i<names.size(); ++i)

		if (names[i].name == s) return true;

	return false;

}



Token_stream ts;



double expression();



double primary() //Calculating negatives and parenthesis

{

	Token t = ts.get();

	switch (t.kind) {	
	case power:
	{
		double n1 = expression();
			if(ts.get().kind!=',') error("column expected");
		double n2 = expression();
		double pow = n1;
		if(n2>0){		
		for(int i=0; i<n2-1; i++)
		{
			pow = pow*n1;
		}
		if(n2<0 || n2==0)error("invalid power");
		}
	}
	case sroot:
	{
		double d=expression();
		if(d<0)
		{
			error("Trying to take the squareroot of a negative number");
		}		
		return(sqrt(d));
	}	
	case '(':

	{	double d = expression();

		t = ts.get();

		if (t.kind != ')') error("'(' expected");
		return d;

	}

	case '-':

		return - primary();

	case number:

		return t.value;

	case name:

		return get_value(t.name);

	default:

		error("primary expected");

	}

}



double term() //Calculating multiplication and division

{

	double left = primary();

	while(true) {

		Token t = ts.get();

		switch(t.kind) {

		case '*':

			left *= primary();

			break;

		case '/':

		{	double d = primary();

			if (d == 0) error("divide by zero");

			left /= d;

			break;

		}

		default:

			ts.unget(t);

			return left;

		}

	}

}



double expression() //calculating summation and substraction

{

	double left = term();

	while(true) {

		Token t = ts.get();

		switch(t.kind) {

		case '+':

			left += term();

			break;

		case '-':

			left -= term();

			break;

		default:

			ts.unget(t);

			return left;

		}

	}

}



double declaration() //add a variable to the variable vector

{

	Token t = ts.get();

	if (t.kind != name) error ("name expected in declaration");

	string name = t.name;

	if (is_declared(name)) error(name, " declared twice");

	Token t2 = ts.get();

	if (t2.kind != '=') error("= missing in declaration of " ,name);

	double d = expression();

	names.push_back(Variable(name,d));

	return d;

}



double statement() //determinate wether the token is a variable or something else.

{

	Token t = ts.get();

	switch(t.kind) {

	case let:

		return declaration();

	default:

		ts.unget(t);

		return expression();

	}

}



void clean_up_mess()

{

	ts.ignore(print);

}



const string prompt = "> ";

const string result = "= ";



void calculate()

{

	while(true) try {

		cout << prompt;

		Token t = ts.get();

		while (t.kind == print) t=ts.get();

		if (t.kind == quit) return;

		ts.unget(t);

		cout << result << statement() << endl;

	}

	catch(runtime_error& e) {

		cerr << e.what() << endl;

		clean_up_mess();

	}

}



int main()



	try {

		names.push_back(Variable("k",1000.0));		
		calculate();

		return 0;

	}

	catch (exception& e) {

		cerr << "exception: " << e.what() << endl;

		char c;

		while (cin >>c&& c!=';') ;

		return 1;

	}

	catch (...) {

		cerr << "exception\n";

		char c;

		while (cin>>c && c!=';');

		return 2;

	}