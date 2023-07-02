Basic Information:

    Unordered map is a container in C++ STL that stores elements in key-value pairs.
    It provides fast access to elements based on their keys.
    The elements in an unordered map are not sorted.
    The keys in an unordered map are unique.
    Unordered maps are implemented using hash tables.

Memory Allocation:

    Unordered maps dynamically allocate memory to store the key-value pairs.
    The memory allocation is typically handled by the container itself.

Implementation:

    Unordered maps are typically implemented using hash tables.
    A hash table is an array of linked lists, where each element in the array is a linked list (bucket).
    When inserting a key-value pair, the hash function is applied to the key to determine the bucket index.
    The key-value pair is then inserted at the appropriate bucket.
    When searching for a key, the hash function is applied again to find the corresponding bucket.
    The linked list in that bucket is traversed to find the key-value pair.

Background:

    Unordered maps were introduced in the C++11 standard as part of the C++ Standard Library (STL).
    They provide efficient lookup and insertion of key-value pairs.

Built-in Functions:
    Element Access:

        operator[]:
            Accesses or inserts the value associated with the specified key.
            Syntax: unordered_map_name[key]
            Time Complexity: Average case O(1), Worst case O(n) due to collisions, where n is the number of elements in the container
            Space Complexity: O(1)

        at():
            Accesses or inserts the value associated with the specified key with bounds checking.
            Syntax: unordered_map_name.at(key)
            Time Complexity: Average case O(1), Worst case O(n) due to collisions, where n is the number of elements in the container
            Space Complexity: O(1)

        find():
            Searches for an element with the specified key.
            Syntax: unordered_map_name.find(key)
            Time Complexity: Average case O(1), Worst case O(n) due to collisions, where n is the number of elements in the container
            Space Complexity: O(1)

        count():
            Returns the number of elements with the specified key.
            Syntax: unordered_map_name.count(key)
            Time Complexity: Average case O(1), Worst case O(n) due to collisions, where n is the number of elements in the container
            Space Complexity: O(1)

    Capacity:

        size():
            Returns the number of elements in the unordered map.
            Syntax: unordered_map_name.size()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        empty():
            Checks if the unordered map is empty.
            Syntax: unordered_map_name.empty()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

    Modifiers:

        insert():
            Inserts a key-value pair into the unordered map.
            Syntax: unordered_map_name.insert({key, value})
            Time Complexity: Average case O(1), Worst case O(n) due to collisions, where n is the number of elements in the container
            Space Complexity: O(1)

        erase():
            Removes an element from the unordered map based on the specified key or position.
            Syntax: unordered_map_name.erase(key) or unordered_map_name.erase(iterator_position)
            Time Complexity: Average case O(1), Worst case O(n) due to collisions, where n is the number of elements in the container
            Space Complexity: O(1)

        clear():
            Removes all elements from the unordered map.
            Syntax: unordered_map_name.clear()
            Time Complexity: Linear time O(n), where n is the number of elements in the container
            Space Complexity: O(1)

        swap():
            Swaps the contents of two unordered maps.
            Syntax: unordered_map_name.swap(other_unordered_map)
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

    Other Functions:

        bucket_count():
            Returns the number of buckets (size of the hash table) in the unordered map.
            Syntax: unordered_map_name.bucket_count()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        load_factor():
            Returns the average number of elements per bucket.
            Syntax: unordered_map_name.load_factor()
            Time Complexity: Constant time O(1)
            Space Complexity: O(1)

        rehash():
            Sets the number of buckets (size of the hash table) in the unordered map to a specified count.
            Syntax: unordered_map_name.rehash(count)
            Time Complexity: Linear time O(n), where n is the number of elements in the container
            Space Complexity: O(1)

        reserve():
            Sets the number of buckets (size of the hash table) in the unordered map to accommodate at least a specified count of elements.
            Syntax: unordered_map_name.reserve(count)
            Time Complexity: Linear time O(n), where n is the number of elements in the container
            Space Complexity: O(1)

When to Use Unordered Maps:

    Use unordered maps when fast access to elements based on their keys is required.
    When the order of elements does not matter.
    When uniqueness of keys is important.

Pros of Unordered Maps:

    Fast access to elements based on keys.
    Efficient insertion and deletion of elements.
    Uniqueness of keys ensures no duplicates.
    Hash table implementation provides good average case performance.

Cons of Unordered Maps:

    Elements are not sorted.
    Overhead of hash table implementation.
    Worst-case time complexity can be high due to collisions.
    Requires a good hash function for optimal performance.

Note: The time complexity mentioned above is based on average and worst-case scenarios. Actual performance may vary depending on the implementation and the specific usage.