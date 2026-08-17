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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

// sum of diameters of all forest
//

int diameter(vvi& g){
    // dfs to any furtherst node
    // dfs to the next futurest node 

    debug(g);
    int n = g.size();
    vi depth(n,0);
    int mxd = 0;
    int id  = 0;
    auto dfs = [&](auto& dfs, int u, int p, int d) -> void{

        debug(u,p,d);
        depth[u] = d;
        if (d > mxd){
            mxd = d;
            id = u;
        }
        for (int v:g[u]){
            if (v == p) continue;
            dfs(dfs,v,u,d+1);
        }
    };
    dfs(dfs, 0, -1, 0);
    debug(depth);
    debug(id);

    // now find the path depth 
    int res = 0;
    auto go  = [&](auto& go, int u, int p, int d) -> void{
        res = max(res,d);
        for (int v:g[u]){
            if (v == p) continue;
            go(go,v,u,d+1);
        }
    };
    go(go,id,-1,0);
    debug(id);
    debug(res);
    return res;
}

void solve(){
    int n;
    cin >> n;
    int res = 0;
    for (int i =0; i < n; i++){
        int sz; cin >> sz;
        vvi g(sz);
        for (int i =0; i +1 < sz; i++){
            int u,v;
            cin >> u >> v;
            u--, v--;
            g[u].pb(v);
            g[v].pb(u);

        }
        res += diameter(g);
    }
    cout << res << endl;

    

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
