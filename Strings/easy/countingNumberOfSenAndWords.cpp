// Given a text, text. The task is to count the number of sentences and words in the text.
// Definition of a sentence :- Sentences are defined as contiguous space-separated strings of characters ending with a sentence punctuation (' . ',  ' ! ' or ' ? ') or the last contiguous set of space-separated strings, even if they don't end with a punctuation mark.
// Definition of a word :- Words are defined as a string of alphabetic characters i.e. any upper or lower case characters a-z or A-Z.

// Example 1:

// Input: text = "Sentences"
// Output: 1 1
// Explaination: There is only one word and
// sentence in the given text.
// Example 2:

// Input: text = "many??? Sentences are"
// Output: 2 3
// Explaination: There are two sentences and
// three words.
// Your Task:
// You do not need to read input or print anything. Your task is to complete the function sentenceWord() which takes text as input parameters and returns a list containing number of sentences and words respectively.

// Expected Time Complexity: O(|text|)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ |text| ≤ 250

// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
public:
    vector<int> sentenceWord(string text)
    {
        // code here
        vector<int> ans;
        int wordCount = 1, sentCount = 1;
        for (int i = 0; i < text.length() - 1; i++)
        {
            if (text[i] == ' ')
            {
                wordCount++;
            }
            if ((text[i] == '?' or text[i] == '.' or text[i] == '!') and text[i + 1] == ' ')
            {
                sentCount++;
            }
        }
        ans.push_back(sentCount);
        ans.push_back(wordCount);

        return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string text;
        cin.ignore();
        getline(cin, text);
        Solution ob;
        vector<int> ans = ob.sentenceWord(text);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
} // } Driver Code Ends
