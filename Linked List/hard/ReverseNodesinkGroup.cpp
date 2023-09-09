// 25. Reverse Nodes in k-Group
// Hard
// 12.4K
// 612
// Companies

// Given the head of a linked list, reverse the nodes of the list k at a time, and return the modified list.

// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes, in the end, should remain as it is.

// You may not alter the values in the list's nodes, only nodes themselves may be changed.

 

// Example 1:

// Input: head = [1,2,3,4,5], k = 2
// Output: [2,1,4,3,5]

// Example 2:

// Input: head = [1,2,3,4,5], k = 3
// Output: [3,2,1,4,5]

 

// Constraints:

//     The number of nodes in the list is n.
//     1 <= k <= n <= 5000
//     0 <= Node.val <= 1000

 

// Follow-up: Can you solve the problem in O(1) extra memory space?
// Accepted
// 762.8K
// Submissions
// 1.4M
// Acceptance Rate
// 56.3%

// Time Complexity : O(N)
// Space Complexity : O(N)

class Solution {
    int calculateLengthOfLL(ListNode *node) {
        int len = 0;
        
        while (node) {
            len++;
            node = node->next;
        }

        return len;
    }
    
    ListNode* reverseKNodes(ListNode *curr, int k, ListNode *&reverseEnd) {
        ListNode *prev = nullptr;

        while (curr && k--) {
            ListNode *nxt = curr->next;

            curr->next = prev;
            prev = curr;

            curr = nxt;
        }

        reverseEnd = prev;

        return curr;
    }
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) {
            return head;
        }

        int n = calculateLengthOfLL(head);

        ListNode *newHead = nullptr;
        ListNode *curr = head, *start = nullptr, *end = nullptr;

        vector<ListNode*> reverseStart, reverseEnd;

        for (int it = 0; it < (n / k); it++) {
            start = curr;
            reverseStart.push_back(start);

            curr = reverseKNodes(curr, k, end);
            
            reverseEnd.push_back(end);
        }

        for (int idx = 0; idx < reverseStart.size() - 1; idx++) {
            reverseStart[idx]->next = reverseEnd[idx + 1];
        }

        reverseStart[reverseStart.size() - 1]->next = curr;

        return reverseEnd[0];

    }
};

// Time Complexity : O(N)
// Space Complexity : O(n / k)


class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode *node = head;

        for (int idx = 0; idx < k; idx++) {
            if (node == nullptr) {
                return head;
            }

            node = node->next;
        }

        ListNode *prev = nullptr, *curr = head, *nxt = head->next;

        for (int idx = 0; idx < k; idx++) {
            nxt = curr->next;

            curr->next = prev;
            prev = curr;

            curr = nxt;
        }

        head->next = reverseKGroup(curr, k);

        return prev;
    }
};