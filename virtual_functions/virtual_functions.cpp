#include<iostream>
#include<math.h>

using namespace std;

class shape
{
	protected:
		float a,b,c;
	public:
		virtual float compute_area()=0;
		shape(float _a,float _b,float _c=0)
		{
			a=_a;
			b=_b;
			c=_c;
		}
};

class triangle : public shape
{
	public:
		float compute_area()
		{
			float s=(a+b+c)/2;
			return sqrt(s*(s-a)*(s-b)*(s-c));
		}
		triangle(float _a, float _b,float _c):shape(_a,_b,_c){}
};

class rectangle : public shape
{
	public:
		float compute_area()
		{
			return (a*b);
		}
		rectangle(float _a, float _b):shape(_a,_b){}
};

int main()
{
	shape *sp;
	float a,b,c;
	int choice;
	rectangle r(0,0);
	triangle t(0,0,0);
	do
	{
		cout<<"Menu\n1. Rectagle\n2. Triangle\n3. Exit\nChoice : ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Enter dimensions of rectangle (length breadth) : ";
				cin>>a>>b;
				r=rectangle(a,b);
				sp=&r;
				cout<<"Area of the rectangle is : "<<sp->compute_area()<<endl;
				break;
			case 2:
				cout<<"Enter dimensions of triangle (side-1 side-2 side-3) : ";
				cin>>a>>b>>c;
				t=triangle(a,b,c);
				sp=&t;
				cout<<"Area of the triagle is : "<<sp->compute_area()<<endl;
				break;
				break;
			case 3:
				return 0;
			default:
				cout<<"Please make a valid choice";
				cin.ignore(100,'\n');
		}
	}while(1);
	return 0;
}
