#include<bits/stdc++.h>
using namespace std;

void solve()
{
    string str;

    cin >> str;

    int ans =0;

    int n = str.length();

    for(int i=1;i<n;i++)
    {
        if(str[i]!=str[i-1])
        {
            if(str[i-1]=='0')
                ans++;
        }

        if(ans>1)
        {
            ans =2;
            break;
        }
    }


    if(str[n-1]=='0' && ans<2)
        ans++;
        
    cout << ans << endl;
}

int main()
{
    int t;
    cin >> t;

    for(int i=0;i<t;i++)
        solve();

    return 0;
}