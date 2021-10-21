#include <bits/stdc++.h>
using namespace std;


vector<int>  maxSum(int arr[], int n, int k)
{
    int max_sum = INT_MIN;
    vector<int> subarray;
    for (int i = 0; i < n - k + 1; i++) {
        int current_sum = 0;
        for (int j = 0; j < k; j++)
            current_sum = current_sum + arr[i + j];
 
        subarray.push_back(current_sum);
    }
 
    return subarray;
}

int main()
{


    int noo ; 
    cin>>noo ;
    int arrr[noo]; 
    int t;
    cin>>t;
    for( int i=0; i<noo ; i++){
        cin>>arrr[i];
    }
    while(t--){

    int zzz;
    cin>>zzz;
    int y;
    cin>>y;

     vector<int> arr = maxSum(arrr , noo ,zzz );
    
    int hash[32] = {0};
    int m = 1;

    int n ;
    cin>>n; 
    int nn=n;
    int k = 0;
    int count = 0;
    while (n)
    {
        count += n & 1;
        hash[k] = n & 1;
        n >>= 1;
        k++;
    }

    for (auto c : hash)
    {

        m++;
    }
    priority_queue<pair<int , int>> v;

    for (auto c : arr)
    {

        k = 0;
        int f = 0;
        int num=c;
        while (c)
        {
            count += c & 1;
            int j=c&1;
            if (!hash[k] == j)
                f++;
            c >>= 1;
            k++;
        }
        v.push({f , num});
    }
    int ans=v.top().second;
    v.pop();
    y--;

    while(y>0){
        auto c=v.top();
        v.pop();
        ans &= c.second;
    y--;
    }
       ans = ans | nn;
    cout << ans << endl;

    }


}
