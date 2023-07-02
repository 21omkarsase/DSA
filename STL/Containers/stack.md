Basic Information:
    A stack is a linear data structure that follows the Last-In-First-Out (LIFO) principle. It is a collection of elements with two main operations: push, which adds an element to the top of the stack, and pop, which removes the topmost element from the stack. The element that is added last is the first one to be removed. Additionally, stack operations such as peek or top allow accessing the top element without modifying the stack.

Memory Allocation:
    Stacks can be implemented using arrays or linked lists. When using an array, a fixed-size array is allocated, and the elements are stored sequentially. The size of the array determines the maximum capacity of the stack. When using a linked list, each element (node) contains the data and a reference to the next node in the stack.

Implementation:
    The implementation of a stack typically involves a data structure to store the elements and a set of operations to manipulate the stack. In an array-based implementation, a pointer (top) keeps track of the topmost element. When a new element is pushed, it is inserted at the top position and the top pointer is incremented. When an element is popped, the top element is removed, and the top pointer is decremented. In a linked list-based implementation, the top pointer is replaced by the head node of the linked list.

Background:
    Stacks are a fundamental data structure in computer science and have various applications. They are commonly used for function call stack management, expression evaluation, backtracking algorithms, parsing, and more. The concept of a stack also plays a crucial role in memory management, as the runtime stack is used to store function calls and local variables.

Functions:
    Element Access:

        top():
            Accesses the top element of the stack.
            Syntax: stack_name.top()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

    Capacity:

        empty():
            Checks if the stack is empty.
            Syntax: stack_name.empty()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        size():
            Returns the number of elements in the stack.
            Syntax: stack_name.size()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

    Modifiers:

        push():
            Adds an element to the top of the stack.
            Syntax: stack_name.push(value)
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        pop():
            Removes the top element from the stack.
            Syntax: stack_name.pop()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        swap():
            Swaps the contents of two stacks.
            Syntax: stack_name.swap(other_stack)
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        emplace():
            Constructs and inserts an element at the top of the stack.
            Syntax: stack_name.emplace(args...)
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        emplace_hint() [C++11]:
            Constructs and inserts an element at a specified position in the stack.
            Syntax: stack_name.emplace_hint(iterator_position, args...)
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

    Non-modifying Sequence Operations:

        none (Stack does not provide non-modifying sequence operations.)

    Iterator Operations:

        none (Stack does not provide iterator operations.)

    Note: The stack data structure does not provide direct access to elements other than the top. It does not have functions for inserting or erasing elements from arbitrary positions.

When to Use Stacks:
Stacks are useful when you need to maintain the order of elements based on the LIFO principle. Here are some common scenarios where stacks are applicable:

    Function call management: Stacks are used by programming languages to manage function calls and their local variables.
    Expression evaluation: Stacks can be used to evaluate postfix or prefix expressions.
    Undo/Redo functionality: Stacks can be used to implement undo and redo operations in applications.
    Backtracking algorithms: Stacks can be used to keep track of the path or choices made during backtracking.

Pros and Cons:
Pros of using a stack:

    Simple and easy to understand.
    Efficient insertion and removal operations (push and pop).
    Provides access to the top element without modifying the stack (peek/top operation).
    Suitable for managing function calls and backtracking algorithms.

Cons of using a stack:

    Limited access to elements other than the top.
    Fixed size if using an array-based implementation.
    May lead to stack overflow if the stack size exceeds the available memory.
    Not suitable for searching or accessing elements in arbitrary order.