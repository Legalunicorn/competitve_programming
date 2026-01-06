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

// any chain if "??" is beautiful 
// this might have to do with fix one end, then find the longest beautfil substring 
// the add the natural sum to the answer 
// if L is 1 or 0, we can try to precompute determine max length 
// if L is "?" we try both 1 and 0? 
// the add the max 
// for 1 and 0, we how do we not n^2 though maybe this is DP 
// dp[i][state] -> return the max length we can reach 
// state -> current state 
//
//
int tc =0;
void solve(){
    tc ++;
    string s;
    cin >> s;
    int n = s.size();
    vvi dp(n, vi(2,-1));
    vi a(n);
    const int WILD = 67;
    for (int i = 0; i < n; i++) {
        if (s[i]=='?') a[i] = WILD;
        else a[i] = s[i] - '0';
    }
    if (tc==3) debug(s,a);

    auto dfs = [&](auto& dfs, int i, int state) -> int{
        if (i == n-1) return dp[i][state] = 1;
        if (i == n) return 0;;
        if (dp[i][state]!=-1) return dp[i][state];
        int len = 1; 
        int need = (state==1? 0:1);
        if (a[i+1] == need || a[i+1] == WILD){
            len = max(len, 1 + dfs(dfs,i+1,need));
        }
        return dp[i][state] = len;
    };
    
    for (int i=0;i<n;i++){
        if (a[i] == WILD){
            dfs(dfs,i,1);
            dfs(dfs,i,0);
        } else{
            dfs(dfs,i,a[i]);
        }
    }

    ll ans = 0;
    for (int i=0;i<n;i++){
        int len = max(dp[i][0], dp[i][1]);
        ans += len;
    }
    cout << ans << endl;


};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
