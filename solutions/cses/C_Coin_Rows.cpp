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
    int n;
    cin >> n;
    vector<ll> pref(n,0), suff(n,0);
    for (int i=0;i<n;i++){
        ll x;
        cin >> x;
        if (i==0) pref[i] = x;
        else pref[i] = pref[i-1]+x;
    }
    // for (int i=n-1;i>=0;i--){
    //     ll x; 
    //     cin >> x;
    //     if (i==n-1) suff[i] = x;
    //     else suff[i] = suff[i+1] +x;
    // }
    for (int i=0;i<n;i++){
        ll x; cin >> x;
        suff[i] = x;
    }
    for (int i=n-2;i>=0;i--){
        suff[i] += suff[i+1];
    }
    if (n==1) {
        cout << 0 << endl;
        return;
    }
    // for (int x: pref) cerr << x << " ";
    // cerr << endl;
    // for (int x: suff) cerr << x << " ";
    // cerr << endl;    
    ll res = INF;
    for (int i=0;i<n;i++){
        if (i==0) res = min(res,pref[n-1]-pref[i]);
        else if (i==n-1) res = min(res,suff[0]-suff[n-1]);
        else{
            ll v = max(pref[n-1]-pref[i],suff[0]-suff[i]);
            res = min(res,v);
        }
        // cerr << "A: " << res << endl;
    }
    cout << res << endl;


};
/*
you can only go down on one square
-> prefix sum first row
-> suffic sum second row

no matter where alice cuts, bob either go down immediately, or go down at the n

depending on what alice picks
1. her sum is prefix[i] + suffix[i]
2. bobs options are suffix[i+1] or prefix[i-1] //this should be minimised
*/


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T =1;
    cin >> T; 
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}