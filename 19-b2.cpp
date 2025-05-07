#include <iostream>
#include <vector>
#include <string>
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

int main() {
    int n;
    cout << "Nhap so nhan vien: ";
    cin >> n;

    vector<Employee*> employees;

    for (int i = 0; i < n; ++i) {
        int type;
        double score;

        cout << "\nNhan vien thu " << i + 1 << ":" << endl;
        cout << "Nhap loai (1 = Manager, 2 = Developer): ";
        cin >> type;
        cout << "Nhap diem hieu suat (performanceScore): ";
        cin >> score;

        Employee* emp = nullptr;
        if (type == 1)
            emp = new Manager();
        else if (type == 2)
            emp = new Developer();
        else {
            cout << "Loai khong hop le. Bo qua nhan vien nay.\n";
            continue;
        }

        double bonus = emp->CalculateBonus(score);
        cout << emp->GetRole() << " duoc thuong: " << bonus << endl;

        employees.push_back(emp);
    }

    for (Employee* e : employees)
        delete e;

    return 0;
}

