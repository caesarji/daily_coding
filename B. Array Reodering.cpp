#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n;cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    vector<int>ans;
    vector<int>odd;
    
    int cnt;
    
        for(int i=0;i<n;i++){
                if(arr[i]%2==0) ans.push_back(arr[i]);
                else odd.push_back(arr[i]);
            }
        for(int i=0;i<odd.size();i++){
                 ans.push_back(odd[i]);
            }
    
        cnt=0;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if( __gcd(ans[i],2*ans[j])>1 ) {cnt++;  }
            }
        }
        
    
        

    
    cout<<cnt<<endl;return;
    
}

int main(){
    
    
    int t; cin>>t;
    while(t--){
        solve();
        
    }

    
    


}

