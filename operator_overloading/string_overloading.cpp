#include<iostream>
#include<string>
#include<cstring> //header file inclusion

using namespace std; //namespace declaration

class STRING
{
		char *str;
		int length;
	public:
		STRING(); //default constructor
		STRING(char *); //parameterized constructor
		STRING(int); //parameterized constructor
		friend ostream &operator <<(ostream &,STRING &); //overloaded operator for output
		friend istream &operator >>(istream &,STRING &); //overloaded operator for input
		friend STRING operator +(STRING,STRING); //overloaded operator for concatenation
		bool operator >(STRING); //overloaded operator for string comparison
		STRING operator ~(); //overloaded operator for string reverse
		bool operator !(); //overloaded operator for palindrome
		STRING operator -(STRING); //overloaded operator for deletion
}; //class for string

STRING operator +(STRING,STRING); //declaration of operator function for concatenation

ostream &operator <<(ostream &,STRING &); //declaration of operator function for output

istream &operator >>(istream &,STRING &); //declaration of operator function for input

int main()
{
	char temp[100];
	cout<<"Enter string 1 :";
	cin.getline(temp,100*sizeof(char));
	STRING a(temp);
	cout<<"Enter string 2 :";
	cin.getline(temp,100*sizeof(char));
	STRING b(temp);
	cout<<endl<<"The following strings were entered"<<endl<<"String 1 : "<<a<<endl<<"String 2 : "<<b;
	cout<<endl;
	if(a>b)
		cout<<endl<<"The given strings are equal.";
	else
		cout<<endl<<"The given strings are not equal";
	STRING c=a+b;
	cout<<endl<<endl<<"String 1 + String 2 = "<<c;
	cout<<endl<<endl<<"Enter a string to delete from both strings : ";
	cin>>temp;
	STRING d(temp);
	STRING e;
	cout<<endl<<"String 1 - given string = ";
	e=a-d;
	cout<<e;
	cout<<endl<<"String 2 - given string = ";
	e=b-d;
	cout<<e;
	cout<<endl<<endl<<"Reverse of string 1 is : ";
	e=~a;
	cout<<e;
	cout<<endl<<"Reverse of string 2 is : ";
	e=~b;
	cout<<e;
	cout<<endl;
	if(!a)
		cout<<endl<<"String 1 is palindrome";
	else
		cout<<endl<<"String 1 is not palindrome";
	if(!b)
		cout<<endl<<"String 2 is palindrome";
	else
		cout<<endl<<"String 2 is not palindrome";
	cout<<endl;
	return 0;
}

STRING::STRING() //definition of default constructor
{
	length=0;
	str = NULL;
}

STRING::STRING(char *s) //definition of parameterized constructor
{
	length=strlen(s);
	str=new char[length+1];
	strcpy(str,s);
}

STRING::STRING(int temp) //definition of parameterized constructor
{
	length =temp;
	str=new char[length];
}

ostream &operator <<(ostream &cout,STRING &str1) //definition of operator function for output
{
	cout<<str1.str;
	return cout;
}

istream &operator >>(istream &cin,STRING &str1) //definition of operator function for input
{
	cin>>str1.str;
	return cin;
}

STRING operator +(STRING str1,STRING str2) //definition of operator function for concatenation
{
	STRING temp;
	temp.str=new char[strlen(str1.str)+strlen(str2.str)];
	strcpy(temp.str,str1.str);
	strcpy(temp.str+strlen(str1.str),str2.str);
	return temp;
}

bool STRING::operator >(STRING str1) //definition of operator function for string comparison
{
	return bool(!strcmp(str1.str,str));
}

STRING STRING::operator ~() //definition of operator function for string reverse
{
	STRING temp;
	int i;
	temp.length=strlen(str);
	temp.str=new char[temp.length];
	for(i=0;i<temp.length;i++)
	{
		temp.str[temp.length-i-1]=str[i];
	}
	temp.str[temp.length]='\0';
	return temp;
}
bool STRING::operator !() //definition of operator function for palindrome
{
	int i;
	for(i=0;i<length/2;i++)
		if(str[i]!=str[length-i-1])
			break;
	if(i==length/2)
		return true;
	else
		return false;
}

STRING STRING::operator -(STRING sub) //definition of operator function for deleting
{
	int i,j,k;
	for(i=0;i<=length-sub.length;i++)
	{
		for(j=0;j<sub.length;j++)
		{
			if(str[i+j]!=sub.str[j])
				break;
		}
		if(j==sub.length)
		{
			for(k=i+j;str[k]!='\0';k++)
			{
				str[k-j]=str[k];
			}
			str[k-j]='\0';
			length-=sub.length;
		}
	}
	return *this;
}
