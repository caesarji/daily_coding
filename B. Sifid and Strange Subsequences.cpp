#include<bits/stdc++.h>
using namespace std;
// #define long long long long
// *min_element(arr + 0, arr +n)?;
// for(int i=0;i<n;i++)
// long long
// sort(arr,arr+n);   incre,...
// INT_MAX  LONG_LONG_MAX


void solve(){
    
    int n;cin>>n; 
    long long arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    
    sort(arr,arr+n);
    if(arr[0]>0){ cout<<1<<endl;return;}
    long long minn=LONG_LONG_MAX;
    int cnt=1;
    for(int i=1;i<n;i++){
        if(arr[i]>0){
            if(arr[i]<=minn) {cout<<cnt+1<<endl; return;}
            else {cout<<cnt<<endl;return;}
        }
        cnt++;
        minn=min(minn,arr[i]-arr[i-1]);
    }
    cout<<cnt<<endl;return;
    
    
    
    
    
    
    // cout<<n-cnt<<endl;return;`
    
    
}
    
    

int main(){
    
    
    long long t; cin>>t;
    while(t--){
        solve();
        
    }

    
    


}

