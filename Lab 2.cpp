#include <iostream>
#include <string>
#include <cctype>

void missmess(std::string w) {
    if (w.empty()) {
        std::cout << w << std::endl;
        return;
    }

    // Convert first and last characters to lowercase for comparison
    char firstChar = std::tolower(w.front());
    char lastChar = std::tolower(w.back());

    bool startsWithM = (firstChar == 'm');
    bool endsWithS = (lastChar == 's');

    if (startsWithM && endsWithS) {
        std::cout << "missmess" << std::endl;
    } else if (startsWithM) {
        std::cout << "miss" << std::endl;
    } else if (endsWithS) {
        std::cout << "mess" << std::endl;
    } else {
        std::cout << w << std::endl;
    }
}

int main() {
    std::string input;

    while (true) {
        std::cout << "Enter a string (or $$$ to quit): ";
        std::cin >> input;

        if (input == "$$$") {
            break;
        }

        missmess(input);
    }

    return 0;
}