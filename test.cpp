#include <iostream>
using namespace std;

int main()
{
    // cout << (3 << 4) << endl;
    cout << (4 << 1 << 0) << " " << (4 << 0) << endl;
    cout << (4 << 1 << 1) << " " << (4 << 1) << endl;
    cout << (3 << 1 << 2) << " " << (3 << 2) << endl;
    cout << (3 << 1 << 3) << " " << (3 << 3) << endl;
    cout << (3 << 1 << 4) << " " << (3 << 4) << endl;
    cout << endl;
    cout << (3 << 2 << 1) << " " << (3 << 1) << endl;
    cout << (3 << 2 << 2) << " " << (3 << 2) << endl;
    cout << (3 << 2 << 3) << " " << (3 << 3) << endl;
    cout << (3 << 2 << 4) << " " << (3 << 4) << endl;
    // cout << (3 << 2 << 4) << endl;
    // cout << (3 << (1 << 4)) << endl;
    return 0;
}