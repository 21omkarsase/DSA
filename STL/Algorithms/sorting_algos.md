Sorting algorithms are essential in computer science and are used to arrange elements in a specific order. The C++ Standard Library provides various sorting algorithms that can be applied to different containers. Here are some commonly used sorting algorithms along with their uses, syntax, code examples, and time complexities:

    sort:
    
        Use: Sorts the elements in a range in ascending order.
        Syntax: sort(range_start, range_end)
        Code example:

        std::vector<int> nums = {4, 2, 1, 3, 5};
        std::sort(nums.begin(), nums.end());

        Time Complexity: O(n log n) in general, where n is the size of the range. The complexity can degrade to O(n^2) in the worst case scenario.

    stable_sort:

        Use: Sorts the elements in a range in ascending order while preserving the relative order of elements with equal values.
        Syntax: stable_sort(range_start, range_end)
        Code example:

        std::vector<int> nums = {4, 2, 1, 3, 5};
        std::stable_sort(nums.begin(), nums.end());

        Time Complexity: O(n log n) in general, where n is the size of the range. The complexity can degrade to O(n^2) in the worst case scenario.

    partial_sort:

        Use: Sorts a specified subrange within a range in ascending order, leaving the remaining elements in an unspecified order.
        Syntax: partial_sort(range_start, range_middle, range_end)
        Code example:

        std::vector<int> nums = {4, 2, 1, 3, 5};
        std::partial_sort(nums.begin(), nums.begin() + 3, nums.end());

        Time Complexity: O(n log k), where n is the size of the range and k is the size of the specified subrange.

    partial_sort_copy:

        Use: Sorts a specified subrange within a range in ascending order and copies the sorted elements to another container.
        Syntax: partial_sort_copy(range_start, range_end, destination_start, destination_end)
        Code example:

        std::vector<int> nums = {4, 2, 1, 3, 5};
        std::vector<int> sorted_nums(3);
        std::partial_sort_copy(nums.begin(), nums.end(), sorted_nums.begin(), sorted_nums.end());

        Time Complexity: O(n log k), where n is the size of the range and k is the size of the destination container.

    is_sorted:

        Use: Checks if the elements in a range are sorted in ascending order.
        Syntax: is_sorted(range_start, range_end)
        Code example:

        std::vector<int> nums = {1, 2, 3, 4, 5};
        bool sorted = std::is_sorted(nums.begin(), nums.end());

        Time Complexity: O(n), where n is the size of the range.

    is_sorted_until:

        Use: Finds the iterator to the first element in a range that is out of order or the last element if the range is sorted.
        Syntax: is_sorted_until(range_start, range_end)
        Code example:

        std::vector<int> nums = {1, 2, 4, 3, 5};
        auto it = std::is_sorted_until(nums.begin(), nums.end());

        Time Complexity: O(n), where n is the size of the range.