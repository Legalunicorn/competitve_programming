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
// if difference is 1 -> output -1 (trivial, its impossible to divide by any number >= 2)
//
// lets try case splitting 
// or examples
// distance = 2, 9 -> 11, 10 -> 12 
// odd-odd, even-even (divisiby by 2) 
//
// or more generally 
// i think we can try to observe the gap 
// the gap is "k" 
// x, x+k 
// -> both items MOD k something 
// at some point they will both MOD k == 0 
// this is the upper bound to the solution 
//
// Lets make some asumstions 
// 1. they are not lucy 
// 2. ignore trivial case, k <= 1
//
// try k = 9 = 3 x 3 
//    5, 14 
//    6, 15 (!! found it)
//    7, 16 
//    8, 17
//    9, 18 
//  -> if they are k distance away 
//  -> they are sort of divisor(k) distance away as well 
//  -> the same modulus argment applies 
//  -> prime factorize (k) 
//      -> for each find the closest mod
//
//  but k is not the only common divisor though!! 
//
//  10 16 , k = 6 
//
//
// 1. same pairity -> either they match now, or the answer is 1 
// 2. HENCE
//  -> have different pairits
//  -> do not match 
//  -> have largeish k 
//  -> k is ODD (if even there will be same pairy)
//
//
//


const int MAXN = 1e7 + 5;
int spf[MAXN]; // smallest prime factor

void sieve() {
    iota(spf, spf + MAXN, 0);
    for (int i = 2; (long long)i * i < MAXN; i++) {
        if (spf[i] == i) {
            for (int j = i * i; j < MAXN; j += i) {
                if (spf[j] == j) spf[j] = i;
            }
        }
    }
}

set<int> factorize(int x) {
    set<int> res;
    while (x > 1) {
        int p = spf[x];
        res.insert(p);
        while (x % p == 0) x /= p;
    }
    return res;
}

void solve(){
    int n;
    cin >> n;
    int x,y;
    for (int i = 0; i < n; i++) {
        cin >> x >> y;
        if (x > y) swap(x,y);
        if (__gcd(x,y) > 1){
            cout << 0 << endl;
            continue;
        }
        debug(x,y);
        if (y -x == 1) {
            cout << -1 << endl;
            continue;
        }
        int d = y - x;
        set<int> st  =factorize(d);
        debug(d, st);
        int best = INT_MAX;
        for (auto& f: st){
            debug(f, x%f, y%f);
            best = min(best,  f - (x % f)) ;
        }
        cout << best << endl;
    }
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    sieve();
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}
