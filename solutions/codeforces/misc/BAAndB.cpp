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

void solve(){
    // binary search for the sum that is as close to 0
    // then perform pack and forth shuffle 
    // actually the gap will overshoot by a bit like lets say 1 + 2 +3 + 4 + 5 + 6 -> excess 4 

    ll a,b;
    cin >> a >> b;
    ll d  = abs(a-b);
    ll l = 0, r = max(a,b);
    ll res = LONG_MAX;
    ll moves = r;
    while(l<=r){
        ll m = l + (r - l)/2;
        ll calc = m * (m+1)/2;
        if (calc >= d){
            if (m < moves){
                moves = m;
                res = calc;
            }
            r = m - 1;
        } else l = m + 1;
    }
    ll delt = abs(res-d);
    for (int i =0; i < 4; i++){
        ll m2 = moves+i;
        ll nd = (m2 * (m2+1) / 2);
        if (abs(nd-d) % 2 == 0){
            cout << m2 << endl;
            return;
        }
    }
     // if (delt%2==1) {
    //
    //     // if (delt == 1) moves++;
    //     moves+=2;
    // }
    // cout << moves << endl;


    


    // ll a,b;
    // cin >> a >> b;
    // ll d = abs(a-b);
    // ll l = 0, r = max(a,b);
    // ll ans = d;
    // ll res = 0;
    // while(l <= r){
    //     ll m = l + (r-l)/2;
    //     ll calc = (m)*(m+1)/2;
    //     if (calc <= d){
    //         if (d - calc < ans){
    //             ans = d - calc;
    //             res = m;
    //         }
    //         l = m + 1;
    //     } else r = m - 1;
    // }
    // debug(res);
    // debug(ans);
    // debug((res+1)*(res+2)/2);
    // res += ans*2;
    // cout << res << endl;

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
