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
    ll n,x;
    cin >> n >> x;
    vector<ll> arr(n,0);
    for (ll& a:arr) cin >> a;

    for (int i=1;i<n;i++){
        arr[i]+=arr[i-1];
    }
    map<ll,ll> freq;
    for (int i=0;i<n;i++){
        freq[arr[i]]++;
    }
    // for (ll& v : arr) cout << v << " " ;
    cout << endl;
    ll res = freq[x];
    for (int i=0;i<n;i++){
        freq[arr[i]]--;
        ll op = x+arr[i];
        res += freq[op];
    }
    cout << res << endl;


};

/*
read a solutions page.
hints: using prefix sum and map

prefix sum alone would work if there are no negative values.
-> the idea is that there is only a range of points that leads to sum x
-> we can binary search for the min and max position and += the range

with negative values the prefix sum values can go up and down 

can we use a merge sort or some shit? 
prefix sum [r] - prefix sum[l] means a subarray sum from arr[l..r]

since the order is messed up due to negative values, what if we simply sorted it ? and perform a binary search ? 
if we traverse from left to right and we have the sorted values, we can remove each element as we process? 

pbds? 
->

no not really

given prefix[i], let v =  x-prefix[i] 

prefix[i+1:end]
1. what if we using a counting sort with a map? 




how does introducing a map help? 



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