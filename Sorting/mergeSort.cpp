class Solution
{
public:
    void merge(int arr[], int l, int mid, int r, int n)
    {
        int sorted[n];

        int idx1 = l, idx2 = mid + 1, idx = 0;

        while (idx1 <= mid && idx2 <= r) {
           if (arr[idx1] > arr[idx2]) {
            sorted[idx++] = arr[idx2++];
           } else
            sorted[idx++] = arr[idx1++];
        }
         
        while (idx1 <= mid)
            sorted[idx++] = arr[idx1++];
        
        while (idx2 <= r)
            sorted[idx++] = arr[idx2++];
            
        for (int i = 0; i < n; i++)
            arr[i + l] = sorted[i];
         
    }
public:
    void mergeSort(int arr[], int l, int r)
    {
        if(l >= r)
            return;
        
        int n = (r - l) + 1;
        int mid = l + (r - l) / 2;
        
        mergeSort(arr, l, mid);
        mergeSort(arr, mid + 1, r);
        
        merge(arr, l, mid, r, n);
    }
};