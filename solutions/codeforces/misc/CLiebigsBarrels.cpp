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
    int n,k;
    ll l;
    cin >> n >> k >> l;
    int m = n * k;
    vl a(m);
    for (auto& z:a) cin >> z;
    sort(all(a));
    // find the last position of a[0] + l
    int pos = 0;
    ll v = a[0] + l;
    for (int i = 0; i < m; i++){
        if (a[i] <= v) pos = i;
    }
    if (pos + 1  <n){
        cout << 0 << endl; 
        return;
    }
    // int excess = (pos+1) - n;
    // int cur = min(excess, n-1);
    // excess -= cur;
    // ll res = a[0];
    int   excess = (pos+1)-n;
    int cur = 0;
    ll res = 0;
    int taken = 0;
    for (int i = 0; i < m; i++){
        debug(i, cur, excess, res);
        if (taken == n) break;
        if (cur == 0){
            res+=a[i];
            taken++;
            if (excess>0){
                ll v = min(k-1, excess);
                cur = v;
                excess -= v;
            }
        } else{
            cur--;
        }
    }
    cout << res << endl;

    // for (int i = 1; i <= pos; i++){
    //     debug(i, cur, excess);
    //     if (excess == 0){
    //         res += a[i];
    //         continue;
    //     }
    //     if (cur){
    //         cur--;
    //     } else {
    //         cur = min(n, excess);
    //         excess -= cur;
    //         res += a[i];
    //     }
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
