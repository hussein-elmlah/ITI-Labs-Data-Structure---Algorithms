#include <iostream>
using namespace std;
// void swap(int &x, int &y);
void quickSort(int arr[], int startB, int endB);
int partitioning(int arr[], int startB, int endB);

/*
void swap(int &x, int &y)
{
    int temp = x;
    x = y;
    y = temp;
}
 */

void quickSort(int arr[], int startB, int endB)
{
    if(startB<endB)
    {
        int pivot = partitioning(arr, startB, endB);
        quickSort(arr, startB, pivot-1);
        quickSort(arr, pivot+1, endB);
    }
}

int partitioning(int arr[], int startB, int endB)
{
    int pivot = startB;
    while(startB<endB)
    {
        while (arr[startB]<=arr[pivot])
        {
            startB++;
        }
        while (arr[endB]>arr[pivot])
        {
            endB--;
        }
        if(startB<endB)
        {
            swap(arr[startB],arr[endB]);
        }
    }
    swap(arr[pivot],arr[endB]);
    return endB;
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
    quickSort(arrForTest, 0, size-1);

    // Print the array elements after sorting
    cout << "The array elements are: ";
    for (int i = 0; i < size; i++)
    {
        cout << arrForTest[i] << " ";
    }

    delete [] arrForTest;
    return 0;
}
