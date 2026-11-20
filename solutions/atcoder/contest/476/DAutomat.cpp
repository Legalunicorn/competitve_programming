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

// NOTE:
// probably not dpable 
// 1,k
// k
//
// we get change in 1
//
// could be binary search or greedy 
//
// A: 1,k
// B: k 
//
// so long we have money, we can buy anything from A 
// but for B it depends on K notes only 
//
// so we have to buy a certain amoung of B 
// then the remaining spend on A 
//
// sort A 
// sort B 
// iterate B 
// binay search on A
//
void solve(){
    ll n,m,k;
    cin >> n >> m >> k;
    ll x,y;
    cin >> x >> y;
    vl a(n), b(m);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    sort(all(a));
    sort(all(b));
    for (int i = 1; i < n; i++) a[i] += a[i-1];
    ll res = 0;
    ll kleft = y;
    ll mleft = x + (k * y);
    for (int i = 0; i < n; i++){
        if (a[i] <= mleft) res = i+1;
    }
    debug(a);
    debug(b);
    debug(x,y);

    for (int i = 0; i < m; i++){
        debug(i, kleft,mleft);
        ll ned = b[i]/k;
        if (b[i]%k!=0) ned++;
        if (ned > kleft) break;
        kleft -= ned;
        mleft -= b[i];

        // binary search over A
        ll l = 0, r = n-1, evl = 0;
        while(l<=r){
            int m = (l+r)/2;
            if (a[m] <= mleft){
                evl = m+1;
                l = m+1;
            } else r = m-1;
        }
        res = max(res, evl + i + 1);
        debug(evl, a[evl-1], mleft);
        debug(mleft, evl, res);
        cerr << endl;
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
    while(T--) solve();
    return 0;
}
