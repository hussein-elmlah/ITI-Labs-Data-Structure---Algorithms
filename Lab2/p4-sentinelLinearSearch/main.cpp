#include <iostream>
using namespace std;

int sentinelLinearSearch(int arr[], int Size, int target)
{
    int lastElement = arr[Size - 1];
    arr[Size - 1] = target;

    int i = 0;
    while (arr[i] != target)
    {
        i++;
    }

    arr[Size - 1] = lastElement;

    if (i < Size - 1)
    {
        return i;
    }

    return -1;
}

int main()
{
    const int Size = 7;
    int numbers[Size] = {10, 20, 30, 40, 50, 60, 70};

    cout << "Enter a number to search: ";
    int target;
    cin >> target;

    int result = sentinelLinearSearch(numbers, Size, target);

    if (result != -1)
    {
        cout << "Number found at index: " << result << endl;
    }
    else
    {
        cout << "Number not found in the array." << endl;
    }

    return 0;
}
