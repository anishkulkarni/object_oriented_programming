#include<cstdio>
#include<iostream>
#include<iomanip>

#define MAX 20

using namespace std;

void printHeader()
{
	cout << "| id |         Title        |        Author        |      Publisher       |  Price  |  Stock  |";
}

void printFooter()
{
	cout << "-----------------------------------------------------------------------------------------------";
}

class book
{
private:
	static int successful_transactions;
	static int unsuccessful_transactions;
	char *title;
	char *author;
	int price;
	char *publisher;
	int stock;
	int id;
public:
	book()
	{
		title = new char[20];
		author = new char[20];
		publisher = new char[20];
		stock = 200;
		price = 0;
		id = -1;
	}
	void createBook(int);
	static void displayTransactions();
	static void unsuccessfulTransaction();
	static void successfulTransaction();
	void createBook(int, int,char []);
	void displayBook();
	void updateStock(int);
	int searchBook_byTitle(char []);
	int searchBook_byAuthor(char []);
	int searchBook_byPublisher(char []);
	int searchBook_byPrice(int);
	int searchBook_byStock(int);
	void displayReciept(int);
	void updateBook();
	int sellBook(int);
};

int book::successful_transactions;
int book::unsuccessful_transactions;

void book::displayTransactions()
{
	cout << "-------------------------------------------------------";
	cout << endl << "| Successful Transactions | Unsuccessful Transactions |";
	cout << endl << "-------------------------------------------------------";
	cout << endl<<"| " << setw(23)<<successful_transactions<< " | " << setw(25)<<unsuccessful_transactions<< " |";
	cout << endl << "-------------------------------------------------------";
}
int book::sellBook(int qty)
{
	if (stock >= qty)
	{
		stock -= qty;
		successful_transactions++;
		return 1;
	}
	else
	{
		unsuccessful_transactions++;
		return 0;
	}
}

void book::unsuccessfulTransaction()
{
	unsuccessful_transactions++;
}

void book::successfulTransaction()
{
	successful_transactions++;
}

void book::displayReciept(int qty)
{
	cout << "\n------------------------------------------------------------------------------------------------------------";
	cout << "\n| id |         Title        |        Author        |      Publisher       |  Price  | Quanity | Total cost |";
	cout << "\n------------------------------------------------------------------------------------------------------------";
	cout << "\n| " << setw(2) << id << " | " << setw(20) << title << " | " << setw(20) << author << " | " << setw(20) << publisher << " | " << setw(7) << price << " | " << setw(7) << qty << " | " << setw(10) << qty * price << " |";
	cout << "\n------------------------------------------------------------------------------------------------------------";
}

void printMenu()
{
	cout <<"Menu\n1. Add book\n2. Update book\n3. Display Database\n4. Search book\n5. Purchase book\n6. Sell Book\n7. Display successfull and unsuccessful transactions\n8. Exit\nChoice : ";
}

void book::updateStock(int add)
{
	stock += add;
}

void book::displayBook()
{
	cout << "| " << setw(2) << id << " | " << setw(20) << title << " | " << setw(20) << author << " | " << setw(20) << publisher << " | " << setw(7) << price << " | " << setw(7) << stock << " | ";
}

