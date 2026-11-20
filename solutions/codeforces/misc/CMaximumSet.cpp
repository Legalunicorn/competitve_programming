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
// NOTE: obviosuly optimal is to spam x2 
// also not that we can only x2 or x3 becaue x4 =  x2 x2 which is not optimal 
// also note we can only x3 max one time, becase 3x3 = 9 < 2x2x2 = 8, 2 operations vs 3 operations 
// also not the max size is 20 
// but still there is t queries and [l,r] up to 1e6 
// we cannot brute force dp each query, and need to precompute
//
// i have an interesting idea  but i dont think it works
// where we compute the dp[i]...to MAX for each i from [1, 1e6+5]
// then we compute the suffix sum or something like that (MOD m)
// then for each query 
// does sf[l] - sf[r] return the answer? 
// i dont think so because we 


// READ THE EDITORIAL 
// we solve this purely with math 
// Observations i didnt see 
// split NO 3, and ONE 3 into two separate cases 
// 1. for each case only a_1 matters! 
// for the NO 3 case -> itsd obvious 
// for the ONE 3 case -> we can just place the 3 anywhere along the chain!  -> thus we just meed to multiply by the number of places x3 can be
//
// the MOD is a red herring, you dont need it
//
//
// NOTE: only 2's 
// s >= L 
// s (2 ^{m-1}) <= R 
// s  <= R/(2^{m-1}) 
//
void solve(){
    ll l,r;
    cin >> l >> r;
    ll s =l;
    int m = 1;
    while(s*2 <= r){
        s *=2;
        m++;
    }
    if (m ==1){
        cout << 1 << " " << (r -l + 1) << endl;
        return;
    }

    ll ans = 0ll;
    // calculate the right bound
    // r / 2^{m-1};
    ll div = 1ll << (m-1);
    ll rb = r/div;
    ll temp = rb - l + 1;
    debug(l,rb, temp);
    if (temp >=0) ans += temp;

    if (m >= 2) {
        div = 1ll << (m-2);
        div *= 3;
        rb = r/div;
        debug("!", l,rb);
        temp = rb-l+1;
        if (temp>=0){
            ll cont = (m-1)*temp;
            ans += cont;
        }
    }
    cout << m << " " << ans << endl;
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
