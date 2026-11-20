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

// we can delete "k" edges
// k is only up to 5 
// i think we can solve this using layers 


struct node{
    ll w;
    int u,k;
    node(ll w, int u, int k): w(w), u(u), k(k){}
};

void solve(){
    int n,m,K;
    cin >> n >> m >> K;
    vector<vector<pair<int,ll>>> g(n);
    for (int i= 0; i < m; i++){
        int u, v , w;
        cin >> u >> v >> w;
        u --, v--;
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    debug(g);
    auto cmp = [](const auto& p, const auto& q) {
        return p.w > q.w;
    };
    priority_queue<node,vector<node>, decltype(cmp)> pq(cmp);
    vvl dist(n, vl(K+1, INF));
    //for (int i = 0; i <= K; i++) dist[0][i] = 0;
    dist[0][0] = 0LL;
    pq.push({0, 0, 0});
    while(!pq.empty()){
        node t = pq.top(); pq.pop();
        int u = t.u, k = t.k, w = t.w;
        debug(u,k,w);
        if (dist[u][k] < w) continue;
        for (auto& [v, d]: g[u]){
            ll d2 = dist[u][k] + d;
            if (d2 < dist[v][k]){
                dist[v][k] = d2;
                pq.push({d2, v, k});
            }
            if (k+1 < K + 1){
                if ( dist[u][k] <  dist[v][k+1]){
                    dist[v][k+1] = dist[u][k];
                    pq.push({dist[u][k], v, k+1});
                }
            }
        }
    }
    debug(dist);
    ll res = INF;
    for (int i = 0; i <= K; i++) res = min(res, dist[n-1][i]);
    
    //ll res = dist[n-1][K];
    if (res == INF) res = -1;
    cout << res << endl;
    // {distance, node, layer}


    // we just need to graph into layers
    // k transitions -> k + 1 layers

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
