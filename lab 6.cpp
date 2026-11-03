#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

class NumberArray
{
private:
    float* numbers;
    int size;

public:
    // Constructors
    NumberArray();
    NumberArray(int);

    // Destructor
    ~NumberArray();

    // Member functions
    int getSize() const;
    void setNumber(int, float);
    float getNumber(int) const;

    float getHighest() const;
    float getLowest() const;
    float getAverage() const;
};

// Default constructor using constructor delegation
NumberArray::NumberArray() : NumberArray(10)
{
}

// Constructor that accepts the array size
NumberArray::NumberArray(int s)
{
    if (s <= 0)
    {
        cout << "Invalid array size. Setting size to 10." << endl;
        size = 10;
    }
    else
    {
        size = s;
    }

    numbers = new float[size];

    // Initialize all elements to 0
    for (int i = 0; i < size; i++)
    {
        numbers[i] = 0.0;
    }
}

// Destructor
NumberArray::~NumberArray()
{
    delete[] numbers;
}

// Return the number of elements
int NumberArray::getSize() const
{
    return size;
}

// Store a number in the array
void NumberArray::setNumber(int index, float value)
{
    if (index >= 0 && index < size)
    {
        numbers[index] = value;
    }
    else
    {
        cout << "Error: Invalid array index." << endl;
    }
}

// Retrieve a number from the array
float NumberArray::getNumber(int index) const
{
    if (index >= 0 && index < size)
    {
        return numbers[index];
    }
    else
    {
        cout << "Error: Invalid array index." << endl;
        return 0.0;
    }
}

// Return the highest value
float NumberArray::getHighest() const
{
    float highest = numbers[0];

    for (int i = 1; i < size; i++)
    {
        if (numbers[i] > highest)
        {
            highest = numbers[i];
        }
    }

    return highest;
}

// Return the lowest value
float NumberArray::getLowest() const
{
    float lowest = numbers[0];

    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < lowest)
        {
            lowest = numbers[i];
        }
    }

    return lowest;
}

// Return the average value
float NumberArray::getAverage() const
{
    float total = 0.0;

    for (int i = 0; i < size; i++)
    {
        total += numbers[i];
    }

    return total / size;
}

int main()
{
    // Create an object using the default constructor
    NumberArray array1;

    cout << "The size of the first array is: "
         << array1.getSize() << endl;

    cout << endl;

    // Create an object that holds 15 numbers
    NumberArray array2(15);

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Store 15 randomly generated numbers
    for (int i = 0; i < array2.getSize(); i++)
    {
        float randomNumber = rand() % 100 + 1;

        array2.setNumber(i, randomNumber);
    }

    // Display the numbers
    cout << "The 15 numbers stored in the array are:" << endl;

    for (int i = 0; i < array2.getSize(); i++)
    {
        cout << array2.getNumber(i) << " ";
    }

    cout << endl << endl;

    // Display maximum, minimum, and average
    cout << "Highest value: "
         << array2.getHighest() << endl;

    cout << "Lowest value: "
         << array2.getLowest() << endl;

    cout << "Average value: "
         << array2.getAverage() << endl;

    return 0;
}