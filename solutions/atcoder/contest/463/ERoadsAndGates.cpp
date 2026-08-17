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
// special edgex
// A -> B -> C 
// makes no sense 
// A -> C directly will always be cheaper 
// 
//
// so SP from [1,k], at most one "special" edge 
// n nodes each n * 2 
// dp[n][2] 
// how do we decide when to uyse the special edge, its still n ^ 2 
// dp[n][2] 
// totla M normal edgesd 
//
//
// so is it really m^232 edges? 
// what if we sort 
// possible special edge to be in the middlke 
//


void solve(){
    int n,m; cin >> n >> m;
    ll y; cin >> y;
    vvpl g(n);
    for (int i = 0; i < m; i++){
        int u, v;
        ll w;
        cin >> u>> v >> w;
        u--, v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    debug(g);
    vl X(n);
    for (auto& z:X) cin >> z;
    debug(X);
    vl dist(n, 0LL);
    for (int i  = 1 ; i < n; i++) dist[i] = X[0] + X[i] + y;
    priority_queue<pl, vpl, greater<pl>> pq;
    dist[0] = 0LL;
    for (int i = 0; i < n; i++) pq.push({dist[i], i});
    // pq.push({0LL,0});
    debug(dist);
    ll mn = X[0] + y;
    while(!pq.empty()){
        auto t = pq.top();
        ll u = t.S, w = t.F;
        pq.pop();
        if (dist[u] < w) continue;
        for (auto& [v, d]: g[u]){
            ll ww = dist[u] + d;
            ll w2 = X[v] + y + mn;
            debug(mn, ww, w2);
            ww = min(ww,w2);
            mn = min(mn,   ww + X[v]);
            if (ww < dist[v]){
                dist[v] = ww;
                pq.push({ww, v});
            }
        }
    }
    for (int i = 0; i < n; i++) dist[i] = min(dist[i],  mn + X[i] + y);
    for (int i = 1; i <n;i++) cout << dist[i] << " ";
    // sort by X, and try to relax in that order 
    // vpl Z(n);
    // for (int i = 0; i < n; i++) Z[i] = {X[i] + dist[i], i};
    // sort(all(Z));
    // debug(Z);
    // debug(dist);
    // for (int i = 0; i < n; i++){
    //     // ll evl =  y + Z[0].F;
    //     ll evl = X[i] + Z[0].F + y;
    //     debug(i, evl, dist[i]);
    //     dist[i] = min(dist[i], evl);
    //     if (i>0) cout << dist[i] << " ";
    // }
    // debug(dist);
    // // maybe -> one last relaxation from whatever to [i] 
    // vl pf = dist;
    // vl sf = dist;
    // for (int i = 0; i < n; i++){
    //     pf[i] += X[i];
    //     sf[i] += X[i];
    // }
    // for (int i = 1; i < n; i++) pf[i] = max(pf[i], pf[i-1]);
    // for (int i = n-2; i>=0; i--) sf[i] = max(sf[i], sf[i+1]);
    // for (int i = 1; i < n; i++){
    //     ll mn = pf[i-1];
    //     if (i + 1 < n) mn = min(mn, sf[i+1]);
    //     ll ans = min(mn + y + X[i], dist[i]);
    //     cout << ans << " ";
    // }

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
