#include<bits/stdc++.h>
using namespace std;
// #define long long long long

void solve(){
    long long n; cin>>n;
    
    long long arr[n];
    unordered_map<long long,long long>m;
    for(long long i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]-i) m[arr[i]-i]++;
        // else if( (arr[i]-i) <0) ar[i-arr[i] + 20000]++;
    }
    long long cnt=0;
    for(auto i:m)
        cnt+=(i.second*(i.second-1))/2;
        
    cout<<cnt<<endl;return;
    
    
}

int main(){
    
    
    long long t; cin>>t;
    while(t--){
        solve();
        
    }

    
    


}

