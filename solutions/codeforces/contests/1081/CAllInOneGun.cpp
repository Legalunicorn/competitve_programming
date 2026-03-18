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


// the full mag has the same damange no matter what 
// we want to optimise the fasted bullet to kill the remainder 


void solve(){
    ll n,h,k;
    cin >> n >> h >> k;
    vl a(n);
    for (auto& z:a) cin >> z;
    ll sum = 0;
    for (auto& z:a) sum += z;
    ll md = h % sum;
    if (md == 0){
        // shoot all 
        ll d = h / sum;
        ll res = n * d;
        if (d > 1) res += k * (d-1);
        cout << res << endl;
        return;
    }
    vl vmx(n);
    ll mx = a[n-1];
    for (int i = n-1; i>=0; i--){
        mx = max(mx, a[i]);
        vmx[i] = mx;
    }

    vl lmx(n);
    ll low = a[0];
    for (int i = 0; i < n; i++){
        low = min(low,a[i]);
        lmx[i] = low;
    }

    ll best = n;
    ll cnt = 0;
    for (int i = 0; i + 1 < n; i++){
        cnt += a[i];
        if (cnt >= md || cnt - lmx[i] + vmx[i+1] >= md){
            best = i + 1;
            break;
        }
    }


    debug(vmx);
    debug(h,sum,md);
    debug(a,best);
    cerr << endl;

    ll d = (h / sum);
    ll full = (n + k) * d;
    ll ans = full + best;
    cout << ans << endl;

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
