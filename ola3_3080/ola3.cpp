/*Author:  Lorenzo McDaniel
 *Course:  CSCI 3080
 *Lab number: Lab 3
 *Purpose: Program that performs matrix operations (addition, subtraction, multiplication and boolean multiplication) based on user input.
 *Due date: October 2, 2020
*/



#include <iostream>
#include <string>
using namespace std;


// function that adds matrix A and B. Matrix C will be updated with final result.
void add(int a[][10], int b[][10] , int c[][10], int row, int col) 
{
	for (int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			c[i][j] = a[i][j] + b[i][j];
		}
	}

}

// function that subtracts matrix A and B. Matrix C will be updated with final result.
void subtract(int a[][10], int b[][10] , int c[][10], int row, int col) 
{
	for (int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{
			c[i][j] = a[i][j] - b[i][j];
		}
	}

}


// function that performs multiplaction on matrix A and B. Matrix C will be updated with final result.
void multiply(int a[][10], int b[][10] , int c[][10], int row, int col) 
{

	for (int i = 0; i < row; i++)
	{
		
		for(int j = 0; j < col; j++)
		{
			c[i][j] = 0; 
			
			for (int k = 0; k < row; k++) 
                {
					c[i][j] += (a[i][k] *  b[k][j]); 

				}
			
		}
	}

}



// function that performs boolean multiplication on matrix A and B. Matrix C will be updated with final result.
void boolean_multiply(int a[][10], int b[][10] , int c[][10], int row, int col) 
{
	
	for (int i = 0; i < row; i++)
	{
		for(int j = 0; j < col; j++)
		{	
			bool val = false;
			for (int k = 0; k < row; k++) 
            {
				val = val || (a[i][k] && b[k][j]);
	
			}
			
			c[i][j] = val;	
		}
	}

}




int main()
{
// create the 3 2D arrays before accepting user input
	int A[10][10];

	int B[10][10];

	int C[10][10];

// create row and cols for both matrix A and B 
	int a_row;
	int a_col;

	int b_row;
	int b_col;

	int nums; // users matrix elements get entered into this variable

	char choice; // char used for user to make decisions 
	

// prompt user for array A
	std::cout << "input the row size and col of A" << endl;

	cin >> a_row >> a_col;

	std::cout << "input matrix A" << endl;


// input elements for array A
	for (int i = 0; i < a_row; i++)
	{
		for(int j = 0; j < a_col; j++)
		{
			cin >> nums;
			A[i][j] = nums;

		}

	}



// prompt user for array B 
	std::cout << "input the row size and col of B" << endl;

	cin >> b_row >> b_col;

	std::cout << "input matrix B" << endl;


	// input elements for array B
	for (int i = 0; i < b_row; i++)
	{
		for(int j = 0; j < b_col; j++)
		{
			cin >> nums;
			B[i][j] = nums;

		}

	}

	// prompt user for which operation they want to do , then cin their choice 

	std:cout << "choose your operation: A for add, S for subtract, M for multiply, B for boolean multiply" << endl;
	cin >> choice;



	// addition
	if (choice == 'A')
	{
		// need to check if can add the matrix
		// row and col for both matrix must match to do add operation
		if (a_row == b_row && a_col == b_col)
		{
			add(A,B,C,a_row,a_col); // if dimensions match do the add operation on the 2 matrixes

			// will print matrix to screen
			std::cout << "the answer is:" << endl;
			for (int i = 0; i < a_row; i++)
			{
				for(int j = 0; j < a_col; j++)
				{
					std::cout << C[i][j] << " ";
				}
				std::cout << "\n";
			}

		}
		else
		{
			std::cout << "dimensions are not compatible";
		}

	}

	// subtraction
	if (choice == 'S')
	{
		// need to check if can subtract the matrix
		// row and col for both matrix must match to do subtract operation
		if (a_row == b_row && a_col == b_col)
		{
			subtract(A,B,C,a_row,a_col); // if dimensions match do the subtract operation on the 2 matrixes

			// will print matrix to screen
			std::cout << "the answer is:" << endl;
			for (int i = 0; i < a_row; i++)
			{
				for(int j = 0; j < a_col; j++)
				{
					std::cout << C[i][j] << " ";
				}
				std::cout << "\n";
			}

		}
		else
		{
			std::cout << "dimensions are not compatible";
		}

	}
	
	// multiplication
	if (choice == 'M')
	{
		// need to check if can subtract the matrix
		// row and col for both matrix must match to do subtract operation
		if (a_col == b_row)
		{
			multiply(A,B,C,a_row,b_col); // if dimensions match do the multiply operation on the 2 matrixes

			// will print matrix to screen
			std::cout << "the answer is:" << endl;
			for (int i = 0; i < a_row; i++)
			{
				
				for(int j = 0; j < b_col; j++)
				{
					std::cout << C[i][j] << " ";
				}
				std::cout << "\n";
			}

		}
		else
		{
			std::cout << "dimensions are not compatible";
		}
	}

	// boolean multiplication
	if (choice == 'B')
	{
		// check the dimensions of A and B matrix to see if can continue 
		if (a_col == b_row)
		{
			boolean_multiply(A,B,C,a_row,b_col); // if dimensions match do the boolean multiply operation on the 2 matrixes

			// will print matrix to screen
			std::cout << "the answer is:" << endl;
			for (int i = 0; i < a_row; i++)
			{
				
				for(int j = 0; j < b_col; j++)
				{
					std::cout << C[i][j] << " ";
				}
				std::cout << "\n";
			}

		}
		else
		{
			std::cout << "dimensions are not compatible";
		}
	

	}


return 0;
}