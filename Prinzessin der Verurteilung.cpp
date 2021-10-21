#include<bits/stdc++.h>
using namespace std;

void solve(){
    
        
        int len;
        cin>>len;
        string inpStr;
        cin>>inpStr;
    char str='a';
    string strr;
    
    
    for(int k=1;k<=len;k++){
        int num=1;
        for(int i=1;i<=k;i++){
            num*=26;
        }
            for(int i=0;i<num;i++){
                int temp=i;
                // cout<<temp<<endl;
                string s;
                for(int j=1;j<=k;j++){
                      
                    int d=temp%26;
                    
                    // cout<<d<<" ";
                    // cout<<char(str+d)<<" " ;
                    s.push_back(char(str+d));
                    temp/=26;
                }
                // cout<<endl;
                reverse(s.begin(), s.end());
                if(inpStr.find(s)==-1) {cout<<s<<endl; return;}
                // cout<<s<<endl;
      
             }

        

    }
    
}

int main(){
    
    
    int t; cin>>t;
    while(t--){
        solve();
        
    }

    
    


}

