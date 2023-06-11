// Identical Linked Lists
// BasicAccuracy: 51.37%Submissions: 70654Points: 1
// Given two Singly Linked List of N and M nodes respectively. The task is to check whether two linked lists are identical or not. 
// Two Linked Lists are identical when they have same data and with same arrangement too.

// Example 1:

// Input:
// LinkedList1: 1->2->3->4->5->6
// LinkedList2: 99->59->42->20
// Output: Not identical 
// Example 2:

// Input:
// LinkedList1: 1->2->3->4->5
// LinkedList2: 1->2->3->4->5
// Output: Identical
 
// Your Task:
// The task is to complete the function areIdentical() which takes the head of both linked lists as arguments and returns True or False.

// Constraints:
// 1 <= N <= 103

// Expected Time Complexity : O(N)
// Expected Auxilliary Space : O(1)

//{ Driver Code Starts
#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<bits/stdc++.h>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

bool areIdentical(struct Node *a, struct Node *b);


int main()
{
    int T;
    cin>>T;
    while(T--){
        int n1, n2, tmp , d1 , d2;
        struct Node *head1 = NULL , *tail1=NULL;
        struct Node *head2 = NULL , *tail2 =NULL;
        cin>>n1;
        cin>>d1;
        head1 = new Node(d1);
        tail1 = head1;
        while(n1-- > 1){
            cin>>tmp;
            tail1->next = new Node(tmp);
            tail1 = tail1->next;
        }
        cin>>n2;
        cin>>d2;
        head2 = new Node(d2);
        tail2 = head2;
        while(n2-- >1)
        {
            cin>>tmp;
            tail2->next = new Node(tmp);
            tail2 = tail2->next;
        }
        areIdentical(head1, head2)?cout<<"Identical"<<endl:cout<<"Not identical"<<endl;
    }
	return 0;
}

// } Driver Code Ends


/*
Structure of the node of the linked list is as
struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/

//Function to check whether two linked lists are identical or not. 
bool areIdentical(struct Node *head1, struct Node *head2)
{
    struct Node *temp1=head1,*temp2=head2;
    if(temp1->next==NULL and temp2->next==NULL and temp1->data!=temp2->data)return false;
    
    while(temp1->next!=NULL and temp2->next!=NULL){
        int x=temp1->data,y=temp2->data;
        if(x!=y)return false;
        temp1=temp1->next;
        temp2=temp2->next;
    }
    if((temp1->next!=NULL and temp2->next==NULL)or (temp1->next==NULL and temp2->next!=NULL))return false;
    return true;
}