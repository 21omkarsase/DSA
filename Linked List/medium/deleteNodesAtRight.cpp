// Delete nodes having greater value on right
// MediumAccuracy: 37.92%Submissions: 71065Points: 4
// Given a singly linked list, remove all the nodes which have a greater value on their right side.

// Example 1:

// Input:
// LinkedList = 12->15->10->11->5->6->2->3
// Output: 15 11 6 3
// Explanation: Since, 12, 10, 5 and 2 are
// the elements which have greater elements
// on the following nodes. So, after deleting
// them, the linked list would like be 15,
// 11, 6, 3.
// Example 2:

// Input:
// LinkedList = 10->20->30->40->50->60
// Output: 60
// Your Task:
// The task is to complete the function compute() which should modify the list as required and return the head of the modified linked list. The printing is done by the driver code,

// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)

// Constraints:
// 1 ≤ size of linked list ≤ 1000
// 1 ≤ element of linked list ≤ 1000
// Note: Try to solve the problem without using any extra space.

// View Bookmarked Problems 
// Company Tags
// Amazon
// Topic Tags
// Linked List

//{ Driver Code Starts
#include<bits/stdc++.h>

using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};


void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}



// } Driver Code Ends
/*

The structure of linked list is the following

struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
*/

Node* reverseLinkedList(Node* head){
    Node* prev=NULL,*temp=head,*nxt=head->next;
    while(temp!=NULL){
        temp->next=prev;
        prev=temp;
        temp=nxt;
        if(nxt!=NULL)
            nxt=nxt->next;
    }
    return prev;
}

class Solution
{
    public:
    Node *compute(Node *head)
    {
        head=reverseLinkedList(head);
        int currMax=head->data;
        Node* temp=head->next;
        Node* prev=head;
        while(temp!=NULL){
            if(temp->data>=currMax){
                currMax=temp->data;
                prev=temp;
            }else{
                prev->next=temp->next;
            }
            temp=temp->next;
        }
        head=reverseLinkedList(head);
        return head;
    }
    
};
   


//{ Driver Code Starts.

int main()
{
    int T;
    cin>>T;

    while(T--)
    {
        int K;
        cin>>K;
        struct Node *head = NULL;
        struct Node *temp = head;

        for(int i=0;i<K;i++){
            int data;
            cin>>data;
            if(head==NULL)
                head=temp=new Node(data);
            else
            {
                temp->next = new Node(data);
                temp = temp->next;
            }
        }
        Solution ob;
        Node *result = ob.compute(head);
        print(result);
        cout<<endl;
    }
}

// } Driver Code Ends