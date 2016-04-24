#include <iostream>
using namespace std;

class matrix
{
private:
	int arr[3][3];
public:
	void getarr();
	void disparr();
	matrix operator +(const matrix& obj2);
	matrix operator -(const matrix& obj2);
};
void matrix::getarr()
{
	int i,j;
	cout<<"Filling the matrix:"<<endl;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			cin>>arr[i][j];

}
void matrix::disparr()
{
	int i,j;
	cout<<"The matrix is"<<endl;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			cout<<arr[i][j]<<"    ";
		}
		cout<<endl;
	}
}
matrix matrix::operator +(const matrix& obj2)
{
	matrix m;
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			m.arr[i][j]=this->arr[i][j]+obj2.arr[i][j];
return m;
}
matrix matrix::operator -(const matrix& obj2)
{
	matrix m;
	int i,j;
	for(i=0;i<3;i++)
		for(j=0;j<3;j++)
			m.arr[i][j]=this->arr[i][j]-obj2.arr[i][j];
return m;
}

int main()
{
	matrix arr1,arr2,arr3;
	cout<<"for the FIRST matrix"<<endl;
	arr1.getarr();
	arr1.disparr();
	cout<<"for the second matrix"<<endl;
	arr2.getarr();
	arr2.disparr();
	arr3=arr1+arr2;
	cout<<"SUM"<<endl;
	arr3.disparr();
	cout<<"DIFFERENCE"<<endl;
	arr3=arr1-arr2;
	arr3.disparr();
	return 0;
}