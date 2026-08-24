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
    int n;
    cin >> n;
    vpl a(n);
    for (int i = 0; i < n; i++) cin >> a[i].F >> a[i].S;
    vvi g(n);
    for(int i = 1; i < n; i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    debug(a);
    debug(g);
    vvl dp(n, vl(2, -1)); // -1 not possible
    auto dfs = [&](auto& dfs, int u, int p, int s) -> ll {
        if (dp[u][s] != -1) return dp[u][s];
        ll res = 0ll;
        for (auto& v: g[u]){
            if (v == p) continue;
            ll one = dfs(dfs, v, u, 0);
            ll two = dfs(dfs, v,u,1);
            ll t  = (s==0? a[u].F : a[u].S);
            
            res += max(
                    one + abs(t - a[v].F),
                    two + abs(t - a[v].S )
                    );
        }
        return dp[u][s] = res;
    };
    ll ans = dfs(dfs,0,-1,0);
    ans = max(ans,dfs(dfs,0,-1,1));
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
    while(T--) solve();
    return 0;
}
