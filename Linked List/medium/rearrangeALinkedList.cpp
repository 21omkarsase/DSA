

// Rearrange a linked list
// MediumAccuracy: 49.14%Submissions: 34957Points: 4
// Lamp
// Geek Week 2022 is LIVE! Click Here to View All the Exciting Offers!

// Given a singly linked list, the task is to rearrange it in a way that all odd position nodes are together and all even positions node are together.
// Assume the first element to be at position 1 followed by second element at position 2 and so on.
// Note: You should place all odd positioned nodes first and then the even positioned ones. (considering 1 based indexing). Also, the relative order of odd positioned nodes and even positioned nodes should be maintained.

// Example 1:

// Input:
// LinkedList: 1->2->3->4
// Output: 1 3 2 4
// Explanation:
// Odd elements are 1, 3 and even elements are
// 2, 4. Hence, resultant linked list is
// 1->3->2->4.
// Example 2:

// Input:
// LinkedList: 1->2->3->4->5
// Output: 1 3 5 2 4
// Explanation:
// Odd elements are 1, 3, 5 and even elements are
// 2, 4. Hence, resultant linked list is
// 1->3->5->2->4.
// Your Task:
// The task is to complete the function rearrangeEvenOdd() which rearranges the nodes in the linked list as required and doesn't return anything.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 ≤ Size of the linked list ≤ 104
// 0 ≤ value of linked list ≤ 103

// View Bookmarked Problems
// Company Tags
// AmazonMicrosoft
// Topic Tags
// Linked List

//{ Driver Code Starts
// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
using namespace std;

/* Link list Node */
struct Node
{
    int data;
    struct Node *next;

    Node(int x)
    {
        data = x;
        next = NULL;
    }
};

// } Driver Code Ends
/* Node structure

struct Node
{
    int data;
    struct Node* next;

    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

class Solution
{
public:
    void rearrangeEvenOdd(Node *head)
    {
        Node *temp1 = head, *temp2 = head->next, *root2 = head->next;
        while (temp1->next != NULL and temp2->next != NULL)
        {
            temp1->next = temp1->next->next;
            temp1 = temp1->next;
            temp2->next = temp2->next->next;
            temp2 = temp2->next;
        }
        temp1->next = root2;
    }
};

//{ Driver Code Starts.

/* Driver program to test above function*/
int main()
{
    int T, i, n, l;

    cin >> T;

    while (T--)
    {
        struct Node *head = NULL;
        struct Node *temp = head;
        cin >> n;
        for (i = 1; i <= n; i++)
        {
            cin >> l;

            if (head == NULL)
            {
                head = temp = new Node(l);
            }
            else
            {
                temp->next = new Node(l);
                temp = temp->next;
            }
        }
        Solution ob;
        ob.rearrangeEvenOdd(head);
        while (head != NULL)
        {
            printf("%d ", head->data);
            head = head->next;
        }
        printf("\n");
    }
    return 0;
}

// } Driver Code Ends