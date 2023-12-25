#include <iostream>
using namespace std;

void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}

void selectionSort(int arr[], int n)
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
    cout << "Enter number of numbers : ";
    cin >> size;
    int *numbers = new int[size];

    // array input
    for (int i = 0; i < size; i++) {
        cout << "Enter an integer number: ";
        cin >> numbers[i];
    }

    // sorting using my function
    selectionSort(numbers, size);

    // Print the array elements after sorting
    cout << "The array elements are: ";
    for (int i = 0; i < size; i++) {
        cout << numbers[i] << " ";
    }

    delete [] numbers;
    return 0;
}
