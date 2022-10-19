// Swap Kth nodes from ends
// MediumAccuracy: 46.75%Submissions: 41631Points: 4
// LampGeek Week 2022 is LIVE! Click Here to View All the Exciting Offers!
// Given a singly linked list of size N, and an integer K. You need to swap the Kth node from the beginning and Kth node from the end of the linked list. Swap the nodes through the links. Do not change the content of the nodes.

// Example 1:

// Input:
// N = 4,  K = 1
// value[] = {1,2,3,4}
// Output: 1
// Explanation: Here K = 1, hence after
// swapping the 1st node from the beginning
// and end thenew list will be 4 2 3 1.

// Example 2:

// Input:
// N = 5,  K = 7
// value[] = {1,2,3,4,5}
// Output: 1
// Explanation: K > N. Swapping is invalid.
// Return the head node as it is.

// Your Task:
// You do not need to read input or print anything. The task is to complete the function swapkthnode(), which has takes head of link list, N and K as input parameters and returns the new head.
// The generated output will be 1 if you are able to complete your task.

// Expected Time Complexity: O(n)
// Expected Auxillary space Complexity: O(1)

// Constraints:
// 1 <= N <= 103
// 1 <= K <= 103

// View Bookmarked Problems
// Company Tags
// Topic Tags

//{ Driver Code Starts
#include <iostream>

using namespace std;

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

Node *swapkthnode(Node *head, int num, int K);

void addressstore(Node **arr, Node *head)
{
    Node *temp = head;
    int i = 0;
    while (temp)
    {
        arr[i] = temp;
        i++;
        temp = temp->next;
    }
}

bool check(Node **before, Node **after, int num, int K)
{
    if (K > num)
        return 1;
    return (before[K - 1] == after[num - K]) && (before[num - K] == after[K - 1]);
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int num, K, firstdata;
        cin >> num >> K;
        int temp;
        cin >> firstdata;
        Node *head = new Node(firstdata);
        Node *tail = head;
        for (int i = 0; i < num - 1; i++)
        {
            cin >> temp;
            tail->next = new Node(temp);
            tail = tail->next;
        }

        Node *before[num];
        addressstore(before, head);

        head = swapkthnode(head, num, K);

        Node *after[num];
        addressstore(after, head);

        if (check(before, after, num, K))
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
}

// } Driver Code Ends

// User function Template for C++

/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
     Node(int x) {
        data = x;
        next = NULL;
  }
  }
*/

// Function to swap Kth node from beginning and end in a linked list.
Node *swapkthnode(Node *head, int num, int k)
{
    if (k > num)
        return head;

    Node *temp = head;
    Node *start = head, *prevStart = NULL;
    Node *end = head, *prevEnd = NULL;

    for (int i = 1; i < k; i++)
    {
        prevStart = start;
        start = start->next;
    }

    for (int i = 1; i < num - k + 1; i++)
    {
        prevEnd = end;
        end = end->next;
    }

    if (k == 1)
    {
        prevEnd->next = start;
        end->next = start->next;
        start->next = NULL;
        return end;
    }

    if (k == num)
    {
        prevStart->next = end;
        start->next = end->next;
        end->next = NULL;
        return start;
    }
    else
    {
        prevStart->next = end;
        prevEnd->next = start;
        temp = start->next;
        start->next = end->next;
        end->next = temp;
        return head;
    }
}
