#include<iostream>
#include<iomanip>  // header file inclusion

#define N 10 // macro to define maximum size of object array

using namespace std; // namespace declaration

class student // class student to hold student report
{
		char *stdName;
		int stdRollNo;
		int marks1,marks2,marks3;
		float per;
	public:
		student(); // externally defined constructor of student class
		void updateReport(); // externally defined method
		void displayReport(); // externally defined method
		~student(); // externally defined destructor od student class
};
student::student()
{
	/*
	input : none
	utility : Default constructor of class student
	output : none
	*/
	stdName=new char[20];
	stdRollNo=0;
	marks1=0;
	marks2=0;
	marks3=0;
	per=0.0;
}
void student::updateReport()
{
	/*
	input : none
	utility : Method of class student to update object values
	output : none
	*/
	cout<<"Please Enter your name: ";
	cin>>stdName;
	cout<<"Please Enter your roll number: ";
	cin>>stdRollNo;
	cout<<"Please Enter your marks in subject 1 : ";
	cin>>marks1;
	cout<<"Please Enter your marks in subject 2 : ";
	cin>>marks2;
	cout<<"Please Enter your marks in subject 3 : ";
	cin>>marks3;
}
void student::displayReport()
{
	/*
	input : none
	utility : Method of class student to display object values
	output : none
	*/
	per = (float)(marks1+marks2+marks3)/3;
	cout<<"|"<<setw(12)<<right<<stdName<<"|"<<setw(13)<<right<<stdRollNo<<"|"<<setw(9)<<right<<marks1<<"|"<<setw(9)<<right<<marks2<<"|"<<setw(9)<<right<<marks3<<"|"<<setw(11)<<right<<per<<"|"<<endl;
}
student::~student()
{
	/*
	input : none
	utility : Destructor of class student
	output : none
	*/
	delete stdName;
}
int main()
{
	/*
	input : none
	utility : Main function to drive the program
	output : none
	*/
	student A[N];
	int count,i;
	char choice;
	while(1)
	{
		cout<<"Menu\n1. Update Report\n2. Display Report\n3. Exit\nPlease enter your choice : ";
		cin>>choice;
		switch(choice)
		{
			case '1':
				cout<<"Enter the value for which you want to update report : ";
				cin>>count;
				A[count-1].updateReport();
				break;
			case '2':
				cout<<endl<<"|    Name    | Roll number | Marks 1 | Marks 2 | Marks 3 | Percetage |"<<endl;
				for(i=0;i<N;i++)
					A[i].displayReport();
				break;
			case '3':
				return 0;
			default:
				cout<<"Please enter a valid choice";
				break;
		}
	}
	return 0;
}
