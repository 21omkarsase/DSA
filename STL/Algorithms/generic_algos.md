Generic algorithms in the C++ Standard Library are algorithms that operate on sequences of elements without any knowledge of the specific container type. They are designed to work with different types of containers and provide generic functionality. Here are some commonly used generic algorithms along with their uses, syntax, code examples, and time complexities:

    for_each:
        Use: Applies a given function to each element in a range.
        Syntax: for_each(range_start, range_end, function)
        Code example:

        std::vector<int> vec = {1, 2, 3, 4, 5};
        std::for_each(vec.begin(), vec.end(), [](int n) {
            std::cout << n << " ";
        });

        Time Complexity: O(N), where N is the size of the range.

    transform:

        Use: Applies a given function to each element in a range and stores the result in another range.
        Syntax: transform(range_start1, range_end1, range_start2, function)
        Code example:

        std::vector<int> vec1 = {1, 2, 3, 4, 5};
        std::vector<int> vec2(vec1.size());
        std::transform(vec1.begin(), vec1.end(), vec2.begin(), [](int n) {
            return n * 2;
        });
        // vec2: {2, 4, 6, 8, 10}

        Time Complexity: O(N), where N is the size of the range.

    find:

        Use: Finds the first occurrence of a value in a range.
        Syntax: find(range_start, range_end, value)
        Code example:

        std::vector<int> vec = {1, 2, 3, 4, 5};
        auto it = std::find(vec.begin(), vec.end(), 3);
        if (it != vec.end()) {
            std::cout << "Found at index: " << std::distance(vec.begin(), it) << std::endl;
        } else {
            std::cout << "Not found" << std::endl;
        }

        Time Complexity: O(N), where N is the size of the range.

    sort:

        Use: Sorts the elements in a range in ascending order.
        Syntax: sort(range_start, range_end)
        Code example:

        std::vector<int> vec = {5, 2, 8, 1, 6, 4};
        std::sort(vec.begin(), vec.end());
        // vec: {1, 2, 4, 5, 6, 8}

        Time Complexity: O(N log N), where N is the size of the range.

    count:

        Use: Counts the number of occurrences of a value in a range.
        Syntax: count(range_start, range_end, value)
        Code example:

        std::vector<int> vec = {1, 2, 3, 2, 4, 2};
        int count = std::count(vec.begin(), vec.end(), 2);
        std::cout << "Count: " << count << std::endl;

        Time Complexity: O(N), where N is the size of the range.