#include <iostream>
#include <vector>
#include <memory>

using namespace std;


class Employee {
public:
    int id;
    string name;
    string position;

    Employee(int id, string name, string position)
        : id(id), name(name), position(position) {}
};

#interface
class IEmployeeData {
public:
    virtual void addEmployee(const Employee& emp) = 0;
    virtual void removeEmployee(int id) = 0;
    virtual vector<Employee> getAllEmployees() = 0;
    virtual ~IEmployeeData() {}
};


#implementor
class EmployeeDataInMemory : public IEmployeeData {
private:
    vector<Employee> employees;

public:
    void addEmployee(const Employee& emp) override {
        employees.push_back(emp);
    }

    void removeEmployee(int id) override {
        employees.erase(remove_if(employees.begin(), employees.end(),
            [id](const Employee& e) { return e.id == id; }),
            employees.end());
    }

    vector<Employee> getAllEmployees() override {
        return employees;
    }
};

#abstraction
class EmployeeManager {
protected:
    shared_ptr<IEmployeeData> dataImpl;

public:
    EmployeeManager(shared_ptr<IEmployeeData> impl)
        : dataImpl(impl) {}

    virtual void addEmployee(const Employee& emp) {
        dataImpl->addEmployee(emp);
    }

    virtual void removeEmployee(int id) {
        dataImpl->removeEmployee(id);
    }

    virtual void showEmployees() {
        vector<Employee> list = dataImpl->getAllEmployees();
        cout << "Danh sách nhân viên:\n";
        for (const auto& e : list) {
            cout << "- ID: " << e.id << ", Tên: " << e.name << ", V? trí: " << e.position << endl;
        }
    }

    virtual ~EmployeeManager() {}
};

#demo 

int main() {
    
    shared_ptr<IEmployeeData> data = make_shared<EmployeeDataInMemory>();

    
    EmployeeManager manager(data);

    
    manager.addEmployee(Employee(1, "Nguyen Van A", "Developer"));
    manager.addEmployee(Employee(2, "Tran Thi B", "Designer"));

   
    manager.showEmployees();

    
    manager.removeEmployee(1);

    
    cout << "\nSau khi xóa nhân viên ID = 1:\n";
    manager.showEmployees();

    return 0;
}

