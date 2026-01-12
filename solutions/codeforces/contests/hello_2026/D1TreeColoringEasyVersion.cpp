#include <bits/stdc++.h>
#include <memory>
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

// optimal to tak
// the no edge thing is massive 
// 1 node -> 10 children 
// when the parent is take 


void solve(){
    int n;
    cin >> n;
    vvi g(n);
    vi depth(n,0);
    for (int i=0;i<n-1;i++){
        int u,v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }

    int mxd = 0, mxrow = 1;
    int ans = 0;
    auto dfs = [&](auto& dfs, int u, int p, int d)->void{
        depth[d]++;
        int st = 1;
        mxd = max(mxd, d);
        for (int v:g[u]){
            if (v==p) continue;
            st++;
            dfs(dfs,v,u,d+1);
        }
        ans = max(ans,st);
    };

    dfs(dfs,0,-1,0);
    debug(depth);
    for (int i=0;i<=mxd;i++){
        mxrow = max(mxrow,depth[i]);
    }
    int res = max(mxrow, ans);



    cout << res << endl;
    // vi odd,even;
    // for (int i=0;i<=mxd;i++){
    //     if (i%2==0) odd.pb(depth[i]);
    //     else even.pb(depth[i]);
    // }
    // debug(depth);
    // debug(odd);
    // debug(even);
    // cerr << endl;
    // int x = MAX(odd);
    // int y = MAX(even);
    // cout << x+y << endl;
};

// we can only select white notes 
// we cant selct parents 
// why not select alternatie nodes 
// 1. we can only select 1 node per depth, and non must be connected 
//
//

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
