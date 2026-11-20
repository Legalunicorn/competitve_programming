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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

// find the min value of f(l,x) + f(x,r)
// l r 10e9 
// doesnt make sense to binary search either 
// we can consiuder each digit separately 
// we just need to ensure that x is actually left than r 
// there is a tight bound 
// MIN value -> we want the same as much as possible 
// wait what drugs am i on 
// we dont want it to be the same 
// one we "break free" we can choose anything we want 
// not really 
// if the lower and upper bound differ by "1" 
// we have to sick to one of them 
// 9 9 9 
// 8 7 9 
// 8, 9 9
// 9 5 0 
// 9 9 0 
// 8 8 0 
//
// 8 9 x 

void solve(){
    ll l,r;
    cin >> l >> r;
    vi a,b;
    ll tl = l, tr = r;
    while(tl>0){
        a.pb(tl%10);
        tl /=10;
    }
    while(tr>0){
        b.pb(tr%10);
        tr /= 10;
    }
    debug(l,r);
    reverse(all(a));
    reverse(all(b));
    int n = a.size();
    int res = 0;

    int dp[12][2][2];
    memset(dp,-1,sizeof(dp));
    debug(a,b);
    debug(n);
    auto dfs = [&](auto& dfs, int i, int tl , int tr) -> int{
        debug(i,tl,tr) ;
        if (i == n ) return 0;
        if (dp[i][tl][tr] != -1) return dp[i][tl][tr];
        int dlow = (tl ? a[i] : 0);
        int dhigh = (tr ? b[i]: 9);
        // actually this "d" is kinda useless? 
        int ans = 10000;
        debug(i, dlow, dhigh);
        for (int d = dlow; d <= dhigh; d++){
            int tl2 = tl;
            int tr2 = tr;
            if (tl && d>a[i]) tl2 = 0;
            if (tr && d<b[i]) tr2 = 0;
            int pts = 0;
            if (d == a[i])  pts++;
            if (d==b[i])  pts++;
            ans = min(ans, pts + dfs(dfs,i+1, tl2,tr2));
        }

        return dp[i][tl][tr] = ans;
    };

    int score = dfs(dfs,0,1,1);
    cerr << endl;
    cout << score << endl;
    

    

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
