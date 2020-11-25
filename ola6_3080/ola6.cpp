/*Author:  Lorenzo McDaniel
 *Course:  CSCI 3080
 *Lab number: Lab 6
 *Purpose: decode packets from file. check for error in packet and extract gray code.
 After extracting graycode program will convert code to binary then to decimal to output 
 a message after reading all packets in packets.dat file.
 *Due date: November 23, 2020
*/

#include <iostream>
using namespace std;


// function that converts binary to decimal 
int conversion(int array[], int len); 


int main()

{

    char packet[13]; // char array to hold packets 

    int binary[8]; // int array for the binary code

    string gray; // used to hold the gray code after extracting from packet

    int errorArr[4]; // arrary used to calculate the error code

    int onesCount; // counts the odd number of 1's 

    char character; // used to print the ASCII conversion of decimalValue

    int decimalValue; // holds the decimal value of binary code

    int error; // holds the index of error to correct in the packet




    // read file to end 
    while(cin >> packet)

    {

        // reset all vars before reading next packet 
        gray = "";

        onesCount = 0;

        character = ' ';

        decimalValue = 0;

        error = 0;


        // check for error    
        errorArr[0] = (packet[7] + packet[8] + packet[9] + packet[10] + packet[11]) % 2;

        errorArr[1] = (packet[3] + packet[4] + packet[5] + packet[6] + packet[11]) % 2;

        errorArr[2] = (packet[1] + packet[2] + packet[5] + packet[6] + packet[9] + packet[10]) % 2;

        errorArr[3] = (packet[0] + packet[2] + packet[4] + packet[6] + packet[8] + packet[10]) % 2;


        // calculate the index postion of the error 
        error = errorArr[0]*8 + errorArr[1]*4 + errorArr[2]*2 + errorArr[3]*1; 


        
        // only do error correction if there is an error
        if (error != 0)

        {

        // if error correct it 

            if (packet[error-1] == '1')

            {
                packet[error-1] = '0';
            }

            else
            {

                packet[error-1] = '1';

            }

        }

        // extract gray code
        for (int i = 0; i < 13; i++)
        {
            // ignore the parity bits (1248) subtract one to account for the 0 index

            if( i !=0 && i != 1 && i != 3 && i !=7 ) 
            {

                gray+= packet[i];
            }
        }

        // convert gray to binary 

                if (gray[0] == '1')
                {

                    binary[0] = 1;
                }
                else
                {
                    binary[0] = 0;
                }

        for (int i = 1; i <= 8; i++)
        {

            if (gray[i-1] == '1')
            {

                onesCount++; // count number of ones 

            }

            if (onesCount % 2 == 0) // if even number of ones
            {

                if (gray[i] == '1')
                {

                    binary[i] = 1;

                }
                else
                {

                    binary[i] = 0;

                }

            }

            else // odd number of ones 
            {

                if(gray[i] == '1')
                {

                    binary[i] = 0;

                }
                
                if(gray[i] == '0')
                {

                    binary[i] = 1;

                }

            }

        }

        // convert binary to decimal 
    
        decimalValue = conversion(binary, 8);
      
        // subtract 3 from the decimal value to get correct letter of packet
        character = (decimalValue - 3 );

        cout << character;

    }

    

    return 0;

}


// function that converts binary to decimal
int conversion(int array[], int len) {
    int output = 0;
    int power = 1;

    for (int i = 0; i < len; i++)
    {
        output += array[(len - 1) - i] * power;
        
        power *= 2;
    }

    return output;
}



