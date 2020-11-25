/*Author:  Lorenzo McDaniel
 *Course:  CSCI 3080
 *Lab number: Lab 4
 *Purpose: Give inverse of matrix 
 *Due date: October 16, 2020
*/


#include <iostream>
#include <string>
#include <cmath>
using namespace std;



int main()
{
	// create vars for matrix size, and matrix element inputs
	int size = 0;
	int nums = 0;

	// prompt user for matrix size 
	std::cout << "input row size ";

	cin >> size;


	

	// create 2 matrix 
	float A[10][10];
	float B[10][10];


	
	// prompt user to input elements of matrix 
	std::cout << "input the matrix to invert" << endl;



	// input elements for array A
	for (int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			cin >> nums;
			A[i][j] = nums;

		}

	}



	// creates identity matrix for B to match matrix A
	 for (int i = 0; i < size; i++) 
    { 
        for (int j = 0; j < size; j++) 
        { 
            
            if (i == j) 
                B[i][j] = 1; 
            else
                B[i][j] = 0; 
        } 
    }



    // calculate inverse
    float multiplier = 0;
	for (int i = 0; i < size; i++) 
	{	
		float divisor = A[i][i];
		for(int j = 0; j < size ; j++)  
		{
			
			A[i][j] /= divisor; 
			B[i][j] /= divisor; 
		}

		for (int k = 0; k < size; k++) 
        {

            if(k!=i) 
			{
				
				multiplier = A[k][i];
						
			}

		for(int n = 0; n < size; n++)
			{
				if(k!=i) 
				{

					A[k][n] = A[k][n] - (multiplier * A[i][n]); 
					B[k][n] = B[k][n] - (multiplier * B[i][n]); 
				}

			}	

		}


	}
	

	// print out the inverse matrix 
	std::cout << "the answer is:" << endl;
	for (int i = 0; i < size; i++)
	{
				
		for(int j = 0; j < size; j++)
		{
			std::cout << round(B[i][j])<< " ";
		}
		
		std::cout << "\n";
	
	}





return 0;
}