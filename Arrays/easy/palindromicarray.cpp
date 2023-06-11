// Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.

#include <iostream>
#include <typeinfo>
using namespace std;

int PalinArray(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int reverse = 0;
        int num = a[i];
        while (num != 0)
        {
            int lastDigit = num % 10;
            reverse = reverse * 10 + lastDigit;
            num /= 10;
        }
        if (a[i] != reverse)
        {
            return 0;
        }
    }
    return 1;
}

int main()
{
    int arr[3] = {11, 121, 354453};
    cout << "start" << endl;
    cout << PalinArray(arr, 3) << endl;
    cout << "end" << endl;
    return 0;
}