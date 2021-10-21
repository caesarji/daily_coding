#include<bits/stdc++.h>
using namespace std;
// #define long long long long
// *min_element(arr + 0, arr +n)?;
// for(int i=0;i<n;i++)


void solve(){
    
    int n;cin>>n; 
    int arr[n];
    for(int i=0;i<n;i++) cin>>arr[i];
    int minn= *min_element(arr + 0, arr +n);
    
    int cnt=0;
    for(int i=0;i<n;i++){
        if(arr[i]==minn) cnt++;
    }
    cout<<n-cnt<<endl;return;
    
    
}
    
    

int main(){
    
    
    long long t; cin>>t;
    while(t--){
        solve();
        
    }

    
    


}

