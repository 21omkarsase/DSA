// 86. Partition List
// Medium
// 5.9K
// 671
// Companies

// Given the head of a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

// You should preserve the original relative order of the nodes in each of the two partitions.

 

// Example 1:

// Input: head = [1,4,3,2,5,2], x = 3
// Output: [1,2,2,4,3,5]

// Example 2:

// Input: head = [2,1], x = 2
// Output: [1,2]

 

// Constraints:

//     The number of nodes in the list is in the range [0, 200].
//     -100 <= Node.val <= 100
//     -200 <= x <= 200

// Accepted
// 481.3K
// Submissions
// 906.6K
// Acceptance Rate
// 53.1%

class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
        ListNode *left = new ListNode(-1), *right = new ListNode(-1), *temp = head;

        ListNode *leftFront = left, *rightFront = right;

        while (temp) {
            if (temp->val < x) {
                left->next = temp;
                left = left->next;
            }
            else {
                right->next = temp;
                right = right->next;
            }

            temp = temp->next;
        }

        left->next = rightFront->next;
        right->next = nullptr;
        
        return leftFront->next;
    }
};