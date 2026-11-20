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


// NOTE:
// y - + 
// g - + 
//
// [0] = y+ g+
// [1] = y+ g-
// [2] = y- g+
// [3] = y- g-
//
// what about y = 0, or y = 0;
// special case ? we 
//
//
// consider 



// SORT  with pos gradients and sort within nega
//
// within each POS ``
void solve(){
    int n;
    cin >> n;

    vpl g_pos_top;
    vpl g_pos_bot;
    vpl g_neg_top;
    vpl g_neg_bot;
    int negcnt = 0;
    int poscnt = 0;
    int hpos = 0, hneg = 0;
    int vpos = 0, vneg = 0;
    map<pl, int> cp;
    map<pl, int> cn;
    for (int i= 0; i < n; i++){
        ll x,y;
        cin >> x >> y;
        if (x == 0){
            if (y < 0) vneg++;
            else vpos++;
            continue;
        } else if (y == 0 ){
            if (x < 0) hneg++;
            else hpos++;
            continue;
        }

        int cnt = 0;
        if (x < 0) cnt++;
        if (y < 0) cnt++;
        ll top = abs(x);
        ll bot = abs(y);
        ll g = __gcd(top,bot);
        top /= g;
        bot /= g;
        if (cnt == 0 || cnt == 2){ // g_pos
            if (y > 0) g_pos_top.pb({top,bot});
            else g_pos_bot.pb({top,bot});
            cp[{top,bot}]++;
        } else {
            if (y > 0) g_neg_top.pb({top,bot});
            else g_neg_bot.pb({top,bot});
            cn[{top,bot}]++;
        }
    }
    auto cmp = [&](const auto& p, const auto q){
        ll left = p.F * q.S;
        ll right = p.S * q.F;
        return left > right;
    };
    sort(all(g_pos_top), cmp);
    sort(all(g_pos_bot), cmp);
    sort(all(g_neg_top), cmp);
    sort(all((g_neg_bot)), cmp);
    ll above = g_pos_top.size() + g_neg_top.size() + vpos;
    ll below = g_pos_bot.size() + g_neg_bot.size() + vneg;
    ll right = g_pos_top.size() + g_neg_bot.size() + hpos;
    ll left  = g_pos_bot.size() + g_neg_top.size() + hneg;

    ll res = max({
            above + max(hpos, hneg),
            below + max(hpos, hneg),
            right + max(vpos, vneg),
            left  + max(vpos, vneg)
            });


    auto gt = [&](vpl& x, ll t, ll b) -> int {
        if (x.empty()) return 0;
        ll l = 0, r = x.size()-1, bs = x.size();
        while(l<=r){
            ll m = (l+r)/2;
            ll ad = t * x[m].S;
            ll bc = b * x[m].F;
            if (ad > bc){
                bs = m;
                r = m -1;
            } else l = m+1;
        }
        return x.size()-bs;
    };
    auto lt = [&](vpl& x, ll t, ll b) -> int {
        if (x.empty()) return 0;
        ll l = 0, r = x.size()-1, bs = -1;
        while(l<=r){
            ll m = (l+r)/2;
            ll ad = t * x[m].S;
            ll bc = b * x[m].F;
            if (ad < bc){
                bs = m;
                l = m + 1;
            } else r = m- 1;
        }
        return bs+1;
    };
    for (auto& [t,b]: g_pos_top){
        ll base = hpos + vneg + g_neg_bot.size();
        base += lt(g_pos_top,t,b);
        base += gt(g_pos_bot,t,b);
        base += cp[{t,b}];
        res = max(res, base);

        base = hneg + vpos + g_neg_top.size();
        base += gt(g_pos_top,t,b);
        base += lt(g_pos_bot,t,b);
        base += cp[{t,b}];
        res = max(res, base);
    }
    debug(res);
    for (auto& [t,b]: g_neg_bot){
        ll base = vpos + hpos + g_pos_top.size();
        base += lt(g_neg_bot, t,b);
        base += gt(g_neg_top,t,b);
        base += cn[{t,b}];
        res = max(res, base);

        base = vneg+hneg + g_pos_bot.size();
        base += gt(g_neg_bot, t,b);
        base += lt(g_neg_top,t,b);
        base += cn[{t,b}];
        res = max(res, base);
    }
    debug(res);
    for (auto& [t,b]: g_pos_bot){
        ll base = g_neg_top.size() + hneg + vpos + cp[{t,b}];
        base += lt(g_pos_bot, t,b);
        base += gt(g_pos_top, t,b);
        res = max(res, base);

        base = g_neg_bot.size() + hpos + vneg + cp[{t,b}];
        base += gt(g_pos_bot, t,b);
        base += lt(g_pos_top, t,b);
        res = max(res, base);
    }
    debug(res);

    for (auto& [t,b]: g_neg_top){
        ll base =  g_pos_top.size() + vpos + hpos + cn[{t,b}];
        base += gt(g_neg_top, t,b);
        base += lt(g_neg_bot, t,b);
        res = max(res, base);

           base =  g_pos_bot.size() + vneg + hneg + cn[{t,b}];
        base += lt(g_neg_top, t,b);
        base += gt(g_neg_bot, t,b);
        res = max(res, base);
    }
    debug(res);
    cout << res << endl;
}



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
