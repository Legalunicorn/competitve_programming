#include <bits/stdc++.h>
#include <stdatomic.h>
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
    int n,h,w; 
    cin >> n >> w >> h;
    vvi a;
    for (int i = 0; i < n; i++){
        int x,y; cin >> x >> y;
        if (x > w && y > h) a.pb({x,y, i+1});
    }
    if (a.size() == 0){
        cout << 0 << endl;
        return;
    }
    sort(all(a));

    int m = a.size();
    vi dp(m+1, 1), trace(m+1);
    for (int i = 0; i < m; i++) trace[i] = i;
    for (int i = 1; i < m; i ++){
        for (int j = 0; j < i; j++){
            if (a[j][1] < a[i][1] && a[j][0] < a[i][0]){
                if (dp[j]+1 > dp[i]){
                    dp[i] = dp[j]+1;
                    trace[i] = j;
                }
            }
        }
    }
    int res = 1;
    int pos = 0;
    for (int i = 0; i  < m; i++) 
        if (dp[i] > res){
            res = dp[i]; 
            pos = i;
        }

    vi ans;
    while(pos != trace[pos]){
        ans.pb(a[pos][2]);
        pos = trace[pos];
    }
    ans.pb(a[pos][2]);
    reverse(all(ans));
    cout << res << endl;
    for (auto& r:ans) cout << r << " ";




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
