Basic Information:
    An unordered set is a container in C++ that stores a collection of unique elements in no particular order. It is part of the Standard Template Library (STL) and is implemented as a hash table. Unordered sets provide fast access, insertion, and deletion of elements, typically with average constant-time complexity.

Memory Allocation:
    Unordered sets dynamically allocate memory to store elements. The amount of memory allocated depends on the number of elements in the set and the implementation details of the hash table. The hash table internally manages memory to handle collisions and maintain efficient lookup operations.

Implementation:
    Unordered sets are implemented using hash tables, which are data structures that use a hash function to map keys to buckets. Each bucket stores a linked list or a balanced binary tree of elements with the same hash value. The hash function helps distribute elements evenly across the buckets, enabling efficient search, insert, and delete operations.

Background:
    Unordered sets were introduced in C++11 as part of the STL to provide a container with constant-time average complexity for insertion, deletion, and search operations. They were designed to combine the advantages of sets (unique elements) with the efficiency of hash tables.

Built-in Functions:
Capacity:

    size(): Returns the number of elements in the unordered_set.
        Syntax: unordered_set_name.size()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

    empty(): Checks if the unordered_set is empty.
        Syntax: unordered_set_name.empty()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

    max_size(): Returns the maximum number of elements the unordered_set can hold.
        Syntax: unordered_set_name.max_size()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

Modifiers:

    insert(): Inserts an element into the unordered_set.
        Syntax: unordered_set_name.insert(value)
        Time Complexity: Average case O(1), worst case O(n), where n is the size of the unordered_set
        Space Complexity: O(1)

    erase(): Removes elements from the unordered_set.
        Syntax: unordered_set_name.erase(value)
        Time Complexity: Average case O(1), worst case O(n), where n is the size of the unordered_set
        Space Complexity: O(1)

    clear(): Removes all elements from the unordered_set.
        Syntax: unordered_set_name.clear()
        Time Complexity: Linear time O(n), where n is the size of the unordered_set
        Space Complexity: O(1)

    swap(): Swaps the contents of two unordered_set containers.
        Syntax: unordered_set_name.swap(other_unordered_set)
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

Lookup:

    count(): Returns the number of elements with a specific value.
        Syntax: unordered_set_name.count(value)
        Time Complexity: Average case O(1), worst case O(n), where n is the size of the unordered_set
        Space Complexity: O(1)

    find(): Searches for an element with a specific value.
        Syntax: unordered_set_name.find(value)
        Time Complexity: Average case O(1), worst case O(n), where n is the size of the unordered_set
        Space Complexity: O(1)

Bucket Interface:

    bucket_count(): Returns the number of buckets in the unordered_set.
        Syntax: unordered_set_name.bucket_count()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

    max_bucket_count(): Returns the maximum number of buckets the unordered_set can have.
        Syntax: unordered_set_name.max_bucket_count()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

    bucket_size(): Returns the number of elements in a specific bucket.
        Syntax: unordered_set_name.bucket_size(bucket_index)
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

    bucket(): Returns the bucket number where a specific element is located.
        Syntax: unordered_set_name.bucket(value)
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

Hash Policy:

    load_factor(): Returns the current load factor of the unordered_set.
        Syntax: unordered_set_name.load_factor()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

    max_load_factor(): Returns the maximum load factor of the unordered_set.
        Syntax: unordered_set_name.max_load_factor()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

    rehash(): Sets the number of buckets to match a specified load factor.
        Syntax: unordered_set_name.rehash(bucket_count)
        Time Complexity: Average case O(n), where n is the number of elements in the unordered_set
        Space Complexity: O(n)

Iterator Operations:

    begin(): Returns an iterator pointing to the beginning of the unordered_set.
        Syntax: unordered_set_name.begin()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

    end(): Returns an iterator pointing to the end (one past the last element) of the unordered_set.
        Syntax: unordered_set_name.end()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

    cbegin(): Returns a constant iterator pointing to the beginning of the unordered_set.
        Syntax: unordered_set_name.cbegin()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

    cend(): Returns a constant iterator pointing to the end (one past the last element) of the unordered_set.
        Syntax: unordered_set_name.cend()
        Time Complexity: Constant time O(1)
        Space Complexity: O(1)

When to Use:
Unordered sets are suitable in scenarios where you need to store a collection of unique elements and require fast lookup, insertion, and deletion operations. Some use cases for unordered sets include:

    Removing duplicates: Unordered sets automatically handle duplicates by storing only unique elements.
    Fast membership check: You can quickly determine if an element is present in the set using constant-time lookup.
    Counting occurrences: Unordered sets allow you to count the number of occurrences of elements efficiently.

Pros of Unordered Sets:

    Fast insertion, deletion, and search operations on average.
    Efficient handling of large datasets due to constant-time complexity.
    Automatic handling of unique elements.
    Suitable for scenarios that require fast membership checks or counting occurrences.
    Support for various data types and user-defined objects.

Cons of Unordered Sets:

    Elements are not stored in a specific order.
    Slightly slower than ordered sets for iterating over elements.
    Extra memory overhead due to the hash table structure.
    Hash collisions may affect performance, especially with a poorly implemented hash function.
    Iterators may be invalidated after insertions or deletions, affecting ongoing iterations.