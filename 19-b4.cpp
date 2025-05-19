#include <iostream>
#include <string>
using namespace std;

class Employee {
public:
    virtual void showInfo() = 0;
    virtual ~Employee() {}
};

class Manager : public Employee {
public:
    void showInfo() override {
        cout << "This is a Manager." << endl;
    }
};

class Engineer : public Employee {
public:
    void showInfo() override {
        cout << "This is an Engineer." << endl;
    }
};

class EmployeeFactory {
public:
    virtual Employee* createManager() = 0;
    virtual Employee* createEngineer() = 0;
    virtual ~EmployeeFactory() {}
};

class FullTimeEmployeeFactory : public EmployeeFactory {
public:
    Employee* createManager() override {
        return new Manager();  
    }

    Employee* createEngineer() override {
        return new Engineer(); 
    }
};

class PartTimeEmployeeFactory : public EmployeeFactory {
public:
    Employee* createManager() override {
        return new Manager();  
    }

    Employee* createEngineer() override {
        return new Engineer(); 
    }
};

void clientCode(EmployeeFactory* factory) {
    Employee* manager = factory->createManager();
    Employee* engineer = factory->createEngineer();

    manager->showInfo();
    engineer->showInfo();

    delete manager;
    delete engineer;
}

int main() {
    cout << "Full-time Employees:\n";
    FullTimeEmployeeFactory fullTimeFactory;
    clientCode(&fullTimeFactory);

    cout << "\nPart-time Employees:\n";
    PartTimeEmployeeFactory partTimeFactory;
    clientCode(&partTimeFactory);

    return 0;
}

