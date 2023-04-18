#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
	ifstream infile("sampleRatings.txt");
    int16_t n32_rating, n32_count = 0, n32_total = 0;
    string userId, songId;

    while (infile >> userId >> songId >> n32_rating) 
	{
        if (n32_rating != 255) 
		{ // ignore ratings of 255
            n32_total += n32_rating;
            n32_count++;
        }
    }

    infile.close();

    cout << "Total number of ratings: " << n32_count << endl;
    cout << "Total number of points: " << n32_total << endl;
    double f_average = (double)n32_total / n32_count;
    cout << fixed << setprecision(2) << f_average << endl;

    return 0;
}

