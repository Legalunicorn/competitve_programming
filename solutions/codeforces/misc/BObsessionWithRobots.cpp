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
    string s;
    cin >> s;
    set<pi> vis;
    map<pi, int> mp; //set a timer 
    set<pi> st;

    int x = 0; 
    int y = 0;
    int t = 0; 

    // you cannot have adjacent points that arent related 

    
    vis.insert({x,y});

    mp[{x,y}] = 0;
    for (char c: s){
        t++;
        if (c=='L') x--;
        else if (c=='R') x++;
        else if (c=='U') y--;
        else y++;
        if (vis.count({x,y})){
            cout << "BUG" << endl;
            return;
        }
        for (auto& d: dirs){
            int r = x+d[0], c = y+d[1];
            if (mp.count({r,c})){
                if (mp[{r,c}] + 1 < t) {
                    cout << "BUG" << endl;
                    return;
                }
            }
        }
        vis.insert({x,y});
        mp[{x,y}] = t;
    }
    debug(mp);
    cout << "OK" << endl;


    // st.insert({0,0});
    // for (char c: s){
    //     if (st.count({x,y})){
    //         cout << "BUG" << endl;
    //         return;
    //     }
    //     st.insert({x,y});
    //     st.insert({x-1,y});
    //     st.insert({x+1,y});
    //     st.insert({x,y-1});
    //     st.insert({x,y+1});
    // }
    // cout << "OK" << endl;

};

// you canno go to a squarer within reach 

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
