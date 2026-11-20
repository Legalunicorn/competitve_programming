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

void solve(){
    ll a,b;
    int n;
    cin >> a >> b >> n;
    ll x = __gcd(a,b);
    // greatest common divisors of "a" and "b" 
    // from [LOW, HIGH]
    // 10^4 queries only 
    // gcd of "a" and "b" is just the prime factorization max(exp_a, exp_b)
    // from this set of divisors we have to somehow construct a max value 
    // there are at mosst 30 exponenets
    // 2 << 30 numbers we can create
    // 10^4 queries 
    // binary search might be possible
    // x only hsa ~ sqrt(10e9) divisors max
    vl d;
    for (ll i  = 1; i * i <= x; i++){
        if (x%i==0){
            d.pb(i);
            if (i * i != x) d.pb(x/i);
        }
    }
    sort(all(d));
    while(n--){
        ll l,r;
        cin >> l >> r;
        if (x < l) {
            cout << -1 << endl;
        } else {
            // find the largest divisor in
            // range [l,r]
            // 1. find the largest number less than "r" 
            auto it = lower_bound(all(d), r);
            if (*it >= l && *it <= r){
                cout << *it << endl;
                continue;
            }
            it--;
            ll v = *it;
            if (v >= l && v <= r){
                cout << v << endl;
            } else cout << -1 << endl;
        }
    }
}




int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}
