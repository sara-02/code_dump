#include <iostream>
#include <cstdlib>
using namespace std;

class ndoverload
{
public:
	void* operator new(size_t size);
	void operator delete(void* ptr);

};

void* ndoverload::operator new(sizer_t size)
{
	cout<<"Memory allocated"<<endl;
	return malloc(size);
}
void ndoverload::operator delete(void* ptr)
{
	cout<<"Memory freed"<<endl;
	free(ptr);
}
int main()
{
	ndoverload *nd1=new ndoverload();
	ndoverload *nd2=new ndoverload();
	delete nd1;
	ndoverload *nd3=new ndoverload();
	delete nd2;
	delete nd3;
	return 0;
}