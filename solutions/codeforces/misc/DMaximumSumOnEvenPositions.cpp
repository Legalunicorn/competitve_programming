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
    vl a(n);
    for (auto& z:a) cin >> z;
    ll res = 0;
    debug(a);
    for (int i = 0; i < n; i+=2) res += a[i];
    ll base = res;
    debug(res);
    vl b = a;
    for (int i = 0; i < n; i += 2) b[i] *= -1;
    for (int i = 1; i < n; i++) b[i] += b[i-1];
    // start at even, end at odd 
    {
        ll low = 0ll;
        ll gain = 0LL;
        for (int i = 1; i < n; i +=2){
            gain = max(gain, b[i] - low);
            low = min(low,b[i] );
        }
        debug(gain,low);
        res = max(res, base + gain);
    }
    {
        ll low = b[0];
        ll gain = 0ll;
        for (int i = 2; i < n; i+=2){
            gain = max(gain, b[i] - low);
            low = min(low, b[i]);
        }
        debug(gain,low);
        res = max(res, base + gain);
    }
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
    while(T--) solve();
    return 0;
}
