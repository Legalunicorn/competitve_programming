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
    // do two sliding windows one starting at 0 one starting at 1
    int n,k;
    cin >> n >> k;
    string s; cin >> s;
    vi a(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == 'b') a[i] = 1;
    }
    // solve for a, then solve for b 
    int res = 0;
    // solve for "a"
    int cnt = 0;
    debug(a);
    for (int l = 0, r = 0; l < n; l++){
        while(r<n && (cnt + a[r] <= k)) {
            cnt += a[r];
            r++;
        }
        debug(l,r);
        res = max(res, r- l );
        cnt -= a[l];
    }
    for (int i = 0; i < n; i++){
        a[i] = 1 - a[i];
    }
    cnt = 0;
    debug(a);
    for (int l = 0, r = 0; l < n; l++){
        while(r<n && (cnt + a[r] <= k)) {
            cnt += a[r];
            r++;
        }
        debug(l,r);
        res = max(res, r- l );
        cnt -= a[l];
    }
    cout << res << endl;


    // i thought count = a count =b NO 
    // k *= 2;
    // string s; 
    // cin >> s;
    // vi a(n);
    // for (int i = 0; i < n; i++){
    //     if (s[i] == 'a') a[i] = -1;
    //     else a[i] = 1;
    // }
    // debug(a);
    // int cnt = 0;
    // int res = 0;
    // for (int l = 0, r = 0; l < n; l += 2){
    //     while(r + 1< n && abs(cnt + a[r] + a[r+1]) <= k){
    //         cnt += (a[r] + a[r+1]);
    //         r += 2;
    //     }
    //     debug(l,r, cnt);
    //     res = max(res, r - l);
    //     cnt -= (a[l] + a[l+1]);
    // }
    // cnt = 0;
    // cerr << endl;
    // for (int l = 1, r = 1; l < n; l += 2){
    //     while(r + 1< n && abs(cnt + a[r] + a[r+1]) <= k){
    //         cnt += (a[r] + a[r+1]);
    //         r += 2;
    //     }
    //     debug(l,r,cnt);
    //     res = max(res, r - l);
    //     cnt -= (a[l] + a[l+1]);
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
