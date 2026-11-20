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

void solve(){
    ll a,b,c,d;
    cin >> a >> b >> c >> d;
    int tot = a+b+c+d;
    if (a == 0){
        if (a+b+c+d>0) cout << 1 << endl;
        else cout << 0 << endl;
        return;
    }
    ll res = a;
    // A up, B down
    // A down, B up 
    // they basically cancel out each outher 
    ll mn = min(b,c);
    res += mn*2;
    b-=mn;
    c-=mn;
    ll bob = a, alice = a;
    // either b or c will remain
    if (b>0){
        mn = min(bob,b) ;
        res += mn;
        bob -= mn;
    } else if (c>0){
        mn = min(alice,c);
        res += mn;
        alice -= mn;
    }
    // left is both dislike 
    mn = min({bob,alice,d});
    res += mn;
    debug(res,tot);
    if (res<tot) res++;
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
