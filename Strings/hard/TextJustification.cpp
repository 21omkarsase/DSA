// 68. Text Justification
// Hard
// 2.6K
// 3.7K
// Companies

// Given an array of strings words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.

// You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.

// Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line does not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.

// For the last line of text, it should be left-justified, and no extra space is inserted between words.

// Note:

//     A word is defined as a character sequence consisting of non-space characters only.
//     Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
//     The input array words contains at least one word.

 

// Example 1:

// Input: words = ["This", "is", "an", "example", "of", "text", "justification."], maxWidth = 16
// Output:
// [
//    "This    is    an",
//    "example  of text",
//    "justification.  "
// ]

// Example 2:

// Input: words = ["What","must","be","acknowledgment","shall","be"], maxWidth = 16
// Output:
// [
//   "What   must   be",
//   "acknowledgment  ",
//   "shall be        "
// ]
// Explanation: Note that the last line is "shall be    " instead of "shall     be", because the last line must be left-justified instead of fully-justified.
// Note that the second line is also left-justified because it contains only one word.

// Example 3:

// Input: words = ["Science","is","what","we","understand","well","enough","to","explain","to","a","computer.","Art","is","everything","else","we","do"], maxWidth = 20
// Output:
// [
//   "Science  is  what we",
//   "understand      well",
//   "enough to explain to",
//   "a  computer.  Art is",
//   "everything  else  we",
//   "do                  "
// ]

 

// Constraints:

//     1 <= words.length <= 300
//     1 <= words[i].length <= 20
//     words[i] consists of only English letters and symbols.
//     1 <= maxWidth <= 100
//     words[i].length <= maxWidth

// Accepted
// 312.1K
// Submissions
// 807.1K
// Acceptance Rate
// 38.7%

class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        int n = words.size();

        vector<string> ans;
        
        for (int idx = 0; idx < n; idx++) {
            int tempLen = 0, wordLen = 0;
            
            int idx2 = idx;

            while (idx2 < n && tempLen + words[idx2].size() <= maxWidth) {
                tempLen += (words[idx2].size() + 1);
                wordLen += words[idx2].size();

                idx2++;
            }
            
            idx2--;

            int defaultExtraSpaces = idx2 - idx;
            int addedExtraSpace = maxWidth - wordLen - defaultExtraSpaces;
            int defaultExSpacePerWord;
            int remainingSpace;

            if (idx2 - idx <= 0) {
                defaultExSpacePerWord = maxWidth - wordLen;
                remainingSpace = 0;
            }
            else {
                defaultExSpacePerWord = (defaultExtraSpaces + addedExtraSpace) 
                                        / (idx2 - idx);
                remainingSpace = (defaultExtraSpaces + addedExtraSpace) % (idx2 - idx);
            }

            string curr = "";
            
            if (idx2 == n - 1) {
                for (int idx3 = idx; idx3 <= idx2; idx3++) {
                    curr += words[idx3];
                    if (idx3 != idx2) {
                        curr += " ";
                    }
                }
            }
            else {
                for (int idx3 = idx; idx3 <= idx2; idx3++) {
                    curr += words[idx3];

                    if (idx3 != idx2) {
                        for (int space = 0; space < defaultExSpacePerWord; space++) {
                            curr += " ";
                        }
                    } 
                    
                    if (remainingSpace > 0 && idx3 != idx2) {
                        curr += " ";
                        remainingSpace--;
                    }
                }
            }

            while (curr.size() < maxWidth) {
                curr += " ";
            }

            ans.push_back(curr);
            idx = idx2;
        }

        return ans;
    }
};