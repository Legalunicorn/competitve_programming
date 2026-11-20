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
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

void solve(){
    string a,b,c;
    cin >> a >> b >> c;
    // clearly this is dp? 
    // we want the min modifications 
    int n = a.size(), m = b.size(), k = c.size();
    vvi dp(n+1, vi(m+1, -1));
    auto dfs = [&](auto& dfs, int i, int j) -> int{
        if (i == n && j == m) return 0;
        if (dp[i][j]!=-1) return dp[i][j];
        int res = k;
        if (i<n) res = min(res, dfs(dfs,i+1,j) + (a[i]==c[i+j]?0:1));
        if (j<m) res = min(res, dfs(dfs,i,j+1) + (b[j]==c[i+j]?0:1));
        return dp[i][j] = res;
    };
    cout << dfs(dfs,0,0) << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
