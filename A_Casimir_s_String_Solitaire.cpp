#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i, n) for (ll i = 0; i < n; i++)
#define loop1(i, k, n) for (ll i = k; i < n; i++)
#define pb push_back
#define debug cout << (__LINE__)
typedef long long int ll;
void solve()
{
    string s;
    cin >> s;
    int ca = 0, cb = 0, c = 0;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == 'A')
            ca++;
        else if (s[i] == 'B')
            cb++;
        else
            c++;
    }
    if (c + ca == cb)
        cout << "YES\n";
    else
        cout << "NO\n";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t;
    cin >> t;
    // while(t--){
    // solve();
    // }
    for (ll i = 1; i <= t; i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}