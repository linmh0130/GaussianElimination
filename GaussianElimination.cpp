/** An Example to solve  Equations Ax = b **/
/*  Coding by Lin Menghan of XJTU
 *  Using Gaussian Elimination and Column Pivot Element
 *  I wish you like this code!
*/
#include <iostream>
#include <vector>
#include <cmath>
#include <stdlib.h>

using namespace std;

vector<vector<double> > A; // The matrix A
vector<double> tmp, b;     // a temp vector and the vector b

// Use functions to get martix A and vector b
void getA(int n)
{
	double a; // a number in A
	cout<<"Please input the matrix A:"<<endl;
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
		{
			cin>>a;
			tmp.push_back(a); // Save row vector in tmp first
		}
		A.push_back(tmp); // Then put tmp into A
		tmp.clear(); // Clean tmp for next row vector
	}
}
void getb(int n)
{
	double a;	// a number in b
	cout<<"Please input the vector b:"<<endl;
	for (int i=0;i<n;i++)
	{
		cin>>a;
		b.push_back(a);
	}
}

//Solve the problem by Gaussian Elimination
void Solve(int n)
{
	double TmpDouble;
	int TmpInt;
	
	for (int j=0;j<n;j++)
	{
		// Find column pivot element,
		// the largest number in column vector
		TmpInt = j;
		for (int i=j+1;i<n;i++)
		{
			if (abs(A[i][j]) > abs(A[TmpInt][j]))
			{
				TmpInt = i;
			}
		}
		
		// swap A[j] with the vector has largest number in j
		if (A[TmpInt][j] == 0)
		{	// at this time, det(A) = 0
			cerr<<"Error! The program may have no solution."<<endl;
			exit(1); 
		}
		if (TmpInt!=j)
		{
			tmp = A[j];
			A[j] = A[TmpInt];
			A[TmpInt] = tmp;
			
			TmpDouble = b[j];
			b[j] = b[TmpInt];
			b[TmpInt] = TmpDouble;
		}
		
		// Gaussian Elimination
		for (int i=j+1;i<n;i++)
		{
			double c = A[i][j] / A[j][j]; // The rate to minus
			A[i][j] = 0;
			for (int k=j+1;k<n;k++)
			{
				A[i][k] = A[i][k] - c * A[j][k];
			}
			b[i] = b[i] - c * b[j];
		}
	}
	// Return to get vector x and save in b
	for (int i=n-1;i>=0;i--)
	{
		TmpDouble = 0;	//b[i] should minus something
		for (int k=i+1;k<n;k++)
		{
			TmpDouble += b[k] * A[i][k]; 
		}
		b[i] -= TmpDouble;
		b[i] /= A[i][i];
	}
}

int main()
{
	int n = 0; // The rank of A
	cout<<"Solving Ax = b by Gaussian Elimination"<<endl;
	cout<<"--------------------------------------"<<endl;
	cout<<"This program can only solve questions "
	      "with just one solution.\n"<<endl;
	while(n<1)
	{
		cout<<"Please input the rank of A:";
		cin>>n;
		if (n<1) cout<<"Please input a number larger than 1!"<<endl;
	}
	getA(n);getb(n);
	Solve(n); // To Solve
	
	// The code follows in /**/ is use to debug
	/*
	for (int i=0;i<n;i++)
	{
		for (int j=0;j<n;j++)
			cout<<A[i][j]<<' ';
		cout<<endl;
	}*/
	
	//Output
	cout<<"x = [";
	for (int i=0;i<n;i++)
	{
		cout<<b[i]<<' ';
	}
	cout<<']'<<endl;
	
	return 0;
}
