#include <bits/stdc++.h>
#include <cstdlib>
#include <functional>
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
// the optimal strategy is obvious 3 groups 
// 1. divisible by all elements
// 2. not divisible by any element 
// 3. divisible by some
//
// since x dont change, its optimaly to consume 3 first, and then each person is left ot their own resources
// we need to count 2/3 of those values, they are mutually exclusive
//
// NOTE: 
// the values are bounded by n,m 
// x1, x2, .., xn 
// suppose we just iterate over all their multiples, its M log M ? 
// or we precompute M log M or something -> 
//
// can we conside prime factors? 
// consider sqrt(n)?    
//
// PERF: divisible by all -> y | LCM(x)
// -> trivial, just find LCM(x), and for each y | LCM, we add 1
//
// PERF: disisible by none ?
//
//
// PERF: mixed, divisible by some -> we cant count how many its divisible by OR upper bound it 
// 
//
//
//
// perhaps  (brute force)
// 1. get all divisors of Y_i 
// 2. iterate divisors and check if exist if X_i
//
// i have no clue if this tle

vb s(2000005);
// vi f(2000005);



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

struct SetHash {
    set<int> elements;
    uint64_t h = 0;
    custom_hash hash_number;

    void insert(int x) {
        if (elements.insert(x).second) h ^= hash_number(x);
    }
    void erase(int x) {
        if (elements.erase(x)) h ^= hash_number(x);
    }
};

//
// vi divi[2000005];
// void init(){
//     for (int i = 1; i < 2000004; i++){
//         for (int j = i; j < 2000004; j +=i){
//             divi[j].pb(i);
//         }
//     }
// }


void solve(){
    int n,m;
    cin >> n >> m;
    vl a(n), b(m);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    int u = n+m+1;
    int none = 0, mix = 0, all = 0;
    ll l = 1;
    for (auto& z: a){
        l = lcm(z, l);
        l = min(l,u+5ll);
    }
    vb seen(u);
    map<int,int> ma;

    for (auto& z: a) ma[z]++;
    for (auto& [v,c]: ma){
        ll z = v;
        while(z < u){
            seen[z] = true;
            z += v;
        }
    }
    for (auto& t:b){
        if (t >= l && t % l == 0){
            all++;
            continue;
        }
        if (!seen[t]) none++;
        else mix++;
    }

    debug(a);
    debug(b);
    debug(none,mix,all);

    for (int i = 0; i < m; i++){
        if (mix>0){
            mix--;
            continue;
        }
        if (i%2==0){ // alice turn
            if (all == 0){
                // debug(i,none,mix,all);
                cout << "Bob" << endl;
                return;
            }
            all--;
        } else{
            if (none ==0) {
                // debug(i,none,mix,all);
                cout << "Alice" << endl;
                return;
            }
            none--;
        }
    }
    // debug("end", none,mix,all);
    if (m % 2 == 0) cout << "Bob" << endl;
    else cout << "Alice" << endl;
}
// void solve(){
//     ll n,m;
//     cin >> n >> m;
//     for (int i = 0; i <= n+m+1; i++) {
//         s[i] = false;
//         // f[i] = 0;
//     }
//     int u = n + m + 1;
//     // set<ll> x;
//     ll l = 1ll;
//     for (int i =0 ;i < n; i++){
//         ll z; cin >> z;
//         l = min(l, 10000000ll);
//         l = lcm(l,z);
//         l = min(l, 10000000ll);
//         // x.insert(z);
//         s[z] = true;
//     }
//     unordered_map<ll,int,custom_hash> mp;
//     for (int i= 0 ; i < m; i++){
//         ll z; cin >> z;
//         mp[z]++;
//     }
//     int none = 0, mix = 0, all = 0;
//
//     // O(m)
//     for (auto& [v,c]: mp){
//         // divisible by all 
//         if ((v >= l) && (v % l == 0)){
//             all += c;
//             continue;
//         }
//         // if (x.count(1ll) || x.count(v)){
//         //     mix += c;
//         //     continue;
//         // }
//         if (s[1] || s[v]){
//             mix += c;
//             continue;
//         }
//         bool found = false;
//         for (auto& d: divi[v]){
//             if(s[d] || s[v/d]){
//                 found = true;
//                 break;
//             }
//         }
//         // for (ll i = 2; i * i <= v; i++){
//         //     if (v%i==0 && (s[i] || s[v/i])){
//         //         found = true;
//         //         break;
//         //     }
//         // }
//         if (found) mix +=c;
//         else none+=c;
//     }
//
//     // O(m)
//     for (int i = 0; i < m; i++){
//         if (mix>0){
//             mix--;
//             continue;
//         }
//         if (i%2==0){ // alice turn
//             if (all == 0){
//                 // debug(i,none,mix,all);
//                 cout << "Bob" << endl;
//                 return;
//             }
//             all--;
//         } else{
//             if (none ==0) {
//                 // debug(i,none,mix,all);
//                 cout << "Alice" << endl;
//                 return;
//             }
//             none--;
//         }
//     }
//     // debug("end", none,mix,all);
//     if (m % 2 == 0) cout << "Bob"  << endl;
//     else cout << "Alice" << endl;
//
//
// };

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
