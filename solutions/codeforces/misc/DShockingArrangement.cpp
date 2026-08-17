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


// NOTE: 
// gay construction
// start with max/min? 
// -3 1 1 1 -3 1 1 1 

void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    sort(all(a));
    ll lim = a.back() - a.front();

    ll cur = 0LL;
    int f = n-1, b=  0;
    vl c;
    debug(a);
    while(b <= f){
        if (f == b) {
            c.pb(a[f]);
            break;
        } else{
            ll x = cur + a[f];
            if (abs(x) < lim){
                cur += a[f];
                c.pb(a[f]);
                f--;
            } else{
                cur += a[b];
                c.pb(a[b]);
                b++;
            }
        } 
    }
    a = c;
    debug(a);
    // checker algorithm
    ll mx = 0LL, mn = 0LL,sum = 0LL;
    for (int i = 0; i < n; i++){

        sum += a[i];
        ll p = abs(sum - mx), q = abs(sum - mn);
        if (p >= lim || q >= lim){
            cout << "No" << endl;
            return;
        }
        mx = max(mx, sum);
        mn = min(mx, sum);
    }
    cout << "Yes" << endl;
    for (auto& z:a) cout << z << " ";
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
