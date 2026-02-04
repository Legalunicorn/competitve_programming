#include <bits/stdc++.h>
using namespace std;
using ll = long long; using ull = unsigned long long;using ld = double; 
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using pl = pair<ll,ll>; using vpl = vector<pl>; using vvpl = vector<vpl>;
using pi = pair<int,int>; using vpi = vector<pi>;using vvpi = vector<vpi>;
using vb = vector<bool>; using vvb = vector<vb>;

#if defined(LOCAL) && __has_include("debug.h")
#include "debug.h"
#else
#define debug(...)
#endif

#define endl '\n' 
#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

// this is clearly dp isnt it 
// min(  min(2,5)) 
// dp 
//


void solve(){
    int n;
    cin >> n;
    vvpi dp(n, vpi(n,{-1,-1}));
    vvpi g(n, vpi(n)) ;
    using vc = vector<char>;
    using vvc = vector<vc>; 
    vvc trace(n, vc(n, '#'));
    for (int i = 0; i < n ;i++){
        for (int j = 0; j < n ;j++){
            int x; cin >> x ;
            int two = 0, five = 0;
            while(x && x%2==0){
                two++;
                x/=2;
            }
            while(x && x%5==0){
                five++;
                x/=5;
            }
            g[i][j] = {two,five};
        }
    }
    
    auto dfs = [&](auto& dfs, int i, int j) -> pi{
        if (i == n-1 && j == n-1) dp[i][j] = g[i][j];
        if (dp[i][j].F != -1) return dp[i][j];
        int t = g[i][j].F, f = g[i][j].S;
        int best = INT_MAX;
        pi ans;
        if (j+1<n){
            trace[i][j] ='R';
            pi evl =  dfs(dfs,i,j+1);
            best = min(t+evl.F, f+evl.S);
            ans = {t+evl.F, f+evl.S};
        }
        if (i+1 < n){
            pi evl = dfs(dfs,i+1,j);
            int chk = min(t+evl.F, f+evl.S);
            if (chk <= best){
               best = chk;
               ans = {t+evl.F , f + evl.S};
               trace[i][j] = 'D';
            }
        }
        debug(i,j, best);
        return dp[i][j] = ans;
    };
    pi ans = dfs(dfs,0,0);
    int res = min(ans.F,ans.S);
    string s;
    int i = 0, j = 0;
    while(i!=n-1 || j!=n-1){
        if (trace[i][j]=='D'){
            s+='D';
            i++;
        } else{
            s+='R';
            j++;
        }
    }
    debug(trace);
    debug(dp);

    cout << res << endl;
    cout << s << endl;


};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
