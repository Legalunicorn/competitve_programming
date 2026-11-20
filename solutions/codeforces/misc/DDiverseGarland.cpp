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

void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    // there are only 3 colors 
    // greedy might not work we have to switch it somehow 
    // R, G, B -> '0' , '1' , '2' 
    // dp[i][3] -> given a[i] is set to XX, what is the min cost to make arr [i,n] diverse 

    vvi dp(n, vi(3,-1));
    vi a(n);
    for (int i=0;i<n;i++){
        if (s[i]=='B') a[i] = 1;
        else if (s[i]=='G') a[i] = 2;
    }
    debug(a);
    vvi trace(n, vi(3,0));

    auto go = [&](auto& go, int pos, int col) -> int{
        debug(pos,col);
        if (pos == n) return 0;
        if (dp[pos][col] != -1) return dp[pos][col];
        // col -> the wanted color for a[pos];
        int base = (a[pos] == col ? 0 : 1);
        int extra = n;
        for (int c2 = 0; c2 < 3; c2++){
            if (col == c2 ) continue;
            int t = go(go,pos+1, c2);
            extra = min(extra, t);
        }
        debug(pos,col,extra+base);
        return dp[pos][col] = extra+base;
    };


    ll res = n;
    for (int c = 0 ; c < 3; c++){
        ll x = go(go, 0, c);
        debug("=============");
        if (x < res){
            res = x;
        }
    }
    string out;
    int curr = -1;
    for (int i=0; i <n;i++){
        int mn= n+1;
        int op = -1;
        for (int j =0; j < 3; j++){
            if (j == curr) continue;
            if (dp[i][j] < mn ){
                mn = dp[i][j];
                op = j;
            }
        }
        curr = op;
        if (curr==0) out+='R';
        else if (curr==1) out+='B';
        else out+='G';
    }
    debug(dp);
    cout << res << endl << out << endl;
    


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
