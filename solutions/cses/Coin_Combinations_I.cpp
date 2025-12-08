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



// ll go(int left, vector<int>& coins,vector<ll>& dp){
//     if (left<0) return 0;
//     if (left==0) return 1;
//     if (dp[left]!=-1) return dp[left];
//     ll res = 0;
//     for (int c: coins){
//         // if (left-c>=0){
//             res += (go(left-c,coins,dp))%MOD;
//         // } else break;
//     }
//     return dp[left] = res%MOD;

// };

void solve(){
    int n,x;
    cin >> n >> x;
    vector<int> coins(n,0);
    for (int i=0;i<n;i++) cin >> coins[i];
    vector<ll> dp (x+1);
    dp[0]= 1;
    for (int i=1;i<=x;i++){
        for (int c: coins){
            if (i-c>=0) dp[i] = (dp[i]+dp[i-c])%MOD;
        }
    }
    cout << dp[x] << endl;
    // ll res = go(x,coins,dp);
    // cout << res << endl;
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