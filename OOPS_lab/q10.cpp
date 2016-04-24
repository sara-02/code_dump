#include <iostream>
using namespace std;

class friendfnc2;
class friendfnc1
{
public:
	void getnum();
	friend  int avg(friendfnc1, friendfnc2);
private:
	float n1,n2;

};
class friendfnc2
{
public:
	void getnum();
	friend int avg(friendfnc1,friendfnc2);
private:
	float n3,n4,n5;
};
void friendfnc1::getnum()
{
	cout<<"Enter the first number:: ";
	cin>>n1;
	cout<<"Enter the second number:: ";
	cin>>n2;
}
void friendfnc2::getnum()
{
	cout<<"Enter the third number:: ";
	cin>>n3;
	cout<<"Enter the fourth number:: ";
	cin>>n4;
	cout<<"Enter the fifth number:: ";
	cin>>n5;
}
int avg(friendfnc1 f1,friendfnc2 f2)
{
	float avg;
	avg=f1.n1+f1.n2+f2.n3+f2.n4+f2.n5;
	avg=avg/5;
	return avg;

}
int main()
{
	friendfnc1 f1;
	friendfnc2 f2;
	f1.getnum();
	f2.getnum();
	cout<<"The average is:: "<<avg(f1,f2)<<endl;
	return 0;
}
