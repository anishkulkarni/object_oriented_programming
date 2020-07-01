#include<iostream>
#include<iomanip>
using namespace std;
int inputCount;
float hTSum=0,lTSum=0,rSum=0,sSum=0;
class weather
{
		int day;
		float highTemp, lowTemp, rainAmt, snowAmt;
	public:
		weather()
		{
			day=99;
			highTemp=999.0;
			lowTemp=-999.0;
			rainAmt=0.0;
			snowAmt=0.0;
		}
		void updateWeather(int dayUpdate)
		{
			day=dayUpdate;
			cout<<"Enter the high temperature of the day: ";
			cin>>highTemp;
			cout<<"Enter the low temperature of the day: ";
			cin>>lowTemp;
			cout<<"Enter the rain amount of the day: ";
			cin>>rainAmt;
			cout<<"Enter the snow amount of the day: ";
			cin>>snowAmt;
			hTSum+=highTemp;
			lTSum+=lowTemp;
			rSum+=rainAmt;
			sSum+=snowAmt;
		}
		void printReport()
		{
			cout<<"\n| ";
			cout<<setw(13)<<right<<day;
			cout<<"|"<<setw(18)<<right<<highTemp;
			cout<<"|"<<setw(17)<<right<<lowTemp;
			cout<<"|"<<setw(16)<<right<<rainAmt;
			cout<<"|"<<setw(16)<<right<<snowAmt<<"|";
		}
		
};
weather report[30];
int i,day,choice,dayC[30]={0},index=0;
void printMenu()
{
	cout<<"Menu\n1. Update weather report\n2. Display weather report\n3. Exit\nPlease choose an appopriate option : ";
}
void updateWeatherReport()
{
	int j;
	cout<<"How may days do you want to update the record for? : ";
	cin>>inputCount;
	for(i=0;i<inputCount;i++)
	{
		cout<<"Which day do you want to update the record for?: ";
		cin>>day;
		for(j=0;j<index;j++)
		{
			if(dayC[j]==day)
				break;
		}
		if(j==index)
		{
			dayC[index++]=day;
			report[day-1].updateWeather(day);
		}
		else
		{
			cout<<"This day has already been modified. Please try again : \n";
			i--;
		}
	}
}
void displayWeatherReport()
{
	cout<<"\n---------------------------------------------------------------------------------------";
		cout<<"\n| Day of month | high temperature | low temperature | Amount of rain | Amount of snow |";
		cout<<"\n---------------------------------------------------------------------------------------";
		for(i=0;i<30;i++)
		{
			report[i].printReport();
		}
		cout<<"\n---------------------------------------------------------------------------------------";
		cout<<"\n|  Average     |"<<setw(18)<<hTSum/inputCount<<"|"<<setw(17)<<lTSum/inputCount<<"|"<<setw(16)<<rSum/inputCount<<"|"<<setw(16)<<sSum/inputCount<<"|";
		cout<<"\n---------------------------------------------------------------------------------------\n";
}
int getChoice()
{
	while(1)
	{
		printMenu();
		cin>>choice;
		switch(choice)
		{
			case 1:
				updateWeatherReport();
				break;
			case 2:
				displayWeatherReport();
				break;
			case 3:
				return 0;
			default:
				cout<<"\nPlease input a valid choice.";
				break;
		}
	}
}
int main()
{
	getChoice();
	return 0;
}
