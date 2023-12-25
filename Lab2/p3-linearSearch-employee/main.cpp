#include <iostream>
#include <string>
using namespace std;

class Employee
{
public:
    int id;
    string name;
    double salary;
    // Function to print employee details
    void print()
    {
        cout << "Employee ID: " << id << "\n";
        cout << "Employee Name: " << name << "\n";
        cout << "Employee Salary: $" << salary << "\n";
    }
};

int linearSearchByName(Employee arr[], int Size, string& targetName)
{
    for (int i = 0; i < Size; ++i)
    {
        if (arr[i].name == targetName)
        {
            return i;
        }
    }
    return -1;
}


int linearSearchById(Employee arr[], int Size, int targetId)
{
    for (int i = 0; i < Size; ++i)
    {
        if (arr[i].id == targetId)
        {
            return i;
        }
    }
    return -1;
}


int linearSearchBySalary(Employee arr[], int Size, double targetSalary)
{
    for (int i = 0; i < Size; ++i)
    {
        if (arr[i].salary == targetSalary)
        {
            return i;
        }
    }
    return -1;
}


int main()
{
    /*  // if you want to make array input from user.
        int Size;
        cout << "Enter number of employees : ";
        cin >> Size;
        Employee *employees = new Employee[Size];

        // array input
        for (int i = 0; i < Size; i++)
        {
            cout << "Enter Employee id: ";
            cin >> employees[i].id;
            cout << "Enter Employee name: ";
            cin >> employees[i].name;
            cout << "Enter salary name: ";
            cin >> employees[i].salary;
        }
     */
    const int Size = 3;
    Employee employees[Size] =
    {
        {1, "belal", 10000.0},
        {2, "ali", 20000.0},
        {3, "taha", 30000.0}
    };

    int selectedIndex = -1;
    cout << "======================================================" << endl;
    string searchName = "ali";
    selectedIndex = linearSearchByName(employees, Size, searchName);
    employees[selectedIndex].print();
    cout << "======================================================" << endl;
    selectedIndex = linearSearchById(employees, Size, 3);
    employees[selectedIndex].print();
    cout << "======================================================" << endl;
    selectedIndex = linearSearchBySalary(employees, Size, 10000);
    employees[selectedIndex].print();
    cout << "======================================================" << endl;

    return 0;
}
