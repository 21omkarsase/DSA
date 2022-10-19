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
            while(arr[i]!=NULL){
                prev=mergeTwoSortedLinkedLists(prev,arr[i]);
                cout<<prev->data<<" ";
                arr[i]=arr[i]->next;
            }cout<<"\n";
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