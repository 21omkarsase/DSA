// 445. Add Two Numbers II
// Medium
// 4.6K
// 248
// Companies

// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

// You may assume the two numbers do not contain any leading zero, except the number 0 itself.

 

// Example 1:

// Input: l1 = [7,2,4,3], l2 = [5,6,4]
// Output: [7,8,0,7]

// Example 2:

// Input: l1 = [2,4,3], l2 = [5,6,4]
// Output: [8,0,7]

// Example 3:

// Input: l1 = [0], l2 = [0]
// Output: [0]

 

// Constraints:

//     The number of nodes in each linked list is in the range [1, 100].
//     0 <= Node.val <= 9
//     It is guaranteed that the list represents a number that does not have leading zeros.

 

// Follow up: Could you solve it without reversing the input lists?
// Accepted
// 377.1K
// Submissions
// 630.4K
// Acceptance Rate
// 59.8%

// Time Complexity : O(4N)
// Space Complexity : O(1)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    ListNode* reverseLL(ListNode *&head) {
        ListNode *prev = nullptr, *curr = head;
        while (curr) {
            ListNode *temp = curr->next;

            curr->next = prev;
            prev = curr;
            curr = temp;
        }

        return prev;
    }
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *head1 = reverseLL(l1);
        ListNode *head2 = reverseLL(l2);

        ListNode *temp = new ListNode(-1);
        ListNode *dummy = temp;

        int carry = 0;
        
        while (head1 && head2) {
            int num = head1->val + head2->val + carry;

            temp->next = new ListNode(num % 10); 
            num /= 10;
            carry = num;

            head1 = head1->next;
            head2 = head2->next;
            temp = temp->next;
        }
        
        while (head1) {
            int num = head1->val + carry;

            temp->next = new ListNode(num % 10); 
            num /= 10;
            carry = num;

            head1 = head1->next;
            temp = temp->next;
        }
        
        while (head2) {
            int num = head2->val + carry;

            temp->next = new ListNode(num % 10);
            num /= 10;
            carry = num;

            head2 = head2->next;
            temp = temp->next;
        }

        if (carry) {
            temp->next = new ListNode(carry);
        }
        
        ListNode *head = dummy->next;
        dummy->next = nullptr;

        head = reverseLL(head);

        return head;
    }
};