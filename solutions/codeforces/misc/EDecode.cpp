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

// strange wording
// ax + ay + az = a(x + y + z)
//
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    ll res = 0ll;
    vl a(n);
    for (int i = 0; i < n; i++){
        if (s[i]=='0') a[i] = -1;
        else a[i] = 1;
    }
    vl pf = a;
    map<ll,ll> mp;
    mp[0] = 1LL;
    ll acc = 0;
    for (ll i = 0; i < n; i++){
        acc += a[i];
        ll tot = mp[acc];
        ll evl = (n-i)*tot % MOD;
        debug(i, acc, tot, n-i);
        res += evl;
        res %= MOD;
        mp[acc]+=(i+2); // i +2 not 1 why ? n = 4 ,i = 1 ? we have to include the empty start i = -1;;
        debug(i,res);
    }
    cout << res << endl;
    cerr << endl;
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
