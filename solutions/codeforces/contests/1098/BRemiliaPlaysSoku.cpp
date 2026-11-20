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


// REI -> can moev k positions 
// REM -> move 1 position
//
// REI -> want to catch REM 
// calculate their min distance 
// -> 
// how can k be zero?? 
// r u fucking kidding me 
// 
//
// who the fuck named these 
//
// REM -> moves K squares
// REI -> move once 
//
// REI want to catch asap (she moves once)
// REM want to slow down (she moves k) 
// i think does not reset 



void solve(){
    ll n,a,b,k;
    cin >> n >> a >> b >> k;
    if (n <= 3){
        cout << 1 << endl;
        return;
    }
    ll l = min(a,b);
    ll r = max(a,b);
    ll d1 = r - l;
    ll d2 = (n-r)+l;
    ll p = min(d1,d2);
    // debug(d1,d2);
    // if (d1 == d2){
    //     ll res = k + p + 1;
    //     cout << res << endl;
    //     return;
    // }
    // k is just a time wasted
    ll res = k + p;

    // if ()


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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
