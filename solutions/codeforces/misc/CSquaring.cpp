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
// x^(2^y) < a^(2^b) 
// 2^y log (x) < 2^b log (a)
// log(2^y . log x ) <  log(2^b . log a) 
// log(2^y) + log(X) < log(2^b) + log a 
// log(2^y) + log(x) - log(a) - log(2^b)
// ylog(2) + log(x) - log(x) - b log(2) < 0 
// log(2)(y- b) + log x - log a < 0
// log -> 

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    int base = a[0];
    int pow = 0;
    ll res =0;

    auto cmp = [&](int x, int y, int a, int b){
        // double one = log(2.0)*(y-b);
        // double two = log(log(x*1.0));
        // double three = log(log(a*1.0));
        double res = log(2.0)*(y-b) + log(log(x*1.0)) - log(log(a*1.0));
        debug(x,y,a,b,res);
        return res <= EPS;
    };


    for (int i = 1; i < n; i++){
        debug(a[i], base, pow);
        if (a[i] == 1 && base > 1){
            cout << -1 << endl;
            return;
        }
        if (a[i] == 1){
            base = a[i];
            pow = 0;
            continue;
        }
        int l = 0, r = n*10;
        int evl  = r;
        while(l<=r){
            int m = (l+r)/2;
            if (cmp(base,pow, a[i], m)){
                evl = m;
                r = m-  1;
            } else l = m + 1;
        }
        base = a[i];
        pow =  evl;
        res += evl;
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
