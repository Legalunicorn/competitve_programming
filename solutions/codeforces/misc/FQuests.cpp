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


// lets handle inifnite separately 
// means for whatever k 
// it means that the first d elements is greater than c



void solve(){
    int n, d;
    ll c;
    cin >> n >> c >> d;
    vl a(n);
    for (auto& z:a) cin >> z;
    sort(a.rbegin(), a.rend());
    int l = 0, r = max(n,d) + 5;
    int res = -1;

    ll sum = 0;
    for (int i = 0; i < min(n,d); i++) sum += a[i];
    if (sum >= c){
        cout << "Infinity" << endl;
        return;
    }

    debug(a);
    // n log k should be fine 
    auto check = [&](int k) -> bool {
        ll tot = 0;
        int sz = k + 1;
        int grps = d / sz;
        int rem = d % sz;
        for (int i = 0; i < sz; i++){
            if (i >= n) continue;
            tot += grps * a[i];
            if (i < rem) tot += a[i];
            debug(i, tot);
        }
        debug(n,k,grps,rem,tot);
        return tot >= c;
    };

    while(l <= r){
        int m = (l + r) / 2;
        if (check(m)) {
            res = m;
            l = m + 1;
        } else r = m -1;
    }
    if (res == -1){
        cout << "Impossible" << endl;
    } else cout << res << endl;
    debug("      ");
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
