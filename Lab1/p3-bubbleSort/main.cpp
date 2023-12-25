#include <iostream>
#include <string>
using namespace std;

class employee
{
public:
    int emp_id;
    string emp_name;
    int emp_salary;
};

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void bubbleSort(employee arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        for (int j = 0; j < n-1-i; j++)
            if (arr[j].emp_id > arr[j+1].emp_id)
                swap(&arr[j], &arr[j+1]);
    }
}

int main()
{
    int size;
    cout << "Enter number of employees : ";
    cin >> size;
    employee *employees = new employee[size];

    // array input
    for (int i = 0; i < size; i++)
    {
        cout << "Enter employee id: ";
        cin >> employees[i].emp_id;
        cout << "Enter employee name: ";
        cin >> employees[i].emp_name;
    }

    // sorting using my function
    bubbleSort(employees, size);

    // Print the array elements after sorting
    cout << "The array elements are: "<< endl;
    for (int i = 0; i < size; i++)
    {
        cout << employees[i].emp_id << " : ";
        cout << employees[i].emp_name << " " << endl;
    }

    return 0;
}
