Let's go through the code line by line and explain what it does:

## The header files

```cpp
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;
```

These lines include the necessary header files for input and output operations on the console and files, string streams, and input/output manipulators, and bring all the names in the standard library into the current scope.

## Entry point and input stream

```cpp
int main()
{
    ifstream infile; 
    istringstream ss; 
    int32_t n32_running_total [20] = {0};
    int32_t n32_review_count [20] = {0};
    infile.open("songRatings_hw2.tsv");
    if (!infile)
    {
        cout << "Error opening file songRatings_hw2.tsv" <<  endl;
        return 1;
    }
```

These lines define the `main()` function, which is the entry point of the program.

The program first declares an input file stream object named `infile`, a string stream object named `ss`, and two integer arrays `n32_running_total` and `n32_review_count`, both initialized to `0`.

The program opens the file `"songRatings_hw2.tsv"` for input using the `open()` method of the `infile` object.

If the file cannot be opened, the program displays an error message and exits with an error code.

## Reading from the file and updating the stats

```cpp
    uint32_t n32_count = 0;
    uint32_t n32_total = 0;
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
```

These lines read each line of the input file using the `getline()` function and stores it in a string variable named `songDetail`.

The program extracts the user ID, song ID, and rating from `songDetail` using the `>>` operator on the `ss` object, which is a string stream object initialized with `songDetail`. If the user ID is between `1` and `20` (inclusive), and the rating is not equal to `255` (which represents a missing value), the program adds the rating to the running total and increments the review count for the user.

```cpp
for (int i = 0; i < 20; i++)
{
    if (n32_review_count[i] > 0)
    {
        double d_average = (double)n32_running_total[i] / (double)n32_review_count[i];
        cout << "User ID" <<  setw(4) << i + 1 << " " << setw(8) << fixed << setprecision(2) << d_average << endl;
    }
}
```

After processing all the lines in the file, the program loops through the n32_review_count array and calculates the average rating for each user who has submitted a review. If a user has not submitted a review, the program skips that user.

## Closing the file

```cpp
    infile.close();
    return EXIT_SUCCESS;
}
```

Finally, the program closes the input file and returns a status code indicating successful termination.