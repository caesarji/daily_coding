#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;
bool differByOne(string s1, string s2)
{

    int n1 = s1.size();
    int n2 = s2.size();
    if (n1 != n2)
        return false;

    vector<int> hash1(26, 0);
    vector<int> hash2(26, 0);
    // char a='c';
    // int x=int('a')-'a';
    // cout << x<< endl;
    // cout<<endl;
    for (auto c : s1)
    {
        hash1[c - 'a']++;
        // cout<<c-'a';
    }
    // cout<<endl;
    for (auto c : s2)
    {
        hash2[c - 'a']++;
        // cout<<c-'a';
    }
    // cout<<endl;
    int cnt = 0;
    for (int i = 0; i < 26; i++)
    {
        // cout << i+1 <<"----- "<<hash1[i] << " " << hash2[i] << endl;
        if (hash1[i] != 0 && hash2[i] != 0)
        {
            cnt += min(hash1[i], hash2[i]);
            // cout << "----------------"<<cnt << endl;
        }
    }
    if (n1 - cnt == 1)
        return true;
    return false;
}

void dfs(string s, map<string, int> &p, unordered_map<string, set<string>> adj, int &count, map<string, bool> &vis, string e)
{
    cout << "dfs for " << s << " " << p[e] << endl;
    vis[s] = true;
    count++;

    for (auto c : adj[s])
    {
        // cout << "child now is " << c << vis[c] << endl;



        


        if (p[c] > count)
            p[c] = count;
        if (c == e)
        {
            vis[c] = false;
            vis[s] = false;
            count--;
            return;
        }
        // if(c==e)
        if (!vis[c])
        {
            // cout<<"going for dfs of "<<c<<endl;
            dfs(c, p, adj, count, vis, e);
            // cout << "dfs for " << c << " ended" << endl;
        }
    }
    vis[s] = false;
}
int ladderLength(string b, string e, vector<string> &l)
{
    bool f = false;
    for (auto c : l)
    {
        if (c == e)
            f = true;
    }
    if (!f)
        return 0;

    int n = l.size();
    // vector<string> adj(n + 1);
    unordered_map<string, set<string>> adj;
    // cout<<differByOne("sad", "dad")<<endl;
    // cout<<differByOne("sad", "dap")<<endl;
    for (auto c : l)
    {
        if (differByOne(b, c))
        {
            adj[b].insert(c);
            adj[c].insert(b);
        }
    }
    for (auto c : l)
    {
        for (auto d : l)
        {
            if (c == d)
                continue;
            if (differByOne(c, d))
            {
                adj[c].insert(d);
                adj[d].insert(c);
            }
        }
    }

    for (auto c : adj)
    {
        cout << c.first << "----";
        for (auto d : c.second)
        {
            cout << d << " ";
        }
        cout << endl;
    }
    if(adj[b].size()==0) return 0;

    map<string, int> p;
    map<string, bool> vis;
    p[b] = INT_MAX;
    //    cout<<b<<" "<<p[b]<<endl;
    for (auto c : l)
    {
        p[c] = INT_MAX;
        //    cout<<c<<" "<<p[c]<<endl;
    }
    int count = 1;
    //    cout<<p[e]<<endl;
    dfs(b, p, adj, count, vis, e);
    cout << p[e] << endl;
    return 0;
}
int main()
{
    vector<string> v = {"ted","tex","red","tax","tad","den","rex","pee"};
    ladderLength("red", "tax", v);
}
