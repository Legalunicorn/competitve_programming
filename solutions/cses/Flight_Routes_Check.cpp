#include <bits/stdc++.h>
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



void dfs(int u, vvi& g, vector<bool>& vis, vi& out){
    vis[u] = true;
    for (int v:g[u]){
        if (vis[v]) continue;
        dfs(v,g,vis,out);
    }
    out.pb(u);

}
void solve(){
    int n,m;
    cin >> n >> m;
    vvi g(n);
    vi order;
    vector<bool> vis (n,false);
    for (int i=0;i<m;i++){
        //read the edges
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].pb(b);
    }
    for (int i=0;i<n;i++){
        if (!vis[i]){
            dfs(i,g,vis,order);
        }
    }
    // reverse the 
    vvi gp(n);
    for (int u=0;u<n;u++){
        for (int v:g[u]){
            gp[v].pb(u);
        }
    }
    vis.assign(n,false);
    reverse(all(order));
    // vi roots(n,0);

    //now we do a revesse dfs
    // vvi comps;
    vi roots;
    for (int u : order){ //we go in order 
        if (!vis[u]){
            vi scc;
            dfs(u,gp,vis,scc);
            // comps.pb(scc);
            int root = *min_element(all(scc));
            roots.pb(root); //we just need the root 
            //idt this is needed
            // for (int v: scc){
            //     roots[v] = root;
            // }
        }
    }
    //we dont need the condensation graph 
    if (roots.size()==1){
        cout << "YES" << endl;
    } else{
        cout << "NO" << endl;
        cout << roots[1]+1 << " " << roots[0]+1 << endl;
    }

 
};
/*
i dont think i need to do the whole alorithm? 
? 

i just do a single dfs and reach everythign
just find the number of connected components
if its more than 1 print no

also m must be at least n 

print the root of the connected componnents 
*/


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