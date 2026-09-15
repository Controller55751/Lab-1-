#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double weight, height, bmi;

    while (true) {
        cout << "Enter your weight in pounds (0 to stop): ";
        cin >> weight;

        if (weight == 0) {
            cout << "Program ended." << endl;
            break;
        }

        cout << "Enter your height in inches: ";
        cin >> height;

        // Calculate BMI
        bmi = (weight / (height * height)) * 703;

        // Display BMI
        cout << fixed << setprecision(2);
        cout << "BMI: " << bmi << endl;

        // Determine weight status
        if (bmi < 18) {
            cout << "Weight Status: Underweight" << endl;
        }
        else if (bmi < 24) {
            cout << "Weight Status: Normal" << endl;
        }
        else if (bmi < 30) {
            cout << "Weight Status: Overweight" << endl;
        }
        else {
            cout << "Weight Status: Obese" << endl;
        }

        cout << endl;
    }

    return 0;
}
