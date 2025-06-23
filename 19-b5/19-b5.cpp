#include <iostream>
#include <string>
#include <memory>

class Employee {
private:
    std::string name;
    std::string position;
    double salary;

public:
    void setName(const std::string& n) { name = n; }
    void setPosition(const std::string& p) { position = p; }
    void setSalary(double s) { salary = s; }

    void showInfo() const {
        std::cout << "Name: " << name << "\n"
                  << "Position: " << position << "\n"
                  << "Salary: $" << salary << "\n";
    }
};

class EmployeeBuilder {
public:
    virtual ~EmployeeBuilder() {}
    virtual void buildName() = 0;
    virtual void buildPosition() = 0;
    virtual void buildSalary() = 0;
    virtual std::shared_ptr<Employee> getEmployee() = 0;
};

class DeveloperBuilder : public EmployeeBuilder {
private:
    std::shared_ptr<Employee> employee;

public:
    DeveloperBuilder() { employee = std::make_shared<Employee>(); }

    void buildName() override {
        employee->setName("Nguyen Van A");
    }

    void buildPosition() override {
        employee->setPosition("Developer");
    }

    void buildSalary() override {
        employee->setSalary(1500.0);
    }

    std::shared_ptr<Employee> getEmployee() override {
        return employee;
    }
};

class ManagerBuilder : public EmployeeBuilder {
private:
    std::shared_ptr<Employee> employee;

public:
    ManagerBuilder() { employee = std::make_shared<Employee>(); }

    void buildName() override {
        employee->setName("Tran Thi B");
    }

    void buildPosition() override {
        employee->setPosition("Manager");
    }

    void buildSalary() override {
        employee->setSalary(3000.0);
    }

    std::shared_ptr<Employee> getEmployee() override {
        return employee;
    }
};

class HRDirector {
private:
    EmployeeBuilder* builder;

public:
    void setBuilder(EmployeeBuilder* b) {
        builder = b;
    }

    std::shared_ptr<Employee> createEmployee() {
        builder->buildName();
        builder->buildPosition();
        builder->buildSalary();
        return builder->getEmployee();
    }
};

int main() {
    HRDirector director;

    DeveloperBuilder devBuilder;
    director.setBuilder(&devBuilder);
    std::shared_ptr<Employee> dev = director.createEmployee();
    std::cout << "Developer Info:\n";
    dev->showInfo();

    std::cout << "\n";

    ManagerBuilder mgrBuilder;
    director.setBuilder(&mgrBuilder);
    std::shared_ptr<Employee> mgr = director.createEmployee();
    std::cout << "Manager Info:\n";
    mgr->showInfo();

    return 0;
}

