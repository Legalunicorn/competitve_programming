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

void solve(int n){
    int m;
    cin >> m;
    debug(n,m);
    using node = pair<ld, int>;
    vector<vector<node>> g(n);
    for (int i = 0; i < m; i++){
        int u,v;
        ld r;
        cin >> u >> v >> r;
        ld e = -log(r);
        debug(u,v,e);
        g[u].pb({e,v});
        g[v].pb({e,u});
    }
    debug(g);
    priority_queue<node, vector<node>, greater<node>> pq;
    vector<ld> dist(n, INF);
    vector<node> trace(n, {0.0,-1});
    dist[0] = 0.0;
    pq.push({0.0, 0});
    while(!pq.empty()){
        auto [wt, u] = pq.top();
        pq.pop();
        if (wt > dist[u]) continue;
        for (auto& [w, v]: g[u]){
            ld d2 = dist[u] + w;
            if (d2 < dist[v]){
                dist[v] = d2;
                pq.push({d2, v});
                //trace[v] = {};
            }
        }
    }

    ld res = exp(-dist[n-1]);
    printf("%.4lf\n", res);
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(cin >> T && T !=0){
        solve(T);
    }
    cerr << " == END ==" << endl;
    return 0;
}
