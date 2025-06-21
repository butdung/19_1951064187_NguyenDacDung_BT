#include <iostream>
#include <string>
using namespace std;

class EmployeeStrategy {
public:
    virtual int getMaxSalary() const = 0;
    virtual string getPosition() const = 0;
    virtual ~EmployeeStrategy() = default;
};

class OfficeEmployeeStrategy : public EmployeeStrategy {
private:
    string position;
public:
    OfficeEmployeeStrategy(const string& position) : position(position) {}

    int getMaxSalary() const override {
        return 1000; 
    }

    string getPosition() const override {
        return position;
    }
};

class TechnicalEmployeeStrategy : public EmployeeStrategy {
private:
    string position;
public:
    TechnicalEmployeeStrategy(const string& position) : position(position) {}

    int getMaxSalary() const override {
        return 2000; 
    }

    string getPosition() const override {
        return position;
    }
};

class EmployeeContext {
private:
    EmployeeStrategy* strategy;
public:
    void setStrategy(EmployeeStrategy* strategy) {
        this->strategy = strategy;
    }

    int getMaxSalary() const {
        return strategy ? strategy->getMaxSalary() : 0;
    }

    string getEmployeePosition() const {
        return strategy ? strategy->getPosition() : "Unknown";
    }
};

int main() {
    EmployeeContext context;

    EmployeeStrategy* officeEmp = new OfficeEmployeeStrategy("Nhân viên hành chính");
    context.setStrategy(officeEmp);
    cout << "Office Employee Position: " << context.getEmployeePosition() << endl;
    cout << "Max Salary: $" << context.getMaxSalary() << endl;

    EmployeeStrategy* techEmp = new TechnicalEmployeeStrategy("K? su ph?n m?m");
    context.setStrategy(techEmp);
    cout << "\nTechnical Employee Position: " << context.getEmployeePosition() << endl;
    cout << "Max Salary: $" << context.getMaxSalary() << endl;

    delete officeEmp;
    delete techEmp;

    return 0;
}

