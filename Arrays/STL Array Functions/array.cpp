#include <iostream>
#include <string>
#include <array>
#include <algorithm>

using namespace std;

int main()
{
    array<int, 4> a = {1, -88, 3, 40};

    cout << a.size() << endl;

    array<string, 3> s = {"omkar", "sase", string{"pce"}};
    // s.fill("omkar");

    swap(s.front(), s.back());

    for (auto &i : s)
        cout
            << i << " ";
    cout << endl;
    cout << *a.begin() << endl;

    sort(a.begin(), a.end());
    sort(s.begin(), s.end());

    a.fill(10);
    bool ba[4] = {0};
    for (auto i : ba)
        cout << i << " ";
    cout << endl;

    array<bool, 5> b;
    b.fill(1);
    for (auto i : b)
        cout << i << " ";
    cout << endl;

    array<int, 4> arr;
    arr.fill(20);

    a.swap(arr);

    for (auto i : a)
        cout << i << " ";
    cout << endl;

    cout << a.front() << " " << a.back() << endl;

    cout << a.empty() << endl;

    array<int, 10> arra;
    for (int i = 0; i < 9; i++)
        arr[i] = 30;

    cout << arra.size() << " " << arra.max_size() << " " << sizeof(arra);

    return 0;
}