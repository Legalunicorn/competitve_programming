#include <bits/stdc++.h>1 4

#include <chrono>
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


//This part should be okay 
struct Fenwick{
    ll n;
    vl BIT;
    Fenwick(ll s): n(s),BIT(s+1,0){};
    void update(ll i, ll delta){
        for (;i<=n;i+= i&-i) BIT[i] += delta;
    }
    ll query(ll i){
        ll sum = 0;
        for (;i>0;i-= i&-i) sum += BIT[i];
        return sum;
    }
};

struct Tree{
    ll n,root,timer;
    vl tin,tout,par,weight;
    vvi g;
    vl dist;

    Tree(ll _n){
        n = _n+1;
        timer = 0;
        root = 1;
        tin.resize(n);
        tout.resize(n);
        par.resize(n);
        dist.resize(n);
        g.resize(n);
        weight.resize(n);
    }

    void addEdge(ll u, ll v){
        g[u].pb(v);
        g[v].pb(u);
    }

    void dfs(ll u, ll p, ll curr){
        curr += weight[u];
        dist[u] = curr;
        par[u] = p; //we don't need this i think 
        tin[u] = ++timer;
        for (ll v: g[u]){
            if (v==p) continue;
            dfs(v,u,curr);
        }
        tout[u] =  timer;
    }

    void init(ll rt=1){
        root = rt;
        dfs(root,-1,0L);
    }
};


void solve(){
    ll n,q;
    cin >> n >> q;
    Tree tree(n);
    for (ll i=0;i<n;i++){
        ll x; cin >> x;
        tree.weight[i+1]=x;
    }
    for (ll i=0;i<n-1;i++){
        ll a,b;
        cin >> a >> b;
        tree.addEdge(a,b);
    }
    tree.init();
      

    Fenwick fw(tree.timer+1); //
    while(q--){
        ll z,s;
        cin >> z >> s;
        if (z==1){
            ll x; cin >> x;
            ll oldVal = tree.weight[s];
            ll delta = x-oldVal;

            fw.update(tree.tin[s],delta);
            fw.update(tree.tout[s]+1,-delta);
            tree.weight[s] = x;

        } else{
            ll ans = tree.dist[s] + fw.query(tree.tin[s]); //fw stores the delta
            cout << ans << endl;
            
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