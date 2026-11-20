#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;
 
//template 
// distinct - pbds 
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// 
template <class T> using ordered_multiset = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;
 

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
    set<pi> ss;
    Dsu dall(n);
    for (int i = 0; i < m; i++){
        int u,v; cin >> u >> v;
        u--,v--;
        if (u == v) continue;
        if (ss.count({u,v})) continue;
        else ss.insert({u,v});
        dall.union_set(u,v);
        g[u].pb(v);
 
    }

    ordered_set<int> st;
    map<int,int> mp; // DSU ID -> seen so far 
    Dsu dsu(n);

    set<int> missing;

    for (int i = 0; i < n; i++){
        int base = dsu.find(0);
        int q = dsu.find(i);
        int xx = dall.find(0);
        int yy = dall.find(i); bool pass = true;

        if (base != q || xx != yy ) {
            pass = false;
            cout << -1 << endl;
            continue;
        }

        st.insert(i);
        for (int v: g[i]){
            // v is not connected to our graph! 
            st.insert(v);
        }

        int pos = st.order_of_key(i+1);
        int res = st.size() - pos;
        if (pass) cout << res << endl;
        else cout << -1 << endl;

        if (!pass) continue;
        for (int v: g[i]){
            dsu.union_set(v,i);
        }
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
