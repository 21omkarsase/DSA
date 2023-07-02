Basic Information:

    deque, short for "double-ended queue," is a container in C++ Standard Library that provides a sequence of elements with dynamic size. It allows efficient insertion and deletion of elements at both the beginning and the end of the sequence. deque is implemented as a sequence container that supports random access.

Memory Allocation:

    Memory for a deque is dynamically allocated. It typically allocates memory in chunks or blocks, which allows efficient resizing and insertion/deletion at both ends. The specific memory allocation strategy may vary between different implementations of the C++ Standard Library.

Implementation:

    deque is usually implemented as a dynamic array of fixed-size blocks or chunks. Each block is a separate segment of memory that stores a fixed number of elements. The deque container maintains pointers to the beginning and end of the sequence and dynamically allocates new blocks as needed when elements are added or removed. This implementation allows constant-time insertion and deletion at both ends, as well as efficient random access to elements within each block.

Background:

    The deque container was introduced in the C++ Standard Library as an extension to the vector container. It provides similar functionality as vector but with the additional ability to efficiently insert and delete elements at the front. The name "deque" reflects its double-ended nature, allowing operations on both ends of the sequence.

Functions:
    Element Access:

        operator[]: Accesses the element at the specified index.
            Syntax: deque_name[index]
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        at(): Accesses the element at the specified index with bounds checking.
            Syntax: deque_name.at(index)
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        front(): Accesses the first element of the deque.
            Syntax: deque_name.front()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        back(): Accesses the last element of the deque.
            Syntax: deque_name.back()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        data(): Returns a pointer to the underlying array serving as element storage.
            Syntax: deque_name.data()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

    Capacity:

        size(): Returns the number of elements in the deque.
            Syntax: deque_name.size()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        empty(): Checks if the deque is empty.
            Syntax: deque_name.empty()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        capacity(): Returns the number of elements that the deque can hold without reallocation.
            Syntax: deque_name.capacity()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        reserve(): Requests that the deque capacity be at least enough to contain a specified number of elements.
            Syntax: deque_name.reserve(new_capacity)
            Time Complexity: Linear time O(n), where n is the new capacity
            Space Complexity: O(n)

    Modifiers:

        push_back(): Adds an element at the end of the deque.
            Syntax: deque_name.push_back(value)
            Time Complexity: Amortized constant time O(1)
            Space Complexity: O(1)

        pop_back(): Removes the last element from the deque.
            Syntax: deque_name.pop_back()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        push_front(): Adds an element at the beginning of the deque.
            Syntax: deque_name.push_front(value)
            Time Complexity: Amortized constant time O(1)
            Space Complexity: O(1)

        pop_front(): Removes the first element from the deque.
            Syntax: deque_name.pop_front()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        insert(): Inserts elements at a specified position.
            Syntax: deque_name.insert(iterator_position, value(s))
            Time Complexity: Linear time O(n + m), where n is the number of elements inserted and m is the number of elements shifted
            Space Complexity: O(n)

        erase(): Removes elements at a specified position or range.
            Syntax: deque_name.erase(iterator_position) or deque_name.erase(iterator_start, iterator_end)
            Time Complexity: Linear time O(n), where n is the number of elements erased
            Space Complexity: O(1)

        clear(): Removes all elements from the deque.
            Syntax: deque_name.clear()
            Time Complexity: Linear time O(n)
            Space Complexity: O(1)

        resize(): Changes the size of the deque.
            Syntax: deque_name.resize(new_size) or deque_name.resize(new_size, value)
            Time Complexity: Linear time O(n), where n is the new size
            Space Complexity: O(1)

        swap(): Swaps the contents of two deques.
            Syntax: deque_name.swap(other_deque)
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        assign(): Replaces the contents of the deque with copies of a given value or a range.
            Syntax: deque_name.assign(count, value) or deque_name.assign(iterator_start, iterator_end)
            Time Complexity: Linear time O(n), where n is the number of elements assigned
            Space Complexity: O(n)

        emplace(): Constructs and inserts an element at a specified position.
            Syntax: deque_name.emplace(iterator_position, args...)
            Time Complexity: Linear time O(n), where n is the number of elements shifted
            Space Complexity: O(1)

        emplace_back(): Constructs and inserts an element at the end of the deque.
            Syntax: deque_name.emplace_back(args...)
            Time Complexity: Amortized constant time O(1)
            Space Complexity: O(1)

        resize(): Changes the size of the deque.
            Syntax: deque_name.resize(new_size) or deque_name.resize(new_size, value)
            Time Complexity: Linear time O(n), where n is the new size
            Space Complexity: O(1)

        swap(): Swaps the contents of two deques.
            Syntax: deque_name.swap(other_deque)
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

    Non-modifying Sequence Operations:

        count(): Counts the occurrences of a given value in the deque.
            Syntax: std::count(deque_name.begin(), deque_name.end(), value)
            Time Complexity: Linear time O(n), where n is the number of elements in the deque
            Space Complexity: O(1)

        find(): Searches for the first occurrence of a given value in the deque.
            Syntax: std::find(deque_name.begin(), deque_name.end(), value)
            Time Complexity: Linear time O(n), where n is the number of elements in the deque
            Space Complexity: O(1)

    Binary Search:

        binary_search(): Checks if a given value exists in the sorted deque.
            Syntax: std::binary_search(deque_name.begin(), deque_name.end(), value)
            Time Complexity: Logarithmic time O(log n), where n is the number of elements in the deque
            Space Complexity: O(1)

        lower_bound(): Returns an iterator pointing to the first element that is not less than a given value.
            Syntax: std::lower_bound(deque_name.begin(), deque_name.end(), value)
            Time Complexity: Logarithmic time O(log n), where n is the number of elements in the deque
            Space Complexity: O(1)

        upper_bound(): Returns an iterator pointing to the first element that is greater than a given value.
            Syntax: std::upper_bound(deque_name.begin(), deque_name.end(), value)
            Time Complexity: Logarithmic time O(log n), where n is the number of elements in the deque
            Space Complexity: O(1)

    Comparison:

        equal(): Checks if two deques are equal, element-wise.
            Syntax: std::equal(deque_name1.begin(), deque_name1.end(), deque_name2.begin())
            Time Complexity: Linear time O(n), where n is the number of elements in the deque
            Space Complexity: O(1)

        lexicographical_compare(): Compares two deques lexicographically.
            Syntax: std::lexicographical_compare(deque_name1.begin(), deque_name1.end(), deque_name2.begin(), deque_name2.end())
            Time Complexity: Linear time O(n), where n is the number of elements in the deque
            Space Complexity: O(1)

    Iterator Operations:

        begin(): Returns an iterator pointing to the first element of the deque.
            Syntax: deque_name.begin()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        end(): Returns an iterator pointing one past the last element of the deque.
            Syntax: deque_name.end()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)


When to Use deque:

    When you need a container that supports efficient insertion and deletion of elements at both the front and the back.
    When you require random access to elements within the container.
    When the number of elements in the container may change frequently and dynamically.
    When you want to avoid the overhead of resizing a vector when inserting or deleting elements at the front.

Pros of deque:

    Efficient insertion and deletion of elements at both the front and the back (constant time complexity).
    Random access to elements within the container (constant time complexity).
    Dynamic size and automatic memory management.
    No reallocation and copying of elements when inserting or deleting at the front or back.

Cons of deque:

    Slightly higher memory overhead compared to vector due to the block-based memory allocation.
    Slower element access compared to vector due to non-contiguous memory layout.
    Relative complexity in implementation compared to simpler containers like vector or list.