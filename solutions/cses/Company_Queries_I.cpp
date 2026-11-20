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


vector<vector<int>> g,up;
vector<int> depth;
int LOG;


void solve(){
    int n,q; 
    cin >> n >> q;
    while((1<<LOG)<=n) LOG++;
    up = vector<vector<int>>(n,vector<int>(LOG));
    depth = vector<int>(n);
    vector<int> parent (n);
    parent[0] = 0;
    for (int i=0;i<n-1;i++){
        int x;
        cin >> x;
        parent[i+1] = x-1; // their boss
    }
    //build the table 
    for (int v=0;v<n;v++){
        up[v][0] = parent[v];
        if (v!=0) depth[v] = depth[parent[v]]+1;
    }
    for (int j=1;j<LOG;j++){
        for (int v=0;v<n;v++){
            up[v][j] = up[up[v][j-1]][j-1];
        }
    }

    while(q--){
        int u,k;
        cin >> u >> k;
        u--;

        if (depth[u]<k) {
            cout << -1 << endl;
            continue;
        }
        for (int j=0;j<LOG;j++){
            if ((k>>j)&1) u = up[u][j];
        }
        cout << u+1 << endl;




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