#include <iostream>
using namespace std;

class num_rev
{
	public:
		void getnum();
		int reve_num();
	private:
		int num;
};

void num_rev::getnum()
{
	cout<<"Enter the number: ";
	cin>>num;
}
int num_rev::reve_num()
{
	int num2=0,p=0;
	while(num>0)
	{
		p=num%10;
		num2=num2*10+p;
		num=num/10;
	}
	return num2;
}

int main()
{
	num_rev n1;
	n1.getnum();
	cout<<"The reverse of a number is ="<<n1.reve_num()<<endl;
	return 0;
}