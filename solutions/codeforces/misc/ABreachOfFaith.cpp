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

// NOTE:
// the issue is guarentee a[0] generated is unique 
// we know the other values are unique, and all positive 
// the smallest set of values is 
// 1, 2 ,3 .. .n, n + 1, ... 2n 
// if we use the greedy method
// plus all [n, 2n] 
// 1 2 3 6 
//
// the largest we can generate is x, the smallest is -x 
// but we can only use from [1, x-1] 
// let say its 1 2 3 4 
// 7 - 3 = 4 
// [1,3] -> not possible it will surely coincided 
// 1 2 4 6 3 
// 1 2 3 4
// take the smallest as a[0]
//
// then the rest we construct the smallest fucking number 
// we want to fill in the gap with an even larger number
// which will be a positive init 
//
// we are missing a plus 
// so its 
// - - - 
// + + (?) 
//
// what is this ? 
// - > 
//
// s = - - - + + (?)
//(?)= + + + - - +s 
// but this will be FUCKING SMALL 
//
// s = + + + - - (?)
//
// 1 2 3 4 
// "1" = ? - 4 + 2 - 3 
// "?"+ 
//
//
//
//
// NOTE: realised some, why not just make it as small as possible (hold on to this )
// + - + - 
// - + - + 
// consider MAX(a), -> 10e9 
// we take the smallest number 
//
// observations 
// 1. its NOT always possible to generate a[0] 
// 2. condider MAX(a) and beyond 
// 3. consider MIN(a)
// 4. consider 
//
//
// HINT: maximise the missing number 
//
// 1. a[0] IS the midding number, 
// -> then we can maximise it by sum of large - sum of small 
// -> if there already exist a[0] then we need to makea new largest 
//
//
// what if we put the largest number as a[0]? 
// large = (some sum) + missing 
// and we make (some sum) negative
// 2  9 
// 9 = -2 + missing 
// 
//
// 1 2 3 6 
//
// 6 = +    -3 -2 +1   


void solve(){
    int n;
    cin >> n;
    vl a(2*n);
    for (auto& z:a) cin >> z;
    //set<ll> st(all(a));
    ll s = 0;
    sort(all(a));
    vl minus, add;
    ll sum = 0;
    for (int i = 0; i + 1 < n ;i++){
        // small guess, plus all 
        add.pb(a[i]);
        sum += a[i];
    }
    for (int i = n - 1; i + 1 < 2 * n; i++){
        minus.pb(a[i]);
        sum -= a[i];
    }
    ll miss = a[2*n-1] - sum;
    add.pb(miss);
    debug(miss,sum);
    debug(add);
    debug(minus);
    cerr << endl;
    cout << a[2*n-1] << " ";
    for (int i = 0; i < n; i++){
        cout << add[i] << " " << minus[i] << " ";
    }
    cout << endl;



    // debug(sum,miss);
    // cout << a[2*n-1] << " ";
    // for (int i = 0; i < n; i++){
    //     if (i != n -1) cout << a[i+n] << " ";
    //     else cout << miss << " ";
    //     cout << a[i] << " ";
    // }
    // cout << endl;
    //
    
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
