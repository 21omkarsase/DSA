#include <iostream>
using namespace std;

void solve()
{
    int n;
    cin >> n;

    int a[n];
    bool b[n];

    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
    }

    if (n == 2)
    {
        if (b[0] == 1 and b[1] == 1)
        {
            cout << "YES" << endl;
        }
        else if (b[0] == 0 and b[1] == 0)
        {
            cout << "YES" << endl;
        }
        else if (b[0] == 1 and b[1] == 0)
        {
            cout << "NO" << endl;
        }
    }
    else
    {
        int pos = 2;
        int neg = 3;

        if (b[0] == 1)
        {
            a[0] = pos;
            a[1] = neg;
        }
        else
        {
            a[0] = pos;
            a[1] = pos;
        }

        for (int i = 1; i < n; i++)
        {
            if (b[i] == 1)
            {
                if (a[i] = pos)
                {
                    a[i + 1] = neg;
                }
                else
                {
                    a[i + 1] = pos;
                }
            }
            else if (b[i] == 0)
            {
                if (a[i] = pos)
                {
                    a[i + 1] = pos;
                }
                else
                {
                    a[i + 1] = neg;
                }
            }
        }

        if (b[n - 1] == 0)
        {
            if (a[0] == pos and a[n - 1] == pos)
            {
                cout << "YES" << endl;
                cout << 1 << endl;
            }
            else if (a[0] == neg and a[n - 1] == neg)
            {
                cout << "YES" << endl;
                cout << 2 << endl;
            }
            else
            {
                cout << "NO" << endl;
                cout << 3 << endl;
            }
        }
        else if (b[n - 1] == 1)
        {
            if (a[n - 1] == pos and a[0] == neg)
            {
                cout << "YES" << endl;
                cout << 4 << endl;
            }
            else if (a[n - 1] == neg and a[0] == pos)
            {
                cout << "YES" << endl;
                cout << 5 << endl;
            }
            else
            {
                cout << "NO" << endl;
                cout << 6 << endl;
            }
        }
    }
}

int main()
{
    // your code goes here
    // int t;
    // cin>>t;

    // while(t--){
    solve();
    // }
    return 0;
}
