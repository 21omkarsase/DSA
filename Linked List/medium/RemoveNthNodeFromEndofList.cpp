// 19. Remove Nth Node From End of List
// Medium
// 16.7K
// 695
// Companies

// Given the head of a linked list, remove the nth node from the end of the list and return its head.

 

// Example 1:

// Input: head = [1,2,3,4,5], n = 2
// Output: [1,2,3,5]

// Example 2:

// Input: head = [1], n = 1
// Output: []

// Example 3:

// Input: head = [1,2], n = 1
// Output: [1]

 

// Constraints:

//     The number of nodes in the list is sz.
//     1 <= sz <= 30
//     0 <= Node.val <= 100
//     1 <= n <= sz

 

// Follow up: Could you do this in one pass?
// Accepted
// 2.2M
// Submissions
// 5.1M
// Acceptance Rate
// 42.2%

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1001);
        dummy->next = head;

        ListNode *slow = dummy, *fast = dummy;

        while (n-- && fast) {
            fast = fast->next;
        }

        while (fast && fast->next) {
            fast = fast->next;
            slow = slow->next;
        }
        
        ListNode *node_to_be_deleted = slow->next;
        slow->next = slow->next->next;

        delete node_to_be_deleted;

        return dummy->next;
    }
};