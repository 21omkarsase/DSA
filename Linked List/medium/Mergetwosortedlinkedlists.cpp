//{ Driver Code Starts
#include<iostream>
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

Node* sortedMerge(struct Node* a, struct Node* b);

/* Function to print Nodes in a given linked list */
void printList(struct Node *n)
{
    while (n!=NULL)
    {
        cout << n->data << " ";
        n = n->next;
    }
    cout << endl;
}

/* Driver program to test above function*/
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,m;
        cin>>n>>m;

        int data;
        cin>>data;
        struct Node *head1 = new Node(data);
        struct Node *tail1 = head1;
        for (int i = 1; i < n; ++i)
        {
            cin>>data;
            tail1->next = new Node(data);
            tail1 = tail1->next;
        }

        cin>>data;
        struct Node *head2 = new Node(data);
        struct Node *tail2 = head2;
        for(int i=1; i<m; i++)
        {
            cin>>data;
            tail2->next = new Node(data);
            tail2 = tail2->next;
        }

        Node *head = sortedMerge(head1, head2);
        printList(head);
    }
    return 0;
}

// } Driver Code Ends


 

/* Link list Node
struct Node {
  int data;
  struct Node *next;
  
  Node(int x) {
    data = x;
    next = NULL;
  }
};
*/
//Function to merge two sorted linked list.
Node* sortedMerge(Node* head1, Node* head2)  
{  
    // ************** In this approach we are creating new linked list and returning its head node
	// Node* temp1=head1,*temp2=head2;
 //    Node *newHead,*curr;
 //    if(temp1->data<temp2->data){
 //        newHead=new Node(temp1->data);
 //        temp1=temp1->next;
 //    }
 //    else{
 //        newHead=new Node(temp2->data);
 //        temp2=temp2->next;
 //    }
 //    curr=newHead;
	// while(temp1!=NULL and temp2!=NULL){
	// 	if(temp1->data<temp2->data){
 //            Node* nxt=new Node(temp1->data);
	// 		curr->next=nxt;
	// 		curr=nxt;
	// 		temp1=temp1->next;
	// 	}else{
 //            Node* nxt=new Node(temp2->data);
 //            curr->next=nxt;
	// 		curr=nxt;
	// 		temp2=temp2->next;
	// 	}
	// }

 //    while(temp1!=NULL){
 //        Node *nxt=new Node(temp1->data);
 //        curr->next=nxt;
 //        curr=nxt;
 //        temp1=temp1->next;
 //    }
 //    while(temp2!=NULL){
 //        Node *nxt=new Node(temp2->data);
 //        curr->next=nxt;
 //        curr=nxt;
 //        temp2=temp2->next;
 //    }

	// return newHead;



    // ************** In this approach we are not creating new linked list instead we are changing links between the nodes

    Node *p1=head1,*p2=head2;
    Node* dummyNode=new Node(-1);
    Node* p3=dummyNode;

    while(p1!=NULL and p2!=NULL){
        if(p1->data<p2->data){
            p3->next=p1;
            p1=p1->next;
        }else{
            p3->next=p2;
            p2=p2->next;
        }
        p3=p3->next;
    }

    while(p1!=NULL){
        p3->next=p1;
        p1=p1->next;
        p3=p3->next;
    }

    while(p2!=NULL){
        p3->next=p1;
        p2=p2->next;
        p3=p3->next;
    }

    return dummyNode->next;
}  