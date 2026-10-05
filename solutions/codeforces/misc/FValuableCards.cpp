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

// NOTE:
// 10e5 has max ~ 250 divisors 
// if we upper bound it and say for each positoin we check all 250 thats still within time limit 
//
// greedy works. if we can take just take  theres no point leading the next segmet 
// can show with exchange argument
//
// since the max size of divisors is ~250 and we can n * d(n);
// set maintain a set of current divisors and for every element that a[i] | d, we just check thrugh the list of
// might be slow with a set but idk
void solve(){
    int n, x;
    cin >> n >> x;
    vi a(n);
    for (auto& z:a) cin >> z;
    unordered_set<int, custom_hash> st = {1};
    int res = 1;
    vi part;
    debug(a, x);
    for (int i = 0; i < n; i++){
        if (a[i] > x || x%a[i]!=0) continue;
        unordered_set<int,custom_hash> pot;
        int yes = 1;
        for (auto& d: st){
            int nx =  d * a[i];
            if (nx > x) continue;
            if (nx == x){
                yes = 0;
                break;
            }
            if (!st.count(nx)) pot.insert(nx);
        }
        if (!yes){
            // part.pb(i);
            res++;
            st.clear();
            st = {1,a[i]};
        } else{
            for (auto& z: pot) st.insert(z);
        }
        // debug(i, st, res);
    }
    // debug(part);
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
