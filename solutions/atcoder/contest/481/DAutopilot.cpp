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


vector<ll> dijkstra(vector<vector<pair<ll,ll>>> &g, int s){
    using pll = pair<ll,ll>;
    ll inf  = (ll)4e18;
    int n = g.size();
    vector<ll> dist(n, inf);
    dist[s] = 0;
    priority_queue<pair<ll,ll>,vector<pair<ll,ll>>, greater<pair<ll,ll>>> pq;
    pq.push({0ll,s});
    while(!pq.empty()){
        auto [w, u] = pq.top();
        pq.pop();
        if (dist[u] < w) continue;
        debug(u,w);
        for (auto [v, e]: g[u]){
            ll wt = w+e;
            if (wt < dist[v]){
                dist[v] = wt;
                pq.push({wt,v});
                debug(v,e);
            }
        }
        // cerr << endl;
    }
    return dist;
};


void solve(){
    ll n,m,s,t;
    cin >> n >> m >> s >> t;
    s--, t--;
    vvpl g(n);
    for (int i = 0; i < m;i++){
        ll u,v;
        cin >> u >> v;
        u--,v--;
        g[u].pb({v,1ll});
    }
    debug(g);
    for (int i = 0; i < n; i++){
        if (g[i].size()==0) continue;
        ll mn = n+5;
        for (auto& [id,w]: g[i]){
            mn = min(mn,id);
        }
        for (auto& [id, w]: g[i]){
            if (id==mn) w = 0;
        }
    }
    debug(g);

    vl res = dijkstra(g, s);
    ll ans = res[t];
    if (ans > n) ans = -1;
    cout << ans << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}
