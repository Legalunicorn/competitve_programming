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



void solve(){
    ll n;
    cin >> n;
    vector<string> a(n);
    for (string& x: a) cin >> x;
    
    if (a[n-1][n-1]=='*') {
        cout << 0 << endl;
        return;
    }
    vector<vector<ll>> dp (n,vector<ll>(n,0));
    dp[n-1][n-1] = 1; //
    for (int i=n-1;i>=0;i--){
        for (int j=n-1;j>=0;--j){
            if (a[i][j]=='*') continue;
            if (i+1<n && a[i+1][j]!='*') dp[i][j] += (dp[i+1][j])%MOD;
            if (j+1<n && a[i][j+1]!='*') dp[i][j] += (dp[i][j+1])%MOD;
        }
    }
    cout << dp[0][0]%MOD << endl;

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