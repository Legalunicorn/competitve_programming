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
    // cerr << endl;
    int n;
    ll k;
    cin >> n >> k;
    vl a(n);
    for (auto& z:a) cin >> z;
    if (n==1){
        ll evl = k-1;
        if (a[0] <= evl) evl++;
        cout << evl << endl;
        return;
    }
    ll g = a[0];
    for (int i = 1; i < n; i++) g = __gcd(g, a[i]);
    if (g == 1){
        cout << k-1+n << endl;
        return;
    }
    debug(a);
    debug(g);
    ll d = g-1;
    ll used = 0;
    // 0 2 4 
    // k = 3
    // 0   2   4 
    //   1   3   5
    for (int i = 1; i < n; i++){
        ll x = g*i;
        debug(i, used+d);
        if (used + d < k){
            // if (used+d==k-1) {
            //     debug("here1");
            //     cout << used+d << endl;
            //     return;
            // }
            used +=d;
        } else if (used + d == k){
            ll u = (x-g)+d;
            cout << u << endl;
            return;
        } else {
            ll u = (x-g)+((used+d)-k);
            debug(x-g, k-(used+d), u);
            cout << u << endl;
            return;
        }
        debug(i,used);
    }
    cout << k-1+n << endl;
    return;
    // ll cnt = min((ll)n,x/g+1); 
    // if (g==1) cnt = n;
    // ll base = k-1;
    // ll res = base +cnt;
    // cout << res << endl;
    // cerr << endl;
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
