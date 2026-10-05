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
// some squre turn on an turn off 
// suppose there is a moment that a square is LAST turned offed 
// -> it follows the final color change
//
// reword this
// the last COLOR change -> affects everyone who has odd number of tiles operation before that 
//
// 5 7  9 11 
//
// c c c c  (last color operation) 
// O(n)  
// 
// map {index, patity}   square -> how many tile operations
// 
// map represents square whose final color is undecided
// EVEN MAP 
// ODD MAP   -
//
// x x x 
// C
// x x 
// C
// x x x x 
// C
// x x 
// C
// x  -> 
// C  -> blue operaiton 10
//
// C -> final color for all in ODD, 
// x,x,x,x flip square between even and odd
// ad the end a,, unprocesed -> become a

void solve(){
    int n,q;
    cin >> n >> q;
    // vector<vector<char>> p(q, vector<char>(2));
    vvi queries(q, vi(2));
    for (int i = 0; i < q;i ++){
        int id;
        cin >> id;
        queries[i][0] = id;
        if (id == 1){
            int x; cin >> x;
            x--;
            queries[i][1]=x;
        } else {
            char c;
            cin >> c;
            queries[i][1] = c - 'a';
        }
    }
    set<int> done;
    set<int> odd;
    set<int> even;
    // not true;
    vi pairty(n);
    for (int i = 0; i < q;i++){
        if (queries[i][0]==1) pairty[queries[i][1]]++;
    }
    debug(pairty);
    for (int i = 0; i < n; i++){
        if (pairty[i]%2==0) even.insert(i);
        else odd.insert(i);
    }
    vi res(n);
    debug(queries);
    debug(odd, even, done);
    for (int i = q-1; i >= 0; i--){
        if (i+1<q && queries[i][0]==2 && queries[i+1][0]==2) {
            debug("skip", i);
            continue;
        }
        vi qq = queries[i];
        debug(i,qq);
        debug(odd);
        debug(even);
        debug(done);
        if (qq[0] == 1) {
            int v = qq[1];
            if (done.count(v)) continue;
            if (odd.count(v)){
                odd.erase(v);
                even.insert(v);
            } else{
                even.erase(v);
                odd.insert(v);
            }
        } else {
            // clear all odd
            for (auto& o :even){
                res[o] = qq[1];
                debug(o, qq[1]);
                done.insert(o);
            }
            even.clear();
        }
    }
    for(int i = 0; i < n; i++) cout << (char)(res[i]+'a');
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
