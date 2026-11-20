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

void solve(){
    int n,m;
    cin >> n >>  m;
    debug(n, m);
    vvi dp(n+1, vi(m+1, n * m + 1));
    for (int i = 1; i <= n; i++) dp[i][1] = i - 1;
    for (int i = 1; i <= m; i++) dp[1][i] = i - 1;
    for (int i = 1; i <= min(m, n); i++) dp[i][i] = 0;

    debug(dp);
    // NOTE:
    // the order we go ensures that both (i,j) we call, i <= I, j <= J
    // so it suffice for us to process in the normal order

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int ans = dp[i][j];
            for (int r = 1; r < i; r++){
                ans = min(ans, 1 + dp[r][j] + dp[i - r][j]);
            }
            for (int c = 1; c < j; c++){
                ans = min(ans, 1 + dp[i][c] + dp[i][j - c]);
            }
            dp[i][j] = min(dp[i][j], ans);
        }
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
