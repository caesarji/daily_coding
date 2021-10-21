#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pb push_back
#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(x) (x).begin(), (x).end()
#define uniq(v) (v).erase(unique(all(v)), (v).end())
#define sz(x) (int)((x).size())
#define fr first
#define sc second
#define pii pair<int, int>
#define rep(i, x, n) for (int i = x; i < n; i++)
// #define rep(i, 0 n)         for(int i=0;i< n ; i++)
// #define rf(i,s,e,jump)    for(int i=s;i>=e;i-=jump)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define ppc __builtin_popcount
#define ppcll __builtin_popcountll
#define yes cout << "YES" << endl
#define no cout << "NO" << endl
#define debug cout << "here" << endl;
#define read(a)       \
    for (auto &p : a) \
        cin >> p;

template <typename T1, typename T2>
istream &operator>>(istream &in, pair<T1, T2> &a)
{
    in >> a.fr >> a.sc;
    return in;
}
template <typename T1, typename T2>
ostream &operator<<(ostream &out, pair<T1, T2> a)
{
    out << a.fr << " " << a.sc;
    return out;
}
template <typename T, typename T1>
T amax(T &a, T1 b)
{
    if (b > a)
        a = b;
    return a;
}
template <typename T, typename T1>
T amin(T &a, T1 b)
{
    if (b < a)
        a = b;
    return a;
}

//iB trees
//  struct ListNode {int val;ListNode *next;ListNode(int x) : val(x), next(NULL) {}};

//  ListNode* reverse(ListNode* head){
//     ListNode* prev=NULL;ListNode* curr=head;ListNode* fur=head;
//     while(fur!=NULL){fur=fur->next;curr->next=prev;prev=curr;curr=fur;}return prev;}

//  ListNode* middle(ListNode* head){
//     ListNode* slow=head;ListNode* fast=head;
//     while(fast->next->next!=NULL){slow=slow->next;fast=fast->next->next;}
//     return slow;}

//  TreeNode* MergeTwoBinaryTree(TreeNode* a, TreeNode* b) {if(!a) return b ;if(!b) return a ;if(a && b ) a->val+=b->val;
//     a->left=MergeTwoBinaryTree(a->left , b->left);a->right=MergeTwoBinaryTree(a->right , b->right);return a ; }

//  int CompareBinaryTree(TreeNode* a , TreeNode* b){if(!a && !b) return 1;if((!a&&b) || (!b&&a) ||(a->val!=b->val)) return 0;
//      return(CompareBinaryTree(a->left , b->right) && CompareBinaryTree(a->right , b->left));}

//  TreeNode* helperFlattenBinaryTreeToLinkedList(TreeNode* head){if(!head) return NULL ; if(!head->left && !head->right) return head ;
//     TreeNode* ltail=helper(head->left);TreeNode* rtail=helper(head->right);
//     if(ltail && rtail){ltail->right=head->right;head->right=head->left;head->left=NULL;return rtail;}
//     else if(ltail){head->right=head->left;head->left=NULL;return ltail;}
//     return rtail;} TreeNode* FlattenBinaryTreeToLinkedList(TreeNode* A) {helperFlattenBinaryTreeToLinkedList(A);return A ;}

// TreeNode* InvertTheBinaryTree(TreeNode* head) {if(!head) return NULL;  // base
//     InvertTheBinaryTree(head->left);InvertTheBinaryTree(head->right);   //recursion
//     TreeNode* temp=head->left;head->left=head->right;head->right=temp;return head;} //swap

