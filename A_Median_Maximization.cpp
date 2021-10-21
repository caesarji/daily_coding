#include <bits/stdc++.h>
using namespace std;

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        long long n, s;
        cin >> n >> s;
        long long x = n / 2 + 1;
        cout << s / x << endl;
    }
}

// n / 2 + 1
