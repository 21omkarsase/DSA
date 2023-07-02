Basic Information:
        Vectors in C++ are a dynamic array-like data structure provided by the Standard Template Library (STL). They allow for efficient insertion, deletion, and access to elements. Vectors are implemented as a template class and provide a flexible and convenient way to work with collections of elements.

Memory Allocation:
        Vectors internally manage the memory required to store their elements. When you add elements to a vector, it dynamically allocates memory to accommodate the new elements. If the vector reaches its capacity, it will automatically allocate additional memory to ensure space for new elements. Memory deallocation also occurs automatically when elements are removed from the vector.

Implementation:
        Vectors are typically implemented as a dynamically allocated array. The vector class maintains a pointer to the dynamically allocated array, along with other member variables like the current number of elements and the capacity of the vector. The underlying array is resized as needed to accommodate the number of elements.

Background:
        Vectors are part of the Standard Template Library (STL) in C++, which is a powerful library providing generic algorithms and data structures. Vectors offer several advantages over traditional arrays, such as automatic memory management, dynamic resizing, and convenience functions for manipulating the elements.

Built-in Functions:
    Element Access:

    operator[]:
        Accesses the element at the specified index.
        Syntax: vector_name[index]
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)
    
    at():
        Accesses the element at the specified index with bounds checking.
        Syntax: vector_name.at(index)
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)
    
    front():
        Accesses the first element of the vector.
        Syntax: vector_name.front()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)
    
    back():
        Accesses the last element of the vector.
        Syntax: vector_name.back()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)
    
    data():
        Returns a pointer to the underlying array serving as element storage.
        Syntax: vector_name.data()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)


    Capacity:

    size():
        Returns the number of elements in the vector.
        Syntax: vector_name.size()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)
    
    empty():
        Checks if the vector is empty.
        Syntax: vector_name.empty()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)
    
    capacity():
        Returns the number of elements that the vector can hold without reallocation.
        Syntax: vector_name.capacity()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)
    
    reserve():
        Requests that the vector capacity be at least enough to contain a specified number of elements.
        Syntax: vector_name.reserve(new_capacity)
        Time Complexity: Linear time O(n), where n is the new capacity
        Space Complexity: O(n)


    Modifiers:

    push_back():
        Adds an element at the end of the vector.
        Syntax: vector_name.push_back(value)
        Time Complexity: Amortized constant time O(1)
        Space Complexity: O(1)
    
    pop_back():
        Removes the last element from the vector.
        Syntax: vector_name.pop_back()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)
    
    insert():
        Inserts elements at a specified position.
        Syntax: vector_name.insert(iterator_position, value(s))
        Time Complexity: Linear time O(n + m), where n is the number of elements inserted and m is the number of elements shifted
        Space Complexity: O(n)
    
    erase():
        Removes elements at a specified position or range.
        Syntax: vector_name.erase(iterator_position) or vector_name.erase(iterator_start, iterator_end)
        Time Complexity: Linear time O(n), where n is the number of elements erased
        Space Complexity: O(1)
    
    clear():
        Removes all elements from the vector.
        Syntax: vector_name.clear()
        Time Complexity: Linear time O(n)
        Space Complexity: O(1)
    
    resize():
        Changes the size of the vector.
        Syntax: vector_name.resize(new_size) or vector_name.resize(new_size, value)
        Time Complexity: Linear time O(n), where n is the new size
        Space Complexity: O(1)
    
    swap():
        Swaps the contents of two vectors.
        Syntax: vector_name.swap(other_vector)
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)
    
    
        Modifiers:

    assign():
        Replaces the contents of the vector with copies of a given value or a range.
        Syntax: vector_name.assign(count, value) or vector_name.assign(iterator_start, iterator_end)
        Time Complexity: Linear time O(n), where n is the number of elements assigned
        Space Complexity: O(n)
    
    emplace():
        Constructs and inserts an element at a specified position.
        Syntax: vector_name.emplace(iterator_position, args...)
        Time Complexity: Linear time O(n), where n is the number of elements shifted
        Space Complexity: O(1)
    
    emplace_back():
        Constructs and inserts an element at the end of the vector.
        Syntax: vector_name.emplace_back(args...)
        Time Complexity: Amortized constant time O(1)
        Space Complexity: O(1)
    
    resize():
        Changes the size of the vector.
        Syntax: vector_name.resize(new_size) or vector_name.resize(new_size, value)
        Time Complexity: Linear time O(n), where n is the new size
        Space Complexity: O(1)
    
    swap():
        Swaps the contents of two vectors.
        Syntax: vector_name.swap(other_vector)
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)


    Non-modifying Sequence Operations:

    count():
        Counts the occurrences of a given value in the vector.
        Syntax: std::count(vector_name.begin(), vector_name.end(), value)
        Time Complexity: Linear time O(n), where n is the number of elements in the vector
        Space Complexity: O(1)
    
    find():
        Searches for the first occurrence of a given value in the vector.
        Syntax: std::find(vector_name.begin(), vector_name.end(), value)
        Time Complexity: Linear time O(n), where n is the number of elements in the vector
        Space Complexity: O(1)
    
        Binary Search:

    binary_search():
        Checks if a given value exists in the sorted vector.
        Syntax: std::binary_search(vector_name.begin(), vector_name.end(), value)
        Time Complexity: Logarithmic time O(log n), where n is the number of elements in the vector
        Space Complexity: O(1)
    
    lower_bound():
        Returns an iterator pointing to the first element that is not less than a given value.
        Syntax: std::lower_bound(vector_name.begin(), vector_name.end(), value)
        Time Complexity: Logarithmic time O(log n), where n is the number of elements in the vector
        Space Complexity: O(1)
    
    upper_bound():
        Returns an iterator pointing to the first element that is greater than a given value.
        Syntax: std::upper_bound(vector_name.begin(), vector_name.end(), value)
        Time Complexity: Logarithmic time O(log n), where n is the number of elements in the vector
        Space Complexity: O(
            1)

    Comparison:

    equal():
        Checks if two vectors are equal, element-wise.
        Syntax: std::equal(vector_name1.begin(), vector_name1.end(), vector_name2.begin())
        Time Complexity: Linear time O(n), where n is the number of elements in the vector
        Space Complexity: O(1)
    
    lexicographical_compare():
        Compares two vectors lexicographically.
        Syntax: std::lexicographical_compare(vector_name1.begin(), vector_name1.end(), vector_name2.begin(), vector_name2.end())
        Time Complexity: Linear time O(n), where n is the number of elements in the vector
        Space Complexity: O(
            1)

    Iterator Operations:

    begin():
        Returns an iterator pointing to the first element of the vector.
        Syntax: vector_name.begin()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)
    end
    ():
        Returns an iterator pointing one past the last element of the vector.
        Syntax: vector_name.end()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

        
When to Use Vectors:
    Use vectors when you need a dynamic array-like structure that can grow or shrink in size. They are particularly useful when the number of elements is not known in advance or when it may change during runtime. Vectors offer efficient random access to elements and provide a wide range of functions for manipulating and working with collections of data.

Pros of Vectors:

    Dynamic Size: Vectors can dynamically resize, allowing for easy addition or removal of elements.
    Efficient Random Access: Vectors provide constant time access to elements using indexing.
    Automatic Memory Management: Vectors handle memory allocation and deallocation automatically.
    Wide Range of Functions: The vector class provides various built-in functions for common operations.

Cons of Vectors:

    Insertions and Deletions: Insertions and deletions in the middle of a vector can be relatively expensive due to the need for shifting elements.
    Memory Overhead: Vectors may consume more memory than traditional arrays due to their internal management and potential overallocation.
    
