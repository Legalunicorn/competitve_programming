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
// i used a hint: DP 
//
//
// I thought of DP but ruled it out because DP usually means we have to mutate the array 
// BUT in this case we can reframe the DP to NOT mutate the array with an observation 
// ew if we choose a segment of elements, they value is just set to the min of that segment 
//
// now we can reframe it 
// -> we are to chosesome eleemnts to be insegmetns, each segnent continue L - 1 items chosen
// -> we just need to choose when to start a segment, and if its started
// -> note that segments 
// 
// a segment of length L, cost L - 1 operations 
//
// i worked ts on paper 
// dp[i][left] = min(0<=j<=min(left,n-i-1)) {
//  (j+1) x min(0<=x<=j)a[i+x] 
//  + dp[i+j+1][left-j]
// }

void solve(){
    int n,k;
    cin >> n >> k;
    vl a(n);
    for (auto&z:a) cin >> z;
    debug(a);
    vvl dp(n+10, vl(15, INF));
    // base cases
    for (int i = 0; i < 15; i++) dp[n][i]=0;

    for (int i = n-1; i >= 0; i--){
        for (int left = 0; left <= k; left++){
            for (int j = 0; j <= min(left,n-i-1); j++){
                ll mn = a[i];
                for (int k = 0; k <= j; k++){
                    mn = min(mn, a[i+k]);
                }
                dp[i][left] = min(dp[i][left], mn*(j+1) + dp[i+j+1][left-j]);
            }
        }
    }
    ll res = dp[0][0];
    for (int i = 0; i <= k; i++) res = min(res, dp[0][i]);
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
