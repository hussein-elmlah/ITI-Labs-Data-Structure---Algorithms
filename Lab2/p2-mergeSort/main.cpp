#include <iostream>
using namespace std;
// void swap(int &x, int &y);
void mergeSort(int arr[], int startB, int endB);
void Merge(int arr[], int startB, int mid, int endB);

/*
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
 */


void mergeSort(int arr[], int startB, int endB) {
    if (startB < endB) {
        int mid = (startB + endB) / 2;
        // splitting this part of array to two parts.
        mergeSort(arr, startB, mid);
        mergeSort(arr, mid + 1, endB);
        // combining the two parts of this part of array.
        Merge(arr, startB, mid, endB);
    }
}

void Merge(int arr[], int startB, int mid, int endB) {
    // creating copies of two the parts.
    int size1 = mid - startB + 1;
    int size2 = endB - mid;
    int* A1 = new int[size1];
    int* A2 = new int[size2];
    int i, j;

    for (i = 0; i < size1; i++) {
        A1[i] = arr[startB + i];
    }

    for (j = 0; j < size2; j++) {
        A2[j] = arr[mid + 1 + j];
    }

    // comparing and filling the main array with sorted values.
    i = j = 0;
    int k = startB;

    while (i < size1 && j < size2) {
        if (A1[i] < A2[j]) {
            arr[k] = A1[i];
            i++;
        } else {
            arr[k] = A2[j];
            j++;
        }
        k++;
    }

    while (i < size1) {
        arr[k] = A1[i];
        k++;
        i++;
    }

    while (j < size2) {
        arr[k] = A2[j];
        k++;
        j++;
    }

    // deallocating the memory.
    delete[] A1;
    delete[] A2;
}


int main()
{
    int size;
    cout << "Enter number of numbers : ";
    cin >> size;
    int *arrForTest = new int[size];

    // array input
    for (int i = 0; i < size; i++)
    {
        cout << "Enter an integer number: ";
        cin >> arrForTest[i];
    }

    // sorting using my function
    mergeSort(arrForTest, 0, size-1);

    // Print the array elements after sorting
    cout << "The array elements are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arrForTest[i] << " ";
    }

    delete [] arrForTest;
    return 0;
}
