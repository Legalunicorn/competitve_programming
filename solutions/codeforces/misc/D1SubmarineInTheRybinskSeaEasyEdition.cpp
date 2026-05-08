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

// i think it makese sense 
// that we can conut how many each digit appears in each place
//  then sum them individually 
//  we treat each as "j" and multily by n * pos 
//  treat as each "i" and multiply by n * pos 
void solve(){
    ll ten[20];
    ten[0] = 1;
    for (int i = 1; i < 20;i++) ten[i] = ten[i-1] * 10;
    debug(ten[18]);
    // debug(ten)
    int n;
    cin >> n;
    vector<ull> a(n);
    for (auto& z:a) cin >> z;

    ull mod = 998244353;
    ull res = 0;
    int x = to_string(a[0]).size();
    for (auto x: a){
        int p = 0;
        while(x){
            ull r = x % 10;
            ull one = (r * ten[p] % mod) * n % mod;
            ull two = (r * ten[p+1] % mod) * n % mod;
            debug(r * ten[p] * n);
            // debug(r * ten[p+1] * n);
            // debug(x, one, two);
            res = (res + one) % mod;
            res = (res + two) % mod;
            x /= 10;
            p+=2;
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
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
