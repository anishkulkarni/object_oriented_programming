#include<iostream>
#include<string>

using namespace std;

typedef struct birth
{
        short int day;
        short int month;
        short int year;
}birth;

class details
{
        protected:
                string name;
                birth birthDate;
                short int bg;
        public:
                details()
                {
                        name='\0';
                        birthDate.day=0;
                        birthDate.month=0;
                        birthDate.year=0;
                        bg=8;
                }
                ~details()
                {
                	name.~string();
		}
};

class specs
{
        protected:
                float height;
                float weight;
        public:
                specs()
                {
                        height=0.0;
                        weight=0.0;
                }
                ~specs()
                {
		}
};

class policy
{
        protected:
                string policyNo;
                string address;
        public:
                policy()
                {
                        policyNo='\0';
                        address='\0';
                }
                ~policy()
                {
                	policyNo.~string();
                	address.~string();
		}
};

class contact : private details, private specs, private policy
{
        private:
                long int tel;
                string licenceNo;
        public:
                contact()
                {
                        tel=0;
                        licenceNo='\0';
                }
                void printRecord()
                {
                	cout<<"Name : "<<name;
             		cout<<endl<<"Birthdate : "<<birthDate.day<<" / "<<birthDate.month<<" / "<<birthDate.year;
             		cout<<endl<<"BloodGroup : ";
             		switch(bg)
             		{
             			case 1:
             				cout<<"A-";
             				break;
             			case 2:
             				cout<<"A+";
             				break;
             			case 3:
             				cout<<"B-";
             				break;
             			case 4:
             				cout<<"B+";
             				break;
             			case 5:
             				cout<<"O-";
             				break;
             			case 6:
             				cout<<"O+";
             				break;
             			case 7:
             				cout<<"AB-";
             				break;
             			case 8:
             				cout<<"AB+";
             				break;
			}
             		cout<<endl<<"Height : "<<height<<" cm";
             		cout<<endl<<"Weight : "<<weight<<" kg";
             		cout<<endl<<"Policy Number : "<<policyNo;
             		cout<<endl<<"Address : "<<address;
		}
		void addRecord()
		{
			cout<<"Name : ";
			getline(cin,name);
			cout<<"Birthdate (dd mm yyyy) : ";
			cin>>birthDate.day>>birthDate.month>>birthDate.year;
			do
			{
				cout<<"Chose blood group from the following :";
				cout<<endl<<"1. A-\n2. A+\n3. B-\n4. B+\n5. O-\n6. O+\n7. AB-\n8. AB+n\nChoice : ";
				cin>>bg;
				if(bg<1||bg>8)
					cout<<"Invalid choice please try again"<<endl;
			}while(bg<1||bg>8);
			cout<<"Height (cm) : ";
			cin>>height;
			cout<<"Weigth (kg) : ";
			cin>>weight;
			cout<<"Policy Number : ";
			cin.ignore(1000,'\n');
			getline(cin,policyNo);
			cout<<"Address : ";
			getline(cin,address);
		}
		void copy(contact temp)
		{
			name=temp.name;
			birthDate.day=temp.birthDate.day;
			birthDate.month=temp.birthDate.month;
			birthDate.year=temp.birthDate.year;
			bg=temp.bg;
			height=temp.height;
			weight=temp.weight;
			policyNo=temp.policyNo;
			address=temp.address;
		}
		bool search(string nameToSearch)
		{
			if(name==nameToSearch)
				return true;
			return false;
		}
		~contact()
		{
			licenceNo.~string();
		}
};

void printMenu();

