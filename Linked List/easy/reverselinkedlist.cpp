// Reverse a linked list
// EasyAccuracy: 48.93%Submissions: 100k+Points: 2
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.  

// Given a linked list of N nodes. The task is to reverse this list.

// Example 1:

// Input:
// LinkedList: 1->2->3->4->5->6
// Output: 6 5 4 3 2 1
// Explanation: After reversing the list, 
// elements are 6->5->4->3->2->1.
// Example 2:

// Input:
// LinkedList: 2->7->8->9->10
// Output: 10 9 8 7 2
// Explanation: After reversing the list,
// elements are 10->9->8->7->2.
// Your Task:
// The task is to complete the function reverseList() with head reference as the only argument and should return new head after reversing the list.

// Expected Time Complexity: O(N).
// Expected Auxiliary Space: O(1).

// Constraints:
// 1 <= N <= 104

//{ Driver Code Starts
//Initial Template for C++// C program to find n'th Node in linked list
#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

/* Link list Node */
struct Node {
    int data;
    struct Node *next;
    Node(int x)
    {
        data = x;
        next = NULL;
    }
};



// } Driver Code Ends
/* Linked List Node structure:

struct Node
{
    int data;
    struct Node *next;
}
<div class="ace_layer ace_print-margin-layer">…</div>
*/

class Solution
{
    public:
    //Function to reverse a linked list.
    struct Node* reverseList(struct Node *head)
    {
      struct Node* newHead = new Node(head->data);
    //     struct Node* temp=head->next;
    //     struct Node* newNode;
    //     while(temp!=NULL){
    //         newNode=new Node(temp->data);
    //         newNode->next=newHead;
    //         newHead=newNode;
    //         temp=temp->next;
    //     }
    //   return newHead;
    
    //************Modifying given LL************
           struct Node* prev=NULL,*next=NULL,*curr=head;
           while(curr!=NULL){
               next=curr->next;
               curr->next=prev;
               prev=curr;
               curr=next;
           }
          head=prev;
          return head;
    }
};
    


//{ Driver Code Starts.

void printList(struct Node *head)
{
    struct Node *temp = head;
    while (temp != NULL)
    {
       printf("%d ", temp->data);
       temp  = temp->next;
    }
}

/* Driver program to test above function*/
int main()
{
    int T,n,l,firstdata;
    cin>>T;

    while(T--)
    {
        struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        
        for (int i=1; i<n; i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
        
        Solution ob;
        head = ob. reverseList(head);
        
        printList(head);
        cout << endl;
    }
    return 0;
}


// } Driver Code Ends