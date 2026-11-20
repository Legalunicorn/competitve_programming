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
using vii = vector<vi>;


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


bool dfs(int u, vector<vector<int>>& g, vector<bool>& seen, vector<bool>& curr){
    if (curr[u]) return true;
    if (seen[u]) return false;
    curr[u] = seen[u] = true;
    for (int v:g[u]){
        if (dfs(v,g,seen,curr)) return true;
    }
    curr[u] = false;
    return false;
}

void topo(int u, vector<vector<int>>& g, vector<int>& order, vector<bool>& seen){
    seen[u] = true;
    for (int v: g[u]){
        if (!seen[v]) topo(v,g,order,seen);
    }
    order.pb(u);
}
void solve(){
    int n,m;
    cin >> n >> m;
    vector<vector<int>> g (n);
    while(m--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        g[a].pb(b); 
    }
    //1. detect cycles
    vector<bool> seen(n),curr(n);
    for (int i=0;i<n;i++){
        if (!seen[i]){
            if(dfs(i,g,seen,curr)){
                cout << "IMPOSSIBLE" << endl;
                return;
            }
        }
    }

    //2. topo sort
    seen = vector<bool>(n,false);
    vector<int> order;
    for (int i=0;i<n;i++){
        if (!seen[i]) topo(i,g,order,seen);
    }
    reverse(all(order));
    for (int o :order) cout << o+1 << " ";
    cout << endl;

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