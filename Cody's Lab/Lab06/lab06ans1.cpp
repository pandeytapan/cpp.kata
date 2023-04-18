#include <iostream>
using namespace std;

int main()
{
    int mySquare[3][3];
    
    // initialize all values to -1
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            mySquare[i][j] = -1;
        }
    }
    
    // print the values of mySquare
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            cout << mySquare[i][j] << " ";
        }
        cout << endl;
    }
    
    return 0;
}
