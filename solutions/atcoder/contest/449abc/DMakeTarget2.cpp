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

// NOTE: t
// there is a ring pattern for black notes 
// 2 10e 6 ^2 = 10 e 12 total notes 
// i think we can just use the ring pattern  
// we split the vertical and horizontal dots 
// the remove double count corners 
//
// exampe -4, -2, 0, 2 
//
// the black dots are on even rows 
// and also on even columns 
//
// is this combi? 
//
// what is the grid of even ROWS or EVEN COLS 
// can we solve rows by row? 
// can we solve by rings? 
//
// or given a row, and left and right can we find the dots ? 
// what do we notice about coordinates of rings 
//
// 2,2 
// 4,4 
//
// less visual more math 
// row = 4, how many can we grab? anything from 1- 3 
// row = 3 how many can we grab? all even from 4 above 


// what i want is exclusively 
// two components 
// 1. all rows larger than column and is even 
// 2. if the colum is even, tat everything under it 
// what does it mean for abs(row) > abs(col) .. 
//
// can we treat 
//
//
// is my approach just wrong 
// i feel like its correc just super hard to calculat e
// maybe its just math instead 
//
//
// can we split into quardrants? 
//
// or upper and loewr half 
//

void solve(){
    int l,r,d,u;
    cin >> l >> r >> d >> u;

    // if both u and d are negative we can flip them 
    if (u<=0 && d<=0){
        u = abs(u);
        d = abs(d);
        swap(u,d);
    }

    debug(l,r,d,u);
    cerr << endl;

    // column by colum 
    ll res = 0;
    // can we just shift everything by a large amount NO 
    for (int c = l; c <= r; c++){
        int ans = 0;
        int ac = abs(c);

        if (u >= ac){
            // find the lower bound which is the max of {ac, u}
            int bot = max(ac, d);
            if (bot)
            int score = (u - bot) / 2 + 1;
            debug(score, d, bot);
            ans += score;
        }

        if (abs(d) >= ac) {
            // -c ... 
            int bot = min(-ac, u);
            int score = abs((d - bot) / 2) + 1;
            debug(score, d, bot);
            ans += score;
        }

        if (abs(c) % 2 == 0){

            int t = abs(c);
            int high = min(u, t-1);
            int low = max(-(t-1), d);
            if (high >= low){
                debug(high, low);
                int v = high - low + 1;
                ans += v;
            }
            //
            // // if (c == 0) continue;
            //
            //
            //
            // // the full part 
            // int t = abs(c);
            // int high = min(t-1, u);
            // int low = max(-(t-1), d);
            // debug(c,high,low, high-low+1);
            // ans += (high - low + 1);
        }
        res += ans;

        debug(ans,c);
        cerr << endl;
    }
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
