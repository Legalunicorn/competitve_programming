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

// length of "s" is maximal possible? 
//
// i think there is a special pattern with skip 4 
// o x x x x o  
// o x o x o x
//
//
// i dont get it. 
// why cant just use altnerate pattnern 
// the skip 4 case is for equal number
// i found a pattern thant consumes 6 characters each tewice 
// and loops forever seamlessly
// the strategy should look something like 
//
// 1. consume the largest, it forms the alternate pattner 
// 2. the alternator is the max of the remaingint two elements 
// 3. at some point if they become equal we can use the 2-2-2 pattern? 
//
// yeah i cant prove it but im sure at some point they will become equal 
// i did some rough case work not real prove but it seems like they awawasy 
// 
//
// 2 2 2 pattern is ultrma 
// we can end off with 1 - 1 - 1
// which is     second, last, third 
// G A B A B G  | B G A 


// implementation 
// sort it every time

void solve(){
    vector<pair<int,string>> g(3);
    int n= 0;
    for (int i = 0; i < 3; i++) {
        cin >> g[i].F;
        n += g[i].F;
    }
    g[0].S = "R";
    g[1].S = "G"; 
    g[2].S = "B";
    string res;
    vector<string> vals = {"R","G","B"};
    debug(g);
    for (int i = 0; i < n;i++){
        sort(all(g)); 
        // if (g[1].F == 0) break;
        if (g[0].F == g[1].F && g[1].F == g[2].F) break; 

        // BUG: cannot blindly use g[2].F becuase the order is not recognise
        // if (g[])
        debug(res,g);
        if (g[1].F < g[2].F || res.size() <= 1){
            debug("one");
            res += g[2].S;
            g[2].F--;
            if (g[1].F == 0) break;
            res += g[1].S;
            g[1].F--;
        } else {
            debug("two");
            int pos = 2;
            for (int i = 0; i < 3; i++){
                if (g[i].S[0] == res[res.size()-2]){
                    pos = i;
                }
            }
            debug(res,pos, vals[pos]);

            int inv = 3 - pos;
            res += g[pos].S;
            g[pos].F--;
            if (g[inv].F == 0) break;
            res += g[inv].S;
            g[inv].F--;
            debug("final", res);
        }
    }
    // cerr << endl;
    // debug(g,res);
    if (g[1].F == 0) {
        cout << res << endl;
        return; // we are done 
    }

    string last = "G";
    string last2 = "B";
    string third = "R";
    int x = g[0].F;
    while(x >= 2){
        if (res.size() > 0) last = res[res.size()-1];
        if (res.size() > 1) last2 = res[res.size()-2];
        if (last2 == last){
            for (int i = 0; i < 3; i++) if (vals[i] != last) last2 = vals[i];
        }
        for (int i = 0; i < 3; i++){
            if (vals[i] != last && vals[i] != last2) third = vals[i];
        }
        string next = last2 + last + third + last + third +last2; 
        res += next;
        x-=2;
    }
    if (x ==0){
        cout << res << endl;
        return;
    }
    if (res.size() > 0) last = res[res.size()-1];
    if (res.size() > 1) last2 = res[res.size()-2];
    if (last2==last){
        for (int i = 0; i < 3; i++) if (vals[i] != last) last2 = vals[i];
    }
    for (int i = 0; i < 3; i++) if (vals[i] != last && vals[i] != last2) third = vals[i];
    string next = last2 + last + third;
    res += next;
    cout << res << endl;



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
