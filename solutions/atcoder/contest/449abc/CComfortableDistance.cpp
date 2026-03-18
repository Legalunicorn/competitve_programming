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
    int n, l,r;
    cin >> n >> l >> r;
    string s;
    cin >> s;
    ll res = 0;
    vvi f(26, vi(n+1,0));
    for (int i = 0; i < n; i++){
        int c = s[i] - 'a';
        f[c][i] = 1;
    }
    // compute sum
    for (int c = 0; c < 26; c++){
        for (int i = 1; i < n; i++){
            f[c][i] += f[c][i-1];

        }
    }

    for (int i = 0; i < n; i++){
        int c = s[i] - 'a';
        int right = min(n-1, i + r);
        int left = min(n-1, i + l - 1); // we need to go back once for prefix 
        int delta = f[c][right] - f[c][left];
        res += delta;
    }
    cout << res << endl;

    // we can do 26 n that  
    // and some prefix sum 
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
