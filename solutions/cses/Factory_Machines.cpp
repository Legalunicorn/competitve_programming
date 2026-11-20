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



bool check(vector<ll>& arr, ll m,ll t){
    ll cnt = 0;
    for (auto& a :arr){
        cnt += m/a;
        if (cnt>=t) return true;
    }
    return false;
    
}


void solve(){
    ll n,t;
    cin >> n >> t;
    vector<ll> arr(n,0);
    for (ll& v: arr) cin >> v;
    ll l=0, r = arr[0]*t;
    ll ans = r;
    while(l<=r){
        ll m = l+(r-l)/2;
        if (check(arr,m,t)){
            ans = m;
            r = m - 1;
        } else l = m + 1;
    }
    cout << ans << endl;
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