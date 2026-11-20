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

#define F first 
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;
const int inv= 1e9;


 
int MAXN = (int)(3e5+5);
vector<bool> is_prime(MAXN+1, true);
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
    // for (int i=2; i<=MAXN;i++) {
    //     if (is_prime[i]) primes.push_back(i);
    // }
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

class Solution {
public:
    vector<int> maxPrimeSubset(int n, int s) {
        vi primes;
        // max ~ 200 primes up to 1k
        for (int i = 2; i <= n; i++){
            bool valid = true;
            for (int j = 2; j * j <= i; j++){
                if (i % j == 0){
                    valid = false;
                    break;
                }
            }
            if (valid) primes.pb(i);
        }
        debug(primes);
        int p = primes.size();

        const int INF = 1e9;
        vvi dp(p+1, vi(s+1, INF));
        dp[p][0] = 0;

        for (int i = p-1; i >= 0; i--) {
            for (int x = 0; x <= s; x++) {
                // skip current prime
                dp[i][x] = dp[i+1][x];

                // take current prime
                if (x >= primes[i] && dp[i+1][x-primes[i]] != INF) {
                    dp[i][x] = min(
                            dp[i][x],
                            dp[i+1][x-primes[i]] + 1
                            );
                }
            }
        }
        vi res;
        int x  

    }
};
