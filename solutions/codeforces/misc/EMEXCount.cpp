#include <bits/stdc++.h>
#include <csetjmp>
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

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    map<int,int> mp;
    vi freq(n+5);
    int lim = 0;
    for (auto& z:a) mp[z]++;
    for (int i = 0; i <= n+5;i++){
        if (mp[i] == 0){
            lim = i;
            break; // actual mex
        }
    }
    vi diff(n+5, 0);
    for (int m = 0; m <= lim; m++){
        int lb = mp[m];
        int ub = n - m;
        diff[lb]++;
        diff[ub+1]--;
    }
    for (int i = 1; i < n +5; i ++) diff[i] += diff[i-1];
    for (int k = 0; k <= n; k++){
        cout << diff[k] << " ";
    }
    cout << endl;



};

// im blind af 
// EXACLTY k numbers.. 
// maybe we can shift it 
// for each MEX (if attaininable) what values of k? 
// why not we sort the frequencies for valid candidaates? 
// then s

//NOTE:
// the order of the array does not matter
// MEX is probably related to greedy 
// for each k removal what are the possible MEX 
// 1. remove everything -> MEX = 0 
// it makes sense to keep a map of 0,1,2,3,4... 
// count 
// 2 ideas. 1 prefix sum 
// and 2. actual mex by default 
// say the mex = 5, we cannot make the mex any higher 
// since we are only removing 
// so the mex is bounded by the actual mex 
// then how we want to know how many elements can actuqll ybe the emx 
// it depends on how many appened can we remove which can be done with binary search 
// over the prefix sum array from [0,1,2,3,4,5,n]
// we justneed an array of size n (giv ebugger)

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
