#include <iostream>
using namespace std;

// Forward declaration
class Component;

// Interface Mediator
class Mediator {
public:
    virtual void notify(Component* sender) = 0;
    virtual ~Mediator() = default;
};

class Component {
protected:
    Mediator* mediator;

public:
    Component(Mediator* m) : mediator(m) {}
    virtual ~Component() = default;
};

class Employee;
class Manager;
class HRDepartment;

class Employee : public Component {
public:
    Employee(Mediator* m) : Component(m) {}

    void work() {
        cout << "Employee is working.\n";
        mediator->notify(this);
    }

    void report() {
        cout << "Employee sends report to Manager.\n";
    }
};

class Manager : public Component {
public:
    Manager(Mediator* m) : Component(m) {}

    void assign() {
        cout << "Manager assigns tasks.\n";
        mediator->notify(this);
    }

    void review() {
        cout << "Manager reviews report.\n";
    }
};

class HRDepartment : public Component {
public:
    HRDepartment(Mediator* m) : Component(m) {}

    void recruit() {
        cout << "HR recruits new employee.\n";
        mediator->notify(this);
    }

    void updatePolicy() {
        cout << "HR updates company policies.\n";
    }
};

class SystemMediator : public Mediator {
private:
    Employee* employee;
    Manager* manager;
    HRDepartment* hr;

public:
    SystemMediator(Employee* e, Manager* m, HRDepartment* h)
        : employee(e), manager(m), hr(h) {}

    void notify(Component* sender) override {
        if (sender == employee) {
            reactOnEmployee();
        } else if (sender == manager) {
            reactOnManager();
        } else if (sender == hr) {
            reactOnHR();
        }
    }

    void reactOnEmployee() {
        manager->review();
    }

    void reactOnManager() {
        employee->report();
    }

    void reactOnHR() {
        cout << "System logs HR activity.\n";
    }
};

int main() {
    
    Employee* e = new Employee(nullptr);
    Manager* m = new Manager(nullptr);
    HRDepartment* h = new HRDepartment(nullptr);

    SystemMediator* mediator = new SystemMediator(e, m, h);

    e->mediator = mediator;
    m->mediator = mediator;
    h->mediator = mediator;

    
    e->work();       
    m->assign();     
    h->recruit();    

    delete e;
    delete m;
    delete h;
    delete mediator;

    return 0;
}

