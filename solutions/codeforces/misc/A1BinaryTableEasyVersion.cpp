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



void help(int r, int c, vvi& res, vvi& g){
    int cnt = 0;
    vpi ones, zeros;
    for (int i = 0; i < 2; i++){
        for (int j = 0; j < 2; j++){
            if (g[r+i][c+j] == 1) {
                cnt++;
                ones.pb({r+i, c+j});
            } else zeros.pb({r+i, c+j});
        }
    }
    debug(ones, zeros, r, c);
    debug("START", g);
    vi temp;
    int o = 0, z = 0;
    if (cnt == 0) return;
    else if (cnt == 1) {
        o = 1;
        z = 2;
        // flips all the ones!
    } else if (cnt ==2){
        z = 2;
        o = 1;
    } else if (cnt == 3){
        o = 3;
        z = 0;
    } else if (cnt == 4){
        o = 3;
        z = 0;
    }
    debug(o,z);
    for (int i = 0; i < o; i++){
        int x = ones[i].F, y = ones[i].S;
        temp.pb(x+1);
        temp.pb(y+1);
        g[x][y] = 1 - g[x][y];
    }
    for (int i = 0; i < z ; i++){
        int x = zeros[i].F, y = zeros[i].S;
        temp.pb(x+1);
        temp.pb(y+1);
        g[x][y] = 1 - g[x][y];
    }
    debug("END", g);
    res.pb(temp);
    help(r,c,res,g);
    
}


void solve(){
    int n, m;
    cin >> n >> m;
    vvi g(n, vi(m));
    for (int i = 0; i < n; i++){
        string s; cin >> s;
        for (int j = 0; j < m; j++) g[i][j] = s[j]-'0';
    }
    debug(n,m,g);
    vvi res(0, vi(6));
    // clear left to right + the extra
    for (int r = 0; r + 1 < n; r+=2){
        for (int c = 0; c + 1< m; c += 2){
            debug("CALL: ",r ,c);
            help(r,c,res,g);
        }
        if (m%2 ==1) debug("CALL2", r, m-2);
        if (m%2 ==1) help(r, m -2, res, g);
    }
    if (n%2==1){
        for (int c = 0; c + 1 < m; c+=2){
            help(n -2, c, res, g);
        }
        if (m%2==1) help(n-2,m-2, res,g);
    }
    cout << res.size() << endl;
    for (auto& rr: res){
        for (auto& x: rr) cout << x << " ";
        cout << endl;
    }
    cerr << endl;

    // check extra row here: 

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
