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


// int dfs(int u, vector<vector<int>>& g, vector<int>& subs){
//     int res = 1; //just minus one later
//     for (int v: g[u]){
//         res += dfs(v,g,subs);
//     }
//     subs[u] = res-1;
//     return res;
    
// }

void solve(){
    int n;
    cin >> n;

    vector<vector<int>> g(n); 
    vector<int> subs(n,0);
    for (int i=1;i<n;i++){
        int x;
        cin >> x;
        x--;
        g[x].pb(i); 
    }
    function<int(int)> dfs = [&](int u)->int{
        int res = 1;
        for (int v:g[u]){
            res += dfs(v);
        }
        subs[u] = res-1;
        return res;
    };
    dfs(0);
    for (int x: subs){
        cout << x << " " ;
    }
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