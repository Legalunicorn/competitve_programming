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


// 1. from experience likely dp
// min number of lunch boxes? n = 300 
// the brute force dp is pick/not pick 
// dp[n][300][300] might work 

int dp[305][305][305];

void solve(){
    int n;
    cin >> n;
    int one,two; 
    cin >> one >> two;
    vpi a(n);
    for (int i=0;i<n;i++) cin >> a[i].F >> a[i].S;
    memset(dp, -1, sizeof(dp));

    auto dfs = [&](auto& dfs, int i, int x, int y) -> int{
        if (x >= one && y >= two) return 0;
        if (i >= n) return 500;
        if (dp[i][x][y] != -1) return dp[i][x][y];
        int evl = 500;
        int take = 1 + dfs(dfs,i+1, min(300, x+a[i].F), min(300,y+a[i].S));
        evl = min(evl, take);
        int skip = dfs(dfs,i+1,x,y);
        evl = min(evl,skip);
        return dp[i][x][y] = evl;
    };
    int res = dfs(dfs,0,0,0);
    if (res > n) res = -1;
    cout << res << endl;
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
