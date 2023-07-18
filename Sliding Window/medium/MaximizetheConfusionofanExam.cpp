// 2024. Maximize the Confusion of an Exam
// Medium
// 1.1K
// 21
// Companies

// A teacher is writing a test with n true/false questions, with 'T' denoting true and 'F' denoting false. He wants to confuse the students by maximizing the number of consecutive questions with the same answer (multiple trues or multiple falses in a row).

// You are given a string answerKey, where answerKey[i] is the original answer to the ith question. In addition, you are given an integer k, the maximum number of times you may perform the following operation:

//     Change the answer key for any question to 'T' or 'F' (i.e., set answerKey[i] to 'T' or 'F').

// Return the maximum number of consecutive 'T's or 'F's in the answer key after performing the operation at most k times.

 

// Example 1:

// Input: answerKey = "TTFF", k = 2
// Output: 4
// Explanation: We can replace both the 'F's with 'T's to make answerKey = "TTTT".
// There are four consecutive 'T's.

// Example 2:

// Input: answerKey = "TFFT", k = 1
// Output: 3
// Explanation: We can replace the first 'T' with an 'F' to make answerKey = "FFFT".
// Alternatively, we can replace the second 'T' with an 'F' to make answerKey = "TFFF".
// In both cases, there are three consecutive 'F's.

// Example 3:

// Input: answerKey = "TTFTTFTT", k = 1
// Output: 5
// Explanation: We can replace the first 'F' to make answerKey = "TTTTTFTT"
// Alternatively, we can replace the second 'F' to make answerKey = "TTFTTTTT". 
// In both cases, there are five consecutive 'T's.

 

// Constraints:

//     n == answerKey.length
//     1 <= n <= 5 * 104
//     answerKey[i] is either 'T' or 'F'
//     1 <= k <= n

// Accepted
// 27.9K
// Submissions
// 45.4K
// Acceptance Rate
// 61.4%

// Time Complexity : O(4N)
// Space Complexity : O(1)

class Solution {
    int checkForMaxConfused(char ch, int k, int n, string answerKey) {
        int left = 0;
        int confusedLength = 0;

        for (int right = 0; right < n; right++) {
            if (k >= 1 || answerKey[right] == ch) {
                confusedLength = max(confusedLength, right - left + 1);
                
                if (answerKey[right] != ch)
                    k--;

                continue;
            }

            while (k == 0 && left <= right) {
                if (answerKey[left] != ch) {
                    k++;
                }
                left++;
            }

            k = 0;

            confusedLength = max(confusedLength, right - left + 1);
        }

        return confusedLength;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();

        int maxConfusedLength = 0;

        maxConfusedLength = max(maxConfusedLength, checkForMaxConfused('T', k, n, answerKey));
        maxConfusedLength = max(maxConfusedLength, checkForMaxConfused('F', k, n, answerKey));

        return maxConfusedLength;
    }
};

// using binary search
// Time Complexity : O(N*LogN)
// Space Complexity : O(1)

class Solution {
    bool isValid(int mid, int k, int n, string answerKey) {
        int left = 0; 
        
        int trueCount = 0;

        for (int right = 0; right < n; right++) {
            if (answerKey[right] == 'T')
                trueCount++;

            if (right - left + 1 == mid) {
                if (trueCount <= k || mid - trueCount <= k) {
                    return true;
                }

                if (answerKey[left++] == 'T')
                    trueCount--;
            }
        }

        return false;
    }
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int n = answerKey.size();

        int left = 1, right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (isValid(mid, k, n, answerKey)) {
                left = mid + 1;
            } else 
                right = mid - 1;
        }

        return right;
    }
};