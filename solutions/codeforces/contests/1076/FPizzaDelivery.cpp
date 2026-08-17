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


// dp ? 
// obvious we have to splce the grah by x coordinate 
// there are at most "n" slices 
// the "x" is the equivalcen class 
// this is very dp able
// 1. within each vertical slice 
// 2. the distance is MIN dist to edge + height of vertical slice 
//
// sort the coordinates 
// group vertically 
// let dp[i] be the min dist from START to [i] 
//  ---- messy --- 
//
//  let us group by verticla slices x_i 
//
//  dp[i] = 
//
//  i feel like the position you end up in are very limited and obvious 
//  the edge case is at the end we need to add the extra dict to By 


void solve(){
    int n, ax, ay, bx, by;
    cin >> n >> ax >> ay >> bx >> by;
    vi xpos(n), ypos(n);
    vpi pos(n);
    map<int, pi> mp;
    for (auto& z:xpos) cin >> z;
    for (auto& z:ypos) cin >> z;
    mp[ax] = {ay, ay};
    mp[bx] = {by, by};

    for (int i = 0; i < n; i++) {
        int x = xpos[i], y = ypos[i];
        if (!mp.count(x)) mp[x] = {y,y};
        mp[x].F = min(y, mp[x].F);
        mp[x].S = max(y, mp[x].S);
    }

    vl vert;
    vpl bound;
    for (auto& [x, p]: mp){
        vert.pb(x);
        bound.pb(p);
    }
    int m = vert.size();
    vvl dp(m+1, vl(2, 0));
    
    ll md = min( ay - bound[0].F, bound[0].S - ay) + bound[0].S - bound[0].F;

    dp[1][0] =  (bound[0].S - ay) + bound[0].S - bound[0].F; // go to TOP, go to down;
    dp[1][1] =  (ay - bound[0].F) + bound[0].S - bound[0].F; // go down then go up
                                                                  //
    for (int i = 2; i <= m; i++){
        int j = i - 1;
        ll h = bound[j].S - bound[j].F;
        // dp[i][0] -> end up at the BOTTOM 
        // 1) start from previous BOTTOM: go to TOP, go to BOTTOM 
        // 2) startr from previous TOP: go to TO, go to BOTTOM 
        ll btb = dp[i-1][0] +  abs(bound[j-1].F  - bound[j].S) + h;
        ll ttb = dp[i-1][1] + abs(bound[j-1].S - bound[j].S) + h;
        dp[i][0] =   min(btb, ttb) + vert[j] - vert[j-1];

        ll bbt = dp[i-1][0] + abs(bound[j-1].F - bound[j].F) + h;
        ll tbt = dp[i-1][1] + abs(bound[j-1].S - bound[j].F) + h;
        dp[i][1] = min(bbt,tbt) + vert[j] - vert[j-1];
    }
    ll one = dp[m][0] + abs(bound[m-1].F - by);
    ll two = dp[m][1] + abs(bound[m-1].S - by);
    cout << min(one, two) << endl;
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
