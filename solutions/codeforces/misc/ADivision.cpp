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
// p == q ? 
// -> exclude the smallest prime factor, or otherwise 1 if prime 
//
// p divisible by q ? 
// - > p 
//
// q divisibile by p ? 
// - > we have to pick q, limmmited 
//
// no intersection -> take p 
//
//
// NOTE: 
// q inside p 
//  => idea: prime factors of p, remove the smallest prime factor of q 
//      = p / small_factor(q) 
//
// p inside q 
//  => return push_b

typedef __int128_t int128;

// Function for modular exponentiation
ll power(ll base, ll exp, ll mod) {
    ll res = 1;
    base %= mod;
    while (exp > 0) {
        if (exp % 2 == 1) res = (ll)((int128)res * base % mod);
        base = (ll)((int128)base * base % mod);
        exp /= 2;
    }
    return res;
}

// Miller-Rabin primality test
bool is_prime(ll n) {
    if (n < 2) return false;
    if (n == 2 || n == 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    
    ll d = n - 1;
    int s = 0;
    while (d % 2 == 0) {
        d /= 2;
        s++;
    }
    
    // Deterministic bases for n < 2^64
    static const vector<ll> bases = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37};
    for (ll a : bases) {
        if (n <= a) break;
        ll x = power(a, d, n);
        if (x == 1 || x == n - 1) continue;
        bool composite = true;
        for (int r = 1; r < s; r++) {
            x = (ll)((int128)x * x % n);
            if (x == n - 1) {
                composite = false;
                break;
            }
        }
        if (composite) return false;
    }
    return true;
}

// Greatest Common Divisor
ll gcd(ll a, ll b) {
    while (b) { a %= b; swap(a, b); }
    return a;
}

// Pollard's Rho factor finding
ll get_factor(ll n) {
    if (n % 2 == 0) return 2;
    if (is_prime(n)) return n;
    
    static mt19937_64 rng(1337);
    uniform_int_distribution<ll> dist(2, n - 1);
    
    ll x = dist(rng);
    ll y = x;
    ll c = dist(rng);
    ll g = 1;
    
    auto f = [&](ll x, ll c, ll mod) {
        return (ll)(((int128)x * x + c) % mod);
    };

    while (g == 1) {
        x = f(x, c, n);
        y = f(f(y, c, n), c, n);
        g = gcd(abs(x - y), n);
        if (g == n) return get_factor(n); // Failure, retry with different x, c
    }
    return g;
}

// Recursive function to fill the frequency map
void factorize(ll n, map<ll, int>& mp) {
    if (n == 1) return;
    if (is_prime(n)) {
        mp[n]++;
        return;
    }
    ll d = get_factor(n);
    factorize(d, mp);
    factorize(n / d, mp);
}


ll binpow(ll a, ll b){
    ll res = 1;
    while(b>0){
        if (b & 1) res = res *a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void solve(){

    ll p,q;
    cin >> p >> q;
    if (p % q == 0) {
        map<ll,int> f,g;
        factorize(q,f);
        factorize(p,g);
        // map<ll,int> f = factor(q);
        // map<ll,int> g= factor(p);
        ll res = 1;
        for (auto& [val, cnt]: f){
            int x = cnt - 1;
            debug(val,cnt,x);
            ll y = g[val] - x;
            debug(y);
            ll div = binpow(val, y );
            ll evl = p / div;
            res = max(res, evl);
        }
        cout << res << endl;
    } else {
        cout << p << endl;
    }
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
