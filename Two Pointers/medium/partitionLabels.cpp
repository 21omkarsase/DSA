// 763. Partition Labels
// Medium
// 9.5K
// 351
// Companies

// You are given a string s. We want to partition the string into as many parts as possible so that each letter appears in at most one part.

// Note that the partition is done so that after concatenating all the parts in order, the resultant string should be s.

// Return a list of integers representing the size of these parts.

 

// Example 1:

// Input: s = "ababcbacadefegdehijhklij"
// Output: [9,7,8]
// Explanation:
// The partition is "ababcbaca", "defegde", "hijhklij".
// This is a partition so that each letter appears in at most one part.
// A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits s into less parts.

// Example 2:

// Input: s = "eccbbbbdec"
// Output: [10]

 

// Constraints:

//     1 <= s.length <= 500
//     s consists of lowercase English letters.

// Accepted
// 470.3K
// Submissions
// 589.8K
// Acceptance Rate
// 79.7%

//                  o(n)
class Solution {
public:
    vector<int> partitionLabels(string nums) {
        int n = nums.size();

        vector<int> lastOccurence(26, 0);
        for(int i = 0; i < n; i++)
            lastOccurence[nums[i] - 'a'] = i;
        
        int start = 0, end = 0;
        
        vector<int> count;
        while(start < n){
            if(lastOccurence[nums[start] - 'a'] == start){
                count.push_back(1);
                start = start + 1;
                end = start;
                continue;
            }
            end = lastOccurence[nums[start] - 'a'];

            int newStart = start;
            while(newStart <= end){
                if(lastOccurence[nums[newStart] - 'a'] <= end)
                    newStart++;
                else{
                    end = lastOccurence[nums[newStart] - 'a'];
                    newStart++;
                }
            }

            count.push_back(end - start + 1);
            start = newStart;
        }

        return count;
    }
};


//                 o(n2)
class Solution {
public:
    vector<int> partitionLabels(string s) {
        int n = s.size();
        int i = 0, j = 0, k = 0;

        vector<int> count;
        while(k < n){
            int j = s.rfind(s[i]);
            if(j == i){
                i = i + 1;
                j = i, k = i;
                count.push_back(1);
                continue;
            }
            
            while(i <= j){
                int x = s.rfind(s[i]);
                if(x != i && x > j)
                    j = x;
                i++;
            }
            count.push_back(i - k);
            k = i, j = i;
        }

        return count;
    }
};