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

void solve(){
    int n;
    cin >> n;
    vpi a(n);
    for (int i=0;i<n;i++) cin >> a[i].F >> a[i].S;

    // if i.S < i-1.S 

    sort(all(a), [&](const auto& p, const auto& q){
            if (p.F == q.F) return p.S < q.S;
            return p.F < q.F;
    });
    debug(a);
    int mx = a[n-1].F;
    int res = a[0].S;
    for (int i= 1; i < n; i++){
        if (res > a[i].S){
            res = max(res,a[i].F);
        }
        else if (a[i].S < a[i-1].S){
            res = max(res, a[i].F);
        } else {
            res = max(res, a[i].S);
        }
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
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
