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


struct Dsu{
public:
    int n; 
    vector<int> par, size;
// public:
    Dsu(int sz){
        n = sz;
        size.assign(n,1);
        par.assign(n,0);
        iota(par.begin(),par.end(),0);
    }

    int find(int v){
        if (v == par[v]) return v;
        return par[v] = find(par[v]);
    }

    void union_set(int a, int b){
        a = find(a);
        b = find(b);
        if (a != b){
            if (size[a] < size[b]) swap(a,b);
            par[b] = a;
            size [a] += size[b];
        }
    }
};

ll binpowmod(ll a, ll b, ll m){
    a %= m;
    ll res = 1;
    while(b > 0){
        if (b & 1) res = res * a % m;
        a = a  * a % m;
        b >>=1;
    }
    return res;
}

void solve(){
    int n,m;
    ll mod = 998244353;
    cin >> n >> m;
    vvi e(m);
    Dsu dsu(n);
    vvpi g(n);
    for (int i = 0; i < m; i++){
        int u,v;
        cin >> u >> v;
        u--, v--;
        if (dsu.find(u) != dsu.find(v)){
            g[u].pb({v, i});
            g[v].pb({u, i});
            dsu.union_set(u, v);
        }
        // e.pb({i,u,v});
    }
    vl res(n,-1);
    auto go = [&](auto& go, int u, int p, ll d) -> void{
        if (u!=0) res[u]=d;
        for (auto& [v,e]: g[u]){
            if (v ==p) continue;
            ll po = binpowmod(2ll, ll(e), mod);
            go(go, v, u, (d+po) % mod);
        }
    };
    go(go, 0, -1, 0ll);
    for (int i = 1; i < n; i++) cout << res[i] << " ";
    cout << endl;

    // MST 
    // sort(all(e)); // lol its already sorted
    for (int i = 0; i < m; i++){

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
