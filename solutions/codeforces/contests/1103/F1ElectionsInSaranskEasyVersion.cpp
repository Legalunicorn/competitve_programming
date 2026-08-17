#include <bits/stdc++.h>
#include <pthread.h>
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


// x = 1 should be trivial 
// find the number of different arrays p that are ideal 
// so each a[i] -> we have to pick some divisior 
// then wtf does 
// lcm = PRODUCT all 
// even mean 
// doesnt it mean all the numbers are co-prime? 
// we can ignore 1 
// im just guessing it 
// that all numbers hafe to be co prime 
// like 10, 3 
// different just meaans permutation 
// what makes number co prime? 
// no prime has been seem ebfore 
//
// 1. prime factorize the numbers 
// 2. ~ this is a COMBI problem after all 
// 1. each element has a list of prime factors 
//
// NOTE: {1,1,1,1,1,1} -> always valid 
// there is roughly 40k prime numbers up to 510e5 
// we can technically prui froce this 
// 4 10e 4 * 10e 5 -> 10e9 
// nvm too slow 
//
// 1. there is a stupid case where 
// everyone becomes 1, then the rest of the elements take turns being NOT one 
// which is 
// for each number 
// we group by unique prime 
// then we multiply by the friggin size 
//
//
// there is the "1" casse 
//
//
//
// this is some counting probvlem 
// i feel like that 1 case maybe isnt a edge case 
// what we can do is 
// 1. find some co prime counting, then the rest become 1 
//
//
// for the case of "1" -> i know how to calculate 
// what about the cases where its multiple number not used as "1" 
// i think its still boils down to combi 
// its sort of like 
// for each prime in each number 
// we want to know how the rest of the array can configure 
//
//
// fuck math 
// it dont quite make sense now 
// obviously precompute sieve 
// will it help if we maintain a global map of divisor counters 
// of we maintain total produce or some shit 
// i think its easier to guess the solution 
//

map<int,int> factor(int n){
    // vector<int> res;
    map<int,int> mp;
    for (int i=2; i*i <= n;i++){
        while (n%i==0){
            // res.push_back(i);
            mp[i]++;
            n /= i;
        }
    }
    // if (n>1) res.push_back(n);
    if (n>1) mp[n]++;
    return mp;
}

void solve(){
    int n,x;
    cin >> n >> x;
    vi a(n);
    for (auto& z:a) cin >> z;
    ll res = 1;
    vector<map<int,int>> g(n);
    map<int,int> fac;
    for (int i = 0; i < n; i++){
        g[i] = factor(a[i]);
        for (auto&[p,v]: g[i]){
            fac[p] += v;
        }
    }
    for (auto& [p, ls]: fac){
        // ll 
        res = res * (ls + 1);
        res %= MOD;
    }
    cout << res << endl;


};
// think different 
// 2 can be chosen in at most ONE slot 
// so maybe i store prime by their slot counts 
// oh what if for each prime 
// i pick one 
// each prime can only appear in ONE box at most 
//
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
