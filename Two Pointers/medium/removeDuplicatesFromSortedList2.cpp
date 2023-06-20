// 82. Remove Duplicates from Sorted List II
// Medium
// 7.8K
// 208
// Companies

// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.

 

// Example 1:

// Input: head = [1,2,3,3,4,4,5]
// Output: [1,2,5]

// Example 2:

// Input: head = [1,1,1,2,3]
// Output: [2,3]

 

// Constraints:

//     The number of nodes in the list is in the range [0, 300].
//     -100 <= Node.val <= 100
//     The list is guaranteed to be sorted in ascending order.

// Accepted
// 609.7K
// Submissions
// 1.3M
// Acceptance Rate
// 46.1%

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
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode *it = head, *dummy = new ListNode(-1);
        dummy->next = head;
        ListNode *prev = dummy;

        while(it){
            ListNode *temp = it;
            int count = 0;
            while(temp && temp->val == it->val){
                temp = temp->next;
                count++;
            }
            
            if(count > 1){
                prev->next = temp;
                it = temp;
            }else{
                prev = it;
                it = temp;
            }
        }

        return dummy->next;
    }
};