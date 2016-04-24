#include <iostream>
#include <cstdlib>
 using namespace std;

 class count_obj
 {
 public:
 	static int count;
 	count_obj();
 	~count_obj();
 };
 int count_obj::count=0;
 count_obj::count_obj()
 {
 	count++;
 	cout<<"The number of objects= "<<count<<endl;
 }
 count_obj::~count_obj()
 {
 	if(count==0)
 	{
 		cout<<"no more objects to destory";
 		exit(0);
 	}
 	count--;
 	cout<<"The number of objects ="<<count<<endl;
}
int main()
{
	count_obj o1,o2,o3;
	o1.~count_obj();
	o2.~count_obj();
	o3.~count_obj();
	return 0;
}