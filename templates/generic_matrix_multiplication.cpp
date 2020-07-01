#include<iostream> //header file inclusion

using namespace std; //namespace declaration

template <class matrix> class Matrix
{
		matrix *mat;
		int rows;
		int columns;
	public:
		Matrix(int r,int c)
		{
			rows=r;
			columns=c;
			mat = new matrix[rows*columns];
		}
		Matrix()
		{
			rows=columns=0;
			mat=NULL;
		}
		void createMatrix(int r,int c)
		{
			delete []mat;
			rows=r;
			columns=c;
			mat = new matrix[rows*columns];
		}
		void input()
		{
			for(int i=0;i<rows;i++)
			{
				for(int j=0;j<columns;j++)
				{
					cout<<"Element ["<<i<<"]["<<j<<"] : ";
					cin>>mat[i*rows+j];
				}
			}
		}
		void display()
		{
			for(int i=0;i<rows;i++)
			{
				for(int j=0;j<columns;j++)
					cout<<"\t"<<mat[i*rows+j];
				cout<<endl;
			}
		}
		Matrix operator +(Matrix m)
		{
			if(rows==m.rows && columns==m.columns)
			{
				Matrix temp(rows,columns);
				for(int i=0;i<rows;i++)
				{
					for(int j=0;j<columns;j++)
					{
						temp.mat[i*rows+j]+=mat[i*rows+j]+m.mat[i*rows+j];
					}
				}
				return temp;
			}
			else
			{
				Matrix temp;
				return temp;
			}
		}
		Matrix operator -(Matrix m)
		{
			if(rows==m.rows && columns==m.columns)
			{
				Matrix temp(rows,columns);
				for(int i=0;i<rows;i++)
				{
					for(int j=0;j<columns;j++)
					{
						temp.mat[i*rows+j]+=mat[i*rows+j]-m.mat[i*rows+j];
					}
				}
				return temp;
			}
			else
			{
				Matrix temp;
				return temp;
			}
		}
		bool isMatrix()
		{
			if(mat==NULL)
				return false;
			else
				return true;
		}
};

int main()
{
	Matrix<int> m_i_1,m_i_2,m_i_3;
	int r,c;
	cout<<"Integer version of Matrix class : "<<endl;
	cout<<endl<<"Enter rows of first matrix : ";
	cin>>r;
	cout<<"Enter columns of first matrix : ";
	cin>>c;
	m_i_1.createMatrix(r,c);
	m_i_1.input();
	cout<<"Enter rows of second matrix : ";
	cin>>r;
	cout<<"Enter columns of second matrix : ";
	cin>>c;
	m_i_2.createMatrix(r,c);
	m_i_2.input();
	cout<<endl<<"Matrix 1 = "<<endl;
	m_i_1.display();
	cout<<endl<<"Matrix 2 = "<<endl;
	m_i_2.display();
	m_i_3=m_i_1+m_i_2;
	if(m_i_3.isMatrix())
	{
		cout<<endl<<"Matrix 1 + Matrix 2 = "<<endl;
		m_i_3.display();
	}
	else
	{
		cout<<endl<<"Rows and Columns of both matrices are not equal"<<endl<<"Addition not possible"<<endl;
	}
	m_i_3=m_i_1-m_i_2;
	if(m_i_3.isMatrix())
	{
		cout<<endl<<"Matrix 1 - Matrix 2 = "<<endl;
		m_i_3.display();
	}
	else
	{
		cout<<endl<<"Rows and Columns of both matrices are not equal"<<endl<<"Subtraction not possible"<<endl;
	}
	Matrix<float> m_f_1,m_f_2,m_f_3;
	cout<<"Float version of Matrix class : "<<endl;
	cout<<endl<<"Enter rows of first matrix : ";
	cin>>r;
	cout<<"Enter columns of first matrix : ";
	cin>>c;
	m_f_1.createMatrix(r,c);
	m_f_1.input();
	cout<<"Enter rows of second matrix : ";
	cin>>r;
	cout<<"Enter columns of second matrix : ";
	cin>>c;
	m_f_2.createMatrix(r,c);
	m_f_2.input();
	cout<<endl<<"Matrix 1 = "<<endl;
	m_f_1.display();
	cout<<endl<<"Matrix 2 = "<<endl;
	m_f_2.display();
	m_f_3=m_f_1+m_f_2;
	if(m_f_3.isMatrix())
	{
		cout<<endl<<"Matrix 1 + Matrix 2 = "<<endl;
		m_f_3.display();
	}
	else
	{
		cout<<endl<<"Rows and Columns of both matrices are not equal"<<endl<<"Addition not possible"<<endl;
	}
	m_f_3=m_f_1-m_f_2;
	if(m_f_3.isMatrix())
	{
		cout<<endl<<"Matrix 1 - Matrix 2 = "<<endl;
		m_f_3.display();
	}
	else
	{
		cout<<endl<<"Rows and Columns of both matrices are not equal"<<endl<<"Subtraction not possible"<<endl;
	}
	return 0;
}