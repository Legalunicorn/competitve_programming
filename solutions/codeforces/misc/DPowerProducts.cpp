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

// NOTE:
// x [1, 10e5]
// for each x -> 
// we have prime factors 
// then we need to counter how many  pairs can be prime factor * k .. blah 
// even if we hash prime factors, its too slow 
// each x: 10e5 
// each elenment: O(n)
// -> n^ 2 
// unless we can use some tricky hasing to resove this 
// basic hash 
// for each ai, comput ethe hash of the inverse -> count how many 
// atlernative: 
// inspect the divisors of "x" 
// how many combinations can there be at most? 
// sum of exponents <= 40-50 ish 
// what if instead of iterating the array  we iteraate all possible combination 
//
//
// for each element
//
//
// I got the hints from gpt 
// dont interate over "x" this is the most important pitfall for me 
// notice the the prime sums = 0 (mod k) 
//
//
// LESSONS 
// 1. NOTE: dont iterate over  "x" 
// 2. NOTE: congurancy of "MOD" can be abused into a map and counter 


map<int,int> factor(int n){
    map<int, int> res;
    for (int i=2; i*i <= n;i++){
        while (n%i==0){
            res[i]++;
            n /= i;
        }
    }
    if (n>1) res[n]++;
    return res;
}


void solve(){
    int n,k;
    cin >> n >> k;
    vl a(n);
    for (auto& z:a) cin >> z;
    map<vpi,int> freq;
    ll res = 0;
    for (int i = 0; i < n; i++){
        map<int,int> xd = factor(a[i]);
        vpi norm, cong;
        for (auto& [v,c]: xd){
            int one = c % k;
            int two = (k - one) % k;
            if (one == 0) continue;
            norm.pb({v,one});
            cong.pb({v,two});
        }
        res += freq[cong];
        freq[norm]++;
    }
    cout << res << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}
