#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define loop(i,n) for(ll i=0;i<n;i++)
#define loop1(i,k,n) for(ll i=k;i<n;i++)
#define pb push_back
#define debug cout<<(__LINE__)
typedef long long int ll;
int gcd(int a, int b, int* x, int* y)
{
    if (b == 0)
    {
        *x = 1, *y = 0;
        return b;
    }
    int x1, y1;
    int g = gcd(b,  a%b, &x1, &y1);
    *x = y1;
    *y = x1-y1*(a/b);
    return g;
}

int inverse(int k,int m){
    int x, y;
    int g = gcd(k, m, &x, &y);
    if (g != 1)
        return -1;
    else
    {
       return (x % m + m) % m;
    }
}

string encrypt(string pt,int k){
    string cpt="";
    for(int i=0;i<pt.length();i++){
        int temp = ((pt[i]-'a')*k)%26;
        cpt+=(temp+'a');
    }
    return cpt;
}
string decrypt(string s,int k){
    int ik = inverse(k,26);
    if(ik==-1){
        cout<<"wrong key\n";
        return "";
    }
    string pt="";
    for(int i=0;i<s.length();i++){
        int temp = ((s[i]-'a')*ik)%26;
        pt+=(temp+'a');
    }
    return pt;
}
void solve(){
    string pt;
    cin>>pt;
    int k;
    cin>>k;
    string cpt=encrypt(pt,k);
    cout<<"Cipher text: "<<cpt<<endl;
    string dpt = decrypt(cpt,k);
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

