#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i,n) for(ll i=0;i<n;i++)
#define loop1(i,k,n) for(ll i=k;i<n;i++)
#define pb push_back
#define debug cout<<(__LINE__)
typedef long long int ll;

string encrypt(string pt,char k){
    string cpt="";
    char key;
    for(int i=0;i<pt.length();i++){
        if(i==0) key=k-'a';
        else key = pt[i-1]-'a';
        int temp = ((pt[i]-'a')+key)%26;
        cpt+=(temp+'a');
    }
    return cpt;
}
string decrypt(string s,string pt,char k){
    string ans="";
    char key;
    for(int i=0;i<s.length();i++){
        if(i==0) key=k-'a';
        else key=pt[i-1]-'a';
        int shift = ((s[i]-'a')-key);
        if(shift<0) shift+=26;
        int temp = (shift)%26;
        ans+=(temp+'a');
    }
    return ans;
}
void solve(){
    string pt;
    cin>>pt;
    char k;
    cin>>k;
    string cpt=encrypt(pt,k);
    cout<<"Cipher text: "<<cpt<<endl;
    string dpt = decrypt(cpt,pt,k);
    cout<<"Plain text: "<<dpt<<endl;
}
int main(){
    ios_base::sync_with_stdio(false);
	cin.tie(NULL);
    ll t=1;
    for(ll i=1;i<=t;i++){
        solve();
    }
    return 0;
}