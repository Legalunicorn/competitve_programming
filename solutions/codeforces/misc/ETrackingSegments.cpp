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
    int n,m;
    cin >> n >> m;
    // all zeros we can ignore 
    vpi seg(m);
    for (int i = 0; i < m;i ++) cin >> seg[i].F >> seg[i].S;
    for (int i = 0; i < m; i++) {
        seg[i].F--;
        seg[i].S--;
    }
    int q;
    cin >> q;
    vi op(q);
    for (auto& z:op) cin >> z;
    for (auto& z: op) z--;
    int l = 0, r = q, res = -1;
    while(l<=r){
        int mid = (l+r)/2;
        int yes = 0;
        vi a(n+1, -1);
        for (int i = 0; i < mid; i++) a[op[i]] = 1;
        for (int i = 1; i <= n; i++) a[i] += a[i-1];
        for (auto& [l,r]: seg){
            int sum = a[r];
            if (l - 1 >= 0) sum -= a[l-1];
            if (sum > 0){
                yes = 1;
                break;
            }
        }
        if (yes){
            res = mid;
            r = mid- 1;
        } else l = mid+1;
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
