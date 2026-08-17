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

// the large cost is at the head 
// we maintain the sum and reduce it while needed
void solve(){
    ll n,s;
    cin >> n >> s;
    debug(n,s);
    ll t = n;
    int sum = 0;
    while(t){
        sum += t%10;
        t/=10;
    }
    // we can only INCREASE n ! 
    // so its trivial to see 
    // we can solve this greedily 
    ll res = 0; // amount needed to change 
    int fac = 0;
    t = n; // reset t 

    auto chk = [&](ll x) -> bool{
        int s2 = 0;
        while(x) {
            s2 += x % 10;
            x /= 10;
        }
        return s2 <= s;
    };
    if (chk(n)) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < 20; i++){
        ll ten = pow(10, i);

        ll n2 = n;
        int d = n2 % 10;
        for (int j = 0; j <= i; j++){
            d = n2 % 10;
            n2 /= 10;
        }
        d = (10 - d) % 10;
        debug(i,d,n,ten);
        
        n += ten * d;
        res += ten * d;
        if (chk(n)) break;
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
