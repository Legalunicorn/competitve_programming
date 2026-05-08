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
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;


// [a,c] and [b,d] 
//
// a < x <= c 
// b <= y <= d 
//
// x * y  = k * a * b 
//
//  if one pair exist we can iterate the first and maybe derive the second? 
// 
// iterate x: (a, c]
// y = k ( a b / x) 
//  k a b divisible by x 
//  for some k 

// NOTE: 
// x y = k (a b ) 
// y = (k a b) / x 
//
//
//
// conclusion 
// y must be divisible by ab/gcd(ab,x) 
// what?? 
//

void solve(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    for (int x = a+1; x <= c; x++){
        ll g = a * b / gcd(a * b, x);
        ll evl = (ll)ceil((b+1)*1.0 / g)  * g;
        debug(x,g, evl);
        if (evl >  b && evl <= d) {
            cout << x << " " << evl << endl;
            return;
        }
    }
    cout <<"-1 -1" << endl;
    debug("  ");
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
