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
    int n;
    cin >> n;
    vi a(n-1), b(n-1);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;

    vvi dp(n, vi(4, -1));
    auto go = [&](auto& go, int i, int v) -> int{
        if (i == n - 1) return dp[i][v] = 1;
        if (dp[i][v] != -1) return dp[i][v];
        int ans = 0; // not possible;
        for (int u = 0; u <= 3; u++){
            if ( (v&u) == b[i] && (v|u)==a[i]){
                ans |= go(go,i+1,u);
            }
        }
        return dp[i][v] = ans;
    };
    for (int i = 0; i <= 3; i++) go(go,0,i);
    int st = -1;
    for (int v = 0; v <=3; v++){
        if (dp[0][v]==1) st = v;
    }
    if (st == -1){
        cout << "NO" << endl;
        return;
    }
    int cur = st;
    vi t(n);
    debug(st);
    for (int i = 0; i + 1 < n; i++){
        if (dp[i][cur] == 1){
            t[i] = cur;
            for (int nxt = 0; nxt <= 3; nxt++){
                if ( (cur&nxt) == b[i] && (cur|nxt)==a[i] && dp[i+1][nxt]==1){
                    debug(i, nxt);
                    cur = nxt;
                    break;
                }
            }
        }
    }
    t[n-1] = cur;
    debug(dp);
    cout << "YES" << endl;
    for (auto& z: t) cout <<  z << " ";
    cout << endl;

    

    // debug(a,b);
    // bool valid = true;
    // for (int i = 0; i + 1 < n; i++){
    //     if (a[i] < b[i]){
    //         valid = false;
    //     }
    // }
    // vi t(n);
    // for (int i = 0; i + 1 < n; i++){
    //     t[i] |= b[i];
    //     t[i+1] |= b[i];
    // }
    // might have a retarded dp method
    // dp[i][4] -> possible or NOT 
    //
    // for (int i = 0; i < n; i++){
    //     if (i>0) t[i] |= b[i-1];
    //     t[i] |= b[i];
    // }

    // if two numbers in a[i] dont share a bit,
    debug(t);
    // for (int i = n-2; i >= 0; i--){
    //     if ( (t[i]|t[i+1]) == a[i]) continue;
    //
    //     // int g = t[i+1];
    //     // if ()
    //     // you are assuming b[i+1] has to take ALL the missing parts 
    //     // or b[i] has to take ALL the missing parts 
    //     // the special case is: AND = 0, OR = 3 
    //     // it need not be {0,3} or {3,0} but {2,1} works 
    //     //
    //     // for (int b = 0; b < 3; b++){
    //     //     if (a[i] >> b & 1) g |= (1<<b);
    //     // }
    //     // if (i + 2 < n && (g&t[i+2]) != b[i+1]){
    //     //     // b[j] = g not allowed 
    //     //     for (int b = 0; b < 3; b++) if (a[i] >> b ^ 1) t[i] |= (1<<b); // we forced to update t[i]
    //     // } else{
    //     //     t[i+1] = g;
    //     // }
    // }
    //
    // for (int i = 0; i + 1 < n; i++){
    //     if ( (t[i]|t[i+1]) != a[i]) valid = false;
    //     if ( (t[i]&t[i+1]) != b[i]) valid = false;
    // }
    // debug(t);
    // if (valid){
    //     cout << "YES" << endl;
    //     for (auto& z: t) cout << z << " ";
    //     cout << endl;
    // } else cout << "NO" << endl;
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
