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

// NOTE: recurance is trivial 
// solve(i, j) 
// MAX 
// - solve(i-1, j)
// - solve(i, j -1)
// - solve(i-1, j-1) + <?> 
//
// with an iterative dp approach we need t osolve all these small values first 
// can i solve [1,100] before [2, 10]
// yes i think both (i2, j2) must be less than or quals 
// so how it works is for i = 1 to n 
// for j = 1 to n and solve it like that

void solve(){
    int n, m;
    cin >> n;
    cin >> m;
    vi a(n), b(m);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    vvi dp(n+1, vi(m+1, 0));
    // auto go = [&](auto& go, int i, int j) -> int {
    //     if (i < 0 || j < 0) return 0;
    //     if (dp[i][j]  != -1) return dp[i][j];
    //
    //     int y = go(go, i-1, j);
    //     int x = go(go, i, j - 1);
    //     int wild = ((a[i] == b[j]) ? 1 : 0);
    //     int c = go(go, i-1, j-1) + wild;
    //     return dp[i][j] = max({y,x,c});
    // };
    // int res = go(go , n-1, n-1);
    // cout << res << endl;

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            int wild = (a[i-1] == b[j-1] ? 1 : 0);
            dp[i][j] = max({
                dp[i-1][j],
                dp[i][j-1],
                dp[i-1][j-1] + wild
            });
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
