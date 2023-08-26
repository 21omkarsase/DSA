// 234. Palindrome Linked List
// Easy
// 14.9K
// 812
// Companies

// Given the head of a singly linked list, return true if it is a
// palindrome
// or false otherwise.

 

// Example 1:

// Input: head = [1,2,2,1]
// Output: true

// Example 2:

// Input: head = [1,2]
// Output: false

 

// Constraints:

//     The number of nodes in the list is in the range [1, 105].
//     0 <= Node.val <= 9

 
// Follow up: Could you do it in O(n) time and O(1) space?
// Accepted
// 1.5M
// Submissions
// 3M
// Acceptance Rate
// 50.8%

class Solution {
    int calculateLinkListLength(ListNode *head) {
        int n = 0;

        while (head) {
            n++;
            head = head->next;
        }

        return n;
    }
public:
    bool isPalindrome(ListNode* head) {
        int len = calculateLinkListLength(head);
        
        ListNode *prev = nullptr, *curr = head;
        int n = len / 2;

        while (n--) {
            ListNode *nxt = curr->next;

            curr->next = prev;
            prev = curr;

            curr = nxt;
        }

        ListNode *back = prev, *front = curr;

        if (len & 1) {
            front = curr->next;
        }
        
        while (back && front) {
            if (back->val != front->val) {
                return false;
            }

            back = back->next;
            front = front->next;
        }

        if (back || front) {
            return false;
        }

        return true;
    }
};
