// Given an array Arr of size N, print second largest element from an array.

int print2largest(int arr[], int n)
{
    int largest = arr[0];
    int secLargest = -1;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > largest)
        {
            secLargest = largest;
            largest = arr[i];
        }
        else if (arr[i] > secLargest and arr[i] < largest)
        {
            secLargest = arr[i];
        }
    }
    return secLargest;
}