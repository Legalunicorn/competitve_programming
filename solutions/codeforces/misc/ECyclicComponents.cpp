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
    int n,m;
    cin >> n >> m;
    vvi g(n);
    for (int i=0;i<m;i++){
        int u,v;
        cin >> u >> v, u--,v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    // actuall ddsu not needed but whatever 
    // dfs -> return size of graph and ALL edge act 2 

    vb seen(n, false);
    bool two = true;
    int sum = 0;
    auto dfs = [&](auto& dfs, int u) -> int {
        seen[u] = true;
        int sz = 1;
        for (int v:g[u]){
            if (g[u].size()!=2) two = false;
            if (seen[v]) continue;
            sz += dfs(dfs,v);
        }
        return sz;
    };
    int res = 0;
    for (int i=0;i<n;i++){
        if (!seen[i]){
            two = true;
            if (g[i].size()!=2) two = false;
            dfs(dfs,i);
            if (two) res++;
            if (two) debug(i+1);
        }
    }
    
    cout << res << endl;


};

// there are n edges in component of size n 
// each node has exacty degree of 2 



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
