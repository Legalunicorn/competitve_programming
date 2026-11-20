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


ll isqrt(ll x) {
    ll s = sqrtl((long double)x);
    while (1LL * (s + 1) * (s + 1) <= x) s++;
    while (1LL * s * s > x) s--;
    return s;
}

void solve(){
    map<ll,ll> mp;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        ll x; cin >> x;
        mp[x]++;
    }
    debug(mp);
    int q; cin >> q;
    while(q--){
        ll res = 0;
        ll x,y;
        cin >> x >> y;
        ll det = (x * x) - (4 * y);
        pl past = {12312312312,1312313123};
        if (det >= 0){
            // ld sq = sqrt(det*1.0);
            ll sq = isqrt(det);
            if (sq * sq != det) {
                cout << 0 << " "; continue;
            }
            debug(det,sq);
            {
                ld b = (x*1.0 + sq)/2.0;
                ll rb = roundl(b);
                if (true) {
                    ll one = rb, two = x - one;
                    if (one > two) swap(one,two);
                    past = {one,two};
                    debug(x,y,one,two);
                    if (one == two) res += (mp[one] * (mp[one]-1)) /2;
                    else res += (mp[one] * mp[two]);
                }
            }
            {
                ld b = (x - sq)/2.0;
                ll rb = roundl(b);
                if (true) {
                    ll one = rb, two = x - one;
                    if (one > two) swap(one, two);
                    pl pp = {one,two};
                    if (pp != past){
                        debug(x,y,one,two);
                        if (one == two) res += (mp[one]*(mp[one]-1))/2;
                        else res += (mp[one] * mp[two]);
                    }
                }
            }
        }
        cout << res << " ";
    }
    cout << endl;
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
