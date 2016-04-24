#include <iostream>
using namespace std;

class vowel
{
public:
		void getvalue();
		int countvow();

private:
	char p[50];

};
void vowel::getvalue()
{
	cout<<"Enter the string:"<<endl;
	cin>>p;
}
int vowel::countvow()
{
	int i=0;
	int count=0;
	while(*(p+i)!=NULL)
	{
		if(*(p+i)=='A'||*(p+i)=='E'||*(p+i)=='I'||*(p+i)=='O'||*(p+i)=='U')
			count++;
		if(*(p+i)=='a'||*(p+i)=='e'||*(p+i)=='i'||*(p+i)=='o'||*(p+i)=='u')
			count++;
		i++;
	}
	return count;
}
int main()
{
	vowel v1;
	v1.getvalue();
	cout<<"The number of vowles are:"<<v1.countvow()<<endl;
	return 0;
}