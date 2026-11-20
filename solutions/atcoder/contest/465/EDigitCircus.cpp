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

// this looks like digit dp? 
// x -> multiple of 3 -> digit sum = 0 (mod 3)
// contains a three 
// exactly three different digits are used -> bitset of 10 
//
// digit dp 
// 500 * 2 * 3 * 2  * 1000 
// dp[pos][tight][mod3][has3][bitmask]


//     i   t  l  md h3  mask
ll dp[501][2][2][3][2][1050];
void solve(){
    string s;
    cin >> s;
    int n = s.size();
    debug(n, s);
    memset(dp, -1, sizeof(dp));
    ll mod = 998244353LL;
    // maybe this is comnbi not digit dp

    // alot of double countingf? 
    // exaclty one condsition
    // i need leading zeros also 
    auto go = [&](auto& go, int i, int t, int l,  int mod3, int has3, int mask) -> ll{
        if (i == n){
            int cnt = 0;
            for (int j = 0; j < 10; j++){
                if (mask >> j & 1) cnt++;
            }
            int cond = 0;
            if (cnt == 3) cond++;
            if (mod3 == 0) cond++;
            if (has3 == 1) cond++;
            // debug(i,t,l,mod3,has3,mask, cond);
            if (cond == 1) return 1;
            else return 0;
        }
        if (dp[i][t][l][mod3][has3][mask] != -1) return dp[i][t][l][mod3][has3][mask];
        int lim = 9;
        if (t) lim = s[i]-'0';
        ll ans = 0LL;
        for (int d = 0; d <= lim; d++){
            int t2 = t, l2 = l, mod32 = mod3, has32 = has3, mask2 = mask;
            if (t && d < (s[i]-'0')) t2 = 0; // no longer tight 
            if (l && d != 0) l2 = 0; // no longer leadering 

            if (d == 3) has32 = 1; // convert to 1 

            if (!l2) mask2 = mask2 | (1 << d);
            if (!l2) mod32 = (mod3 + d) % 3;

            ll evl = go(go, i+1,t2,l2, mod32, has32, mask2);
            ans = (ans + evl) % mod;
        }
        return dp[i][t][l][mod3][has3][mask] = ans;
    };
    ll res = go(go, 0, 1, 1, 0, 0, 0);
    // we must exclude 0 , which is a valid answer
    res = (res + mod - 1) % mod;
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
