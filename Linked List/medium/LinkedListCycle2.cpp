// 142. Linked List Cycle II
// Medium
// 12.4K
// 880
// Companies

// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.

// There is a cycle in a linked list if there is some node in the list that can be reached again by continuously following the next pointer. Internally, pos is used to denote the index of the node that tail's next pointer is connected to (0-indexed). It is -1 if there is no cycle. Note that pos is not passed as a parameter.

// Do not modify the linked list.

 

// Example 1:

// Input: head = [3,2,0,-4], pos = 1
// Output: tail connects to node index 1
// Explanation: There is a cycle in the linked list, where tail connects to the second node.

// Example 2:

// Input: head = [1,2], pos = 0
// Output: tail connects to node index 0
// Explanation: There is a cycle in the linked list, where tail connects to the first node.

// Example 3:

// Input: head = [1], pos = -1
// Output: no cycle
// Explanation: There is no cycle in the linked list.

 

// Constraints:

//     The number of the nodes in the list is in the range [0, 104].
//     -105 <= Node.val <= 105
//     pos is -1 or a valid index in the linked-list.

 

// Follow up: Can you solve it using O(1) (i.e. constant) memory?
// Accepted
// 1.1M
// Submissions
// 2.3M
// Acceptance Rate
// 49.7%

// Time Complexity : O(N)
// Space Complexity : O(1)

// slow pointer distance = l1 + l2
// fast pointer distance = l1 + l2 + cx

// 2 (d(slow)) = d(fast)
// 2l1 + 2l2 = l1 + l2 + cx
// l1 + l2 = cx 

// l1 = cx - l2 --> (l1 = x - l2)

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if (!head || !head->next) {
            return nullptr;
        }

        ListNode *slow = head, *fast = head;

        while (slow && fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) {
                break;
            }
        }

        slow = head;

        while (slow && fast) {
            if (slow == fast) {
                return slow;
            }

            slow = slow->next;
            fast = fast->next;            
        }

        return nullptr;
    }
};