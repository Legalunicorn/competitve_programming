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
    ll n,k;
    cin >> n >>k;
    ll val  = 1ll;
    ll res = 0ll;

    for (int d = 1; d <= n; d++){
        // the last k days = withdraw
        if (d >= n-k+1){
            val *=2ll;
            res += val;
            debug(d, val);
            val  = 1;;
        } else{
            val *= 2;
            debug(d,val);
        }
        // if (d == n - k+1)  res += val;
        // else if (d < n-k+1) val*=2;
        // else res +=2;
    }
    // cerr << endl;
    cout <<res << endl;
    // ll res = k*2;
    // ll val = 1;
    // for (int i = 0; i <= n-k; i++){
    //     val *=2;
    // }
    // res += val;
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
