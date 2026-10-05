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


// sorted binary is always funny 
// 0000 
// 1111
// 000 | 111 
// 1. if sorted return 0 
// 1. 
//
// uniform arrayy
// if we have a prefix 0, we can AND the rest of the 1s
// if we have a prefix 1, we can OR the rest of the 0s 
//
// 000 | 111  
// -> this is weird form 
// say we want to produce this form 
// then there is a separation 
// all the "1" in left -> we can use "AND" so long there exist a "0" before it 
// all the "0" in right -> we cna use "OR" so long there is a "1" before it 
//
//
// wait actually 
// s1 is undefined? wtf is s1 AND nothing 
// or is it s1 and itself ? 
//  or 
//  o o -
//  NOTE:
// rules: 
//  if there is a "1" we can convert to "1" 
//  if there is a "0" we can coonvert to "0"
//  all "0" come before all "1"
//  
//  - we cannot create "1" out of a prefix of "0s"
//      if we decide to partition, it MUST strart from the firstr "1" position
//      - 
//  - we cannot create "0" out of a prefix of "1"s (and we shouldnt)
// if s0 = 1, we must be all 1s
// assume there is valid partion 
// 1. convert all zeros in the right to ones using OR 
// 1. convert all 1 -> 0, left,  using AND
//
// parition IFF s0 == 0
void solve(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    if (s[0] == '1'){
        // we have no choice
        debug("imp", s);
        int res = 0;
        for (char c: s){
            if (c=='0') res++;
        }
        cout << res << endl;
        return;
    }
    int res = n;
    // lets try base case: no parition, covert all to 0
    int tt = 0;
    for (int i = 0; i < n; i++){
        if (s[i] == '1') tt++;
    }
    res = min(res, tt);
    if (res == 0){
        cout << res << endl;
        return;
    }
    // there exist a 1 somewhere

    vi sf(n);
    vi pf(n);
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') sf[i] = 1;
        else pf[i] = 1;
    }
    // suffix sums of zeros
    for (int i = n-2;i>=0; i--) sf[i]+=sf[i+1];
    for (int i = 1; i < n; i++) pf[i]+=pf[i-1];
    bool seen = false;
    for (int i = 0; i < n; i++){
        if (s[i]=='1') seen = true;
        if (!seen) continue;
        // we have seen, now we must partition 
        int evl = sf[i]; // number of ZEROS
        if (i-1>=0) evl+=pf[i-1]; // number of prefix ONES:
        res = min(res, evl);
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
    cin >> T; 
    while(T--) solve();
    return 0;
}
