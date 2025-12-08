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
using vb = vector<bool>;


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

#define debug_vec(vec) cerr << #vec << " = ["; for (size_t i = 0; i < (vec).size(); ++i) { cerr << (vec)[i]; if (i + 1 < (vec).size()) cerr << ", "; } cerr << "]\n";
#define debug_mat(mat) do { cerr << #mat << " = [\n"; for (size_t i = 0; i < (mat).size(); ++i) { cerr << "  ["; for (size_t j = 0; j < (mat)[i].size(); ++j) { cerr << (mat)[i][j]; if (j + 1 < (mat)[i].size()) cerr << ", "; } cerr << "]\n"; } cerr << "]\n"; } while (0)


void dfs(int u,vvi& g, vb& vis, vi& out){
    vis[u] = true;
    for (int v:g[u]){
        if (vis[v]) continue;
        dfs(v,g,vis,out);
    }
    out.pb(u);
}

void solve(){
    int n,m;
    cin >> n >>m; 
    vvi g(n),gi(n);
    
    
    for (int i=0;i<m;i++){
        int a,b;
        cin >> a >> b;
        a--;b--;
        g[a].pb(b);
    }
    //inverse graph
    for (int u=0;u<n;u++){
        for (int v:g[u]){
            gi[v].pb(u);
        }
    }
    
    //get the initial order
    vb vis(n,false);
    vi order;
    for (int i=0;i<n;i++){
        if (!vis[i]){
            dfs(i,g,vis,order);
        }
    }
    // debug_vec(order);
    reverse(all(order)); //get the right order
    // debug_vec(order);
    vis.assign(n,false);
    vi kindoms(n);
    int k = 1;
    for (int u: order){
        vi scc;
        if (!vis[u]){
            cerr << u << endl;
            dfs(u,gi,vis,scc);
            for (int v:scc){
                kindoms[v] = k;
            }
            k++;
        }
    }
    cout << k-1 << endl;
    for (int i=0;i<n;i++){
        cout << kindoms[i] << " ";
    }
    cout << endl;
    // we traverse using he inverse graph 





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