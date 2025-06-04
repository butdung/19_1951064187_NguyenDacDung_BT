#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class IEmployeeDisplay {
public:
    virtual void showEmployee(const string& name) = 0;
    virtual ~IEmployeeDisplay() {}
};

class NewHRService {
public:
    void displayEmployeeInfo(const string& fullName, int id) {
        cout << "Employee Info:\n";
        cout << "Name: " << fullName << ", ID: " << id << endl;
    }
};

class HRAdapter : public IEmployeeDisplay {
private:
    NewHRService* service;
    unordered_map<string, int> nameToId; 

public:
    HRAdapter(NewHRService* svc) : service(svc) {
        nameToId["Nguyen Van A"] = 101;
        nameToId["Tran Thi B"] = 102;
    }

    void showEmployee(const string& name) override {
        if (nameToId.find(name) != nameToId.end()) {
            int id = nameToId[name];
            service->displayEmployeeInfo(name, id);
        } else {
            cout << "Employee not found: " << name << endl;
        }
    }
};

class EmployeeManager {
private:
    IEmployeeDisplay* display;

public:
    EmployeeManager(IEmployeeDisplay* disp) : display(disp) {}

    void show(const string& employeeName) {
        display->showEmployee(employeeName);
    }
};

int main() {
    NewHRService* newService = new NewHRService();
    HRAdapter* adapter = new HRAdapter(newService);
    EmployeeManager manager(adapter);

    manager.show("Nguyen Van A");
    manager.show("Tran Thi B");
    manager.show("Unknown Name");

    delete newService;
    delete adapter;
    return 0;
}

