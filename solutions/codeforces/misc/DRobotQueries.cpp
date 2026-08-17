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

// we can solve this offline 
// take in the queries
// queries[0...id]
// 1. {r,l, id} sort by "r" descending, "l" tiebreaks  increassing? 
// 2. we need to process the front and back too, where applicable 
// {L, id}; then we sort by L increaseig 
// {R, id}; then we sort by R decreasing
// actually we can just use {l,r, id} and use 3 different comaprator
// then we store the answer in res[q]


void solve(){
    int n,q;
    cin >> n >> q;
    string s;
    cin >> s;
    vpi a(n);
    vpi b(n);
    pi _pos = {0,0};
    for (int i = 0; i < n; i++){
        if (s[i] == 'R') a[i] = {1, 0};
        if (s[i] == 'L') a[i] = {-1, 0};
        if (s[i] == 'D') a[i] = {0, -1};
        if (s[i] == 'U') a[i] = {0, 1};
    }
    for (int i = 0; i < n; i++){
        _pos.F += a[i].F;
        _pos.S += a[i].S;
        b[i].F = _pos.F;
        b[i].S = _pos.S;
    }
    vb res(q, false);
    vpi t(q);
    vvi g(q, vi(3));
    for (int i = 0; i < q; i++){
        cin >> t[i].F >> t[i].S;
        cin >> g[i][0] >> g[i][1];
        g[i][0]--, g[i][1]--;
        g[i][2] = i;
        // {0,0} is an auto yes
    }
    // if (s == "LDDUR"){
    //     string bs = "";
    //     int x = 647;
    //     bs+=to_string(t[x].F);
    //     bs+="_";
    //     bs+=to_string(t[x].S);
    //     bs+= "_";
    //     bs+=to_string(g[x][0]);
    //     bs+= "_";
    //     bs+=to_string(g[x][1]);
    //     cout << bs << endl;
    //     return;
    // }
    debug(t);
    debug(s);
    debug(a);
    debug(b);
    set<pi> st;
    st.insert({0,0});
    // 1. sort by L increasing;
    sort(all(g), [&](const auto& p, const auto& q){
        return p[0] < q[0]; // sort by L in ascendsing
    });
    debug(g);
    int id = 0; // the next id to insert
    pi dir = {0,0};
    for (int i = 0; i < q; i ++){
        int j = g[i][2];
        while(id < g[i][0]){
            st.insert(b[id]);
            id++;
        }
        if (st.count(t[j])){ 
            debug(i,id,t[j]);
            res[j] = true; // found
        }
    }
    debug(res);
    sort(all(g), [&](const auto& p, const auto& q){
        return p[1] < q[1]; // sort by "R" ascesningg 
    });
    debug(g);
    st.clear();
    id = n - 1;
    for (int i = q -1 ; i >= 0; i-- ){
        int j = g[i][2];
        while(id > g[i][1]){
            st.insert(b[id]);
            id--;
        }
        debug(i,g[i],t[i],st, id);
        if (st.count(t[j])){
            res[j] = true; 
        }
    }
    debug(res);
    st.clear();
    sort(all(g), [&](const auto& p, const auto& q){
        // sort by L decreasing
        // if L are equal, sort by 
        return p[0] > q[0];
    });
    debug(g);
    // NOTE: recap for middle part 
    // 1. identify delta from L-1 to target position, {Dx,Dy}
    // 2. calculate suffix sum of deltas 
    // 3. for each L, R query, extend until we include L as needed, each of them added to a set ST
    // 4. if R + 1 < q, take the new starting position as suffix[R+1]. ADD IT TO  Dx, Dy. check if result is in ST
    int r = n-1;
    // suffix delta
    debug(r);
    vpi c = a;
    for (int i = n - 2; i >= 0; i--){
        c[i].F += c[i+1].F;
        c[i].S += c[i+1].S;
    }
    debug(a);
    debug(b);
    debug(c);
    map<pi, vi> mp;
    for (int i = 0; i < q; i++){
        int pos = g[i][2];
        while(r >=  g[i][0]){

            // debug(g[i][0],r);
            // st.insert(c[r]); // wht the hell am i doiung
            mp[c[r]].pb(r);
            r--;
        }
        pi start = {0,0};
        if (g[i][0] -1 >= 0){
            start = b[ g[i][0]-1 ];
        }
        pi d = { t[pos].F - start.F, t[pos].S - start.S};
        pi minus = {0,0};
        if (g[i][1] + 1 < n){
            minus = c [g[i][1]+1];
        }
        pi evl = {d.F + minus.F, d.S + minus.S};
        if (pos == 1) {
            debug(g[i]);
            debug(d);
            debug(start);
            debug(minus);
            debug(evl);
            debug(r);
            debug(st);
        }
        cerr << endl;
        if (mp.count(evl)){ 
            // mp has a bunch of stuff 
            // we want anyone that that is greater than g[i][1];
            auto it = lower_bound(all(mp[evl]), g[i][1] , greater<int>());
            if (it != mp[evl].end()) res[pos] = true;
            // res[pos] = true;

        }
    }
    debug(res);
    for (int i = 0; i < q; i++){
        cout << (res[i]? "YES": "NO") << endl;
    }





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
