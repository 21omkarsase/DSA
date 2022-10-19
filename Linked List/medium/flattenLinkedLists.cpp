// //{ Driver Code Starts
// #include <bits/stdc++.h>

// struct Node
// {
//     int data;
//     struct Node *next;
//     struct Node *bottom;

//     Node(int x)
//     {
//         data = x;
//         next = NULL;
//         bottom = NULL;
//     }
// };

// using namespace std;

// void printList(Node *Node)
// {
//     while (Node != NULL)
//     {
//         printf("%d ", Node->data);
//         Node = Node->bottom;
//     }
// }

// Node *flatten(Node *root);

// int main(void)
// {

//     int t;
//     cin >> t;
//     while (t--)
//     {
//         int n, m, flag = 1, flag1 = 1;
//         struct Node *temp = NULL;
//         struct Node *head = NULL;
//         struct Node *pre = NULL;
//         struct Node *tempB = NULL;
//         struct Node *preB = NULL;
//         cin >> n;
//         int work[n];
//         for (int i = 0; i < n; i++)
//             cin >> work[i];
//         for (int i = 0; i < n; i++)
//         {
//             m = work[i];
//             --m;
//             int data;
//             scanf("%d", &data);
//             temp = new Node(data);
//             temp->next = NULL;
//             temp->bottom = NULL;

//             if (flag)
//             {
//                 head = temp;
//                 pre = temp;
//                 flag = 0;
//                 flag1 = 1;
//             }
//             else
//             {
//                 pre->next = temp;
//                 pre = temp;
//                 flag1 = 1;
//             }
//             for (int j = 0; j < m; j++)
//             {

//                 int temp_data;
//                 scanf("%d", &temp_data);
//                 tempB = new Node(temp_data);

//                 if (flag1)
//                 {
//                     temp->bottom = tempB;
//                     preB = tempB;
//                     flag1 = 0;
//                 }
//                 else
//                 {
//                     preB->bottom = tempB;
//                     preB = tempB;
//                 }
//             }
//         }
//         Node *fun = head;
//         Node *fun2 = head;

//         Node *root = flatten(head);
//         printList(root);
//         cout << endl;
//     }
//     return 0;
// }

// // } Driver Code Ends

// /* Node structure  used in the program

// struct Node{
//     int data;
//     struct Node * next;
//     struct Node * bottom;

//     Node(int x){
//         data = x;
//         next = NULL;
//         bottom = NULL;
//     }

// };
// */

// /*  Function which returns the  root of
//     the flattened linked list. */

// Node *mergeTwoLinkedLists(Node *a, Node *b)
// {
//     Node *temp = new Node(0);
//     Node *head = temp;

//     while (a != NULL and b != NULL)
//     {
//         if (a->data < b->data)
//         {
//             temp->bottom = a;
//             temp = temp->bottom;
//             a = a->bottom;
//         }
//         else
//         {
//             temp->bottom = b;
//             temp = temp->bottom;
//             b = b->bottom;
//         }
//     }

//     if (a != NULL)
//     {
//         temp->bottom = a;
//     }
//     else
//     {
//         temp->bottom = b;
//     }

//     return head->bottom;
// }

// Node *flatten(Node *root)
// {
//     if (root == NULL or root->next == NULL)
//     {
//         return root;
//     }

//     root->next = flatten(root->next);

//     root = mergeTwoLinkedLists(root, root->next);

//     return root;
// }

// ///////***********extraa space********************

// // Node *flatten(Node *root)
// // {
// //     Node *temp1 = root;
// //     vector<int> v;
// //     while (temp1 != NULL)
// //     {
// //         Node *t = temp1;
// //         while (t != NULL)
// //         {
// //             v.push_back(t->data);
// //             t = t->bottom;
// //         }
// //         temp1 = temp1->next;
// //     }

// //     sort(v.begin(), v.end());

// //     Node *head = new Node(*v.begin());
// //     Node *temp2 = head;
// //     for (int i = 1; i < v.size(); i++)
// //     {
// //         Node *t = new Node(v[i]);
// //         temp2->bottom = t;
// //         temp2 = temp2->bottom;
// //     }

// //     return head;
// // }

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
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
void printList(Node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->next;
    }
    cout << "\n";
}

// } Driver Code Ends
// User function template for C++

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
class Solution
{
public:
    Node *divide(int N, Node *head)
    {
        // vector<int>v1,v2;
        // Node* temp=head;
        // while(temp!=NULL){
        //     if(temp->data&1)
        //       v2.push_back(temp->data);
        //     else
        //         v1.push_back(temp->data);
        //     temp=temp->next;
        // }
        // Node* start=new Node(-1);
        // temp=start;

        // for(int i=0;i<v1.size();i++){
        //     Node* t=new Node(v1[i]);
        //     temp->next=t;
        //     temp=temp->next;
        // }
        // for(int i=0;i<v2.size();i++){
        //     Node* t=new Node(v2[i]);
        //     temp->next=t;
        //     temp=temp->next;
        // }
        // return start->next;
        Node *e_start = NULL, *o_start = NULL, *root1 = NULL, *root2;

        Node *temp = head;
        bool flag_e = true, flag_o = true;
        while (temp != NULL)
        {
            if (flag_e and !(temp->data & 1))
            {
                e_start = temp;
                root1 = temp;
                flag_e = false;
                temp = temp->next;
                e_start = e_start->next;
                continue;
            }
            if (flag_o and (temp->data & 1))
            {
                o_start = temp;
                flag_o = false;
                root2 = temp;
                temp = temp->next;
                o_start = o_start->next;
                continue;
            }

            // if (!(temp->data & 1))
            // {
            //     e_start->next = temp;
            //     e_start = e_start->next;
            // }
            // else
            // {
            //     o_start->next = temp;
            //     o_start = o_start->next;
            // }

            // temp = temp->next;
        }

        e_start->next = root2;
        return root1;
    }
};

//{ Driver Code Starts.

int main()
{
    // code
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        int data;
        cin >> data;
        struct Node *head = new Node(data);
        struct Node *tail = head;
        for (int i = 0; i < N - 1; ++i)
        {
            cin >> data;
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