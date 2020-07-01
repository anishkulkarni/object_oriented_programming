#include <iostream> //Header file inclusion

using namespace std; //Namespace declaration

void divide(float,float); //Prototype of functio to cary out division

int main()
{
	float i, j;
	cout << "Enter dividend : ";
	cin >> i;
	cout << "Enter divisor : ";
	cin >> j;
	divide(i, j); //function call for division
	return 0;

}

void divide(float a, float b)
{
	try //division and error checking
	{
		if(!b)
			throw b; // check for divide-by-zero
		cout<<a<<" / "<<b<<" = "<<a/b<<endl;
	} //handling the error
	catch (float b)
	{
		cout<<"Divisor = 0, invalid division"<<endl;
	}
}
