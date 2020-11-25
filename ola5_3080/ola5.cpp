/*Author:  Lorenzo McDaniel
 *Course:  CSCI 3080
 *Lab number: Lab 5
 *Purpose: Read nodes and adjacency relation into program. Program will then create adjacency matrix
 from the adjacency relation. Program will determine and print if there are any isolated nodes and if a Euler
 path exists.
 *Due date: October 28, 2020
*/


#include <iostream>
#include <string>
using namespace std;



int main()
{

	int nodes;


	// read in user input to create matrix 

	cout << "Please input the number of nodes: " << endl;


    cin >> nodes; // get the nodes 
    while (nodes > 10) // need to protect against input greater than 10 

    {
        cout << "Number of nodes must be less than or equal 10" << endl;
        cout << "Please input the number of nodes: " << endl;
        

        cin >> nodes;   
    }

	// create matrix 

	int matrix[10][10];
	int IsoNodes[nodes]; // array used to print out multiple isolated nodes at end 


	// x and y coordinates 
	int x;
	int y;
	
	// symbols in input gonna ignore 
	char punct1; 
	char punct2;
	char punct3;

	// need to set everything in matrix to zero 
	 for (int i = 0; i < 10; i++) 
    { 
        IsoNodes[i] = 0; 
        for (int j = 0; j < 10; j++) 
        { 
            matrix[i][j] = 0;

        }

    }
     
    cout << "Please input the adjacency relation: " << endl;
    

    punct3 = ' '; // set punct 3 = space 

    cin >> punct1 >> punct2;

    while (punct3!= '\n')
    {

    	cin >> x >> punct1 >> y;
    	
    	matrix[x-1][y-1] = 1;

    	cin >> punct1 >> punct2;
    	cin.get(punct3);
    	
    }
       
    int OddNodes = 0;
    int indexCapture; 
    bool isolated = false;
    bool eulerPath = false;
    

   
     for (int i = 0; i < nodes; i++)  // rows 
    { 
    	int count = 0;

        for (int j = 0; j < nodes; j++) // cols 
        { 
           
           if (matrix[i][j] == 1)
           {

           		count+=1;
           }

        }

        if (count == 0)
        {
        	indexCapture = i + 1;
        	IsoNodes[i] = indexCapture; 
        	isolated = true;
        }

        if (count % 2 != 0) 
        {
        	OddNodes+=1;
        }


    }

    
    if (OddNodes <=  2)
    {
        eulerPath = true;

    }



    // print the adjacency matrix
    cout << " " << endl;
    std::cout << "The Adjacency matrix is: " << endl;
	for (int i = 0; i < nodes; i++)
	{
				
		for(int j = 0; j < nodes; j++)
		{
			std::cout << matrix[i][j]<< " ";
		}
		
		std::cout << "\n";
	
	}

    cout << " " << endl;
   

	


	// print if there is a isolated node
	
	if (isolated == true)
	{	
		for (int i = 0; i < nodes; i++)

        {

        	if (IsoNodes[i] > 0)
        	{
        		std::cout << IsoNodes[i] << " is an isolated node " << endl;
        	
        	}

         
        }
		
	}

    else
    {

        std::cout << "There are no isolated nodes " << endl;


    }


	// print if Euler path exists or not 
	if (eulerPath == true)
	{

		std::cout << "An Euler path does exist in the graph. " << endl;
		
	}
	else
	{
		std::cout <<  "An Euler path does not exist in the graph. " << endl;

	}


return 0;

}