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

// this is the math path distance of a tree 
// does it always use the diamter? 
// we might be able to cheese this by considering each node as LCA of some path 
// then we choose the best 2 answers


void solve(){
    int n;
    cin >> n;
    vvpl g(n);
    for(int i =0 ;i + 1 < n;i ++){
        ll u,v,w;
        cin >> u >> v >> w;
        u--, v--;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }

    // to your parent just tell it the MAX distaince to one leadf
    ll res = 0ll;
    debug(g);
    auto dfs = [&](auto& dfs, int u, int p ) -> ll{
        vl a;
        // ll d = 
        ll best = 0LL;
        for (auto& [v, w]: g[u]){
            if (v == p) continue;
            ll evl =  w + dfs(dfs, v, u);
            best = max(best, evl);
            a.pb(evl);
        }
        sort(rall(a));
        if (a.size() > 1){
            res = max(res, a[0] + a[1]);
        }
        res = max(res, best);
        debug(u+1, a, best, res);
        return best;
    };

    dfs(dfs, 0, -1);
    res = res % MOD;
    cout << res << endl;
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
