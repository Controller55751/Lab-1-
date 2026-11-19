#include <iostream>
#include <string>

class PersonData {
protected:
    std::string lastName;
    std::string firstName;
    std::string address;
    std::string city;
    std::string state;
    std::string zip;
    std::string phone;

public:
    PersonData()
        : lastName(""), firstName(""), address(""),
          city(""), state(""), zip(""), phone("") {}

    PersonData(const std::string& last, const std::string& first,
               const std::string& addr, const std::string& cty,
               const std::string& st, const std::string& z,
               const std::string& ph)
        : lastName(last), firstName(first), address(addr),
          city(cty), state(st), zip(z), phone(ph) {}

    void setLastName(const std::string& last) { lastName = last; }
    void setFirstName(const std::string& first) { firstName = first; }
    void setAddress(const std::string& addr) { address = addr; }
    void setCity(const std::string& cty) { city = cty; }
    void setState(const std::string& st) { state = st; }
    void setZip(const std::string& z) { zip = z; }
    void setPhone(const std::string& ph) { phone = ph; }

    std::string getLastName() const { return lastName; }
    std::string getFirstName() const { return firstName; }
    std::string getAddress() const { return address; }
    std::string getCity() const { return city; }
    std::string getState() const { return state; }
    std::string getZip() const { return zip; }
    std::string getPhone() const { return phone; }
};

class CustomerData : public PersonData {
private:
    int customerNumber;
    bool mailingList;

public:
    CustomerData()
        : PersonData(), customerNumber(0), mailingList(false) {}

    CustomerData(const std::string& last, const std::string& first,
                 const std::string& addr, const std::string& cty,
                 const std::string& st, const std::string& z,
                 const std::string& ph, int custNum, bool mailList)
        : PersonData(last, first, addr, cty, st, z, ph),
          customerNumber(custNum), mailingList(mailList) {}

    void setCustomerNumber(int custNum) { customerNumber = custNum; }
    void setMailingList(bool mailList) { mailingList = mailList; }

    int getCustomerNumber() const { return customerNumber; }
    bool getMailingList() const { return mailingList; }
};

void printCustomer(const std::string& heading, const CustomerData& customer) {
    std::cout << "=== " << heading << " ===\n";
    std::cout << "Customer Number: " << customer.getCustomerNumber() << "\n";
    std::cout << "First Name:      " << customer.getFirstName() << "\n";
    std::cout << "Last Name:       " << customer.getLastName() << "\n";
    std::cout << "Address:         " << customer.getAddress() << "\n";
    std::cout << "City:            " << customer.getCity() << "\n";
    std::cout << "State:           " << customer.getState() << "\n";
    std::cout << "ZIP:             " << customer.getZip() << "\n";
    std::cout << "Phone:           " << customer.getPhone() << "\n";
    std::cout << "Mailing List:    " << (customer.getMailingList() ? "Yes" : "No") << "\n\n";
}

int main() {
    CustomerData activeCustomer(
        "Mercer",
        "Elena",
        "410 Maple Ave",
        "Brooklyn",
        "NY",
        "11201",
        "718-555-0194",
        1042,
        true
    );

    printCustomer("Parameterized CustomerData Object", activeCustomer);

    CustomerData defaultCustomer;
    printCustomer("Default CustomerData Object", defaultCustomer);

    return 0;
}