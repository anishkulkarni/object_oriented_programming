#include<iostream>
using namespace std;

template<typename T>
void bubble_sort(T a[50],int n)
{
	int i,j,k,o,comp=0,comptt=0,swap=0,swaptt=0;
	T temp;
	cout<<"Initial |";
	for(o=0;o<n;o++)
	{
		cout<<a[o]<<"\t";
	}
	cout<<"|Swap="<<swap<<"|Comp="<<comp<<"|\n";
	for(i=0;i<n-1;i++)
	{
		swap=0;comp=0;
		for(j=0;j<(n-i-1);j++)
		{
			k=j+1;
			comp++;
			if(a[j]>a[k])
			{
				temp=a[j];
				a[j]=a[k];
				a[k]=temp;
				swap++;
			}
		}
		swaptt+=swap;
		comptt+=comp;
		cout<<"Pass="<<i+1<<"  |";
		for(o=0;o<n;o++)
		{
			cout<<a[o]<<"\t";
		}
		cout<<"|Swap="<<swap<<"|Comp="<<comp<<"|\n";
		if(swap==0)
			break;
	}
	cout<<"\nTotal Swap="<<swaptt<<"   Total Comp="<<comptt<<"\n\n";
}

int main()
{
	int a[50];
	float b[50];
	char c[50];
	int n,i,ch;
	while(1)
  	{
		cout<<"\nMenu\n1.Interger bubble sort\n2.Float bubble sort\n3.Char bubble sort\n4.Exit\n";
		cout<<"enter your choice : ";
		cin>>ch;
		switch(ch)
		{
		case 1:
			cout<<"Enter total number of elements : "	;
 			cin>>n;
 		 	for(i=0;i<n;i++)
 		 	{
 		 		cout<<"enter the element :";
 		 		cin>>a[i];
 		 	}
 	   	 	bubble_sort(a,n);
        		 break;
		case 2:
			cout<<"Enter total number of elements : "	;
 		 	cin>>n;
 		 	for(i=0;i<n;i++)
 		 	{
 				cout<<"enter the element :";
 				cin>>b[i];
 			}
 			bubble_sort(b,n);
			break;
		case 3:
			cout<<"Enter total number of elements : "	;
 		 	cin>>n;
 		 	for(i=0;i<n;i++)
 		 	{
 		 	cout<<"enter the element :";
 		 	cin>>c[i];
 			}
 			bubble_sort(c,n);
			break;

		case 4: 
			return 0;
			break;
		}
	}
	return 0;
}
