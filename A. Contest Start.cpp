#include<bits/stdc++.h>
using namespace std;
// #define long long long long
// *min_element(arr + 0, arr +n)?;
// for(int i=0;i<n;i++)
// long long
// sort(arr,arr+n);   incre,...
// INT_MAX  LONG_LONG_MAX
unsigned long long int cnt; 

void solve(){
    long long n,x,t; cin>>n>>x>>t;
    long long s=x;
    long long e=t;
    cnt=0;
    
    if(n==1){cout<<0<<endl;return;}
    long long p=t/x;   
    if(n>p) cnt=p*(n-p)+(p*(p-1))/2;
    else cnt=((n-1)*n)/2;
    cout<<cnt<<endl;
    
    
    
    
    
    
    
    
    
    
    
    // if(t>=(n-1)*x){ cout<<(n*(n-1))/2<<endl;return;}
    
    
    
    
    
    
    
    
    // for(long long i=1;i<n;i++){
        
    //     while(e>=s && s<=(n-1)*x) {cnt++; s+=x;}
    //     e+=x; s=e-t+x;
    // }
    // cout<<cnt<<endl;
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    
    // pair<long long,long long>p[n];
    // long long s=0;
    // long long e=t;
    // for(int i=0;i<n;i++){
    //     p[i].first=s;
    //     p[i].second=e;
    //     s+=x;
    //     e+=x;
    // }
    // cnt=0;
    // for(int i=0;i<n;i++){
    //     for(int j=i+1;j<n;j++){
    //         // cout<<p[i].second<<"--------"<<p[j].first<<endl;
    //         if(  p[i].second>=p[j].first ) cnt++;
    //         else break;
    //     }
    //     // cout<<cnt<<endl;
    // }
    // cout<<cnt<<endl; return;
}
    
    

int main(){
    
    
    long long t; cin>>t;
    while(t--){
        solve();
        
    }

    
    


}

