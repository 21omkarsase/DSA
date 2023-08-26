// 21. Merge Two Sorted Lists
// Easy
// 19.6K
// 1.8K
// Companies

// You are given the heads of two sorted linked lists list1 and list2.

// Merge the two lists into one sorted list. The list should be made by splicing together the nodes of the first two lists.

// Return the head of the merged linked list.

 

// Example 1:

// Input: list1 = [1,2,4], list2 = [1,3,4]
// Output: [1,1,2,3,4,4]

// Example 2:

// Input: list1 = [], list2 = []
// Output: []

// Example 3:

// Input: list1 = [], list2 = [0]
// Output: [0]

 

// Constraints:

//     The number of nodes in both lists is in the range [0, 50].
//     -100 <= Node.val <= 100
//     Both list1 and list2 are sorted in non-decreasing order.

// Accepted
// 3.4M
// Submissions
// 5.5M
// Acceptance Rate
// 63.0%

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *dummy = new ListNode(-101);

        ListNode *ptr1 = list1, *ptr2 = list2;
        ListNode *ptr = dummy;

        while (ptr1 && ptr2) {
            if (ptr1->val < ptr2->val) {
                ptr->next = ptr1;
                ptr1 = ptr1->next;
            }
            else {
                ptr->next = ptr2;
                ptr2 = ptr2->next;
            }

            ptr = ptr ->next;
        }

        if (ptr1) {
            ptr->next = ptr1;
        }

        if (ptr2) {
            ptr->next = ptr2;
        }

        return dummy->next;
    }
};