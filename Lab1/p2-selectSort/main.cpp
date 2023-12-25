#include <iostream>
#include <string>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void selectionSort(string arr[], int n)
{
    int min_idx;
    for (int i = 0; i < n-1; i++)
    {
        min_idx = i;
        for (int j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

int main()
{
    int size;
    cout << "Enter number of strings : ";
    cin >> size;
    string *strings = new string[size];

    // array input
    for (int i = 0; i < size; i++) {
        cout << "Enter a string: ";
        cin >> strings[i];
    }

    // sorting using my function
    selectionSort(strings, size);

    // Print the array elements after sorting
    cout << "The array elements are: " << endl;
    for (int i = 0; i < size; i++) {
        cout << strings[i] << endl;
    }

    delete [] strings;
    return 0;
}
