class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lb = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        
        return lb == ub ? -1 : lb;
    }
};

// std::lower_bound returns an iterator to the first element that is not less than val (i.e., the lower bound), and std::upper_bound returns an iterator to the first element that is greater than val (i.e., the upper bound). If the value is not found, both functions return the end iterator of the container.


class Solution {
public:
    int search(vector<int>& arr, int k) {
        int low=0;
        int high=arr.size()-1;
        
        
        while(low<=high)
        {
        int mid=(low+high)/2;
            if(k==arr[mid])
            {
                return mid;
            }
            else if(k>arr[mid])
            {
                low=mid+1;
            }
            else 
            {
                high=mid-1;
            }
        }
        
        return -1;
    }
};