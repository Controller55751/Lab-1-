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
