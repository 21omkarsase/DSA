Non-modifying algorithms in the C++ Standard Library operate on ranges of elements without modifying them. They provide operations such as searching, counting, finding the maximum or minimum element, and checking conditions on the elements. Here are the details of each non-modifying algorithm:

    find:
        Use: Searches for a value in a range and returns an iterator to its first occurrence.
        Syntax: find(start_iterator, end_iterator, value)
        Code example:

        std::vector<int> nums = {1, 2, 3, 4, 5};
        auto it = std::find(nums.begin(), nums.end(), 3);
        if (it != nums.end()) {
            std::cout << "Value found at index: " << std::distance(nums.begin(), it) << std::endl;
        } else {
            std::cout << "Value not found" << std::endl;
        }

        Time Complexity: Linear time O(n), where n is the size of the range.

    find_if:

        Use: Searches for an element in a range that satisfies a given condition and returns an iterator to its first occurrence.
        Syntax: find_if(start_iterator, end_iterator, condition)
        Code example:

        std::vector<int> nums = {1, 2, 3, 4, 5};
        auto it = std::find_if(nums.begin(), nums.end(), [](int num) { return num % 2 == 0; });
        if (it != nums.end()) {
            std::cout << "First even number found at index: " << std::distance(nums.begin(), it) << std::endl;
        } else {
            std::cout << "No even number found" << std::endl;
        }

        Time Complexity: Linear time O(n), where n is the size of the range.

    find_if_not:

        Use: Searches for an element in a range that does not satisfy a given condition and returns an iterator to its first occurrence.
        Syntax: find_if_not(start_iterator, end_iterator, condition)
        Code example:

        std::vector<int> nums = {1, 2, 3, 4, 5};
        auto it = std::find_if_not(nums.begin(), nums.end(), [](int num) { return num % 2 == 0; });
        if (it != nums.end()) {
            std::cout << "First odd number found at index: " << std::distance(nums.begin(), it) << std::endl;
        } else {
            std::cout << "No odd number found" << std::endl;
        }

        Time Complexity: Linear time O(n), where n is the size of the range.

    count:

        Use: Counts the occurrences of a value in a range.
        Syntax: count(start_iterator, end_iterator, value)
        Code example:

        std::vector<int> nums = {1, 2, 2, 3, 2, 4, 5};
        int occurrence = std::count(nums.begin(), nums.end(), 2);
        std::cout << "Value 2 occurs " << occurrence << " times" << std::endl;

        Time Complexity: Linear time O(n), where n is the size of the range.

    count_if:

        Use: Counts the occurrences of elements in a range that satisfy a given condition.
        Syntax: count_if(start_iterator, end_iterator, condition)
        Code example:

        std::vector<int> nums = {1, 2, 3, 4, 5};
        int evenCount = std::count_if(nums.begin(), nums.end(), [](int num) { return num % 2 == 0; });
        std::cout << "Number of even numbers: " << evenCount << std::endl;

        Time Complexity: Linear time O(n), where n is the size of the range.

    all_of:

        Use: Checks if all elements in a range satisfy a given condition.
        Syntax: all_of(start_iterator, end_iterator, condition)
        Code example:

        std::vector<int> nums = {2, 4, 6, 8, 10};
        bool allEven = std::all_of(nums.begin(), nums.end(), [](int num) { return num % 2 == 0; });
        if (allEven) {
            std::cout << "All numbers are even" << std::endl;
        } else {
            std::cout << "Not all numbers are even" << std::endl;
        }

        Time Complexity: Linear time O(n), where n is the size of the range.

    any_of:

        Use: Checks if any element in a range satisfies a given condition.
        Syntax: any_of(start_iterator, end_iterator, condition)
        Code example:

        std::vector<int> nums = {1, 2, 3, 4, 5};
        bool hasEven = std::any_of(nums.begin(), nums.end(), [](int num) { return num % 2 == 0; });
        if (hasEven) {
            std::cout << "At least one even number exists" << std::endl;
        } else {
            std::cout << "No even numbers found" << std::endl;
        }

        Time Complexity: Linear time O(n), where n is the size of the range.

    none_of:

        Use: Checks if none of the elements in a range satisfy a given condition.
        Syntax: none_of(start_iterator, end_iterator, condition)
        Code example:

        std::vector<int> nums = {1, 3, 5, 7, 9};
        bool noneEven = std::none_of(nums.begin(), nums.end(), [](int num) { return num % 2 == 0; });
        if (noneEven) {
            std::cout << "None of the numbers are even" << std::endl;
        } else {
            std::cout << "At least one even number found" << std::endl;
        }

        Time Complexity: Linear time O(n), where n is the size of the range.

    equal:

        Use: Checks if two ranges are equal element-wise.
        Syntax: equal(range1_start, range1_end, range2_start)
        Code example:

        std::vector<int> nums1 = {1, 2, 3, 4, 5};
        std::vector<int> nums2 = {1, 2, 3, 4, 5};
        bool equalRanges = std::equal(nums1.begin(), nums1.end(), nums2.begin());
        if (equalRanges) {
            std::cout << "The ranges are equal" << std::endl;
        } else {
            std::cout << "The ranges are not equal" << std::endl;
        }

        Time Complexity: Linear time O(n), where n is the size of the range.

    equal:

        Use: Checks if two ranges are equal element-wise using a binary predicate.
        Syntax: equal(range1_start, range1_end, range2_start, binary_predicate)
        Code example:

        std::vector<int> nums1 = {1, 2, 3, 4, 5};
        std::vector<int> nums2 = {1, 4, 9, 16, 25};
        bool squareEqual = std::equal(nums1.begin(), nums1.end(), nums2.begin(), [](int num1, int num2) {
            return num1 * num1 == num2;
        });
        if (squareEqual) {
            std::cout << "The squares of the ranges are equal" << std::endl;
        } else {
            std::cout << "The squares of the ranges are not equal" << std::endl;
        }

        Time Complexity: Linear time O(n), where n is the size of the range.

    mismatch:

        Use: Finds the first position where two ranges differ element-wise.
        Syntax: mismatch(range1_start, range1_end, range2_start)
        Code example:

        std::vector<int> nums1 = {1, 2, 3, 4, 5};
        std::vector<int> nums2 = {1, 2, 6, 4, 5};
        auto mismatchPair = std::mismatch(nums1.begin(), nums1.end(), nums2.begin());
        if (mismatchPair.first != nums1.end()) {
            std::cout << "Mismatch found at index: " << std::distance(nums1.begin(), mismatchPair.first) << std::endl;
        } else {
            std::cout << "The ranges are equal" << std::endl;
        }

        Time Complexity: Linear time O(n), where n is the size of the range.

    mismatch:

        Use: Finds the first position where two ranges differ element-wise using a binary predicate.
        Syntax: mismatch(range1_start, range1_end, range2_start, binary_predicate)
        Code example:

        std::vector<int> nums1 = {1, 2, 3, 4, 5};
        std::vector<int> nums2 = {1, 4, 9, 16, 25};
        auto squareMismatchPair = std::mismatch(nums1.begin(), nums1.end(), nums2.begin(), [](int num1, int num2) {
            return num1 * num1 == num2;
        });
        if (squareMismatchPair.first != nums1.end()) {
            std::cout << "Mismatch found at index: " << std::distance(nums1.begin(), squareMismatchPair.first) << std::endl;
        } else {
            std::cout << "The squares of the ranges are equal" << std::endl;
        }

        Time Complexity: Linear time O(n), where n is the size of the range.

    max_element:

        Use: Finds the iterator to the maximum element in a range.
        Syntax: max_element(start_iterator, end_iterator)
        Code example:

        std::vector<int> nums = {4, 2, 9, 1, 7};
        auto maxIt = std::max_element(nums.begin(), nums.end());
        std::cout << "Max element: " << *maxIt << std::endl;

        Time Complexity: Linear time O(n), where n is the size of the range.

    min_element:

        Use: Finds the iterator to the minimum element in a range.
        Syntax: min_element(start_iterator, end_iterator)
        Code example:

        std::vector<int> nums = {4, 2, 9, 1, 7};
        auto minIt = std::min_element(nums.begin(), nums.end());
        std::cout << "Min element: " << *minIt << std::endl;

        Time Complexity: Linear time O(n), where n is the size of the range.

    minmax_element:

        Use: Finds the iterators to the minimum and maximum elements in a range.
        Syntax: minmax_element(start_iterator, end_iterator)
        Code example:

        std::vector<int> nums = {4, 2, 9, 1, 7};
        auto minmaxPair = std::minmax_element(nums.begin(), nums.end());
        std::cout << "Min element: " << *minmaxPair.first << std::endl;
        std::cout << "Max element: " << *minmaxPair.second << std::endl;

        Time Complexity: Linear time O(n), where n is the size of the range.

    lexicographical_compare:

        Use: Checks if one range is lexicographically less than another range.
        Syntax: lexicographical_compare(range1_start, range1_end, range2_start, range2_end)
        Code example:

    std::vector<int> nums1 = {1, 2, 3};
    std::vector<int> nums2 = {1, 2, 4};
    bool less = std::lexicographical_compare(nums1.begin(), nums1.end(), nums2.begin(), nums2.end());
    if (less) {
        std::cout << "Range 1 is lexicographically less than Range 2" << std::endl;
    } else {
        std::cout << "Range 1 is lexicographically greater than or equal to Range 2" << std::endl;
    }

    Time Complexity: Linear time O(n), where n is the size of the smaller range.