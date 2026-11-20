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
    vl  w(n), v(n);
    for (auto& z:w) cin >> z;
    for (auto& z:v) cin >> z;
    Dsu dsu(n);
    for (int i = 0; i < m; i++){
        int x,y; cin >> x >> y;
        x --, y--;
        dsu.union_set(x, y);
    }
    // id to vector pos 
    map<int, vi> mp;
    for (int i = 0; i < n; i++){
        int p = dsu.find(i);
        mp[p].pb(i);
    }
    ll res = 0;
    for (auto& [id, ls]: mp){
        vl weight, price;
        for (auto& i: ls){
            weight.pb(w[i]);
            price.pb(v[i]);
        }
        sort(all(weight));
        sort(all(price));
        for (int i = 0; i < weight.size(); i ++ ){
            res += (weight[i] * price[i]);
        }
    }
    cout << res << endl;




    // swaps can be used any amoung of times 
    // this is basically a union 
    // so for each group within M we can just sort and get the best pairings 


    // initiaitally i -> i 
    // w -> weight 
    // v -> cost per weight 
    //
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
