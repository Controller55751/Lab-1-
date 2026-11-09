#include <iostream>
#include <iomanip>
using namespace std;

class DivSales
{
private:
    double sales[4];
    static double totalCorporateSales;

public:
    // Default constructor
    DivSales()
    {
        for (int i = 0; i < 4; i++)
        {
            sales[i] = 0;
        }
    }

    // Store quarterly sales and update corporate total
    void setSales(double q1, double q2, double q3, double q4)
    {
        sales[0] = q1;
        sales[1] = q2;
        sales[2] = q3;
        sales[3] = q4;

        totalCorporateSales += q1 + q2 + q3 + q4;
    }

    // Return sales for a specific quarter
    double getSales(int quarter)
    {
        if (quarter >= 0 && quarter <= 3)
        {
            return sales[quarter];
        }
        return -1;
    }

    // Return total corporate sales
    static double getCorporateSales()
    {
        return totalCorporateSales;
    }
};

// Initialize static variable
double DivSales::totalCorporateSales = 0;

int main()
{
    DivSales divisions[6];

    cout << fixed << setprecision(2);

    cout << "Initial Corporate Sales: $"
         << DivSales::getCorporateSales() << endl;

    // Enter sales for each division
    for (int i = 0; i < 6; i++)
    {
        double q1, q2, q3, q4;

        cout << "\nDivision " << i + 1 << endl;

        cout << "Enter Quarter 1 sales: ";
        cin >> q1;
        while (cin.fail() || q1 <= 0)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter a positive value: ";
            cin >> q1;
        }

        cout << "Enter Quarter 2 sales: ";
        cin >> q2;
        while (cin.fail() || q2 <= 0)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter a positive value: ";
            cin >> q2;
        }

        cout << "Enter Quarter 3 sales: ";
        cin >> q3;
        while (cin.fail() || q3 <= 0)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter a positive value: ";
            cin >> q3;
        }

        cout << "Enter Quarter 4 sales: ";
        cin >> q4;
        while (cin.fail() || q4 <= 0)
        {
            cin.clear();
            cin.ignore(10000, '\n');
            cout << "Enter a positive value: ";
            cin >> q4;
        }

        divisions[i].setSales(q1, q2, q3, q4);
    }

    // Display sales table
    cout << "\nDIVISION SALES REPORT\n";
    cout << "------------------------------------------------\n";
    cout << setw(12) << "Division"
         << setw(12) << "Quarter 1"
         << setw(12) << "Quarter 2"
         << setw(12) << "Quarter 3"
         << setw(12) << "Quarter 4" << endl;

    for (int i = 0; i < 6; i++)
    {
        cout << setw(12) << i + 1;

        for (int j = 0; j < 4; j++)
        {
            cout << setw(12) << divisions[i].getSales(j);
        }

        cout << endl;
    }

    // Display total corporate sales
    cout << "\nTotal Corporate Sales for the Year: $"
         << DivSales::getCorporateSales() << endl;

    return 0;
}
