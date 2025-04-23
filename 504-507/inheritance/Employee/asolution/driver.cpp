#include <iostream>
#include <vector>
#include <string>
using namespace std;

struct Employee {
    std::string first_name, last_name;
    Employee(std::string first_name, std::string last_name) :
        first_name(first_name), last_name(last_name) {}
};

struct HourlyEmployee : public Employee {
    double hourly_wage;
    HourlyEmployee(std::string first_name, std::string last_name,
        double hourly_wage) : Employee(first_name, last_name),
        hourly_wage(hourly_wage) {}
};

struct SalariedEmployee : public Employee {
    double annual_salary;
    SalariedEmployee(std::string first_name, std::string last_name,
        double annual_salary) : Employee(first_name, last_name),
        annual_salary(annual_salary) {}
};

int main ()
{

    HourlyEmployee he {"James", "Williams", 18.50};
    cout << "HourlyEmployee" << endl;
    cout << '\t' << he.first_name << ' ' << he.last_name << '\t' << he.hourly_wage << endl;

    SalariedEmployee sh {"Mary", "Smith", 134000};
    cout << "SalariedEmployee" << endl;
    cout << '\t' << sh.first_name << ' ' << sh.last_name << '\t' << sh.annual_salary << endl;

    return 0;

}