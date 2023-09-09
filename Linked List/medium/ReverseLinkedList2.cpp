// 92. Reverse Linked List II
// Medium
// 9.9K
// 451
// Companies

// Given the head of a singly linked list and two integers left and right where left <= right, reverse the nodes of the list from position left to position right, and return the reversed list.

 

// Example 1:

// Input: head = [1,2,3,4,5], left = 2, right = 4
// Output: [1,4,3,2,5]

// Example 2:

// Input: head = [5], left = 1, right = 1
// Output: [5]

 

// Constraints:

//     The number of nodes in the list is n.
//     1 <= n <= 500
//     -500 <= Node.val <= 500
//     1 <= left <= right <= n

 
// Follow up: Could you do it in one pass?
// Accepted
// 686.6K
// Submissions
// 1.5M
// Acceptance Rate
// 45.9%

// Time Complexity : O(N)
// space complexity : O(1)

class Solution {
    ListNode* reverseLL(ListNode* node, int k) {
        ListNode* curr = node, *prev = nullptr, *nxt = node->next;
        int it = 1;

        while (it <= k) {
            nxt = curr->next;

            curr->next = prev;
            prev = curr;

            curr = nxt;
            it++;
        }

        node->next = curr;
        
        return prev;
    }
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;

        ListNode* temp = dummy;
        int it = 1;

        while (it < left) {
            temp = temp->next;
            it++;
        }

        temp->next = reverseLL(temp->next, right - left + 1);

        return dummy->next;
    }
};