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
// if the ROOT is a damn, we only know if the beaver went there if he did not go to any other damn
//
// 1. if a subtree only has ONE DAMN, we just need one camera 
// 2. if a subtree has multiple dams, i GUESS, the bea

void solve(){
    int n;
    cin >> n;   
    vvi g(n);
    for (int i = 1; i < n; i ++){
        int p;
        cin >> p;
        p--;
        g[i].pb(p);
        g[p].pb(i);
    }
    int m;
    cin >> m;
    set<int> dam;
    // im pretty sure
    // you just add for ALL damns 
    // except for any damn in the hightlest level? 
    //
    for (int i = 0; i < m; i++){
        int x; cin >> x;
        dam.insert(x);
    }
    debug(dam);
    vector<pi> a;
    auto dfs = [&](auto& dfs, int u, int p, int h) -> void{
        if (dam.count(u+1)) a.pb({h, u});
        for (int v: g[u]){
            if (v == p) continue;
            dfs(dfs, v, u, h+1);
        }
    };
    dfs(dfs,0,-1,0);
    sort(all(a));
    reverse(all(a));
    vi res;
    for (int i = 0; i + 1 < a.size(); i++){
        res.pb(a[i].S + 1);
    }
    cout << res.size() << " ";
    for (auto& z: res) cout << z << " ";
    cout << endl;
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
