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
 
/*
Good problem

Lerning points: 
- knapsack was the right and obvious idea
- HAVE to optimise the dp size, n*k is too big for initialization
- instead the dp only requires the last row and we can use a matrix of 2*k for the dp 
*/
 
 
void solve(){
    ll n,x;
    cin >> n >> x;
    // Read input O(n)
    vector<vector<ll>> a(n,vector<ll>(2,0));
    for (int j=0;j<2;j++){
        for (int i=0;i<n;i++){
            cin >> a[i][j];
        }
    }

    vector<vector<ll>> dp(2,vector<ll>(x+1,0));
    int id = 0;
    int curr,last;
    for (int i=1;i<=n;i++){
        ll cost = a[id][0];
        ll pg = a[id][1];   
        id++;
        curr = i%2;
        last = 1-curr;     
        for (int j=0;j<=x;j++){ //for each cost
            dp[curr][j] = dp[last][j];
            if (j-cost>=0) dp[curr][j] = max(dp[curr][j],pg+dp[last][j-cost]);
        }
    }
    // printf("%lld \n",dp[n%2][x]);
    cout << dp[curr][x] << endl;
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
};
