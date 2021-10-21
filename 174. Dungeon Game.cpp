#include <bits/stdc++.h>
using namespace std;

vector<int>  maxSum(int arr[], int n, int k)
{
        vector< int >ssum;

    long long int sum =0;

    for(int i=0;i<k;i++)
    sum+=arr[i];

    ssum.push_back(sum);

    for(int i=k;i<n;i++){
    sum = sum -arr[i-k] + arr[i];
    ssum.push_back(sum);
    }

    return ssum;
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
     
    //  for( auto c:arr){
    //      cout<<c<<" ";
    //  }
    //  cout<<endl;
    
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
            if (!hash[k]  && !hash == j)
                f++;
            c >>= 1;
            k++;
        }
        // cout<<num<<" "<<f<<endl;
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
