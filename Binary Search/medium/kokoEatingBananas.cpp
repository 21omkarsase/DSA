// 875. Koko Eating Bananas
// Medium
// 7.8K
// 374
// Companies

// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

 

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4

// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30

// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23

 

// Constraints:

//     1 <= piles.length <= 104
//     piles.length <= h <= 109
//     1 <= piles[i] <= 109

// Accepted
// 371.7K
// Submissions
// 718.8K
// Acceptance Rate
// 51.7%

class Solution {
    bool isValidValue(long long k, int hours, vector<int> &piles){
        long long h = 0;
        for(auto pile : piles){
            if(pile % k == 0)
                h += (pile / k);
            else h += (pile / k + 1);
        }
        return hours >= h;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        long long st = 1;
        long long en = accumulate(piles.begin(), piles.end(), static_cast<long long>(0));

        while(st <= en){
            long long mid = st + (en - st) / 2;
            cout << st << " : " << mid << " : " << en << " ==> ";

            if(isValidValue(mid, h, piles)){
                en = mid - 1;
            }else st = mid + 1;
        }

        cout << " end : " << st << " : " << en << "\n";

        return static_cast<int>(st);
    }
};
