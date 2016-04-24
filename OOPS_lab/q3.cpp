#include <iostream>
using namespace std;

class arth
{
public:
	inline void add();
	inline void sub();
	inline void mul();
	inline void div();
	inline void mod();
	void getvals();
private:
	int a,b;
};

void arth::getvals()
{
	cout<<"Enter the first number: ";
	cin>>a;
	cout<<"Enter the second number: ";
	cin>>b;
}
inline void arth::add()
{
	cout<<"The sum is= "<<(a+b)<<endl;
}
inline void arth::sub()
{
	cout<<"The difference is= "<<(a-b)<<endl;
}
inline void arth::mul()
{
	cout<<"The product is= "<<(a*b)<<endl;
}
inline void arth::div()
{
	if(b!=0)
		cout<<"The quotient is= "<<(a/b)<<endl;
	else
		cout<<"not possible"<<endl;

}
inline void arth::mod()
{
	if(b!=0)
		cout<<"The remainder is= "<<(a%b)<<endl;
	else
		cout<<"not possible"<<endl;

}
int main()
{
	int ch;
	arth a1;
	a1.getvals();
	cout<<"Enter 1 to add, 2 to sub,3 to multi,4 to div,5 for rem"<<endl;
	cout<<"Enter your choice"<<endl;
	cin>>ch;
	switch(ch)
	{
		case 1: a1.add();break;
		case 2: a1.sub();break;
		case 3: a1.mul();break;
		case 4: a1.div();break;
		case 5: a1.mod();break;
		default: cout<<"wrong choice";
	}
	return 0;
}
