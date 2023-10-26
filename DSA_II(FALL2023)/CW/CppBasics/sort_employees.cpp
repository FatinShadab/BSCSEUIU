/*
    "Write a C++ program that takes input for a list of employees,
    each represented by their name, height, and age. Implement a 
    sorting mechanism that arranges the employees first in descending
    order of their height and then, for employees with the same height,
    in descending order of their age. Finally, display the sorted list 
    of employees."
*/

#include <bits/stdc++.h>

using namespace std;

class Employee{
    public:
        string name;
        int height;
        int age;

    public:
        Employee(string name, int height, int age) {
            this->name = name;
            this->height = height;
            this->age = age;
        }

        string desc() {
            return this->name;
        }
};

bool employeeComparator(Employee emp1, Employee emp2) {
    if (emp1.height > emp2.height) {
        return true;
    }
    if (emp1.height < emp2.height) {
        return false;
    }

    return (emp1.age > emp2.age) ? true:false;
}

int main() {
    string name;
    int height;
    int age;

    int numberOfEmployees; cin >> numberOfEmployees;
    vector <Employee> employees;

    while (numberOfEmployees --) {
        cin.ignore();
        getline(cin, name);
        cin >> height;
        cin >> age;
        Employee emp = Employee(name, height, age);

        employees.push_back(emp);
    }

    sort(employees.begin(), employees.end(), employeeComparator);

    for (Employee emp : employees) {
        cout << emp.desc() << "\n";
    }

    return 0;
}