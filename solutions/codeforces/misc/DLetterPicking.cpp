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


int cmp(char a, char b){
    if (a<b) return -1;
    else if (a>b) return 1;
    return 0;
};

void solve(){
    string s; cin >> s;
    int n = s.size();
    vvi dp(n+1, vi(n));
    for (int i = 0; i+1<n;i++)
        if (s[i]!=s[i+1]) dp[i][i+1] = -1;
        else dp[i][i+1] = 0;
    for (int d = 3; d < n; d +=2){
        for (int i = 0; i < n-d; i++){
            int j = i+d, r1,r2,r3,r4;
            if (dp[i+2][j]!=0) r1 = dp[i+2][j];
            else r1 = cmp(s[i], s[i+1]);
            if (dp[i+1][j-1]!=0) r2 = dp[i+1][j-1];
            else r2 = cmp(s[i],s[j]);
            if (dp[i+1][j-1]!=0) r3 = dp[i+1][j-1];
            else r3 = cmp(s[j], s[i]);
            if (dp[i][j-2]!=0) r4  = dp[i][j-2]; 
            else r4 = cmp(s[j], s[j-1]);
            dp[i][j] = min(
                    max(r1,r2), // alice left 
                    max(r3,r4)  // alic right
                    );
        }
    }
    int ans = dp[0][n-1];
    if (ans == 0) cout << "Draw" << endl;
    else cout << "Alice" << endl;
}


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
