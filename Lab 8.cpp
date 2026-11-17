#include <iostream>

class NumDays {
private:
    double hours;
    double days;

    void updateDays() {
        days = hours / 8.0;
    }

    void updateHours() {
        hours = days * 8.0;
    }

public:
    NumDays(double h = 0.0) {
        hours = h;
        updateDays();
    }

    void setHours(double h) {
        hours = h;
        updateDays();
    }

    void setDays(double d) {
        days = d;
        updateHours();
    }

    double getHours() const {
        return hours;
    }

    double getDays() const {
        return days;
    }

    NumDays operator+(const NumDays &right) const {
        return NumDays(this->hours + right.hours);
    }

    NumDays operator-(const NumDays &right) const {
        return NumDays(this->hours - right.hours);
    }

    NumDays& operator++() {
        ++hours;
        updateDays();
        return *this;
    }

    NumDays operator++(int) {
        NumDays temp(hours);
        hours++;
        updateDays();
        return temp;
    }

    NumDays& operator--() {
        --hours;
        updateDays();
        return *this;
    }

    NumDays operator--(int) {
        NumDays temp(hours);
        hours--;
        updateDays();
        return temp;
    }
};

int main() {
    NumDays obj1(12.0); // 1.5 days
    NumDays obj2(18.0); // 2.25 days

    std::cout << "Object 1 Days: " << obj1.getDays() << " days\n";
    std::cout << "Object 2 Days: " << obj2.getDays() << " days\n\n";

    NumDays obj3 = obj1 + obj2;
    std::cout << "Object 3 (Obj1 + Obj2) Days: " << obj3.getDays() << " days\n\n";

    NumDays obj4;

    obj4 = obj3++;
    std::cout << "After Postfix Increment (Obj4 = Obj3++):\n";
    std::cout << "  Obj4 Days: " << obj4.getDays() << " days\n";
    std::cout << "  Obj3 Days after increment: " << obj3.getDays() << " days\n\n";

    obj4 = ++obj3;
    std::cout << "After Prefix Increment (Obj4 = ++Obj3):\n";
    std::cout << "  Obj4 Days: " << obj4.getDays() << " days\n";
    std::cout << "  Obj3 Days: " << obj3.getDays() << " days\n\n";

    obj4 = obj3--;
    std::cout << "After Postfix Decrement (Obj4 = obj3--):\n";
    std::cout << "  Obj4 Days: " << obj4.getDays() << " days\n";
    std::cout << "  Obj3 Days after decrement: " << obj3.getDays() << " days\n\n";

    obj4 = --obj3;
    std::cout << "After Prefix Decrement (Obj4 = --obj3):\n";
    std::cout << "  Obj4 Days: " << obj4.getDays() << " days\n";
    std::cout << "  Obj3 Days: " << obj3.getDays() << " days\n";

    return 0;
}