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

void solve(){
    int n;
    cin >> n;
    vvi g(n);
    for (int i =0; i + 1 < n; i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vi par(n,-1);
    vi s(n);
    // max, sum 
    auto go = [&](auto& go, int u, int p) -> int{
        par[u] = p;
        int c = 1;
        for (auto& v: g[u]){
            if (v==p) continue;
            c += go(go, v, u);
        }
        return s[u] = c;
    };
    go(go,0,-1);
    int l = 0;
    for (int u = 0; u < n; u++){
        vi e;
        for (auto& v: g[u]){
            if (v == par[u]) continue;
            e.pb(s[v]);
        }
        sort(rall(e));
        if (u == 0){
            if (e.size()>=3) l = max(l, e[2]);
        } else{
            if (e.size()>=2) l = max(l, e[1]);
        }
    }
    cout << n- l << endl;


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
