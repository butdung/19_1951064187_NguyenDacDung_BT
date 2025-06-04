#include <iostream>
#include <string>

class Component;

class Mediator {
public:
    virtual void notify(Component* sender, const std::string& event) = 0;
    virtual ~Mediator() = default;
};

class Component {
protected:
    Mediator* mediator;
public:
    Component(Mediator* m) : mediator(m) {}
    virtual ~Component() = default;
};

class Employee : public Component {
public:
    Employee(Mediator* m) : Component(m) {}
    
    void requestLeave() {
        std::cout << "Employee: Requesting leave.\n";
        mediator->notify(this, "leaveRequest");
    }

    void updateInfo() {
        std::cout << "Employee: Updating info.\n";
        mediator->notify(this, "updateInfo");
    }
};

class Department : public Component {
public:
    Department(Mediator* m) : Component(m) {}

    void assignEmployee() {
        std::cout << "Department: Assigning employee.\n";
        mediator->notify(this, "assign");
    }

    void notifyChanges() {
        std::cout << "Department: Notifying changes.\n";
    }
};

class Manager : public Component {
public:
    Manager(Mediator* m) : Component(m) {}

    void approveLeave() {
        std::cout << "Manager: Leave approved.\n";
    }

    void reviewPerformance() {
        std::cout << "Manager: Reviewing performance.\n";
    }
};

class ConcreteMediator : public Mediator {
private:
    Employee* employee;
    Department* department;
    Manager* manager;

public:
    void setEmployee(Employee* e) { employee = e; }
    void setDepartment(Department* d) { department = d; }
    void setManager(Manager* m) { manager = m; }

    void notify(Component* sender, const std::string& event) override {
        if (event == "leaveRequest") {
            std::cout << "Mediator: Handling leave request.\n";
            manager->approveLeave();
        } else if (event == "updateInfo") {
            std::cout << "Mediator: Employee updated info, notifying Department.\n";
            department->notifyChanges();
        } else if (event == "assign") {
            std::cout << "Mediator: New assignment triggered.\n";
        }
    }
};

int main() {
    ConcreteMediator mediator;

    Employee emp(&mediator);
    Department dept(&mediator);
    Manager mgr(&mediator);

    mediator.setEmployee(&emp);
    mediator.setDepartment(&dept);
    mediator.setManager(&mgr);

    emp.requestLeave();
    emp.updateInfo();
    dept.assignEmployee();

    return 0;
}

