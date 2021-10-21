#include<bits/stdc++.h>
using namespace std;
#include <cstdio>
#include <cstring>
int n,q;char s[100011];int sum[100011];
int main()
{
    scanf("%d%d",&n,&q);
    scanf("%s",s+1);
    for(int i=1;i<=n;++i) 
    {
    sum[i]=sum[i-1]+s[i]-'a'+1;
    cout<<s[i]<<"----"<<s[i]-'a'+1<<"========"<<sum[i]<<endl;}
    while(q--)
    {
        int l,r;scanf("%d%d",&l,&r);
        printf("%d\n",sum[r]-sum[l-1]);
    }return 0;
}