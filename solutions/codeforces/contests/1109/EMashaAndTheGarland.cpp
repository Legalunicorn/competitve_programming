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
// there two patterns and only two 
// start with 0 or statrt with 1 
// oh wait im confused
// the gamesd are indenepdent 
// okok 
// the game is only considered [L,R]
// and the k options is free to choose ANY subsegments
//
//
// we just need to preprocess [L,R] stuff 
// obviously if k >= [l,r]/2 we can just win 
// we want the min operations 
// there is some greedy involved?
//
//
// NOTE:
// (1) -> we can consider offline qwuiereis     
// 
//
// NOTE:
// we must first solve the problem of string -> alternative min steps
// overulsy k operatyion do not overlap on a segment    
// and also the selectred segment MUST be alternating itself 
// or ewlse it makes no sense 
//
// worse case? 
//  0 0 0 0 
//  -> 2 operation 
//  0 0 1 1 -> 1 operation 
//  0 0 0 1 -> 1 operation 
//  1 0 0 1 -> 1 operation 
//
//  i think we can split the string into segments of alternating paths 
//  0 0 1 1 0 
//  0 | 0 1 | 1 0 
//  then the answer is how many segments are within LR? let X = segcount, we need X//2 
//
// i thin kso



void solve(){
    int n,q;
    cin >> n  >> q;
    string s; cin >> s;

    vi mark(n,0);

    char cur = s[0];
    for (int i = 0; i < n; i++){
        if (s[i] != cur){
            cur = s[i]; 
        } else{
            mark[i]++;
            cur = s[i];
        }
    }
    for (int i = 1; i < n; i++) mark[i] += mark[i-1];

    // my implementation is right 
    // means idea is ass
    // there is no zero division either
    for (int z = 0; z < q; z++){
        int l,r,k;
        cin >> l >> r >> k;
        l--,r--;
        int segs = mark[r];
        segs = segs - mark[l] + 1;
        // if (l-1 >= 0) segs = segs - mark[l-1] + 1; // this s
        int ned = segs/2;
        debug(l,r,k,segs,ned);
        if (ned <= k) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    // cerr << endl;
};

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
