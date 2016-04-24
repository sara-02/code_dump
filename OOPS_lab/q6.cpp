#include <iostream>
using namespace std;

class polygon
{
public:
	void read();
	float getbase();
	float getheight();
	virtual void area()
	{

	}
private:
	float base;
	float height;
};
void polygon::read()
{
	cout<<"Enter the base/width:  ";
	cin>>base;
	cout<<"Enter the height:  ";
	cin>>height;
}
float polygon::getbase()
{
	return base;
}
float polygon::getheight()
{
	return height;
}
class rectangle:public polygon
{
	void area()
	{
		cout<<"The area of the rectangle is:: "<<(getbase()*getheight())<<"sq. units"<<endl;

	}
};
class triangle:public polygon
{
	void area()
	{
		cout<<"The area of the triangle is:: "<<(getbase()*getheight()/2)<<"sq. units"<<endl;

	}
};
int main()
{
	polygon *p;
	rectangle r1;
	triangle t1;
	p=&r1;
	cout<<"For the rectangle:"<<endl;
	r1.read();
	p->area();
	p=&t1;
	cout<<"For the triangle:"<<endl;
	t1.read();
	p->area();
	return 0;

}