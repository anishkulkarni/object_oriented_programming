#include<iostream>
#include<iomanip>
#include<string>

using namespace std;

typedef struct birthDate
{
	short int day;
	short int month;
	short int year;
}birthDate;

class personalDetails
{
	protected:
		string name;
		birthDate birth;
		string bg;
};

class professionalDetails
{
	protected:
		string year_exp;
		string skill_expertise;
};

class academicDetails
{
	protected:
		string degree_percentile;
};

class resume:protected personalDetails,protected professionalDetails,protected academicDetails
{
	public:
		void createResume()
		{
			cout<<"Please Enter details :"<<endl;
			cout<<"Name : ";
			getline(cin,name);
			cout<<"Birthdate (dd mm yyyy) : ";
			cin>>birth.day>>birth.month>>birth.year;
			cout<<"Blood Group : ";
			cin.ignore(1000,'\n');
			getline(cin,bg);
			cout<<"Years of experience : ";
			//cin.ignore(1000,'\n');
			getline(cin,year_exp);
			cout<<"Skill of expertise : ";
			//cin.ignore(1000,'\n');
			getline(cin,skill_expertise);
			cout<<"Percentile of Degree : ";
			//cin.ignore(1000,'\n');
			getline(cin,degree_percentile);
		}
		void displayResume()
		{
			cout<<endl<<endl<<endl;
			cout<<"\t\t\t\t\t\t\tResume\n\n\n";
			cout<<"\t\t\t\t\t\t     "<<name<<endl<<"\t\t\t\t\t\t     ";
			int i;
			for(i=0;i<name.length();i++)
				cout<<"-";
			cout<<endl<<endl;
			cout<<"\t\t\t\t\t\tBirthdate : "<<setw(2)<<birth.day<<" / "<<setw(2)<<birth.month<<" / "<<setw(4)<<birth.year<<endl;
			cout<<"\t\t\t\t\t\t            ";
			for(i=0;i<15;i++)
				cout<<"-";
			cout<<endl<<endl<<endl<<endl;
			cout<<"\t\t\tBlood Group : "<<bg<<endl;
			cout<<"\t\t\t              ";
			for(i=0;i<bg.length();i++)
				cout<<"-";
			cout<<endl<<endl;
			cout<<"\t\t\tYears of experience : "<<year_exp<<endl;
			cout<<"\t\t\t                      ";
			for(i=0;i<year_exp.length();i++)
				cout<<"-";
			cout<<endl<<endl;
			cout<<"\t\t\tSkill of Expertise : "<<skill_expertise<<endl;
			cout<<"\t\t\t                     ";
			for(i=0;i<skill_expertise.length();i++)
				cout<<"-";
			cout<<endl<<endl;
			cout<<"\t\t\tPercentile of degree : "<<degree_percentile<<endl;
			cout<<"\t\t\t                       ";
			for(i=0;i<degree_percentile.length();i++)
				cout<<"-";
			cout<<endl<<endl<<endl<<endl<<endl<<endl<<endl;
		}
};

int main()
{
	resume my_resume;
	my_resume.createResume();
	my_resume.displayResume();
	return 0;
}
