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
    int n;
    cin >> n;
    vi a(2 * n);
    for (auto& z:a) cin >> z;
    ll res = 0ll;
    for (auto& z:a) res += abs(z); // defautl -> all zeros
    if (n == 1){
        // special case: we can just use the same numer 
        // if n == 2, 2 is a special casse
        int d = abs(a[0]-a[1]);
        cout << d << endl;
        return;
    } 
    if (n ==2){ // has special case if 2 2 2 2 
        ll evl = 0;
        for (auto& z: a) evl += abs(z - 2);
        res = min(res,evl);
    }
    if (n % 2 == 0){ // even n has the -1 trick 
        ll base = 0ll;
        for (auto& z:a) base += abs(-1 - z);
        for (auto& z:a){ 
            ll ab = abs(- 1 -z);
            res = min(res, base - ab + abs(n - z));
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
    cin >> T; 
    while(T--) solve();
    return 0;
}
