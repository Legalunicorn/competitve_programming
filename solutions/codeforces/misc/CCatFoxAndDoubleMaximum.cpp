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
// construction problem 
// does the permutation mater? 
// range of the new array [2, 2n]
// a b c d e f 
// -> local max --> we want to make the element --> we want to do so with the least additions? assuming there are alternative index
//
// n is even, n >=4 
// n = 2m
// [1, 2m]
// not that edges cannot be local max
// a b c 
// assume w want to make b local max
// a b d 
// e f g
// b >= a+e-f
// b+f >= d+ g - f
// 1 . . . . . . . . n
// is it optimal to make arr[1] local max if posible? 
// is it always possible to maximise the local max to the max answer? 
// 6 5 1 4 2 3 
// 2 5 1 4 3 6 
// 8 |  10 2 8 5 |9 --> 4 in the middle, nad we have 2 local max
//
// im guessing its always possibl for (n-2)/2 local max, but we need to prove first
// it might not be true, but we should try to do local mex from a[1] or a[2] and then alternate indicies
// each time we add the list possible, and maintain a set of whats left using st.lower_bound();
// is one of two greedy options always optimal? 
//
// what if the solition is not 
// x . x . x . x . 
// . x . x . x .
// but its like 
// 0 8 1 2 7 3 6 4 5 
// . x . x . x . x
// x . . x . x . x
// 1 2 3 4 5 6 7 8 
// 4 > 3, 
// 1 > 2 
// i cant prove it 
//
// alterative direction 
// calcualte for all potential a



void solve(){
    // mega trivial lol
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    bool one = true;
    for (int i =1 ; i < n; i+=2){
        if (a[i] ==1) one = false;
    }
    vi b(n);
    vpi small;
    vpi large;
    vb mark(n, false);
    if (one){
        for (int i = 1; i + 1 < n; i+=2){
            large.pb({a[i],i});
            mark[i] = true;
        }
        for (int i = 0; i < n;i++){
            if (!mark[i]) small.pb({a[i],i});
        }
    } else{
        for (int i = 2; i + 1 < n; i+=2){
            large.pb({a[i],i});
            mark[i] = true;
        } 
        for (int i = 0; i < n; i++){
            if (!mark[i]) small.pb({a[i],i});
        }
    }
    debug(large);
    debug(small);
    sort(all(large));
    sort(rall(small));
    for (int i = 0; i < large.size(); i++){
        b[large[i].S] = n - i;
    }
    for (int i = 0; i < small.size(); i++){
        b[small[i].S] = i+1;
    }
    for (int i= 0 ;i < n;i++) cout << b[i] << " ";
    cout << endl;
    // for (int i = 0; i < n; i++) cerr << a[i] + b[i] << " ";
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
