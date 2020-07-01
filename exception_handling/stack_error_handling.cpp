#include<iostream>
using namespace std;
class stack
{
	int top;
	int *st=NULL;
	int max;
	public:
	stack(int size)
	{
		max=size;
		top=-1;
		st=new int[max];	
	}
	void push(int);
	int pop();
	void display();
	~stack()
	{
		delete [] st;
		cout<<"memory deleted";
	}
};

void stack::push(int num)
{
	if(top==max-1)
		throw(num);
	else
	{
		st[++top]=num;
	}
	
}

int stack::pop()
{
	if(top==-1)
		throw(1);
	else
	{
		return st[top--];
	}
	
}

void stack::display()
{
	int i;
	if(top==-1)
		throw(1);
	for(i=0;i<=top;i++)
	{
		cout<<st[top]<<endl;
	}
	
}

int main()
{
	int size;
	cout<<"Enter size of stack : ";
	cin>>size;
	stack s1(size);
	int ch,num;
	while(1)
	{
		cout<<"\nMenu"<<endl<<"1.Push\n2.Pop\n3.Display\n4.Exit\n";
		cout<<"Enter your choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1: 
			try
			{
				cout<<"\nEnter number : ";
				cin>>num;
				s1.push(num);
			}
			catch(int i)
			{
				cout<<"Stack overflow";
			}
			break;
		case 2:
			try
			{
				num=s1.pop();
				cout<<"\nPopped element is : "<<num;
			}
			catch(int i)
			{
				cout<<"Stack empty";
			}
			break;
		case 3:
			try
			{
				s1.display();
			}
			catch(int i)
			{
				cout<<"Stack empty";
			}
			break;

		case 4: 
			break;
		}
	}
	return 0;
}
