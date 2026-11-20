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

// NOTE :
// n = 2000 
// we want the fastest way to make an elmenet 1 
// then we just span n-1 operations to make the non 1 elements 1 
//
// if contains 1 anywhere, return count of non 1s 
// else we just find any 
// otherwise we just need to analys two numbers ? 
// any number coprime -> gcd (1) 
// if all numbres or equals its not possible 
// if gcd of all numbers > 1 its not possible 
//


void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    int g = a[0];
    int one = 0;
    for (auto& z:a) {
        if (z==1) one++;
        g = __gcd(g, z);
    }
    // impossible
    if (g > 1){
        cout << -1 << endl;
        return;
    }
    // "1" already exist just need to convert the rest
    if (one > 0){
        cout << n-one << endl;
        return;
    }
    int mn = n-1;
    for (int i = 0; i < n; i++){
        int gg = a[i];
        for (int j = i; j < n;j++){
            gg = __gcd(gg, a[j]);
            debug(i,j,gg);
            if (gg == 1) mn = min(mn, j - i);
        }
    }
    debug(mn);
    cout << mn + (n - 1) << endl;
    // now the real problem 
    // its a tmost n-1 + n-1 = 2n - 2 
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
