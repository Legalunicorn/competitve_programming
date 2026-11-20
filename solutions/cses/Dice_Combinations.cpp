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


// constants 

constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9+7;

// macros
#define endl '\n' 
#define F first
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MP make_pair


void solve(){
    int n;
    cin >> n; 
    vector<long> dp(n+1,0);
    dp[0] = 1; // empty set is the only way to get 1
    for (int i=1;i<=n;i++){
        for (int j=1;j<=6;j++){
            if (i-j>=0) dp[i] += dp[i-j];
            dp[i]%=MOD;
        }
    }
    cout << dp[n] << endl;
    /*
    1 1 1 1
    1 1 2
    1 2 1
    2 1 1
    2 2
    1 3
    3 1
    4 

    dp[1] = 1
    dp[2] 
        += d[1] 
        += d[0]
        = 2
    d[3] 
        += d[2]
        += d[1]
        += d[0]
        = 
    // x ways to form 1 + D1
    // y ways to form 0 + D2
    dp[3] += dp[1]+1  +=dp[2]=2 = 
    */
};

/*

if there are x ways to get v

5 ways to get "6" now how ways are there to get "8" using 2?

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