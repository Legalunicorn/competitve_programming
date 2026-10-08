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

// 
// NOTE:
// wait odd natural divisors is just perfect square
// that means the prime divisors are all even
//
//this might be just imppl 
//
// regardless -> we want to find ALL i 
//  that satisfies some condition 
//  - unseen prime divisor -> even 
//  - 
//
//  if we current have some ODD powers 
//  IFF -> we expact the search number to have ODD pointer in exactly all those 
//  in essetneice 
//  must match exaclty
//  idk if a map is fast
//
// the idea is just 
// maintain the freuqnecy of prime factors as we go 
// then maintain set of ODD frequencyes 
// then 
//
// BUG: 1 -> is a special case, we must consider it or what idk?
// 1 -> changes nothing to product, so if we have no ODD, we can plus all the ones
//
//
// PERF: 1) for each j, count how many i 
// seems more natural 
// -> maintain 
//
//
//
// PERF: 2) for each i count how many j

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

unordered_map<int,int,custom_hash> factor(int n){
    unordered_map<int,int,custom_hash> res;
    for (int i=2; i*i <= n;i++){
        while (n%i==0){
            res[i]++;
            n /= i;
        }
    }
    if (n>1) res[n]++;
    return res;
}

long long compute_hash(ll x) {
    static const ull seed =
        chrono::steady_clock::now().time_since_epoch().count();
    return custom_hash::splitmix64(x + seed);
}

long long gay(set<int>& st) {
    const int p = 31;
    const int m = 1e9 + 9;
    long long hash_value = 0;
    long long p_pow = 1;
    for (int c: st) {
        hash_value = (hash_value + (c - 'a' + 1) * p_pow) % m;
        p_pow = (p_pow * p) % m;
    }
    return hash_value;
}

void solve(){
    int n ;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    // map<set<int>, int > g;
    // unordered_map<ll,int, custom_hash>g;
    map<set<int>,int> g;
    int one = 0;
    int alle = 0;


    vector<unordered_map<int,int,custom_hash>> ff(n);
    for (int i = 0; i < n; i++){
        unordered_map<int,int,custom_hash> mp = factor(a[i]);
        auto pt  = &ff[i];
        *pt = mp;
        set<int> codd;
        for (auto& [f,c]: mp){
            if (c%2==1) codd.insert(f);
        }
        // debug(i,a[i], codd);
        if (codd.size()>0){
            g[codd]++;
            // ll h = compute_hash(codd);
            //
            // ll v  = gay(codd);
            // g[v]++;
            // ll t = 0;
            // // for (auto&z: codd) t ^= compute_hash(z);
            // g[t]++;
        }
        else alle++;
    }
    
    // debug(g);
    unordered_map<int,int,custom_hash> freq;
    set<int> odd;
    ull res = 0ll;
    // debug(a);
    ull xxx = 0ll;
    for (int i = 0;i  < n; i++){
        unordered_map<int,int,custom_hash> mp = factor(a[i]);
        bool same = true;
        for (auto& [f,c]:ff[i]){
            int old = freq[f];
            freq[f]+=c;
            int nxt = old+c;
            if ((old%2)==(nxt%2)) continue;
            if (old%2==1){
                odd.erase(f);
                same = false;
            } else {
                odd.insert(f);
                // xxx ^= compute_hash(f);
                same = false;
            }
        }
        // debug(i,freq);
        // consider all answrs nmow
        if (odd.size()>0 && odd.size() < 10){
            ll pp = gay(odd);
            res += g[odd];
        } else{
            if (odd.size()==0) res += alle;
        }
    }
    cout << res << endl;
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
