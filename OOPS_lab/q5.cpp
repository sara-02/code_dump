#include <iostream>
using namespace std;

class pntr_obj
{
public:
	void set_data();
	void print();
private:
	char name[30];
	int roll_no;
};
void pntr_obj::set_data()
{
	cout<<"Enter the name: ";
	cin>>name;
	cout<<"Enter the roll no. : ";
	cin>>roll_no;
}
void pntr_obj::print()
{
	cout<<"The name is -->"<<name<<endl;
	cout<<"The roll no is-->"<<roll_no<<endl;
	cout<<endl;
}
int main()
{
	pntr_obj po1,po2,po3;
	cout<<"Receiving data"<<endl;
	po1.set_data();
	po2.set_data();
	po3.set_data();
	cout<<"Printing data"<<endl;
	po1.print();
	po2.print();
	po3.print();
	return 0;
}
