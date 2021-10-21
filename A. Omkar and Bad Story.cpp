#include<bits/stdc++.h>
using namespace std;

void solve(){
    int n; cin>>n;
    
    int arr[n]; int flag=false;
    for(int i=0;i<n;i++){
        cin>>arr[i];
        if(arr[i]<0) flag=true;
    }
    if(flag) {cout<<"NO"<<endl; return;}
    else{ cout<<"YES"<<endl;cout<<101<<endl;
        for(int i=0;i<=100;i++) cout<<i<<" "; cout<<endl;return;
    }
    
    
    
}

int main(){
    
    
    int t; cin>>t;
    while(t--){
        solve();
        
    }

    
    


}

