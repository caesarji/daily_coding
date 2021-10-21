#include<bits/stdc++.h>
using namespace std;
// #define long long long long



void solve(){
    long long  n,m,i,j;cin>>n>>m>>i>>j; long long  x1,x2,y1,y2;
        if(n-i > i-1)  x1=n; else x1=1;
        if(m-j > j-1)  y1=m; else y1=1;
        
        // if(x1==n && y1==m)  if(i-1>j-1)  y2=1; else 
        
        long long vt=i-1;
        long long vb=n-i;
        long long hs=j-1;
        long long hl=m-j;
        
        
        
        long long z1=2*hl + 2*vb;
        long long z2=2*hl + 2*vt;
        long long z3=2*hs + 2*vb;
        long long z4=2*hs + 2*vt;
        long long arr[4];
        arr[0]=z1;
        arr[1]=z2;
        arr[2]=z3;
        arr[3]=z4;
        sort(arr,arr+4);
        if(arr[3]==z1){ x1=n,y1=m;}
        else if(arr[3]==z2){ x1=1,y1=m;}
        else if(arr[3]==z3){ x1=n,y1=1;}
        else if(arr[3]==z4){ x1=n,y1=1;}
        
        if(arr[2]==z1){ x2=n,y2=m;}
        else if(arr[2]==z2){ x2=1,y2=m;}
        else if(arr[2]==z3){ x2=n,y2=1;}
        else if(arr[2]==z4){ x2=n,y2=1;}
        
        
        
        
        
        // if( x1-i >= y1-j ) { x2=x1;if(y1==m) y2=1; else y2=m;}
        // else { y2=y1;  if(x1==n) x2=1; else x2=n;}
        
        
        
        
        
        // if(x1==n && y1==m) {x2=i+1; y2=j;}
        // else if(x1==n && y1==1) {x2=i; y2=j-1;}
        // else if(x1==1 && y1==m) {x2=i; y2=j+1;}
        // else if(x1==1 && y1==1) {x2=i-1; y2=j;}
        cout<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<endl;return;
    
    }
    
    

int main(){
    
    
    long long t; cin>>t;
    while(t--){
        solve();
        
    }

    
    


}

