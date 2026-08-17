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

//  temp 
//  1 1 2 2 3 3 4 4 5 5 .. n n 
//  0 1 1 2 2 3 3 4 4 5 5 .. n-1
//  0 0 1 1 2 2 3 3 4 4 5 5 . n-1
//  5 4 3 2 1 1 2 3 4 5 
//  0 0 0 0 0 1 2 3 4 5 
//  0 0 0 0 0 0 0 0 0 0
//
//
// NOTE: observations
// 1. after any iteration
//  - the array is prefixed with "0"
//  - the array is non-decreasing 
// 2. at least one new "0" prefixed, -> at most "n" iterations 
// 3. the number of appears can increase 
// 4. say we processed once 
//  -> any number that appears once is gone next 
//  -> if it appears at least twice now, it has to be in a row 
//  -> 
//  
// WARNING: 
// 1. do two iterations 
//  -> first one markes the arrya but might not be consistent 
//  -> second one remove singles, 
//  -> the rest we multiply by the index left 
//
// guess? 
// -> after some number of iteratoins it becomes normal 
// -> 


void solve(){
    int n;
    cin >> n;
    vi a(n), b(n);
    ll res = 0;
    for (auto& z:a) cin >> z;
    vi freq(n+1,0);
    int mx = 0;
    for (int i = 0; i < 2; i++){
        freq.assign(n+1,0);
        b.assign(n, 0);
        mx = 0;
        for (int j = 0; j  < n; j++){
            res += a[j];
            freq[a[j]]++;
            if (freq[a[j]] > 1) mx = max(mx, a[j]);
            b[j] = mx;
        }
        debug(a, res);
        a = b;
    }
    debug(a,res );
    for (int i = 0; i < n; i++){
        int k = n - i;
        res += (ll)a[i] * k;
    }
    cerr << endl;
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
