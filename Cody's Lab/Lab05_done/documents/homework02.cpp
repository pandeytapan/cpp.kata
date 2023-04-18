#include <iostream> // for cout, cin
#include <fstream> // for file I/O
#include <sstream> // for string stream
#include <iomanip> // for setprecision
using namespace std;

int main()
{
    // open the file
    ifstream infile; //to read the input tsv file
    istringstream ss; // string stream
    int32_t n32_running_total [20] = {0};
    int32_t n32_review_count [20] = {0};
    // open the file
    infile.open("songRatings_hw2.tsv");
    if (!infile)
    {
        cout << "Error opening file sampleRatings.txt" <<  endl;
        return 1;
    }

    // read the file
    std::string songDetail;

    while (getline(infile, songDetail))
    {
        uint32_t n32_user_id;
        uint32_t n32_song_id;
        uint32_t n32_rating;
        
        ss.str(songDetail);
        ss >> n32_user_id >> n32_song_id >> n32_rating;
        if(n32_user_id > 0 && n32_user_id < 21)
        {
            if (n32_rating != 255)
            { 
                n32_running_total[n32_user_id - 1] += n32_rating;
                n32_review_count[n32_user_id - 1]++;
            }
        }
        ss.clear();
    }

    for (int i = 0; i < 20; i++)
    {
        if (n32_review_count[i] > 0)
        {
            double d_average = (double)n32_running_total[i] / (double)n32_review_count[i];
            cout << "User ID" <<  setw(4) << i + 1 << " " << setw(8) << fixed << setprecision(2) << d_average << endl;
        }
    }
    // close the file
    infile.close();
    return EXIT_SUCCESS;
}