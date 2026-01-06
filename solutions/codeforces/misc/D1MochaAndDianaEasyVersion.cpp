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

void solve(){
    int n,m1,m2;
    cin >> n >> m1 >> m2;
    vvi g(n), f(n);
    Dsu d1(n), d2(n);
    for (int i=0;i<m1;i++){
        int u,v; 
        cin >> u >> v, u--,v--;
        d1.union_set(u, v);
        // g[u].pb(v);
        // g[v].pb(u);
    }
    for (int i=0;i<m2;i++){
        int u,v;
        cin >> u >> v,u--,v--;
        d2.union_set(u, v);
        // f[u].pb(v);
        // f[v].pb(u);
    }
    int res = 0;
    vpi edges;
    for (int i = 0; i<n;i++){
        for (int j = i+1;j<n;j++){
            // check that both i,j are disjoint in both dsu 
            if (d1.find(i) == d1.find(j)) continue;
            if (d2.find(i) == d2.find(j)) continue;
            debug(i,j);
            res++;
            edges.pb({i+1,j+1});
            d1.union_set(i, j);
            d2.union_set(i, j);
        }
    }
    cout << res << endl;
    for (auto& x: edges) cout << x.F << " " << x.S << endl;

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
