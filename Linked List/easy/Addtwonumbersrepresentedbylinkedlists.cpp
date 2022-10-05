// Given two decimal numbers represented by two linked lists of size N and M respectively. The task is to return a linked list that represents the sum of these two numbers.

// For example, the number 190 will be represented by the linked list, 1->9->0->null, similarly 25 by 2->5->null. Sum of these two numbers is 190 + 25 = 215, which will be represented by 2->1->5->null. You are required to return the head of the linked list 2->1->5->null.

// Example 1:

// Input:
// N = 2
// valueN[] = {4,5}
// M = 3
// valueM[] = {3,4,5}
// Output: 3 9 0  
// Explanation: For the given two linked
// list (4 5) and (3 4 5), after adding
// the two linked list resultant linked
// list will be (3 9 0).
// Example 2:

// Input:
// N = 2
// valueN[] = {6,3}
// M = 1
// valueM[] = {7}
// Output: 7 0
// Explanation: For the given two linked
// list (6 3) and (7), after adding the
// two linked list resultant linked list
// will be (7 0).
// Your Task:
// The task is to complete the function addTwoLists() which has node reference of both the linked lists and returns the head of the sum list.   

// Expected Time Complexity: O(N+M)
// Expected Auxiliary Space: O(Max(N,M)) for the resultant list.

// Constraints:
// 1 <= N, M <= 5000

// View Bookmarked Problems 
// Company Tags
// AccoliteAmazonFlipkartMakeMyTripMicrosoftMorgan StanleyQualcommSnapdeal

//{ Driver Code Starts
// driver

#include <bits/stdc++.h>
using namespace std;

/* Linked list Node */
struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node* buildList(int size)
{
    int val;
    cin>> val;
    
    Node* head = new Node(val);
    Node* tail = head;
    
    for(int i=0; i<size-1; i++)
    {
        cin>> val;
        tail->next = new Node(val);
        tail = tail->next;
    }
    
    return head;
}

void printList(Node* n)
{
    while(n)
    {
        cout<< n->data << " ";
        n = n->next;
    }
    cout<< endl;
}


// } Driver Code Ends
 node for linked list:

struct Node {
    int data;
    struct Node* next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};


#define ll long long

class Solution
{
    public:
    //Function to add two numbers represented by linked list.
    struct Node* addTwoLists(struct Node* first, struct Node* second)
    {
        string number1="",number2="";
        while(first!=NULL){
            struct Node*temp=first;
            number1+=(first->data+48);
            first=first->next;
            free(temp);
        }
        while(second!=NULL){
            struct Node*temp=first;
            number2+=(second->data+48);
            second=second->next;
            free(temp);
        }
        
        if (number1.length() > number2.length())
        swap(number1, number2);
        string sum = "";
        int len1 = number1.length();
        int len2 = number2.length();
        int digitDiff = len2 - len1;
        int carry = 0;
        int intSum;
        for (int i=len1-1; i>=0; i--) {
           intSum = ((number1[i]-'0') + (number2[i+digitDiff]- '0') + carry);
           sum.push_back(intSum%10 + '0');
           carry = intSum/10;
        }
        for (int i=digitDiff-1; i>=0; i--) {
           intSum = ((number2[i]-'0')+carry);
           sum.push_back(intSum%10 + '0');
           carry = intSum/10;
        }
        if (carry)
         sum.push_back(carry+'0');
         
        struct Node* head=new Node((sum[0]-'0'));
        struct Node* temp;
        for(int i=1;i<sum.length();i++){
            temp=new Node((sum[i]-'0'));
            temp->next=head;
            head=temp;
        }
            
            
        return head;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, m;
        
        cin>>n;
        Node* first = buildList(n);
        
        cin>>m;
        Node* second = buildList(m);
        Solution ob;
        Node* res = ob.addTwoLists(first,second);
        printList(res);
    }
    return 0;
}

// } Driver Code Ends




// ********************Using o(max(n,m)) time and o(1) space****************

// // C++ Code to add two nodes by reversing the two lists

// #include <bits/stdc++.h>
// using namespace std;

// /* Linked list Node */
// struct Node {
//     int data;
//     struct Node* next;
// };

// Node* newNode(int data)
// {
//     Node* new_node = (Node*)malloc(sizeof(Node));
//     new_node->data = data;
//     new_node->next = NULL;
//     return new_node;
// }

// /* Function to insert a node at the
// beginning of the Singly Linked List */
// void push(Node** head_ref, int new_data)
// {
//     /* allocate node */
//     Node* new_node = newNode(new_data);
//     /* link the old list off the new node */
//     new_node->next = (*head_ref);
//     /* move the head to point to the new node */
//     (*head_ref) = new_node;
// }

// void printList(Node* n)
// {
//     while (n) {
//         cout << n->data << " ";
//         n = n->next;
//     }
//     cout << endl;
// }

// struct Node* reverseList(struct Node* list)
// {
//     Node *prev = NULL, *cur = list, *next = NULL;
//     while (cur != NULL) {
//         next = cur->next;
//         cur->next = prev;
//         prev = cur;
//         cur = next;
//     }
//     return prev;
// }

// //----------------------------------------------------------------------------

// Node* addTwoLists(Node* first, Node* second)
// {
//     // code here
//     first = reverseList(first);
//     second = reverseList(second);

//     int carry = 0;
//     Node *head = NULL, *prev = NULL;
//     Node* sum = NULL;
//     // if any one of these is left we are stil left with addition
//     while (first != NULL or second != NULL or carry == 1)
//     {
//         int newVal = carry;
//         if (first)
//             newVal += first->data;
//         if (second)
//             newVal += second->data;
//         // to be used in the next node calculation
//         carry = newVal / 10;
//         newVal = newVal % 10;
//         Node* newNode = (Node*)malloc(sizeof(Node));
//         newNode->data = newVal;
//         // appending in the beginning of the final ans list,
//         // this way we do not have to reverse in the end
//         newNode->next = sum;
//         sum = newNode;
//         // initialising nodes for next iteration

//         if (first)
//             first = first->next;
//         if (second)
//             second = second->next;
//     }

//     return sum;
// }

// //----------------------------------------------------------------------------

// // { Driver Code Starts.

// int main()
// {
//     Node* first = NULL;
//     Node* second = NULL;

//     push(&first, 9);
//     push(&first, 8);
//     push(&first, 7);

//     push(&second, 1);
//     push(&second, 2);
//     push(&second, 3);

//     Node* ans = addTwoLists(first, second);

//     cout << "Sum is : ";
//     printList(ans);

//     return 0;
// }