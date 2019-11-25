#include "../std_lib_facilities.h"
void swap_v(int a, int b) { int temp; temp = a, a=b; b=temp; }

void swap_r(int& a,int& b) { int temp; temp = a, a=b; b=temp; }

//void swap_cr(const int& a, const int& b) { int temp; temp = a, a=b; b=temp; }
void print(int x, int y)
{
	cout<<"x= "<<x<<" y= "<<y<<"\n";
}
int main()
{
	int x = 7;
	int y =9;
	print(x,y);
	swap_r(x,y);                      // replace ? by v, r, or cr
	print(x,y);
	swap_v(7,9);
	const int cx = 7;
	const int cy = 9;
	print(cx,cy);
	swap_v(cx,cy);
	print(cx,cy);
	swap_v(7.7,9.9);
	double dx = 7.7;
	double dy = 9.9;
	print(dx,dy);
	swap_v(dx,dy);
	print(dx,dy);
	swap_v(7.7,9.9);
}