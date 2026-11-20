#include <bits/stdc++.h>
#include <deque>
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

// NOTE: 
// Learning points 
// - I tried to calculate upwards, but can try downwards "bounding" the ansewr 

// NOTE:
// 1. the left and right wizard can tell us some stuff 
// if two ranges are the same 
//  1. only the middle intersect, then the ENDs are NOT 
//  2. 
//
//  WARNING: 
//  HINT: what is the max difference of adjacenment element? 
//  - the max difference is "1", i can see u, u cant see me 
//     - adjacement wizards are of the SAME flag, both allowed
//  - if the difference is "0" -> both both see eo, we both cant see eo (different flags) 
//
//  maybe we can start from the left 
//  -> maintain how many LEFT cape, how many RIGHT cape there are left 
//
//
// Assume wizard 1 starts as L 
// Assume wizzard 1 starts as R 
//
// then we can determine for each if its possible 

void solve(){
    int mod = 676767677;
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    debug(a);

    int res = 0;
    // attempt 1: 
    bool is_left = true;
    bool valid = true;
    // a[i] == a[i-1] 
    //  
    vl left(n), right(n);
    left[0] = 1;
    for (int i = 0; i + 1 < n; i++){
        if ( abs( a[i] - a[i+1]) >  1) {
            valid = false;
            break;
        } else if (a[i] == a[i+1]) {
            is_left = !is_left;
        } 
        if (is_left) left[i+1] = 1;
        else right[i+1] = 1;
    }
    debug(left);
    debug(right);
    if (valid){
        for (int i = 1; i < n; i++) left[i] += left[i-1];
        for (int i = n-2; i >=0; i--) right[i] += right[i+1];
        for (int i = 0; i < n; i++){
            // count left to the left 
            // count right to the right 
            // ensure they are equal 
            int ll = 0, rr = 0;
            if (i > 0) ll = left[i-1];
            if (i + 1 < n) rr = right[i+1];
            if (ll+rr+1 != a[i]) valid = false;
        }
        if (valid) res++;
    }

    left.assign(n,0);
    right.assign(n,0);
    right[0] = 1;
    is_left = false;
    valid = true;

    for (int i = 0; i + 1 < n; i++){
        if ( abs( a[i] - a[i+1]) >  1) {
            valid = false;
            break;
        } else if (a[i] == a[i+1]) {
            is_left = !is_left;
        } 
        if (is_left) left[i+1] = 1;
        else right[i+1] = 1;
    }
    debug(left);
    debug(right);
    if (valid){
        for (int i = 1; i < n; i++) left[i] += left[i-1];
        for (int i = n-2; i >=0; i--) right[i] += right[i+1];
        for (int i = 0; i < n; i++){
            // count left to the left 
            // count right to the right 
            // ensure they are equal 
            int ll = 0, rr = 0;
            if (i > 0) ll = left[i-1];
            if (i + 1 < n) rr = right[i+1];
            if (ll+rr+1 != a[i]) valid = false;
            debug(i, ll+rr+1);
        }
        if (valid) res++;
    }
    cout << res << endl;
    cerr << endl;

};

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
