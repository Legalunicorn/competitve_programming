#include <bits/stdc++.h>
#include <queue>
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

void solve(){
    int n,m;
    cin >> n >> m;
    vvpl g(n);
    for (int i = 0; i < m; i++){
        ll u,v, w;
        cin >> u >> v >> w;
        w *= 2;
        u--, v--;
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    vl dist(n);
    for (auto& z: dist) cin >> z;
    priority_queue<pl, vpl, greater<pl>> pq;
    for (int i = 0; i < n;i++) pq.push({dist[i], i});
    while(!pq.empty()){
        auto t= pq.top(); pq.pop();
        ll u = t.S, w = t.F;
        if (dist[u] < w) continue;
        for (auto& [v, p]: g[u]){
            ll w2 = dist[u]+p;
            if (w2 < dist[v]){
                dist[v] = w2;
                pq.push({w2, v});
            }
        }
    }
    for (int i = 0; i < n; i++) cout << dist[i] << " ";


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
