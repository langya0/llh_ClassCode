#include<iostream>
using namespace std;

class Complex
{
public:
	Complex(double real,double image):
		_real(real),
		_image(image)
	{}
	void ShowComplex()
	{
		cout << _real << "+"<<_image<<"j" << endl;
	}
	bool operator==(const Complex& d)const
	{
		return (_real == d._real&&_image == d._image);
	}
	bool operator !=(const Complex& d)const
	{
		return !((*this) == d);
	}


private:
	double _real;
	double _image;
};