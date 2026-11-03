#ifndef NUMBERARRAY_H
#define NUMBERARRAY_H

class NumberArray {
private:
    float* array;
    int size;

public:
    // Constructors and Destructor
    NumberArray();                        // Default constructor (delegates to parameterized)
    explicit NumberArray(int arraySize);  // Parameterized constructor
    ~NumberArray();                       // Destructor

    // Member functions
    int getSize() const;
    bool storeNumber(int index, float value);
    bool getNumber(int index, float& value) const;
    float getHighest() const;
    float getLowest() const;
    float getAverage() const;
};

#endif // NUMBERARRAY_H

#include "NumberArray.h"
#include <iostream>
#include <stdexcept>
#include <algorithm>

// Parameterized Constructor: performs dynamic memory allocation and bounds checking
NumberArray::NumberArray(int arraySize) {
    if (arraySize <= 0) {
        std::cerr << "Error: Array size must be greater than zero. Defaulting to size 10.\n";
        size = 10;
    } else {
        size = arraySize;
    }
    array = new float[size](); // Zero-initializes all elements
}

// Default Constructor: uses constructor delegation to call the parameterized constructor with size 10
NumberArray::NumberArray() : NumberArray(10) {}

// Destructor: frees allocated dynamic memory
NumberArray::~NumberArray() {
    delete[] array;
}

// Returns the number of elements in the array
int NumberArray::getSize() const {
    return size;
}

// Stores a number at a given index with bounds checking
bool NumberArray::storeNumber(int index, float value) {
    if (index < 0 || index >= size) {
        std::cerr << "Error: Index " << index << " out of bounds.\n";
        return false;
    }
    array[index] = value;
    return true;
}

// Retrieves a number from a given index with bounds checking
bool NumberArray::getNumber(int index, float& value) const {
    if (index < 0 || index >= size) {
        std::cerr << "Error: Index " << index << " out of bounds.\n";
        return false;
    }
    value = array[index];
    return true;
}

// Returns the highest value in the array
float NumberArray::getHighest() const {
    float highest = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] > highest) {
            highest = array[i];
        }
    }
    return highest;
}

// Returns the lowest value in the array
float NumberArray::getLowest() const {
    float lowest = array[0];
    for (int i = 1; i < size; ++i) {
        if (array[i] < lowest) {
            lowest = array[i];
        }
    }
    return lowest;
}

// Returns the average of all numbers in the array
float NumberArray::getAverage() const {
    float sum = 0.0f;
    for (int i = 0; i < size; ++i) {
        sum += array[i];
    }
    return sum / size;
}

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include "NumberArray.h"

int main() {
    // Seed the random number generator
    std::srand(static_cast<unsigned int>(std::time(nullptr)));

    // 1. Create a NumberArray object using the default constructor
    NumberArray defaultArr;
    std::cout << "Default NumberArray object created.\n";
    std::cout << "Size of default array: " << defaultArr.getSize() << "\n\n";

    // 2. Create a second NumberArray object that holds 15 numbers
    const int SECOND_SIZE = 15;
    NumberArray customArr(SECOND_SIZE);
    std::cout << "Second NumberArray object created with size " << customArr.getSize() << ".\n";

    // 3. Store 15 randomly generated numbers (range: 1.0 to 100.0)
    for (int i = 0; i < SECOND_SIZE; ++i) {
        float randomVal = 1.0f + static_cast<float>(rand()) / (static_cast<float>(RAND_MAX / 99.0f));
        customArr.storeNumber(i, randomVal);
    }

    // 4. Print the stored numbers
    std::cout << "\nStored 15 random numbers in the second array:\n";
    std::cout << std::fixed << std::setprecision(2);
    for (int i = 0; i < customArr.getSize(); ++i) {
        float val;
        if (customArr.getNumber(i, val)) {
            std::cout << "Element [" << std::setw(2) << i << "]: " << std::setw(6) << val << "\n";
        }
    }

    // 5. Print statistics
    std::cout << "\n--- Array Statistics ---\n";
    std::cout << "Maximum Value : " << customArr.getHighest() << "\n";
    std::cout << "Minimum Value : " << customArr.getLowest()  << "\n";
    std::cout << "Average Value : " << customArr.getAverage() << "\n";

    return 0;
}