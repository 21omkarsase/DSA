// Merge K sorted linked lists
// MediumAccuracy: 41.42%Submissions: 56862Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.  

// Given K sorted linked lists of different sizes. The task is to merge them in such a way that after merging they will be a single sorted linked list.

// Example 1:

// Input:
// K = 4
// value = {{1,2,3},{4 5},{5 6},{7,8}}
// Output: 1 2 3 4 5 5 6 7 8
// Explanation:
// The test case has 4 sorted linked 
// list of size 3, 2, 2, 2
// 1st    list     1 -> 2-> 3
// 2nd   list      4->5
// 3rd    list      5->6
// 4th    list      7->8
// The merged list will be
// 1->2->3->4->5->5->6->7->8.
// Example 2:

// Input:
// K = 3
// value = {{1,3},{4,5,6},{8}}
// Output: 1 3 4 5 6 8
// Explanation:
// The test case has 3 sorted linked
// list of size 2, 3, 1.
// 1st list 1 -> 3
// 2nd list 4 -> 5 -> 6
// 3rd list 8
// The merged list will be
// 1->3->4->5->6->8.
// Your Task:
// The task is to complete the function mergeKList() which merges the K given lists into a sorted one. The printing is done automatically by the driver code.

// Expected Time Complexity: O(nk Logk)
// Expected Auxiliary Space: O(k)
// Note: n is the maximum size of all the k link list

// Constraints
// 1 <= K <= 103

 

// View Bookmarked Problems 
// Company Tags
// Topic Tags


//{ Driver Code Starts
// C++ program to merge k sorted arrays of size n each
#include <bits/stdc++.h>
using namespace std;

// A Linked List node
struct Node
{
    int data;
    Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
    
};

/* Function to print nodes in a given linked list */
void printList(Node* node)
{
    while (node != NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
    cout<<endl;
}

// } Driver Code Ends
/*Linked list Node structure

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

Node* mergeTwoSortedLinkedLists(Node*a,Node*b){
    Node * dummy = new Node(-1);
    Node* temp=dummy;
    while(a!=NULL and b!=NULL){
        if(a->data<b->data){
            temp->next=a;
            a=a->next;
        }else{
            temp->next=b;
            b=b->next;
        }
        temp=temp->next;
    }
    
    if(a!=NULL)
        temp->next=a;
    else
        temp->next=b;
    
    return dummy->next;
}

class Solution{
  public:
    //Function to merge K sorted linked list.
    Node * mergeKLists(Node *arr[], int k)
    {
        Node* prev=arr[0];
        for(int i=1;i<k;i++){
            prev=mergeTwoSortedLinkedLists(prev,arr[i]);
        }
        return prev;
    }
};



//{ Driver Code Starts.
// Driver program to test above functions
int main()
{
   int t;
   cin>>t;
   while(t--)
   {
       int N;
       cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
        }
        Solution obj;
        Node *res = obj.mergeKLists(arr,N);
        printList(res);

   }

    return 0;
}

// } Driver Code Ends