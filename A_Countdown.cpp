#include <bits/stdc++.h>
using namespace std;

int main()
{

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        string num;
        cin >> num;
        reverse(num.begin() , num.end());
        int nums[n];
        for( int i=0; i<num.size(); i++){
            string t="";
            t+=num[i];
            nums[i]=stoi(t);
        }

        int ans = nums[0];
        int i=1;
        // cout << ans << endl;
        while (i<num.size())
        {
            ans += (nums[i]  == 0) ? 0 : nums[i] + 1;
            // cout << ans << endl;

            i++;
        }
        cout << ans << endl;
    }
}

// 00167829   4039   7100472039   46100020
//  79 36