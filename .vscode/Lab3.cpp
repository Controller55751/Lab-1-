#include <iostream>
#include <string>
#include <cstdlib>
#include <ctime>

int main() {
    // Seed the random number generator so recommendations change on every run
    std::srand(std::time(0));

    const int SIZE = 11;

    std::string songs[SIZE] = {
        "We Found Love", "Old Town Road", "Somebody That I Used To Know",
        "Despacito", "Rolling In The Deep", "Without Me", "Call Me Maybe",
        "Perfect", "Blurred Lines", "I Like It", "Just The Way You Are"
    };

    int songsReleaseYear[SIZE] = {
        2011, 2020, 2012, 2017, 2011, 2019, 2012, 2013, 2017, 2018, 2010
    };

    // Track the index of the newest and oldest songs
    int newestIndex = 0;
    int oldestIndex = 0;

    for (int i = 1; i < SIZE; i++) {
        if (songsReleaseYear[i] > songsReleaseYear[newestIndex]) {
            newestIndex = i;
        }
        if (songsReleaseYear[i] < songsReleaseYear[oldestIndex]) {
            oldestIndex = i;
        }
    }

    // Pick a random index from 0 to SIZE - 1
    int randomIndex = std::rand() % SIZE;

    // Output results
    std::cout << "Newest Song in the List: " << songs[newestIndex] << std::endl;
    std::cout << "Oldest Song in the List: " << songs[oldestIndex] << std::endl;
    std::cout << "Random Song recommendation: " << songs[randomIndex] << std::endl;

    return 0;
}