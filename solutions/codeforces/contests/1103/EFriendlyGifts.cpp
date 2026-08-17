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

// this is binary searchable
// BUG: this is NOT binary searachable 
// -> the order might break it 
// if i can find ans = k 
// then all answer < k also exist
// might rely on some kind of precompute 
//
// n^2 log n is too slow btw 

// the criteria is very strict, if u expand, each elemet must either be min -1  or max + 1 
// note this is not true 
// think about n^ 2 precompute first 
// for each starting point we traverse the array 
// if we see a value before autoamtically invalid 
// otherwise if mx - mn + 1 == LENGTH subsrray, its a valid range from [MN, MX] 
//
// hence we know for each i 
// -> all possible permutations STARTING at it 
// -> there is some distance, each distance is only possible ONCE 
// 
// maybe we can store this range seperate ly 
// with some observcation 
// - if we know two segments exist of lengfth x, and the starting differ by x + 1, 
// its impossible for these segments to overlap 
//
//
// NOTE: 
// -> we if we know exists , it willl NOT overlap 
// -> we can iterate over some constant 
//      1. the length of RES 
//      2. the starting number 
//
//  -> ah wait we can double n^ 2 but im worried its frickly slow 
//  -> first n^2 is precompute 
//  -> second n^2 is 
//      -> for RES = 0 to N/2
//      -> for start in SET(a) 
//          -> query: 
//              start with length R 
//              start+R with length R 
//
// i want to use map but its hella slow 
// imagine 
// 1 2 3 4 5 6 7 8 9 10... 
// i need O(1) access, maybe custom hash 
//
//
//  precompute 
//      ->  for each starting we can derive how many seggs exist 
//          -> 1. size , 2. start 
//
// take from NEAL
struct custom_hash {
    static uint64_t splitmix64(uint64_t x) {
        // http://xorshift.di.unimi.it/splitmix64.c
        x += 0x9e3779b97f4a7c15;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
        x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
        return x ^ (x >> 31);
    }

    size_t operator()(uint64_t x) const {
        static const uint64_t FIXED_RANDOM = chrono::steady_clock::now().time_since_epoch().count();
        return splitmix64(x + FIXED_RANDOM);
    }
};
void solve(){
     int n;
     cin >> n;
     vi a(n);
     for (auto& z:a) cin >>  z;
     set<int> st(all(a));
     vi b;
     for (auto& z: st) b.pb(z);
     // unordered_map<int, unordered_set<int, custom_hash>, custom_hash> mp;
     // vector<unordered_set<int, custom_hash>> g(6001); // i think list is faster
     vector<bitset<6001>> g(6001);
     for (int i = 0; i < n; i++){
         vb seen(6001);
         debug("st", i, a[i]);
         int mn = a[i], mx = a[i];
         for (int j = i; j < n; j++){
             if (seen[a[j]]) break;
             seen[a[j]] = true;
             mn = min(mn, a[j]);
             mx = max(mx, a[j]);
             debug(a[i], j, mn, mx, j - i + 1);
             if (mx - mn + 1 == j - i + 1){
                 // g[mn].insert(j - i + 1); // start -> length;
                 g[mn].set(j - i + 1);
             }
         }
     }
     int res = 0;
     for (int l = 1; l <= n/2; l++){
         bool found = false;
         for (int i = 0; i < b.size(); i++){
             int st = b[i];
             int nx = b[i] + l;
             if (g[st].test(l) && g[nx].test(l)){
                 res = l;
                 found = true;
             }
             if (found) break; // try next L
         }
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