void book::updateBook()
{
	int choice;
	while (1)
	{
		cout << "Chose the filed to modify\n1. Title\n2. Author\n3. Publisher\n4. Price\n5. Stock\n6. Done\nChoice : ";
		cin >> choice;
		switch (choice)
		{
		case  1:
			cout << "Enter the title of the book: ";
			cin >> title;
			cout << "Record successfully updated. The updated record is : ";
			cout << endl;
			printFooter();
			cout << endl;
			printHeader();
			cout << endl;
			printFooter();
			cout << endl;
			this->displayBook();
			cout << endl;
			printFooter();
			cout << endl;
			break;
		case 2:
			cout << "Enter the author of the book : ";
			cin >> author;
			cout << "Record successfully updated. The updated record is : ";
			cout << endl;
			printFooter();
			cout << endl;
			printHeader();
			cout << endl;
			printFooter();
			cout << endl;
			this->displayBook();
			cout << endl;
			printFooter();
			cout << endl;
			break;
		case 3:
			cout << "Enter the publisher of the book : ";
			cin >> publisher;
			cout << "Record successfully updated. The updated record is : ";
			cout << endl;
			printFooter();
			cout << endl;
			printHeader();
			cout << endl;
			printFooter();
			cout << endl;
			this->displayBook();
			cout << endl;
			printFooter();
			cout << endl;
			break;
		case 4:
			cout << "Enter the price of the book : ";
			cin >> price;
			cout << "Record successfully updated. The updated record is : ";
			cout << endl;
			printFooter();
			cout << endl;
			printHeader();
			cout << endl;
			printFooter();
			cout << endl;
			this->displayBook();
			cout << endl;
			printFooter();
			cout << endl;
			break;
		case 5:
			cout << "Enter the available stock of the book : ";
			cin >> stock;
			cout << "Record successfully updated. The updated record is : ";
			cout << endl;
			printFooter();
			cout << endl;
			printHeader();
			cout << endl;
			printFooter();
			cout << endl;
			this->displayBook();
			cout << endl;
			printFooter();
			cout << endl;
			break;
		case 6:
			return;
		default:
			cout << "Please enter a valid choice";
		}
	}
}

void book::createBook(int index)
{
	id = index;
	cout << "Enter the title of the book : ";
	cin >> title;
	cout << "Enter the name of the author of the book : ";
	cin >> author;
	cout << "Enter the name of the publisher of the book : ";
	cin >> publisher;
	cout << "Enter the price of the book : ";
	cin >> price;
	cout << "Enter the available stock of the book : ";
	cin >> stock;
}

void book::createBook(int index, int qty,char name[])
{
	int i=0;
	id = index;
	while (name[i] != '\0')
	{
		title[i] = name[i];
		i++;
	}
	title[i] = '\0';
	stock = qty;
	cout << "Enter the name of the author of the book : ";
	cin >> author;
	cout << "Enter the name of the publisher of the book : ";
	cin >> publisher;
	cout << "Enter the price of the book : ";
	cin >> price;
}

int book::searchBook_byTitle(char searchTitle[])
{
	int i;
	for (i = 0; title[i] != '\0'; i++)
		if (searchTitle[i] != title[i])
			break;
	if (title[i] == '\0')
		return 1;
	else
		return 0;
}

int book::searchBook_byAuthor(char searchAuthor[])
{
	int i;
	for (i = 0; author[i] != '\0'; i++)
		if (searchAuthor[i] != author[i])
			break;
	if (author[i] == '\0')
		return 1;
	else
		return 0;
}

int book::searchBook_byPublisher(char searchPublisher[])
{
	int i;
	for (i = 0; publisher[i] != '\0'; i++)
		if (searchPublisher[i] != publisher[i])
			break;
	if (publisher[i] == '\0')
		return 1;
	else
		return 0;
}

int book::searchBook_byPrice(int searchPrice)
{
	if (searchPrice==price)
		return 1;
	else
		return 0;
}

int book::searchBook_byStock(int searchStock)
{
	if (searchStock == stock)
		return 1;
	else
		return 0;
}

