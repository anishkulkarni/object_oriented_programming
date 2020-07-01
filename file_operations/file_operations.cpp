#include<iostream>
#include<fstream>
using namespace std;
int main()
{
	string s;
	fstream f;
	f.open("content.txt",ios::app);
	cout<<"\nEnter input string : ";
	getline(cin,s);
	f<<s;
	f.close();
	cout<<"\nThe string has been successfully printed to 'content.txt'\n";
	f>>s;
	f.close();
	cout<<"\nThe retrieved conents from 'content.txt' are :\n\n";
	cout<<s<<endl<<endl;
	return 0;
}
