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

// root the tree at 1 
// we need to know if there are dups, how? 
// i think we can use a set to dfs 
// then we just mark yet or no 

// as long as any exist 
// well just know that if one size exist we all win
// map< size, count> 


void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    debug(a);
    vvi g(n);
    for (int i = 0; i + 1 < n; i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    debug(g);

    map<int ,int> mp;
    map<int,int> sz;
    sz[0] = n;
    vb res(n);
    bool more = false;

    auto dfs = [&](auto& dfs, int u, int p) -> void {
        int t  = a[u];
        mp[t]++;
        // add to size 
        int val = mp[t];
        sz[val]++;
        sz[val-1]--;
        if (sz[val-1] == 0) sz.erase(val-1);
        auto it = sz.rbegin();
        debug(u, sz, it ->F, it ->S);

        if (it->F > 1) {
            res[u] = true;
        }

        for (int v: g[u]){
            if (v == p) continue;
            dfs(dfs, v, u);
        }
        mp[t]--;
        val = mp[t];
        sz[val]++;
        sz[val+1]--;
        if (sz[val+1] == 0) sz.erase(val+1);

        
    };
    dfs(dfs,0,-1);

    for (int i = 0; i < n; i++){
        cout << (res[i] ? "Yes":"No") << endl;
    }

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
