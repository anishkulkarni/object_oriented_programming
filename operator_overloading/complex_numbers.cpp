#include<iostream>
using namespace std;
class Complex
{
		float x,y;
	public:
		Complex()
		{
			x=0.0;
			y=0.0;
		}
		Complex(float a,float b)
		{
			x=a;
			y=b;
		}
		friend Complex operator +(Complex ,Complex);
		friend Complex operator -(Complex ,Complex);
		Complex operator *(Complex);
		Complex operator /(Complex);
		friend ostream &operator <<(ostream & ,Complex);
		friend istream &operator >>(istream &,Complex c);
};

Complex operator +(Complex c1,Complex c2)
{
	return Complex(c1.x+c2.x,c1.y+c2.y);
}

Complex operator -(Complex c1,Complex c2)
{
	return Complex(c1.x-c2.x,c1.y-c2.y);
}

Complex Complex::operator *(Complex c)
{
	return Complex(x*c.x-y*c.y,x*c.y+y*c.x);
}

Complex Complex::operator /(Complex c)
{
	return Complex((x*c.x+y*c.y)/(x*c.x+y*c.y),(y*c.x-x*c.y)/(x*c.x+y*c.y));
}

ostream &operator <<(ostream &cout,Complex c)
{
	cout<<c.x<<" + "<<c.y<<" i";
	return cout;
}

istream &operator >>(istream &cin,Complex c)
{
	cin>>c.x>>c.y;
	return cin;
}

int main()
{
	Complex c1(1,2),c2(3,4),c3;
	cout<<"Enter the 1st complex number : ";
	cin>>c1;
	cout<<"Enter the 2st complex number : ";
	cin>>c2;
	c3=c1+c2;
	cout<<"c1 + c2 = "<<c3;
	cout<<endl;
	c3=c1-c2;
	cout<<"c1 - c2 = "<<c3;
	cout<<endl;
	c3=c1*c2;
	cout<<"c1 * c2 = "<<c3;
	cout<<endl;
	c3=c1/c2;
	cout<<"c1 / c2 = "<<c3;
	cout<<endl;
}
