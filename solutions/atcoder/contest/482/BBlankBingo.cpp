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

void solve(){
    int n = 5;
    vector<string> g(n);
    for (auto& z: g) cin >> z;
    int res = 5;
    for (int i = 0; i < 5; i++){
        int c = 0;
        for (int j =0 ;j < 5 ; j++){
            if (g[i][j] == 'o') c++;
        }
        res = min(res, 5 - c);
    }
    debug(res);
    for (int i = 0; i < 5; i++){
        int c = 0;
        for (int j =0 ;j < 5 ; j++){
            if (g[j][i] == 'o') c++;
        }
        res = min(res, 5 - c);
    }
    int a = 0, b = 0;
    debug(res);
    for (int i = 0; i < 5; i ++){
        if (g[i][i] == 'o') a++;
        if (g[i][4-i]=='o') b++;
        res = min({res,5-a,5-b});
    }
    debug(res);
    debug(a,b);
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
    while(T--) solve();
    return 0;
}
