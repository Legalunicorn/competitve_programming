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

/* 
        shortest non empty substring
        the substring dx = 0 dy = 0 for it to work 
        
        we can matain prefix sum of dx, and then dy 
        1. we want to know the MIN  subsegment with 0 dx dy, 
        2. can we map with a traversal? 
        for each point, store the last time we visit such as point 
        map<pi, int > 



*/

void solve(){
    int n;
    cin >> n;
    string s; cin >> s;
    map<pi,int> mp;
    mp[{0,0}] = 1;
    int x = 0, y = 0;
    int id = 2;
    int res = INT_MAX; 
    pi ans;

    for (char c: s){
        debug(id);
        if (c=='U') y--;
        else if (c=='D') y++;
        else if (c=='L') x--;
        else x++;
        if (mp.count({x,y})){
            if (id - mp[{x,y}] < res){
                debug(mp[{x,y}]);
                debug(id);
                ans = {mp[{x,y}], id-1};
                res = id - mp[{x,y}];
            }
        }
        mp[{x,y}] = id;
        id++;
    }
    if (res == INT_MAX) cout << -1 << endl;
    else {
        cout << ans.F << " " << ans.S << endl;
    }
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
