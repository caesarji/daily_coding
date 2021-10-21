#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long l, r;
        cin >> l >> r;
        long long x = (r % 2 == 0) ? r / 2 : r / 2 + 1;
        if (x >= l)
            cout << x - 1 << endl;
        else
            cout << r - l << endl;
    }
    // cout << 999999999 / 2 << endl;
}

// n / 2 + 1
