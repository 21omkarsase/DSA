Heap operations in the C++ Standard Library involve creating and manipulating binary heaps. A binary heap is a complete binary tree where the value of each node is greater than or equal to (in a max heap) or less than or equal to (in a min heap) the values of its children. The C++ Standard Library provides functions for creating heaps, inserting elements, removing elements, and more. Here are some commonly used heap operations along with their uses, syntax, code examples, and time complexities:

    make_heap:
        Use: Creates a binary heap from a range of elements.
        Syntax: make_heap(range_start, range_end)
        Code example:

        std::vector<int> nums = {5, 2, 8, 1, 4};
        std::make_heap(nums.begin(), nums.end());

        Time Complexity: O(n), where n is the size of the range.

    push_heap:

        Use: Inserts an element into a binary heap and maintains the heap property.
        Syntax: push_heap(range_start, range_end)
        Code example:

        std::vector<int> nums = {5, 2, 8, 1, 4};
        nums.push_back(3);
        std::push_heap(nums.begin(), nums.end());

        Time Complexity: O(log n), where n is the size of the heap.

    pop_heap:

        Use: Removes the maximum (in a max heap) or minimum (in a min heap) element from the heap and places it at the end of the range.
        Syntax: pop_heap(range_start, range_end)
        Code example:

        std::vector<int> nums = {8, 5, 4, 2, 1};
        std::pop_heap(nums.begin(), nums.end());
        nums.pop_back();  // The maximum element (8) is now at the end of the range

        Time Complexity: O(log n), where n is the size of the heap.

    sort_heap:

        Use: Converts a binary heap into a sorted range of elements.
        Syntax: sort_heap(range_start, range_end)
        Code example:

        std::vector<int> nums = {8, 5, 4, 2, 1};
        std::sort_heap(nums.begin(), nums.end());

        Time Complexity: O(n log n), where n is the size of the heap.

    is_heap:

        Use: Checks if a range is a valid binary heap.
        Syntax: is_heap(range_start, range_end)
        Code example:

        std::vector<int> nums = {8, 5, 4, 2, 1};
        bool isHeap = std::is_heap(nums.begin(), nums.end());

        Time Complexity: O(n), where n is the size of the range.