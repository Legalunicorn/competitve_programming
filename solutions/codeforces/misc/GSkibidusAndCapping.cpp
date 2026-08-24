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


int MAXN = (int)(3e5+5);
vector<bool> is_prime(MAXN, true);
vector<int> primes;
void init_sieve(){
    is_prime[0] = is_prime[1] = false;
    for (int i = 2; i<= MAXN ; i++){
        if (is_prime[i] && (ll)i * i  <= MAXN){
            for (int j = i *i ; j <= MAXN; j += i){
                is_prime[j] = false;
            }
        }
    }
    for (int i=2; i<=MAXN;i++) {
        if (is_prime[i]) primes.push_back(i);
    }
};

vector<int> trial_div(int n){
    vector<int> fac;
    for (auto& d: primes){
        if (d* d > n) break;
        while(n% d == 0){
            fac.push_back(d);
            n /= d;
        }
    }
    if (n>1) fac.push_back(n);
    return fac;
}

void solve(){
    // omega trivla? 
    // a good pair if 
    // 1. x is prime, then add all other primes we seen so far 
    // 2. x is semi-prime, ie. there is exactyl two prinmes a,b, then count seen[a] + seen [b] but dont double count if equal
    map<int,int> mp;
    int primes = 0;
    ll res = 0;
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >>z;
    sort(all(a));
    // a PRIME is NOT semi-prime
    for (int i = 0; i < n; i ++){
        vi td = trial_div(a[i]);
        if (td.size() >= 3) continue;
        if (td.size() == 1){
            // prime 
            // match with any other prime to get semi prime
            primes++;
            mp[a[i]]++;
            res += primes - mp[a[i]]; // any other prime is fine 
        } else if (td.size() == 2){
            // semi prime 
            // match either (1) factor 0, (2) factor 1, (3) itself
            mp[a[i]]++;
            int u = td[0], v = td[1];
            res += mp[u];
            if (v != u) res += mp[v];
            res += mp[a[i]];
        }
        debug(i, res, primes);
    }

    cout << res << endl;
    cerr << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    init_sieve();
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
