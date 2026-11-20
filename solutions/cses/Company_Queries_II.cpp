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


vector<vector<int>> up;
vector<int> depth,parent;
int LOG;

int lca(int a, int b){
    if (depth[a]<depth[b]) swap(a,b);
    int k = depth[a]-depth[b];
    for (int j=LOG-1;j>=0;j--){
        if ((k>>j)&1) a = up[a][j];
    }
    if (a==b) return a;
    for (int j=LOG-1;j>=0;j--){
        if (up[a][j]!=up[b][j]){
            a = up[a][j];
            b = up[b][j];
        }
    }
    return up[a][0];
}

void solve(){
    int n,q;
    cin >> n >> q;
    while ((1<<LOG)<=n) LOG++;
    parent = vector<int>(n,0);
    depth = vector<int>(n,0);
    up = vector<vector<int>>(n,vector<int>(LOG,0));
    for (int i=0;i<n-1;i++){
        int boss;
        cin >> boss;
        parent[i+1] = boss-1;
    }

    //build table 
    for (int v=0;v<n;v++){
        up[v][0] = parent[v];
        if (v!=0) depth[v] = depth[parent[v]]+1;
    }
    // cerr << 2 << endl;
    for (int j=1;j<LOG;j++){
        for (int i=0;i<n;i++){
            up[i][j] = up[up[i][j-1]][j-1];
        }
    }
    while(q--){
        int a,b;
        cin >> a >> b;
        a--;
        b--;
        int ans = lca(a,b);
        cout << ans+1 << endl;
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