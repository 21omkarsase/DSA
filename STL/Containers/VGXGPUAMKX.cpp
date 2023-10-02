#include <bits/stdc++.h>

using namespace std;



/*
 * Complete the 'getTime' function below.
 *
 * The function is expected to return a LONG_INTEGER.
 * The function accepts STRING s as parameter.
 */

long getTime(string s) {
    long ans = 0;
    
    char curr = 'A';
    
    long n = s.size();
    
    for (int idx = 0; idx < n; idx++) {
        char ch = s[idx];
        
        long a = curr - 'A';
        long b = ch - 'A';
        
        long mn = 1e9;
        
        if (b > a) {
            mn = min(mn, b - a);
            
            long x = curr - 'A';
            long y = 'Z' - ch;
            
            mn = min(mn, x + y + 1);
        }
        else if (a > b) {
            mn = min (mn, a - b);
            
            long x = 'Z' - curr;
            long y = ch - 'A';
            
            mn = min(mn, x + y + 1);
        }
        else {
            mn = 0;
        }
        
        ans += mn;
        curr = ch;
    }
    
    return ans;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s;
    getline(cin, s);

    long result = getTime(s);

    fout << result << "\n";

    fout.close();

    return 0;
}
