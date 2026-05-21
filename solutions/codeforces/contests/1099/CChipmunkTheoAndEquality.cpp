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

// roughly log n operation for each numer 
// min numbr of operations to make all numbers equal 
// NOTE: 
// for each number 
// it will converge to 1 eventually 
// each path to 1 will be ~ log MAX 
// we can maintain a map of numers 
// - count how many numbers meet time 
// - maintain the max step needed to reac them 


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
    for (auto& z:a) cin >> z;
    ll res = INF;
    unordered_map<int,pair<int,ll>, custom_hash> mp; // numbr -> {freq, steps}
    for (auto x: a){
        int o = x;
        if (o == 1) {
            mp[2].S++;
            mp[2].F++;
            mp[1].F++;
            continue;
        }
        int steps = 0;
        mp[x].F ++;
        if (mp[x].F == n){
            res = min(res, mp[x].S);
        }
        while(x != 1){
            if (x % 2 ==1) x++;
            else x/=2;
            steps++;
            mp[x].F++;
            mp[x].S += steps;
            if (mp[x].F == n){
                res = min(res, mp[x].S);
            }
        }
    }
    if (mp[2].F == n) res = min(res, mp[2].S);
    if (mp[1].F == n) res = min(res, mp[1].S);
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
