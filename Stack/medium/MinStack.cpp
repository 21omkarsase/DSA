// 155. Min Stack
// Medium
// 12K
// 745
// Companies

// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.

// Implement the MinStack class:

//     MinStack() initializes the stack object.
//     void push(int val) pushes the element val onto the stack.
//     void pop() removes the element on the top of the stack.
//     int top() gets the top element of the stack.
//     int getMin() retrieves the minimum element in the stack.

// You must implement a solution with O(1) time complexity for each function.

 

// Example 1:

// Input
// ["MinStack","push","push","push","getMin","pop","top","getMin"]
// [[],[-2],[0],[-3],[],[],[],[]]

// Output
// [null,null,null,null,-3,null,0,-2]

// Explanation
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin(); // return -3
// minStack.pop();
// minStack.top();    // return 0
// minStack.getMin(); // return -2

 

// Constraints:

//     -231 <= val <= 231 - 1
//     Methods pop, top and getMin operations will always be called on non-empty stacks.
//     At most 3 * 104 calls will be made to push, pop, top, and getMin.

// Accepted
// 1.3M
// Submissions
// 2.5M
// Acceptance Rate
// 52.6%

//using stack and linked list(for min)

class StackMin {
public:
    int val;
    StackMin *next;
    
    StackMin(int x) {
        val = x;
        next = NULL;
    }
};

class MinStack {
    stack<int> st;
    StackMin *head;
public:
    MinStack() {
        head = NULL;
    }
    
    void push(int val) {
        StackMin *mn = new StackMin(val);

        if(!head || head->val >= val) {
            mn->next = head;
            head = mn;
        }

        st.push(val);
    }
    
    void pop() {
        if (!st.empty()) {
            int x = st.top();
            st.pop();

            if (x == head->val) {
                head = head->next;
            }
        }
    }
    
    int top() {
        if (!st.empty())
            return st.top();
        
        return -1;
    }
    
    int getMin() {
        if(head)
            return head->val;
        
        return -1;
    }
};

// only using linked list

class Stack {
public:    
    int val;
    int mn;
    Stack *next;

    Stack(int x, int currMin) {
        val = x;
        mn = min(currMin, x);
        next = NULL;
    }
};


class MinStack {
    Stack *head;
public:
    MinStack() {
        head = nullptr;
    }
    
    void push(int val) {
        if (head == nullptr) {
            head = new Stack(val, val);
        } else {
            Stack *node = new Stack(val, head->mn);
            node->next = head;
            head = node;
        }
    }
    
    void pop() {
        head = head->next;
    }
    
    int top() {
        return head->val;
    }
    
    int getMin() {
        return head->mn;
    }
};