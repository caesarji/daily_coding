#include <bits/stdc++.h>
#define ll unsigned long long int
using namespace std;

double equi(ll a, ll b, ll c, ll d)
{
    ll op = (a - b) * (a - b);
    ll opp = (c - d) * (c - d);
    return sqrt(op + opp);
}
//accepted
int main()
{
    cout.precision(6);
    ll n;
    cin >> n;
    vector<pair<ll, ll>> v;
    for (int i = 0; i < n; i++)
    {
        string k;
        cin >> k;
        ll a, b;
        cin >> a >> b;
        v.push_back({a, b});
    }

    n = v.size();
    vector<string> ans;
    ll m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        ll a, b;
        string id;
        string str;
        getline(cin, str);
        vector<string> out;
        char *token = strtok(const_cast<char *>(str.c_str()), " ");
        while (token != nullptr)
        {
            out.push_back(string(token));
            token = strtok(nullptr, " ");
        }

        if (out.size() < 3)
        {
            continue;
        }
        else
        {
            id = out[0];
            a = stoi(out[1]);
            b = stoi(out[2]);
        }

        double temp = INT_MAX * 10000.1;
        ll idx = -1;
        for (int j = 0; j < n; j++)
        {
            if (equi(a, v[j].first, b, v[j].second) < temp)
            {
                temp = equi(a, v[j].first, b, v[j].second);
                idx = j;
            }
        }
        ll op1 = v[idx].first;
        ll op2 = v[idx].second;
        double D = INT_MAX * 10000.1;
        for (int j = 0; j < n; j++)
        {
            if (j != idx and equi(op1, v[j].first, op2, v[j].second) < D)
            {
                D = equi(op1, v[j].first, op2, v[j].second);
            }
        }

        if (temp < D)
        {
            ans.push_back(id);
        }
    }
    sort(ans.begin(), ans.end());
    for (auto el : ans)
    {
        cout << el << endl;
    }
}