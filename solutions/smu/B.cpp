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
// the onlyu way to make 0 is 
// b[i] == m
// since we have a permutation isnt it only one at a time? 
// what has k havce to do with abbywehhre 
// oh we just have to add the largest element plus one 
// so we have to plus one to every 
// 4 5 1 2 3 
// 
// 5 0 2 3 4 
// 0 0 3 4 5 
// 0 0 
//
// 1 2 3 4 5 
// 2 3 4 5 0 
// 3 4 5 0 0 
// 4 5 0 0 0 
// 5 0 0 0 0
// 0 0 0 0 0
//
//
// 5 6 2 3 4 
// 6 0 3 4 5 
// 0 0 3 4 5  (3)
// 0 0 4 5 6  (4)
// 0 0 5 6 0   (5)
//

void solve(){
    ll n,k,m;
    cin >> n >> k >> m;
    if (n == 1){
        cout << m - n << endl;
        return;
    }
    if (k == 0){
        ll d = m - n;
        ll res = d;
        res += (m - (d+1));
        cout << res << endl;
        return;
       
    }
    ll d = m - n;
    ll res = d;
    ll l = n - k + 1 + d;
    ll r = 1 + d;
    debug(l, r);
    res += (m - l);
    res += (m - r);
    cout << res << endl;





  // k  // ll d = m - n;
    // res += d * n;
    // res++;
    // cout << res << endl;

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
