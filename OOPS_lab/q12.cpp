#include <iostream>
using namespace std;

template <class X>
 X mini( X  a, X  b)
{
		return a<b?a:b;
}
int main()
{
	int a,b;
	float a1,b1;
	char a2,b2;
	cout<<"For Intergers"<<endl;
	cout<<"Enter the numbers ::"<<endl;
	cin>> a>>b;
	cout<<"The MIN is:: "<<mini(a,b)<<endl;
	cout<<"For Float"<<endl;
	cout<<"Enter the numbers ::"<<endl;
	cin>> a1>>b1;
	cout<<"The MIN is:: "<<mini(a1,b1)<<endl;
	cout<<"For characters"<<endl;
	cout<<"Enter the numbers ::"<<endl;
	cin>> a2>>b2;
	cout<<"The MIN is:: "<<mini(a2,b2)<<endl;


}
