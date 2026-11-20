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


// NOTE:
// very interesting that its 
// undirected
// can we try like graph coloiring? maybe if its mixed with some other claim 
// i realised 
// NOTE: if there is Odd cycle we CANT color the graph
// but this is necesary not sure if its sufficient 
// i can just guess tyhat its sufficient
// even so how do we find the cycke 
// 1. bipartite coloriing 
// 2. if a node CANNOT be color 
//  - it must be inside the odd length cycle? maybe not true 
//
// binpartrite coloring 
// if canot color there is odd length cycel
// but how to find said cyucle? 
// 1. we know it edxist 
// 2. it has the shape R B R B B 
// actually we can just trace back can we?> 
//

void solve(){
    int n,m;
    cin >> n >> m;
    // vvi g(n);
    vvi g(n);
    for(int i = 0; i < m; i++){
        int u ,v;
        cin >> u >> v;
        u--, v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi parent(n, -1);
    vi color(n, -1);
    color[0] = 0;
    int start = -1;
    bool isbi = true;
    bool done = false;
    vi res;
    auto dfs = [&](auto& dfs, int u) -> void {
        for (int v: g[u]){
            if (v  == parent[u]) continue;
            if (done) return;
            if (color[v] == -1){ // not assigned
                color[v] = 1 - color[u];
                parent[v] = u;
                dfs(dfs,v);
            } else if (color[v] == color[u]) {
                done = true;
                for (int z = u; z != v; z = parent[z]) res.pb(z);
                res.pb(v);
                return;
            }
        }
    };

    dfs(dfs, 0);
    if (!done) cout << -1 << endl;
    else {
        cout << res.size() << endl;
        for (auto& r: res) cout << r+1<< " ";
        cout << endl;
    }
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