// //g k
// int APMissingMiddleNumber(){int g1, g2 , g3 , g4 , g5 , g6 , g7 , g8 , g9;
//     cin>>g1 >>g2>>g3;cin>>g4 >>g6;cin>>g7 >>g8>>g9;//g5 missing
//     int cnt=0;if(2*g2==g1+g3)cnt++;if(2*g8==g7+g9)cnt++;if(2*g4==g1+g7)cnt++;if(2*g6==g3+g9)cnt++;map<int,int>m;
//     if((g2+g8)%2==0)m[g2+g8]++;if((g4+g6)%2==0)m[g4+g6]++;if((g3+g7)%2==0)m[g3+g7]++;if((g1+g9)%2==0)m[g1+g9]++;
//     int maxi=INT_MIN;for(auto c:m){if(c.sc>maxi) maxi=c.sc; }
//     if(maxi!=INT_MIN)cnt+=maxi;return cnt;}

// //iB stacksNqueues
// int largestRectangleArea(vector<int> &arr) {
//     int n=arr.size();stack<pair<int, int>>left , right;vector<int> l(n) , r(n);
//     for(int i=0;i<n;i++){while(!left.empty() && left.top().first>=arr[i]) left.pop();l[i]=   !left.empty()   ?   left.top().second:-1;left.push({arr[i], i});}//nearest smallest
//     for(int i=n-1;i>=0;i--){while(!right.empty() && right.top().first>=arr[i]) right.pop();r[i]=   !right.empty()   ?   right.top().second:n;right.push({arr[i], i});}
//     int maxi=INT_MIN;for(int i=0;i<n;i++){maxi=max(maxi, (max(i-l[i]-1 , 0) + max(r[i]-1-i , 0) +1)*arr[i]);}return maxi;}
// //iB
// string FirstNonRepeatingCharacterInAStreamOfCharacters(string str) {queue<char>q;vector<int>v(26,0);string ans="";
// for(char c:str){q.push(c);v[c-'a']++;while(!q.empty() && v[q.front()-'a']>1) q.pop();if(!q.empty()) ans+=q.front();else ans+='#';}return ans;}

// //comma separated , case conversion , char->int
// // while(str[i][j]!=','){if(t==1){if((int)str[i][j]<97 && (int)str[i][j]>64 ) str[i][j]=char((int)str[i][j]+32);fname[i]+=str[i][j];  j++; }
// // } t++;j++;while(str[i][j]!=','){if(t==3){aspend[i]+= (int)str[i][j] -48; j++; aspend[i]*=10;}
// // }t++;j++;while(str[i][j]!='\0'){if(t==4){crlim[i]+=str[i][j]; j++;}}t++;if(t==4) break;}}

// vector<int> SlidingWindowMaximum(const vector<int> &arr, int k) {deque<int> dq;vector<int> ans;int n=arr.size();
//   for(int i=0;i<n;i++){if(!dq.empty() && dq.front()==(i-k))dq.pop_front();
//   while(!dq.empty() && arr[dq.back()]<arr[i])dq.pop_back();
//   dq.push_back(i);if(i>=k-1) ans.push_back(arr[dq.front()]);}return ans;}

// string SimplifyDirectoryPath(string str) {vector<string> v;string path="";string ans="";
//     for(int i=0;i<str.length();i++){
//         while(i<str.length() && str[i]!='/') path+=str[i++];
//         if(path=="" || path==".") continue;if(path==".." ) {if(v.size()>0) v.pop_back();}else v.push_back(path);}
//     if(v.size()==0) return "/";
//     for(auto c:v){ans+="/"+c;}return ans;}

const long long INF = 1e18;
const int32_t M = 1e9 + 7;
const int32_t MM = 998244353;

const int N = 0;

void solve()
{
    int n, k;
    cin >> n >> k;

    int a[n];
    rep(i, 0, n)
    {
        cin >> a[i];
    }

    int l = 0;
    int r = n - 1;

    int ans = INT_MIN;
    if (k > 0)
    {
        int t = l * r - k * (a[l] * a[r]);
        if (t > ans)
            ans = t;
        else
        {

            if (a[l] < a[r])
                ? l++;
        }

    else
    {
    }
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
//freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
#ifdef SIEVE
    sieve();
#endif
#ifdef NCR
    init();
#endif
    int t = 1;
    cin >> t;
    while (t--)
        solve();
    return 0;
}