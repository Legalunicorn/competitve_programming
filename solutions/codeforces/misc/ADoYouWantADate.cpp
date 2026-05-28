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

// NOTE: this has to be some path 
// we can select any two points to be used 
// then the number of elements in between x, there is (1<<x) combinations 
// but we have to calculte this in a smart way 
// we can try to count individually 
// how frequent each gap appears 
//
//
// a  b   d   e   


void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    sort(all(a));
    if (n ==1){
        cout << 0 << endl;
        return;
    }  else if (n==1){
        cout << a[1] - a[0] << endl;
        return;
    }

    vl b;
    for (int i = 1; i < n; i++) b.pb(a[i] - a[i-1]);
    vl p(n,-1);
    p[0] = 1;
    for (int i = 1; i < n; i++) p[i] = (p[i-1] * 2 % MOD);
    debug(p);
    for (int i = 1; i < n; i++) p[i] = (p[i] + p[i-1]) % MOD;
    debug(p);
    debug(b);
    int min = 0;
    int add = n - 3;
    ll res = b[0] * p[n-2] % MOD;
    ll prev = p[n-2], cur = 0;
    debug(p[n-2], n-2, b[0], res);
    for (int i = 1; i < b.size(); i++){
        cur = (prev + p[add] + MOD ) % MOD;
        cur = (cur - p[min] + MOD ) % MOD;
        debug(i, cur);
        res = (res + ((b[i] * cur + MOD) % MOD)) % MOD;
        min++;
        add--;
        prev = cur;
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
