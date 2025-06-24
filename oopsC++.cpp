#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Employee
{
private:
    int empId;
    string name;
    float salary;
    int age;
    vector<string> skills;

public:
    Employee(int id, string n, float s, int a, vector<string> sk)
    {
        empId = id;
        name = n;
        salary = s;
        age = a;
        skills = sk;
    }

    void addSkill(string skill)
    {
        skills.push_back(skill);
    }

    virtual void displayDetails()
    {
        cout << "Employee ID:" << empId << endl;
        cout << "Name: " << name << endl;
        cout << "Salary: " << salary << endl;
        cout << "Age: " << age << endl;
        cout << "Skills: ";
        if (skills.empty())
        {
            cout << "None";
        }
        else
        {
            for (size_t i = 0; i < skills.size(); ++i)
            {
                cout << skills[i];
                if (i != skills.size() - 1)
                {
                    cout << ", ";
                }
            }
        }
        cout << endl;
    }
};

class Manager : public Employee
{
private:
    string department;
    int teamSize;

public:
    Manager(int id, string n, float s, int a, vector<string> sk, string dept, int size)
        : Employee(id, n, s, a, sk), department(dept), teamSize(size) {}

    void displayDetails() override
    {
        Employee::displayDetails();
        cout << "Department: " << department << endl;
        cout << "Team Size: " << teamSize << endl;
    }
};

int main()
{
    Employee emp1(101, "Shyl", 100000, 24, {});
    Manager mgr1(201, "Manoj", 150000, 30, {}, "Software Development", 5);
    mgr1.addSkill("Leadership");
    mgr1.addSkill("Project Management");

    emp1.addSkill("C++");
    emp1.addSkill("Python");
    emp1.addSkill("Java");

    emp1.displayDetails();
    mgr1.displayDetails();
    return 0;
}