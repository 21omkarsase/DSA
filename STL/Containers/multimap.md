Basic Information:
    multimap is an associative container that stores a collection of key-value pairs.
    It allows multiple elements with the same key.
    The elements are sorted by key in ascending order.
    It is implemented as a balanced binary search tree (usually a red-black tree).

Memory Allocation:
    Memory for the elements in a multimap is dynamically allocated by the container.
    The memory is typically managed using a combination of node-based allocation and deallocation techniques.

Implementation Details:
    multimap is typically implemented as a balanced binary search tree, such as a red-black tree.
    The balanced tree structure ensures efficient insertion, deletion, and lookup operations with a time complexity of O(log n), where n is the number of elements in the multimap.
    The keys are used to maintain the order of the elements, and the values are associated with the keys.

Background:
    multimap is part of the C++ STL and has been available since the early versions of the C++ standard.
    It is designed to provide an efficient way to store and retrieve key-value pairs where duplicate keys are allowed.
    The implementation of multimap is based on well-known data structures and algorithms used in computer science, such as balanced binary search trees.

Functions:
    Element Access:

        No direct equivalent of operator[] exists for multimap. The elements can be accessed through iterators.

        at(): Accesses the element at the specified key with bounds checking.
            Syntax: multimap_name.at(key)
            Time Complexity: Average case O(log n), worst case O(n), where n is the number of elements with the specified key.
            Space Complexity: O(1)

    Capacity:

        empty(): Checks if the multimap is empty.
            Syntax: multimap_name.empty()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        size(): Returns the number of elements in the multimap.
            Syntax: multimap_name.size()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

    Modifiers:

        insert(): Inserts elements or key-value pairs into the multimap.
            Syntax: multimap_name.insert(pair(key, value)) or multimap_name.insert(iterator_hint, pair(key, value))
            Time Complexity: Average case O(log n), worst case O(n + m), where n is the number of elements in the multimap and m is the number of elements inserted.
            Space Complexity: O(m), where m is the number of elements inserted.

        erase(): Removes elements from the multimap with the specified key or within a range.
            Syntax: multimap_name.erase(key) or multimap_name.erase(iterator_position) or multimap_name.erase(iterator_start, iterator_end)
            Time Complexity: Average case O(log n + k), worst case O(n), where n is the number of elements in the multimap and k is the number of elements erased.
            Space Complexity: O(1)

        clear(): Removes all elements from the multimap.
            Syntax: multimap_name.clear()
            Time Complexity: Linear time O(n), where n is the number of elements in the multimap
            Space Complexity: O(1)

        swap(): Swaps the contents of two multimap containers.
            Syntax: multimap_name.swap(other_multimap)
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

    Lookup:

        find(): Searches the multimap for an element with a specified key.
            Syntax: multimap_name.find(key)
            Time Complexity: Average case O(log n), worst case O(n), where n is the number of elements with the specified key.
            Space Complexity: O(1)

        count(): Returns the number of elements with a specified key in the multimap.
            Syntax: multimap_name.count(key)
            Time Complexity: Average case O(log n), worst case O(n), where n is the number of elements with the specified key.
            Space Complexity: O(1)

        lower_bound(): Returns an iterator pointing to the first element that is not less than a specified key.
            Syntax: multimap_name.lower_bound(key)
            Time Complexity: Average case O(log n), worst case O(n), where n is the number of elements with the specified key.
            Space Complexity: O(1)

        upper_bound(): Returns an iterator pointing to the first element that is greater than a specified key.
            Syntax: multimap_name.upper_bound(key)
            Time Complexity: Average case O(log n), worst case O(n), where n is the number of elements with the specified key.
            Space Complexity: O(1)

When to Use:
    Use a multimap when you need to store a collection of key-value pairs with duplicate keys.
    It is useful when you want to efficiently associate multiple values with the same key.
    If the order of the keys is important and efficient lookup, insertion, and deletion operations are required, multimap can be a suitable choice.

Pros of multimap:
    Allows multiple elements with the same key.
    Automatically maintains the sorted order of elements based on the keys.
    Provides efficient lookup, insertion, and deletion operations with a time complexity of O(log n).
    Well-suited for scenarios where duplicate keys are common.

Cons of multimap:
    The balanced binary search tree used for implementation requires extra memory compared to simpler data structures like vector or list.
    Iterating through the elements of a multimap in sorted order can be slower compared to linear data structures like vector or list.
    Requires a strict weak ordering on the keys for proper functioning.