

void backtrack(int n , int l , int r , vector<string>& ans , string s){
    cout<<
    if(s.size()==2*n){
        ans.push_back(s);
        return;
    }
    if(l<n){
        backtrack(n , l+1 , r , ans, s+'(');
    }
    if(r<l){
        backtrack(n , l , r+1 , ans, s+')');
    }
}
class Solution
{
    public:
    vector<string> AllParenthesis(int n) 
    {
        vector<string>ans;
        
        backtrack(n , 0 , 0 , ans, "");
        return ans;
        
    }
};
