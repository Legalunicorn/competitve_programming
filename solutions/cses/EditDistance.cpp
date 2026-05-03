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

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// think in terms of invariants of the start char 
// if both starts are the same, increment for both, no cost 
// if the are diffeent 
//  if length diff: longer ++ 
//  if length same: change either
//

void solve(){
    // dp[i][j] 
    // obvious if one is zero we can return the other 
    // ADD 
    // REMOVE 
    // REPLACE
    // we can also do a free cost "replace" when they patch 
    // remove is just ignore the current "i" or "j"
    // add is the inverse or remove 
    string s,t;
    cin >> s >> t;
    int n = s.size(), m = t.size();
    vvi dp(n+1, vi(m+1, n + m + 1));
    for (int i = 0; i <= n; i++){
        for (int j = 0; j <= m; j++){
            if (i == 0) dp[i][j] = j;
            else if (j == 0) dp[i][j] = i;
            else {
                int wild = (s[i-1] == t[j-1] ? 0: 1);
                dp[i][j] = min(dp[i][j], 1+ dp[i-1][j]);
                dp[i][j] = min(dp[i][j], 1+ dp[i][j-1]);
                dp[i][j] = min(dp[i][j], dp[i-1][j-1] + wild);
            }
        }
        debug(i, dp[i]);
    }
    cout << dp[n][m] << endl;
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