int main()
{
        contact *database=NULL,*temp=NULL;
        int choice,size,index=0,i,tempint;
        string name;
        do
        {
               printMenu();
               cin>>choice;
               switch(choice)
               {
              	case 1:
              		if(database==NULL)
              		{
		      		cout<<"Enter the number of records you want to add : ";
		      		cin>>size;
		      		database=new contact[size];
		      		cout<<"Master table successfully created"<<endl;
		      	}
		      	else
			{
				cout<<"You are about to overwrite the previous database"<<endl<<"Current database has "<<index<<" spaces occupied and "<<size<<" spaces free"<<endl;
				cout<<"1. Overwrite and continue"<<endl<<"2. Cancel"<<endl<<"Choice : ";
				cin>>choice;
				switch(choice)
				{
					case 1:
						for(i=0;i<index;i++)
						{
							database[i].~contact();
						}
						//delete database;
					      	cout<<"Enter the number of records you want to add : ";
					      	cin>>size;
					      	database=new contact[size];
					      	cout<<"Master table successfully created"<<endl;
						break;
					case 2:
						cout<<"Transaction cancelled"<<endl;
						break;
					default:
						cout<<"Invalid choice transaction cancelled"<<endl;
						break;
				}
			}
			break;
		case 2:
			if(database!=NULL)
			{
				if(index!=0)
				{
					cout<<"Following "<<index<<" records found"<<endl;
					for(i=0;i<index;i++)
					{
						cout<<"Record "<<i+1<<" :"<<endl;
						database[i].printRecord();
						cout<<endl;
					}
				}	
				else
					cout<<"No records found"<<endl;
			}
			else
				cout<<"Please create a master table using option 1 first."<<endl;
			break;
		case 3:
			if(database!=NULL)
			{
				if(index<size)
				{
					cout<<"Enter the details of the record to be inserted :"<<endl;
					cin.ignore(100,'\n');
					database[index].addRecord();
					index++;
				}
				else
				{
					cout<<"Database full"<<endl;
				}
			}
			else
				cout<<"Please create a master table using option 1 first."<<endl;
			break;
		case 4:
			if(database!=NULL)
			{
				cout<<"Enter the name of the record to be deleted : ";
				cin.ignore(1000,'\n');
				getline(cin,name);
				for(i=0;i<index;i++)
					if(database[i].search(name))
						break;
				if(i<index)
				{
					for(;i<index-1;i++)
					{
						database[i].copy(database[i+1]);
					}
					index--;
					cout<<"Record successfully deleted";
				}
				else
					cout<<"Record not found";
					cout<<endl;
			}
			else
				cout<<"Please create a master table using option 1 first."<<endl;
			break;
		case 5:
			if(database!=NULL)
			{
				cout<<"Enter the name of the record to be modified : ";
				cin.ignore(1000,'\n');
				getline(cin,name);
				for(i=0;i<index;i++)
					if(database[i].search(name))
						break;
				if(i<index)
				{
					cout<<"Following record found :"<<endl;
					database[i].printRecord();
					cout<<endl;
					cout<<"Enter the modified details: "<<endl;
					database[i].addRecord();
					cout<<"Record successfully modified";
				}
				else
					cout<<"Record not found";
					cout<<endl;
			}
			else
				cout<<"Please create a master table using option 1 first."<<endl;
			break;
		case 6:
			if(database!=NULL)
			{
				cout<<"Enter the name of the record to be searched : ";
				cin.ignore(1000,'\n');
				getline(cin,name);
				for(i=0;i<index;i++)
					if(database[i].search(name))
						break;
				if(i<index)
				{
					cout<<"Following record found :"<<endl;
					database[i].printRecord();
				}
				else
					cout<<"Record not found";
					cout<<endl;
			}
			else
				cout<<"Please create a master table using option 1 first."<<endl;
			break;
		case 7:
			if(database!=NULL)
			{
			}
			else
				cout<<"Please create a master table using option 1 first."<<endl;
			return 0;
		default:
			cout<<"Please enter a vaid choice."<<endl;
			break;
               }
               
        }while(1);
        return 0;
}

void printMenu()
{
	cout<<"Menu"<<endl<<"1. Create Master Table"<<endl<<"2. Display Master Table"<<endl<<"3. Add Record"<<endl<<"4. Delete Record"<<endl<<"5. Edit Record"<<endl<<"6. Search record"<<endl<<"7. Exit"<<endl<<"Choice : ";
}
