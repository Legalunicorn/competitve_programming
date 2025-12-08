#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

//template 
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;

template <class T> using ordered_multiset = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

//alias 
using ll = long long;
using ull = unsigned long long; 
using ld = double; 
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vll = vector<vl>;
using pi = pair<int,int>;
using vvpi = vector<vector<pi>>;


// constants 
constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9+7;
constexpr double PI = 3.14159265358979323846;

// macros
#define endl '\n' 
#define F first
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MP make_pair
// #define M_PI 3.14159265358979323846



struct Fenwick{
    ll n;
    vector<ll> BIT;
    Fenwick(ll s){
        n = s;
        BIT.assign(n+1,0);
    }
    
    void update(ll id, ll delta){
        for (;id<=n;id += id&-id) BIT[id]+=delta;
    }
    ll query(ll id){
        ll sum =0;
        for (;id;id -= id&-id) sum += BIT[id];
        return sum;
    }
    ll query(ll l,ll r){
        return query(r)-query(l-1);
    }
};

struct Tree{
    ll timer,n,root;
    vl tin,tout;
    vl treesum,val;
    vector<vector<ll>> g;

    Tree(ll s){
        n = s+1;
        timer = 0; 
        root = 1;
        tin.resize(n);
        tout.resize(n);
        treesum.resize(n);
        val.resize(n);
        g.resize(n);
    }
    void addEdge(ll u, ll v){
        g[u].pb(v);
        g[v].pb(u);
    }
    ll dfs(ll u, ll p){
        ll total = val[u];
        tin[u] = ++timer;
        for (ll v: g[u]){
            if (v==p) continue;
            total += dfs(v,u);
        }
        treesum[u] = total;
        tout[u] = timer;
        return total;
    }

    void init(ll rt=1){
        root = rt;
        dfs(root,-1);
    }

};


void solve(){
    ll n,q;
    cin >> n >> q;
    Tree tree(n);
    for (ll i=0;i<n;i++){
        ll x; cin >> x;
        tree.val[i+1] = x;
    }
    for (ll i=0;i<n-1;i++){
        ll a,b;
        cin >> a >> b;
        tree.addEdge(a,b);
    }
    tree.init();
    Fenwick fw(tree.timer);
    while(q--){
        ll z; cin >> z;
        if (z==1){
            ll s,x;
            cin >> s >> x;
            ll old = tree.val[s];
            ll delta = x-old;
            fw.update(tree.tin[s],delta);
            tree.val[s] = x;

        } else{
            ll s; cin >> s;
            ll changes = fw.query(tree.tin[s],tree.tout[s]);
            ll res = tree.treesum[s] + changes;
            cout << res << endl;
        }
    }
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T =1;
    // cin >> T; 
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}