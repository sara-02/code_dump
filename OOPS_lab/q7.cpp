#include <iostream>
#include <cstdlib>
 using namespace std;

 class person
 {
 private:
 	int count;
 public:
 	person();
 	person operator ++();
 	person operator --();
 	void disp_count();
 };
 person::person()
 {
 	count=0;
 }
 person person::operator ++()
 {
 	count++;
 }
 person person::operator--()
 {
 	if(count ==0)
 		cout<<"Cannot decrease further"<<endl;
 	else
 		count--;
 }
 void person::disp_count()
 {
 	cout<<"The number of people in the bank are:: "<<count<<endl;
 }
 int main()
 {
 	person p1;
 	int ch;
 	while(1)
 	{
 		cout<<"Enter 1 to enter"<<endl<<"Enter 2 to leave"<<endl<<"Enter 3 to display count"<<endl;
 		cout<<"Enter 4 to exit"<<endl;
 		cin>>ch;
 		switch(ch)
 		{
 			case 1: ++p1;break;
 			case 2: --p1; break;
 			case 3: p1.disp_count();break;
 			case 4:
 				exit(0);
 			default:cout<<"wrong choice"<<endl;
 		}
 	}
 	return 0;
}