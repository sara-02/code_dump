#include  <iostream>
using namespace std;

 class marks_avg;
 class student
 {
 public:
 	void getdata();
 	void display();
 	friend class marks_avg;
private:
	char name[10];
	float m1,m2,m3;
};
void student::getdata()
{
	cout<<"Enter the name:: ";
	cin>>name;
	cout<<"Enter the marks in first subject:: ";
	cin>>m1;
	cout<<"Enter the marks in second subject:: ";
	cin>>m2;
	cout<<"Enter the marks in third subject:: ";
	cin>>m3;
}
void student::display()
{
	cout<<"Students Detail::"<<endl;
	cout<<"NAME:: "<<name<<endl;
	cout<<"MARKS 1::"<<m1<<endl;
	cout<<"MARKS 2::"<<m2<<endl;
	cout<<"MARK 3::"<<m3<<endl;
}
class marks_avg
{
public:
	void average(student);

};
void marks_avg::average(student stu1)
{
	float avg;
	avg=stu1.m1+stu1.m2+stu1.m3;
	avg=avg/3;
	cout<<"AVERAGE MARKS::"<<avg<<endl;
}
int main()
{
	student stu1;
	marks_avg avg1;
	stu1.getdata();
	stu1.display();
	avg1.average(stu1);
	return 0;
}