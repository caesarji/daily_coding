    #include <bits/stdc++.h>
    #define            ll           long long int
    #define            pb            push_back
    #define            mp            make_pair
    #define            ff            first
    #define            ss            second
    #define            set1(x)       __builtin_popcount(x)//counts the number of set bits in an integer
    #define            gcd(a,b)      __gcd(a,b)
    #define            inf           1e18
    #define            fastio        ios_base::sync_with_stdio(false); cin.tie(NULL);
    #define            pl            pair<ll,ll>
    #define            all(v)        (v).begin(),(v).end()
    #define            fi(a,n)       for(ll i=a;i<n;i++)
    #define            fj(a,n)       for(ll j=a;j<n;j++)
    #define            fk(a,n)        for(ll k=a;k<n;k++)
    #define            vl            vector<ll>
    #define            deb(x)        cout<<#x <<" "<<x<<"\n";
    #define            ull            unsigned long long int 

    using namespace std;
    //extended_euclidean
    //ncr
    //power_operator

    const ll N =2*1e5+1;
    const ll zero=0;
    const ll lmin=-1e18;
    const ll lmax=1e18;
    const ll tem=5000004;

    int n,m;
    vector<vector<int> > mat(1001,vector<int>(1001));
    vector<int> ans;
    vector<vector<bool> > visited(1001,vector<bool>(1001,false));
    bool inside(int x,int y)
    {
        return (x>=0 && x<n && y>=0 && y<m);
        
    }
    int dfs(int x,int y)
    {
        
        visited[x][y]=true;
        int val=mat[x][y];

        int ans=0;
        
        for(int p=0;p<4;p++)
        {
            int bit=val&1;
            val=val>>1;
            if(bit==0)
            {
                if(p==0)
                {
                    if(inside(x,y-1) && visited[x][y-1]==false)
                        ans+=dfs(x,y-1);

                }
                else if(p==1)
                {
                    if(inside(x+1,y) && visited[x+1][y]==false)
                        ans+=dfs(x+1,y);
                }
                else if(p==2)
                {
                    if(inside(x,y+1) && visited[x][y+1]==false)
                        ans+=dfs(x,y+1);
                }
                else
                {
                    if(inside(x-1,y) && visited[x-1][y]==false)
                        ans+=dfs(x-1,y);
                }
                
            }
            


        }
        return ans+1;
    }

    void solve() 
    {
        
        cin>>n>>m;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cin>>mat[i][j];
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(visited[i][j]==false)
                {
                    int temp=dfs(i,j);
                    ans.pb(temp);
                }
            }
        }  
        sort(ans.begin(),ans.end());
        reverse(ans.begin(),ans.end());
        for(auto x:ans)
        {
            cout<<x<<" ";
        }

        

    
        
    }
    
        
    
    
    int main()
    { 
        fastio
    
    // int t;
    // cin>>t;
    // while(t--){

        solve();
    
    // }
    
    
    
    
    
    return 0;
    
    
        
    
    
    
    }shi