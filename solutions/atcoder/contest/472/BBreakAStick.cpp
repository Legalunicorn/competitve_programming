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
    int n;
    cin >> n;
    vi a(n);
    ll sum = 0;
    for (auto & z:a) cin >> z;
    // read properl!!
    ll res = INF;
    for (int i = 0; i < n; i++){
        ll s1 = 0, s2 = 0;
        for (int j = 0; j < n; j++){
            if (j <= i) s1 += a[j];
            else s2 += a[j];
        }
        debug(i,s1,s2);
        res = min(res, abs(s1-s2));
    }
    cout << res << endl;
    // for (int i = 0; i < n; i++) sum += a[i];
    // ll res = (sum - a[0]);
    // for (int i = 0; i < n; i++){
    //     sum -= a[i];
    //     res = min(res, abs(sum - a[i]));
    // }
    // cout << res << endl;
    // int res = abs(a[1]-a[0]);
    // for (int i = 1; i < n;i++){
    //     res = min(res, abs(a[i] - a[i-1]));
    // }
    // cout << res << endl;
};

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
