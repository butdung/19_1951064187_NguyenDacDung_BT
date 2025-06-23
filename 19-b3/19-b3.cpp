#include <iostream>
#include <vector>
#include <memory>
using namespace std;

class Employee {
public:
    virtual double CalculateBonus(double performanceScore) = 0;
    virtual string GetRole() = 0;
    virtual ~Employee() {}
};

class Manager : public Employee {
public:
    double CalculateBonus(double performanceScore) override {
        return performanceScore * 0.2;
    }
    string GetRole() override {
        return "Manager";
    }
};

class Developer : public Employee {
public:
    double CalculateBonus(double performanceScore) override {
        return performanceScore * 0.1;
    }
    string GetRole() override {
        return "Developer";
    }
};

class EmployeeFactory {
public:
    virtual Employee* CreateEmployee() = 0;
    virtual ~EmployeeFactory() {}
};

class ManagerFactory : public EmployeeFactory {
public:
    Employee* CreateEmployee() override {
        return new Manager();
    }
};

class DeveloperFactory : public EmployeeFactory {
public:
    Employee* CreateEmployee() override {
        return new Developer();
    }
};

int main() {
    vector<unique_ptr<Employee>> employees;

    ManagerFactory managerFactory;
    DeveloperFactory developerFactory;

    employees.emplace_back(managerFactory.CreateEmployee());
    employees.emplace_back(developerFactory.CreateEmployee());

    double performanceScore = 1000;
    for (const auto& emp : employees) {
        cout << emp->GetRole() << " - Bonus: " << emp->CalculateBonus(performanceScore) << endl;
    }

    return 0;
}

