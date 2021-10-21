#include<bits/stdc++.h>
using namespace std;
// #define long long long long

void solve(){
    int n;cin>>n;
    int arr[n]; float sum=0;
    for(int i=0;i<n;i++)
    { cin>>arr[i]; sum+=arr[i];}
        // cout<<float(sum/n)<<endl;
        // cout<<float(1.5)<<endl;
        if(float(sum/n)==1) {cout<<0<<endl; return;}
        if(sum<n){ cout<<1<<endl;return;}
        else {cout<<sum-n<<endl; return;}
    }

int main(){
    
    
    long long t; cin>>t;
    while(t--){
        solve();
        
    }

    
    


}

