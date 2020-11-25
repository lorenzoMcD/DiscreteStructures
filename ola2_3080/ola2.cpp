/*Author:  Lorenzo McDaniel
 *Course:  CSCI 3080
 *Lab number: Lab 2
 *Purpose: Program that displays the boolean AND or boolean OR of P and Q based on user input.
 *Due date: September 18, 2020
*/



#include <iostream>
#include <string>
using namespace std;



int main()
{

	// create 2 arrays one for P and other for Q
	// hard code the appropriate truth value to P and Q vars 

	bool p_arr[4] = {true,true,false,false};

	bool q_arr[4] = {true,false,true,false};

	std::string InputString; // create var to get user input


	// ask user which path they want to take 
	std::cout << "Input an A if you want to calculate P AND Q" << endl;

	std::cout << "Input an O if you want to calculate P OR Q" << endl;



	cin >> InputString; // get user input


	// protect the user input to only match either "O" or "A"
	while (InputString!= "A" and InputString!= "O")
	{

		std::cout << "Input an A if you want to calculate P AND Q" << endl;

		std::cout << "Input an O if you want to calculate P OR Q" << endl;

		cin >> InputString; // get input again
		

	}

		// if user type A, progam will print the and table for P and Q arrays
		if (InputString == "A")

		{
			std::cout << "P AND Q is:" << endl;

			for (int i = 0; i < 4; i++)
			{

				if (p_arr[i] == true && q_arr[i] == true)
				{
				
					std::cout << "TRUE" << endl;

				}

				else if (p_arr[i] == false && q_arr[i] == false)
				{
					std::cout << "FALSE" << endl;

				}

				else
				{

				std:: cout << "FALSE" << endl;

				}


			}


		}
		

		// if user types O, progam will print the or table for P and Q arrays
		if (InputString == "O")

		{
			std::cout << "P OR Q is:" << endl;

			for (int i = 0; i < 4; i++)
			{

				if (p_arr[i] == true && q_arr[i] == true)
				{
				
					std::cout << "TRUE" << endl;

				}

				else if (p_arr[i] == true || q_arr[i] == false)
				{
					std::cout << "TRUE" << endl;

				}


				if (q_arr[i] == false && p_arr[i] == false)
				{
					std::cout << "FALSE" << endl;
					
				}


			}


		}

return 0;
}