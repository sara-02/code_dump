#include <iostream>
using namespace std;
class company
{
private:
		int value;
		float rate;
public:
	void getdata();
	void showdata();
	company operator +(company c1);
	company operator  -(company c1);

};
void company::getdata()
{
	cout<<"Enter the value:: ";
	cin>>value;
	cout<<"Enter the rate:: ";
	cin>>rate;
}
void company::showdata()
{
	cout<<"The details of the company are:"<<endl;
	cout<<"VALUE:: "<<value<<endl;
	cout<<"RATE::"<<rate<<endl;
}
company company::operator +(company c2)
{
	company cadd;
	cadd.value=this->value+c2.value;
	cadd.rate=this->rate+c2.rate;
	return cadd;
}
company company::operator -(company c2)
{
	company csub;
	csub.value=this->value-c2.value;
	csub.rate=this->rate-c2.rate;
	return csub;
}
int main()
{
	company c1,c2,c3;
	cout<<"COMPANY 1"<<endl;
	c1.getdata();
	cout<<"COMPANY 2"<<endl;
	c2.getdata();
	cout<<"DETAIL COMPANY 1"<<endl;
	c1.showdata();
	cout<<"DETAIL COMPANY 2"<<endl;
	c2.showdata();
	cout<<"COMPANY AFTER MERGE"<<endl;
	c3=c1+c2;
	c3.showdata();
	cout<<"COMPANY AFTER SPLIT"<<endl;
	c3=c1-c2;
	c3.showdata();
	return 0;
}