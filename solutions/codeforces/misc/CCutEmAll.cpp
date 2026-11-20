#include <bits/stdc++.h>
#include <csetjmp>
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
    int n;
    cin >> n;
    vvi g(n);
    for (int i=0;i<n-1;i++){
        int u,v; cin >> u >> v;
        v--,u--;
        g[u].pb(v);
        g[v].pb(u);
    }
    if (n%2==1) {
        cout << -1 << endl;
        return;
    }

    int res = 0; 
    auto dfs = [&](auto& dfs, int u, int p) -> int{
        int sz = 1;
        for (int v:g[u]){
            if (v==p) continue;
            sz += dfs(dfs,v,u);
        }
        if (sz%2==0) {
            sz = 0;
            res++;
        }
        debug(u+1,sz);
        return sz;
    };
    dfs(dfs,0,-1);
    cout << res-1 << endl;
    // 6 = 3 + 3 
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
