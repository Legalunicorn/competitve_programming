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
// even + even = even 
// even + odd = odd 
// odd  + odd = even
//
// N-1 is quite powerful, because it shift the modulus of N by 1 
//  
//  1. Select [0, N-1] -> make all of them = 0 (mod N)
//  2. Select [N] -> make it 0
//  3. Select [0,N] -> add by the inverse

void solve(){
    // mega trivial
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >>z;
    if (n == 1){
        cout << "1 1" << endl;
        cout << -a[0] << endl;
        cout << "1 1" << endl;
        cout << 0 << endl;
        cout << "1 1" << endl;
        cout << 0 << endl;
        return;
    }
    cout << "1 " << n-1 << endl;
    debug("bf", a);
    for (int i = 0; i + 1 < n; i ++){
        // every time +(n-1), mod N --
        ll x = a[i];
        ll m = a[i] % n;
        ll ef = m * (n-1);
        cout << ef << " ";
        a[i] += ef;
    }
    debug("fp",a);
    cout << endl;
    cout << n << " " << n << endl;
    cout << -a[n-1] << endl;
    a[n-1] = 0ll;
    cout << 1 << " " << n << endl;
    for (int i = 0; i < n; i++){
        cout << -a[i] << " ";
    }
    cout << endl;
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
