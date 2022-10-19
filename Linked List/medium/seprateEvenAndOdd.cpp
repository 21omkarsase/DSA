// Segregate even and odd nodes in a Link List
// MediumAccuracy: 64.41%Submissions: 39491Points: 4
// Given a link list of size N, modify the list such that all the even numbers appear before all the odd numbers in the modified list. The order of appearance of numbers within each segregation should be same as that in the original list.

// NOTE: Don't create a new linked list, instead rearrange the provided one.


// Example 1:

// Input: 
// N = 7
// Link List:
// 17 -> 15 -> 8 -> 9 -> 2 -> 4 -> 6 -> NULL

// Output: 8 2 4 6 17 15 9

// Explaination: 8,2,4,6 are the even numbers 
// so they appear first and 17,15,9 are odd 
// numbers that appear later.

// Example 2:

// Input:
// N = 4
// Link List:
// 1 -> 3 -> 5 -> 7

// Output: 1 3 5 7

// Explaination: There is no even number. 
// So ne need for modification.

// Your Task:
// You do not need to read input or print anything. Your task is to complete the function divide() which takes N and head of Link List as input parameters and returns the head of modified link list. Don't create a new linked list, instead rearrange the provided one.


// Expected Time Complexity: O(N)
// Expected Auxiliary Space: O(1)


// Constraints:
// 1 ≤ N ≤ 105
// 1 ≤ Each element of the list ≤ 105

// View Bookmarked Problems 
// Topic Tags


//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};
void printList(Node* node) 
{ 
    while (node != NULL) { 
        cout << node->data <<" "; 
        node = node->next; 
    }  
    cout<<"\n";
} 


// } Driver Code Ends
//User function template for C++

/*
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
class Solution{
public:
    Node* divide(int N, Node *head){
        Node *e, *o, *root1, *root2;
        
        bool allEven=true,allOdd=true;
        Node *temp = head;
        while(temp!=NULL){
            if(temp->data&1)
               allEven=false;
            if(!(temp->data&1))
               allOdd=false;
               temp=temp->next;
        }
        
        if(allEven or allOdd)
           return head;

        temp = head;
        bool flag_e = true, flag_o = true;
        while (temp != NULL)
        {
            if (flag_e and !(temp->data & 1))
            {
                e = temp;
                root1 = temp;
                flag_e = false;
                temp = temp->next;
                continue;
            }
            if (flag_o and (temp->data & 1))
            {
                o = temp;
                flag_o = false;
                root2 = temp;
                temp = temp->next;
                continue;
            }
        
            if (!(temp->data & 1))
            {
                e->next = temp;
                e = e->next;
            }
            if(temp->data&1)
            {
                o->next = temp;
                o = o->next;
            }
        
            temp = temp->next;
        }
        o->next=NULL;
        e->next=NULL;
        
        e->next=root2;
        return root1;
    }
};

//{ Driver Code Starts.

int main() {
    //code
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int data;
        cin>>data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N-1; ++i)
        {
            cin>>data;
            tail->next = new Node(data);
            tail = tail->next;
        }
        
        Solution ob;
        Node *ans = ob.divide(N, head);
        printList(ans); 
    }
    return 0;
}

// } Driver Code Ends