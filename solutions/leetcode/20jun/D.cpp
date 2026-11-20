
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

#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;
const int inv= 1e9;

// pos, leading, tight, last 
ll dp[20][2][2][11];

class Solution {
public:
    long long goodIntegers(long long l, long long r, int k) {
        ll right = partial(r, k);
        ll left = partial(l-1, k);
        ll res = right - left;
        cout << right << " " << left << endl;
        return res;
    }

    ll partial(ll x, int k){
        vi a;
        ll t = x;
        while(t){
            a.pb(t%10);
            t/=10;
        }
        reverse(all(a));
        int len = a.size();
        memset(dp, -1, sizeof(dp));

        auto go = [&](auto& go, int i, int lead, int tight, int last) -> ll {
            if (i == len){
                return 1;
            }
            if (dp[i][lead][tight][last] != -1) return dp[i][lead][tight][last];
            ll res = 0;
            int lim = (tight ? a[i]: 9);
            for (int d = 0; d <= lim; d++){
                int t2 = tight, l2 = lead, l = d;
                if (tight && d < lim) t2 = 0; // no londer timgert 
                if (lead && d != 0) l2 = 0; // no longer lead 
                if (!lead && abs(d - last) > k) continue;
                res += go(go, i+1, l2,t2, d);
            }
            return dp[i][lead][tight][last] = res;
        };
        return go(go, 0, 1, 1, 0 );
    }
};

#ifdef LOCAL
int main(){
    int t = 1;
    // cin >> t;
    while(t--) solve();
    cerr << " == END ==" << endl;
    return 0;
}
#endif
