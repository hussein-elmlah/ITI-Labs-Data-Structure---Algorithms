#include <iostream>
using namespace std;

int binarySearch(int arr[], int Size, int target)
{
    int left = 0;
    int right = Size - 1;

    while (left <= right)
    {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
        {
            return mid;
        }

        if (arr[mid] < target)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
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

    int result = binarySearch(numbers, Size, target);

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
