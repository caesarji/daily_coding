#include <bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i, n) for (ll i = 0; i < n; i++)
#define loop1(i, k, n) for (ll i = k; i < n; i++)
#define pb push_back
#define debug cout << (_LINE_)
typedef long long int ll;
string bin(int i)
{
    string s;
    while (i > 0)
    {
        s += to_string(i % 2);
        i /= 2;
    }
    reverse(s.begin(), s.end());
    return s;
}
struct data
{
    char n, e, s, w;
};

// int dx = {1, 0, -1, 0};
// int dy = {0, +1, 0, -1};
void solve()
{
    int n, m;
    unordered_map<int, string> mp;
    for (int i = 0; i <= 15; i++)
    {
        mp[i] = bin(i);
    }
    cin >> n >> m;
    data v[n][m];
    int temp;
    string t;
    loop(i, n)
    {
        loop(j, m)
        {
            cin >> temp;
            t = mp[temp];
            v[i][j] = {t[0], t[1], t[2], t[3]};
        }
    }

    vector<vector<pair<int, int>>> adj(n, vector<pair<int, int>>(m , {0 , 0}));

    // pair<int , int> mat[n*m][4]

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

                if (i + 1 < n && v[i][j].e == '0' && v[i + 1][j].e == '0')
                {
                    adj[i][j].push_back({i + 1, j});
                    adj[i+1][j].push_back({i, j});
                }
                if (j + 1 < m && v[i][j].s == '0' && v[i ][j=1].s == '0')
                {
                    adj[i][j].push_back({i , j+1});
                    adj[i][j+1].push_back({i, j});
                }
                if (i -1 >=0 && v[i][j].w == '0' && v[i -1][j].w == '0')
                {
                    adj[i][j].push_back({i - 1, j});
                    adj[i-1][j].push_back({i, j});
                }
                if (j - 1 >=0 && v[i][j].n == '0' && v[i][j-1].n == '0')
                {
                    adj[i][j].push_back({i , j-1});
                    adj[i][j-1].push_back({i, j});
                }
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout<<i+1<<"-"<<j+1<<"--";
            for( auto c:adj[{i,j}]){
                cout<<c.first<<" "c.second<<endl;
            }

        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t = 1;
    // cin>>t;
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