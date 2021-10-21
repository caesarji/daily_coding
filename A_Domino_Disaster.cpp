#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin>>n;
        string s;
        cin >> s;
        string ans;
        int i = 0;
        while (i < s.size())
        {
            if (s[i] == 'U')
                ans.push_back('D');
            else if (s[i] == 'D')
                ans.push_back('U');
            else
                ans.push_back('#');
            i++;
        }
        if (s.size() == 0)
        {
            cout << ans << endl;
            return 0;
        }
        i = 1;
        while (i < s.size())
        {
            if (ans[i - 1] == '#' && ans[i] == '#')
            {
                ans[i - 1] = 'L';
                ans[i] = 'R';
            }
            i++;
        }
        cout<<ans<<endl;
    }
}