int main()
{
	int choice, i = 0, index = 0, count = 0, qty = 0;
	char name[20];
	book *bookShop;
	bookShop = new book[MAX];
	while (1)
	{
		printMenu();
		//while(getchar()!='\n');
		cin >> choice;
		switch (choice)
		{
		case 1:
			bookShop[index].createBook(index);
			cout<<"Following record added successfully :";
			cout<<endl;
			printFooter();
			cout << endl;
			printHeader();
			cout << endl;
			printFooter();
			cout << endl;
			bookShop[index].displayBook();
			cout << endl;
			printFooter();
			cout << endl;
			index++;
			break;
		case 2:
			if (index == 0)
			{
				cout << "No records exist." << endl;
			}
			else
			{
				while (1)
				{
					printFooter();
					cout << endl;
					printHeader();
					cout << endl;
					printFooter();
					for (i = 0; i < index; i++)
					{
						cout << endl;
						bookShop[i].displayBook();
						cout << endl;
						printFooter();
					}
					cout << endl << "Enter the id of the book you want to modify : ";
					cin >> choice;
					if (choice >= index)
					{
						cout << "Invalid id. Chose a valid id." << endl;
					}
					else
					{
						cout << "Following record selected :";
						cout << endl;
						printFooter();
						cout << endl;
						printHeader();
						cout << endl;
						printFooter();
						cout << endl;
						bookShop[choice].displayBook();
						cout << endl;
						printFooter();
						cout << endl;
						bookShop[choice].updateBook();
						break;
					}
				}
			}
			break;
		case 3:
			if(index==0)
				cout<<"No records exist"<<endl;
			else
			{
				cout<<"Following is the etire database :";
				cout<<endl;
				printFooter();
				cout << endl;
				printHeader();
				cout << endl;
				printFooter();
				for (i = 0; i < index; i++)
				{
					cout << endl;
					bookShop[i].displayBook();
					cout << endl;
					printFooter();
				}
				cout<<endl;
			}
			break;
		case 4:
			while (1)
			{
				cout << "Chose the field to search by :\n1.Title\n2.Author\n3.Publisher\n4.Price\n5.Stock\n6.Done\nChoice : ";
				cin >> choice;
				switch (choice)
				{
				case 1:
					cout << "Enter the title of the book to search : ";
					cin >> name;
					count = 0;
					for (i = 0; i < index; i++)
					{
						if (bookShop[i].searchBook_byTitle(name))
						{
							if (count == 0)
							{
								cout << "Following records found : ";
								cout << endl;
								printFooter();
								cout << endl;
								printHeader();
								cout << endl;
								printFooter();
								cout << endl;
							}
							bookShop[i].displayBook();
							cout << endl;
							printFooter();
							cout << endl;
							count++;
						}
					}
					if (count == 0)
					{
						cout << "Record not found.";
						cout << endl;
					}
					break;
				case 2:
					count = 0;
					cout << "Enter the name of the author to search : ";
					cin >> name;
					for (i = 0; i < index; i++)
					{
						if (bookShop[i].searchBook_byAuthor(name))
						{
							if (count == 0)
							{
								cout << "Following records found : ";
								cout << endl;
								printFooter();
								cout << endl;
								printHeader();
								cout << endl;
								printFooter();
								cout << endl;
							}
							bookShop[i].displayBook();
							cout << endl;
							printFooter();
							cout << endl;
							count++;
						}
					}
					if (count == 0)
					{
						cout << "Record not found.";
						cout << endl;
					}
					break;
				case 3:
					count = 0;
					cout << "Enter the name of the publisher to search : ";
					cin >> name;
					for (i = 0; i < index; i++)
					{
						if (bookShop[i].searchBook_byPublisher(name))
						{
							if (count == 0)
							{
								cout << "Following records found : ";
								cout << endl;
								printFooter();
								cout << endl;
								printHeader();
								cout << endl;
								printFooter();
								cout << endl;
							}
							bookShop[i].displayBook();
							cout << endl;
							printFooter();
							cout << endl;
							count++;
						}
					}
					if (count == 0)
					{
						cout << "Record not found.";
						cout << endl;
					}
					break;
				case 4:
					count = 0;
					cout << "Enter the price to search : ";
					cin >> qty;
					for (i = 0; i < index; i++)
					{
						if (bookShop[i].searchBook_byPrice(qty))
						{
							if (count == 0)
							{
								cout << "Following records found : ";
								cout << endl;
								printFooter();
								cout << endl;
								printHeader();
								cout << endl;
								printFooter();
								cout << endl;
							}
							bookShop[i].displayBook();
							cout << endl;
							printFooter();
							cout << endl;
							count++;
						}
					}
					if (count == 0)
					{
						cout << "Record not found.";
						cout << endl;
					}
					break;
				case 5:
					count = 0;
					cout << "Enter the stock to search : ";
					cin >> qty;
					for (i = 0; i < index; i++)
					{
						if (bookShop[i].searchBook_byStock(qty))
						{
							if (count == 0)
							{
								cout << "Following records found : ";
								cout << endl;
								printFooter();
								cout << endl;
								printHeader();
								cout << endl;
								printFooter();
								cout << endl;
							}
							bookShop[i].displayBook();
							cout << endl;
							printFooter();
							cout << endl;
							count++;
						}
					}
					if (count == 0)
					{
						cout << "Record not found.";
						cout << endl;
					}
					break;
				case 6:
					break;
				default:
					cout << "Please make a valid choice :";
					break;
				}
				if (choice == 6)
					break;
			}
			break;
		case 5:
			cout << "Enter the name of the book purchased : ";
			cin >> name;
			for (i = 0; i < index; i++)
			{
				if (bookShop[i].searchBook_byTitle(name))
				{
					cout << "Record found :";
					cout << endl;
					printFooter();
					cout << endl;
					printHeader();
					cout << endl;
					printFooter();
					cout << endl;
					bookShop[i].displayBook();
					cout << endl;
					printFooter();
					cout << endl;
					cout << "Enter the number of copies purchased : ";
					cin >> choice;
					bookShop[i].updateStock(choice);
					cout << "Summary of transaction :";
					bookShop[i].displayReciept(choice);
					cout << endl;
					cout << "Updated record is :";
					cout << endl;
					printFooter();
					cout << endl;
					printHeader();
					cout << endl;
					printFooter();
					cout << endl;
					bookShop[i].displayBook();
					cout << endl;
					printFooter();
					cout << endl;
					book::successfulTransaction();
					break;
				}
			}
			if (i == index)
			{
				cout << "Enter the number of copies to be added : ";
				cin >> choice;
				bookShop[index].createBook(index, choice, name);
				index++;
				cout << "New record added";
				cout << endl;
				cout << "Summary of transaction :";
				bookShop[index - 1].displayReciept(choice);
				cout << endl;
				cout << "Newly added record is :";
				cout << endl;
				printFooter();
				cout << endl;
				printHeader();
				cout << endl;
				printFooter();
				cout << endl;
				bookShop[i].displayBook();
				cout << endl;
				printFooter();
				cout << endl;
				book::successfulTransaction();
			}
			break;
		case 6:
			cout << "Which book is the sell order for : ";
			cin >> name;
			for (i = 0; i < index; i++)
			{
				if (bookShop[i].searchBook_byTitle(name))
				{
					cout << "Record found :";
					cout << endl;
					printFooter();
					cout << endl;
					printHeader();
					cout << endl;
					printFooter();
					cout << endl;
					bookShop[i].displayBook();
					cout << endl;
					printFooter();
					cout << endl;
					cout << "Enter the number of copies to be sold : ";
					cin >> choice;
					if (bookShop[i].sellBook(choice))
					{
						cout << "Transaction successful."<<endl<<"Updated record is :";
						cout << endl;
						printFooter();
						cout << endl;
						printHeader();
						cout << endl;
						printFooter();
						cout << endl;
						bookShop[i].displayBook();
						cout << endl;
						printFooter();
						cout << endl;
						break;
					}
					else
					{
						cout << "Transaction unsucssesful. Deficient stock.";
						cout << endl;
						break;
					}
				}
			}
			if (i == index)
			{
				cout << "Transaction unsucssesful. Book not present.";
				book::unsuccessfulTransaction();
				cout << endl;
			}
			break;
		case 7:
			book::displayTransactions();
			cout << endl;
			break;
		case 8:
			delete[]bookShop;
			return 0;
		default:
			cout << "Please make a valid choice.";
			cout << endl;
			//while(getchar()!='\n');
			//cin.ignore();
			break;
		}
	}
}
