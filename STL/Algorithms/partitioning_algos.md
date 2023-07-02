Partitioning algorithms in the C++ Standard Library are used to rearrange the elements in a range based on a specific condition. These algorithms partition the elements into two groups: one group that satisfies the condition and another group that does not. Here are some commonly used partitioning algorithms along with their uses, syntax, code examples, and time complexities:

    partition:
        Use: Rearranges the elements in a range such that elements that satisfy a specific condition come before the elements that do not.
        Syntax: partition(range_start, range_end, condition)
        Code example:

        std::vector<int> vec = {5, 2, 8, 1, 6, 4};
        auto partitionPoint = std::partition(vec.begin(), vec.end(), [](int n) { return n % 2 == 0; });
        // Elements before partitionPoint are even, and elements after partitionPoint are odd
        for (auto it = vec.begin(); it != partitionPoint; ++it) {
            std::cout << *it << " ";
        }
        std::cout << "| ";
        for (auto it = partitionPoint; it != vec.end(); ++it) {
            std::cout << *it << " ";
        }

        Time Complexity: O(N), where N is the size of the range.

    stable_partition:

        Use: Rearranges the elements in a range such that elements that satisfy a specific condition come before the elements that do not, while preserving the relative order of elements within each group.
        Syntax: stable_partition(range_start, range_end, condition)
        Code example:

        std::vector<int> vec = {5, 2, 8, 1, 6, 4};
        auto partitionPoint = std::stable_partition(vec.begin(), vec.end(), [](int n) { return n % 2 == 0; });
        // Elements before partitionPoint are even, and elements after partitionPoint are odd, but relative order is preserved
        for (auto it = vec.begin(); it != partitionPoint; ++it) {
            std::cout << *it << " ";
        }
        std::cout << "| ";
        for (auto it = partitionPoint; it != vec.end(); ++it) {
            std::cout << *it << " ";
        }

        Time Complexity: O(N), where N is the size of the range.