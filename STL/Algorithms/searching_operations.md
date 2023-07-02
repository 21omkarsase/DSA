Searching algorithms in the C++ Standard Library involve finding elements in a container or range. The C++ Standard Library provides several search algorithms that can be used for different search requirements. Here are some commonly used searching algorithms along with their uses, syntax, code examples, and time complexities:

    find:
        Use: Searches for a specific value in a range.
        Syntax: find(range_start, range_end, value)
        Code example:


        std::vector<int> vec = {1, 2, 3, 4, 5};
        auto it = std::find(vec.begin(), vec.end(), 3);
        if (it != vec.end()) {
            // Value found
            std::cout << "Value found at index: " << std::distance(vec.begin(), it) << std::endl;
        } else {
            // Value not found
            std::cout << "Value not found" << std::endl;
        }

        Time Complexity: O(N), where N is the size of the range.

    binary_search:

        Use: Checks if a specific value exists in a sorted range.
        Syntax: binary_search(range_start, range_end, value)
        Code example:

        std::vector<int> vec = {1, 2, 3, 4, 5};
        bool found = std::binary_search(vec.begin(), vec.end(), 3);
        if (found) {
            std::cout << "Value found" << std::endl;
        } else {
            std::cout << "Value not found" << std::endl;
        }

        Time Complexity: O(log N), where N is the size of the range. Note that the range must be sorted before using binary_search.

    lower_bound:

        Use: Finds the first element that is not less than a specific value in a sorted range.
        Syntax: lower_bound(range_start, range_end, value)
        Code example:

        std::vector<int> vec = {1, 2, 3, 4, 5};
        auto it = std::lower_bound(vec.begin(), vec.end(), 3);
        if (it != vec.end()) {
            std::cout << "First element not less than value found at index: " << std::distance(vec.begin(), it) << std::endl;
        } else {
            std::cout << "No element not less than value found" << std::endl;
        }

        Time Complexity: O(log N), where N is the size of the range. Note that the range must be sorted before using lower_bound.

    upper_bound:

        Use: Finds the first element that is greater than a specific value in a sorted range.
        Syntax: upper_bound(range_start, range_end, value)
        Code example:

        std::vector<int> vec = {1, 2, 3, 4, 5};
        auto it = std::upper_bound(vec.begin(), vec.end(), 3);
        if (it != vec.end()) {
            std::cout << "First element greater than value found at index: " << std::distance(vec.begin(), it) << std::endl;
        } else {
            std::cout << "No element greater than value found" << std::endl;
        }

        Time Complexity: O(log N), where N is the size of the range. Note that the range must be sorted before using upper_bound.