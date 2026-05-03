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
    // max times he can pass through 0 
    //
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    ld v = 0.5;
    // brute force problem;
    int res = 0;
    int full = 1 << n;
    for (int m = 0; m < full; m++){
        ld v = 0.5;
        int cnt = 0;
        for (int i = 0; i  < n ; i++){
            if (m >> i & 1){
                // plus 
                if (v < 0 && v+a[i] > 0) cnt++;
                v += a[i];
            } else{
                if (v > 0 && v-a[i] < 0) cnt++;
                v -= a[i];
            }
        }
        res = max(res, cnt);
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
