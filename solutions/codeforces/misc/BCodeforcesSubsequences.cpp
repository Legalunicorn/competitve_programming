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

//NOTE 
//c c
//o o
//d 
//e e
//f
//r  
//s 
//
// c o d d  E  e F f o r c e s 
// this is a combinatoric question 
// we need to figire out hte min 
//
// double repeats are "c" and "o" and "e" 
// extra charcate -> x 2 
// wont it double for every new character we add? 
// why does it double if we add the same characer then? 
//n  n a  A t T 
// 2  x 2 x 2 
// (2 c 2) 


void solve(){
    ll k;
    cin >> k;
    int cnt = 0;
    while(k){
        k /=2;
        cnt++;
    }
    if (cnt == 1){
        cout << "codeforces" << endl;
        return;

    }
    debug(cnt);
    int a = cnt/2;
    int b = (cnt % 2 == 0? cnt/2: cnt/2+1);
    debug(a,b);
    for (int i = 0; i < a; i++) cout << "c";
    cout << "codeforces";
    for (int i = 0; i < b; i++) cout << "s";
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
