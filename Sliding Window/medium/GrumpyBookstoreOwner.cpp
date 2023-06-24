// 1052. Grumpy Bookstore Owner
// Medium
// 1.5K
// 123
// Companies

// There is a bookstore owner that has a store open for n minutes. Every minute, some number of customers enter the store. You are given an integer array customers of length n where customers[i] is the number of the customer that enters the store at the start of the ith minute and all those customers leave after the end of that minute.

// On some minutes, the bookstore owner is grumpy. You are given a binary array grumpy where grumpy[i] is 1 if the bookstore owner is grumpy during the ith minute, and is 0 otherwise.

// When the bookstore owner is grumpy, the customers of that minute are not satisfied, otherwise, they are satisfied.

// The bookstore owner knows a secret technique to keep themselves not grumpy for minutes consecutive minutes, but can only use it once.

// Return the maximum number of customers that can be satisfied throughout the day.

 

// Example 1:

// Input: customers = [1,0,1,2,1,1,7,5], grumpy = [0,1,0,1,0,1,0,1], minutes = 3
// Output: 16
// Explanation: The bookstore owner keeps themselves not grumpy for the last 3 minutes. 
// The maximum number of customers that can be satisfied = 1 + 1 + 1 + 1 + 7 + 5 = 16.

// Example 2:

// Input: customers = [1], grumpy = [0], minutes = 1
// Output: 1

 

// Constraints:

//     n == customers.length == grumpy.length
//     1 <= minutes <= n <= 2 * 104
//     0 <= customers[i] <= 1000
//     grumpy[i] is either 0 or 1.

// Accepted
// 64.3K
// Submissions
// 112.6K
// Acceptance Rate
// 57.1%

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        vector<int> nonGrumpyCustomers(n, 0);

        for (int idx = 0; idx < n; idx++) {
            if (idx == 0) {
                nonGrumpyCustomers[0] = grumpy[0] == 1 ? 0 : customers[0];
                continue;
            }

            if (grumpy[idx])
                nonGrumpyCustomers[idx] = nonGrumpyCustomers[idx - 1];
            else
                nonGrumpyCustomers[idx] = nonGrumpyCustomers[idx - 1] + customers[idx];
        }

        int left = 0, customersCountForKMinutes = 0, totalCustomerSatisfiedCount = 0;

        for (int right = 0; right < n; right++) {
            customersCountForKMinutes += customers[right];

            if (right - left + 1 == minutes) {
                int customersSatisfied = nonGrumpyCustomers[n - 1] + customersCountForKMinutes;
                
                if(left > 0)
                    customersSatisfied -= (nonGrumpyCustomers[right] - nonGrumpyCustomers[left - 1]);
                else 
                    customersSatisfied -= nonGrumpyCustomers[right];
                
                totalCustomerSatisfiedCount = max(totalCustomerSatisfiedCount, customersSatisfied);

                customersCountForKMinutes -= customers[left++];
            }
        }

        return max(nonGrumpyCustomers[n - 1], totalCustomerSatisfiedCount);
    }
};

// Time Complexity : O(N)
// Space Complexity : O(1)

class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int n = customers.size();

        int left = 0, currNonGrumpyCustomers = 0, totalNonGrumpyCustomers = 0, customersCountForKMinutes = 0, totalCustomerSatisfiedCount = 0;

        for (int idx = 0; idx < n; idx++) 
            grumpy[idx] == 1 ? totalNonGrumpyCustomers += 0 : totalNonGrumpyCustomers += customers[idx];

        for (int right = 0; right < n; right++) {
            customersCountForKMinutes += customers[right];

            grumpy[right] == 0 ? currNonGrumpyCustomers += customers[right] : currNonGrumpyCustomers += 0;

            if (right - left + 1 == minutes) {
                int customersSatisfied = totalNonGrumpyCustomers - currNonGrumpyCustomers + customersCountForKMinutes;
                
                totalCustomerSatisfiedCount = max(totalCustomerSatisfiedCount, customersSatisfied);

                grumpy[left] == 0 ? currNonGrumpyCustomers -= customers[left] : currNonGrumpyCustomers -= 0;
                customersCountForKMinutes -= customers[left++];
            }
        }

        return max(totalNonGrumpyCustomers, totalCustomerSatisfiedCount);
    }
};