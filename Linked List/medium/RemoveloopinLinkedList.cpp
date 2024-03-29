// Remove loop in Linked List
// MediumAccuracy: 47.96%Submissions: 100k+Points: 4
// Lamp
// This problem is part of GFG SDE Sheet. Click here to view more.  

// Given a linked list of N nodes such that it may contain a loop.

// A loop here means that the last node of the link list is connected to the node at position X(1-based index). If the link list does not have any loop, X=0.

// Remove the loop from the linked list, if it is present, i.e. unlink the last node which is forming the loop.


// Example 1:

// Input:
// N = 3
// value[] = {1,3,4}
// X = 2
// Output: 1
// Explanation: The link list looks like
// 1 -> 3 -> 4
//      ^    |
//      |____|    
// A loop is present. If you remove it 
// successfully, the answer will be 1. 

// Example 2:

// Input:
// N = 4
// value[] = {1,8,3,4}
// X = 0
// Output: 1
// Explanation: The Linked list does not 
// contains any loop. 

// Example 3:

// Input:
// N = 4
// value[] = {1,2,3,4}
// X = 1
// Output: 1
// Explanation: The link list looks like 
// 1 -> 2 -> 3 -> 4
//      |_________|
// A loop is present. 
// If you remove it successfully, 
// the answer will be 1. 

// Your Task:
// You don't need to read input or print anything. Your task is to complete the function removeLoop() which takes the head of the linked list as the input parameter. Simply remove the loop in the list (if present) without disconnecting any nodes from the list.
// Note: The generated output will be 1 if your submitted code is correct.


// Expected time complexity: O(N)
// Expected auxiliary space: O(1)


// Constraints:
// 1 ≤ N ≤ 10^4

// View Bookmarked Problems 
// Company Tags
// AdobeAmazonGoldman SachsKulizaMakeMyTripMicrosoftMorgan StanleyNetskopeOracleQualcommSnapdealVMWareWalmart
// Topic Tags
// Linked Listtwo-pointer-algorithm

//{ Driver Code Starts
// driver code

#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

void loopHere(Node* head, Node* tail, int position)
{
    if(position==0) return;
    
    Node* walk = head;
    for(int i=1; i<position; i++)
        walk = walk->next;
    tail->next = walk;
}

bool isLoop(Node* head)
{
    if(!head) return false;
    
    Node* fast = head->next;
    Node* slow = head;
    
    while( fast != slow)
    {
        if( !fast || !fast->next ) return false;
        fast=fast->next->next;
        slow=slow->next;
    }
    
    return true;
}

int length(Node* head)
{
    int ret = 0;
    while(head)
    {
        ret++;
        head = head->next;
    }
    return ret;
}


// } Driver Code Ends
/*
structure of linked list node:

struct Node
{
    int data;
    Node* next;
    
    Node(int val)
    {
        data = val;
        next = NULL;
    }
};

*/
#include <bits/stdc++.h>
class Solution
{
    public:
    //Function to remove a loop in the linked list.
    void removeLoop(Node* head)
    {
    	// Node* temp=head;
    	// unordered_set<Node*>s;
     //    Node * f ;
    	// while(temp!=NULL){
    	// 	if(s.find(temp)!=s.end()){
     //            f = temp;
     //            break;
    	// 	}else{
     //            s.insert(temp);
    	// 	}
     //        temp=temp->next;
    	// }
     //    temp=head;
     //    bool first=true;
     //    if(temp==f){
     //        while(temp!=NULL){
     //            if(temp->next==f){
     //                temp->next=NULL;
     //                break;
     //            }
     //            temp=temp->next;
     //        }
     //    }
     //    else{
     //        temp=head;
     //        while(temp!=NULL){
     //            if(temp->next==f and first)
     //                first=false;
     //            else if(temp->next==f and !first){
     //                temp->next=NULL;
     //                break;
     //            }
     //            temp=temp->next;
     //        }
     //    }

         // ******************OR*******************
        Node* temp=head;
        unordered_set<Node*>s;
        Node * prev=NULL;
        while(temp!=NULL){
            if(s.find(temp)==s.end()){
                s.insert(temp);
                prev=temp;
                temp=temp->next;
            }else{
                prev->next=NULL;
                break;
            }
        }
    }

};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, num;
        cin>>n;
        
        Node *head, *tail;
        cin>> num;
        head = tail = new Node(num);
        
        for(int i=0 ; i<n-1 ; i++)
        {
            cin>> num;
            tail->next = new Node(num);
            tail = tail->next;
        }
        
        int pos;
        cin>> pos;
        loopHere(head,tail,pos);
        
        Solution ob;
        ob.removeLoop(head);
        
        if( isLoop(head) || length(head)!=n )
            cout<<"0\n";
        else
            cout<<"1\n";
    }
	return 0;
}

// } Driver Code Ends

