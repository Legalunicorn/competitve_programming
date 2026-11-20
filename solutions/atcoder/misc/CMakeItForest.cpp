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

void solve(){

    int n,m;
    cin >> n >> m;
    vvi g(n);
    for (int i=0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    // 1. count number of edges of each connecred component 
    // the max allowed eges is n - 1 
    ll res = 0;
    vb seen(n,false);
    ll edges = 0;
    int nodes = 0;
    auto dfs = [&](auto& dfs, int u) -> void{
        nodes++;
        seen[u] = true;
        edges += g[u].size();
        for (int v:g[u]){
            if (seen[v]) continue;
            dfs(dfs,v);
        }
    };
    for (int i =0;i<n;i++){
        if (!seen[i]){
            edges = 0;
            nodes = 0;
            dfs(dfs,i);
            edges/=2;
            debug(nodes,edges);
            ll mx = nodes -1;
            res += (edges - mx);
        }
    }
    cout << res << endl;
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
