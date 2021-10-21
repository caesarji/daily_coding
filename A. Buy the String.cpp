#include<bits/stdc++.h>
using namespace std;

void solve()
{
    int n,c0,c1,h;
    cin >> n >> c0 >> c1 >> h;
    
    string str;
    cin >> str;
    
    int zeros=0,ones=0;
    for(int i=0;i<n;i++)
    {   
        if(str[i]=='0')
            zeros++;
        else
            ones++;
    }
    
    //cout << ones << " " << zeros << endl;
    
    if(c0==c1)
        cout << n*c0 << endl;
        
    else if(c0+h <c1)
    {
        cout << (c0*n + h*ones) << endl;
    }
    
    else if(c1+h < c0)
    {
        cout << (c1*n + h*zeros) << endl;
    }
    
    else
    {
        cout << zeros*c0 + ones*c1 << endl;
    }
    
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    int t;
    cin >> t;
    
    for(int i=0;i<t;i++)
        solve();
        
    return 0;
}