#include <iostream> // for cout, cin
#include <fstream> // for file I/
using namespace std; 

int main()
{
    ofstream outfile; // create output file stream object
    outfile.open("numbers.txt"); // open file for output
    
    for (int i = 0; i < 6; ++i)
    {
        outfile << i << endl; // write number to file
    }
    
    outfile.close(); // close file
    return EXIT_SUCCESS;
}
