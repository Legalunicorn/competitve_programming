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
    int n,m,k;
    cin >> n >> m >> k;
    vi gov(k);
    vi sizes;
    for (int i=0;i<k;i++){
        int x; cin >> x;
        gov[i] = x-1;
    }
    vvi g(n);
    for (int i =0;i<m;i++){
        int u,v;
        cin >> u >> v, u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vb seen(n, false);
    vb comp;

    auto dfs = [&](auto& dfs, int u) -> int {
        seen[u] = true;
        int sz =1;
        for (int v:g[u]){
            if (seen[v]) continue;
            sz += dfs(dfs,v);
        }
        return sz;
    };
    int left = n;
    for (int i=0;i<k;i++){
        int s = dfs(dfs,gov[i]);
        sizes.pb(s);
        left -= s;

    }
    sort(sizes.rbegin(),sizes.rend());
    sizes[0] += left;
    // calculate totla edges 
    ll mxe = 0;
    for (auto& s: sizes){
        ll v = (ll)s * (s-1) / 2;
        mxe += v;
    }
    cout << mxe - m << endl;
};


// each connected component has 1 K max 
// for each connected component, the complete graph has n * n -1  / 2 edges max 
// for nodes without government, just throw them all into the componenet with the largest government 
// 1. for every k node, do a dfs 
// -> get the count of nodes
// -> sort them in
// 
// 1. we just need to know max edge to add 
// 2. we can calc total max edges - number of edges given 
//
// 3. for all unvisible nodes, throw them in the largest size 
// 4. for all sizes

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
