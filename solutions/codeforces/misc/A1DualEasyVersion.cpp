#include <bits/stdc++.h>
#include <sys/types.h>
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


void solve(){
    // cerr << endl;
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    int mn = a[0];
    int mx = mn;
    map<int,int> mp;
    for (auto& x: a){
        mp[x]++;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    int v;
    vpi res;
    if (mn == mx){
        cout << 0 << endl;
        return;
    }
    if (abs(mn) == abs(mx)){
        if (mp[mn] > mp[mx]) v = mn;
        else v = mx;

    } else if (abs(mn) > abs(mx)) v = mn;
    else v  = mx;

    // find the mn pos;
    int pos = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == v){
            pos = i + 1;
            break;
        }
    }
    // v is NON zero , either pos or neg 
    if (v < 0 ){
        for (int i = 0; i < n; i++){
            if (a[i] >= 0) {
                a[i] += v;
                res.pb({i+1, pos});
                if (a[i] >=0){
                    a[i] += v;
                    res.pb({i+1,pos});
                }
            }
        }
        // do a prefix sum 
        debug(a);
        for (int i = n-2; i >=0; i--){
            a[i] += a[i+1];
            res.pb({i+1, i + 2});
        }
    } else if (v > 0){
        for (int i = 0; i < n; i++){
            if (a[i] <= 0){
                a[i] += v;
                res.pb({i+1, pos});
                if (a[i] <= 0){
                    a[i] += v;
                    res.pb({i+1,pos});
                }
            }
        }
        debug(a);
        for (int i = 1; i < n; i++){
            a[i] += a[i-1];
            res.pb({i+1, i});
        }
    }
    cout << res.size() << endl;
    for (auto& z: res) cout << z.F << " " << z.S << endl;
    debug(res.size());
    debug(a);
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
