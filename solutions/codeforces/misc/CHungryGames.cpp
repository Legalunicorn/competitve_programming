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

// precompute dp where dp[i] 
// 

void solve(){
    ll n,x;
    cin >> n >> x;
    vl a(n);
    for (auto& z:a) cin >> z;
    vl p = a;
    for (int i = 1; i < n;i++) p[i] += p[i-1];
    ll tot = n*(n+1)/2;
    vl dp(n+1,0);
    debug(n,x,a);
    for (int i = n-1;i >= 0;i--){
        // precompute dp[i] using bs, search for first index > x, then use the +1
        int l = i, r = n-1, pos = -1;
        while(l<=r){
            int mid = (l+r)/2;
            ll sum = p[mid]-(i>0?p[i-1]:0);
            debug(i,l,r,sum);
            if (sum>x){
                pos = mid;
                r = mid-1;
            } else l = mid+1;
        }
        debug(i,pos);
        if (pos!=-1) dp[i] = 1 + dp[pos+1];
        tot -= dp[i];
    }
    debug(dp);
    cout << tot << endl;
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
