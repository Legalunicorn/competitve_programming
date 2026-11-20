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

// NOTE: 
// we already have dp[n][m] to mark the answer 
// should we have a trace[n][m] ?  
// recurrance relations 
// - skip one 
// - skip two 
// - if same consume both 
// how do we construct? 
// only the third case is a consume
// store the answer {1,2,3]
// if its 3 we append to the answer}
//
// we do not need skip both base it is converted already

void solve(){
    int n,m;
    cin >> n >> m;
    vi a(n), b(m);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    vvi dp(n+1, vi(m+1, 0));
    vvi trace(n+1, vi(m+1, 0));
    debug(n,m,a,b);
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++) {

            dp[i][j] = dp[i - 1][j]; // opt 1
                                     //
            int o2 = dp[i][j-1];
            if (o2 > dp[i][j]) {
                trace[i][j] = 1; // go here instead
                dp[i][j] = o2;
            }

            int w = (a[i-1] == b[j-1] ? 1 : 0);
            int o3 = dp[i-1][j-1] + w;
            if (o3 > dp[i][j]) {
                dp[i][j] = o3;
                trace[i][j] = 2; // third option
            }
        }
    }
    vi ans;
    cout << dp[n][m] << endl;
    int r = n, c = m;
    while(r >= 1 && c >= 1){
        if (trace[r][c] == 0) r--;
        else if (trace[r][c] == 1) c--;
        else if (trace[r][c] == 2) {
            debug(r,c);
            ans.pb(a[r - 1]);
            r--, c--;
        }
    }
    reverse(all(ans));
    for (auto& z:ans) cout << z << " ";
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
