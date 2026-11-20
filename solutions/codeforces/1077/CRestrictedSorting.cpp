#include <bits/stdc++.h>
#include <iomanip>
using namespace std;
using ll = long long; using ull = unsigned long long;using ld = double; 
using vi = vector<int>; using vvi = vector<vi>;
using vl = vector<ll>; using vvl = vector<vl>;
using pl = pair<ll,ll>; using vpl = vector<pl>; using vvpl = vector<vpl>;
using pi = pair<int,int>; using vpi = vector<pi>;using vvpi = vector<vpi>;
using vb = vector<bool>; using vvb = vector<vb>;

#if defined(LOCAL) && __has_include("debug.h")
#include "debug.h"
#else
#define debug(...)
#endif

#define endl '\n' 
#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// let f return true of false given k 
// f is monotific 
// we can binary search over k 
// if f(k) is possible ->  f(k-1) is possible 
//
// -> actually this is a connected componet? 
// (1,2)   (5,6,7) 
// we can swap between groups but not within 
// we can still permutate everything, as long as 
// this can be done with DSU 

// psedocode 
// binary search over "k", if possible increase, else decrease k 
// default k = 0 
//
// solution to f(k)
// -> initiated DSU 
// -> traversed sorted order and if different < k, we group them 
// -> these componenets are TRAPPED WITHIN
//
// wait what the hell? cant we change difference between mi nand max

// already sorted //

void solve(){
    int n;
    cin >> n;
    vl a(n), b(n);
    for (auto& z:a) cin >> z;
    b = a; 
    sort(all(b));
    if (a == b){
        cout << -1 << endl;
        return;
    }
    ll mn = MIN(a);
    ll mx = MAX(a);
    ll res = INF; 
    for (int i = 0; i < n; i++){
        if (a[i] != b[i]){
            ll d1 = a[i] - mn;
            ll d2 = mx - a[i];
            ll evl  = max(d2,d1);
            res = min(res,evl);
        }
    }
    cout << res << endl;

};

// not that some numbers cannot be moved at all 

// if a[i] - a[j] >= k 
// we create an edge 
// this is a DAG

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
