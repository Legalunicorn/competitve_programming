#include <bits/stdc++.h>
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
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

// NOTE:
// 1. L or R 
// L = k 
// R = size-k-1
// if we remove R -> L remains the same option
// if we remove L -> R remains the same poitons   


// NOTE:
// i thought there was a pattner 
// but now i dont see it 
// n = 10, k = 7 
// -> 


void solve(){
    ll n,k;
    cin >> n >> k;
    vl a(n);
    for (auto& z:a) cin >> z;
    // heading right start from 
    int r = k-1;
    int l = n - k;

    ll res =0ll;
    debug(a);
    vb used(n);

    while(r < n && l >= 0){
        debug(r,l);
        if (r < l) {
            if (!used[r]) res += a[r];
            if (!used[l])res += a[l];
            used[r] = used[l] = true;
        } else if( r == l){
            if (!used[r]) res += a[r];
            used[r] = true;
        } else{
            if (!used[r] && !used[l]) res += max(a[r], a[l]);
        }
        r++,l--;
        debug(res);
    }
    // cerr << endl;
    cout << res << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
