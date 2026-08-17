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

// CANCER implementation 
// the solution is just 
// for each fauclty 
// we sort the cells by height, then by columsn left to right 
// then we sort the students by ID, then, claculate manhattan distance sum, -> score of faculty
// then the sort score of faculty in decreasing order

void solve(){
    int r,c,f,s,g;
    cin >> r >> c >> f >> s >> g; // what is r, c even for>
    map<int,vpl> fcell;
    map<int, int> sz;
    for (int i = 0; i < f ; i++){
        int k; cin >> k;
        sz[i] = k;
        for (int j = 0; j < k; j++){
            int x,y; cin >> x >> y;
            // fcell[i].pb({y, x});
            fcell[i].pb({x,y});
        }
    }
    map<int, vvi> stu;
    for (int i = 0; i < s; i++){
        int sd, sf, sx, sy;
        cin >> sx >> sy >> sd >> sf;
        sf--;
        // cin >> sd >> sf >> sx >> sy;
        stu[sf].pb({sd, sx, sy});
    }
    // number of studfents for each faculty? isnt this given but sure
    map<int,int> fz;
    for (int i = 0; i < f; i++){
        int z; cin >> z;
        fz[i] = z;
    }
    // time to process this!
    vl evl;
    for (auto& [fac, cell]: fcell){
        // sort by y increasing 
        // tiebreak by x increase
        sort(all(cell));
        vvi ss = stu[fac];
        sort(all(ss));
        // ll cost = 0;
        vl cost;
        for (int i = 0; i < ss.size(); i++){
            int dx = abs(ss[i][1] - cell[i].F);
            int dy = abs(ss[i][2] - cell[i].S);
            // cost += (dx + dy);
            cost.pb(dx + dy);
        }
        sort(all(cost));
        ll sum = 0;
        for (int i = 0; i < fz[fac]; i++){
            sum += cost[i];
        }
        evl.pb(sum);
        // evl.pb(cost);
    }
    sort(all(evl));
    debug(evl);
    ll res =  0;
    for (int i = 0; i < g; i++) res += evl[i];
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
