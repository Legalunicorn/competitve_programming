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
// 1. optimal to tkae the slowest path to gcd(a,b)
// do we need to consever the parity? not reall right? 
// gcd = 2,3,5,7 
// a = 2,3
// b = 23 
//
// actually its no harm
// so we can take just take max 
// then l = k - max 
// just check if l <= d(a/gcd(a,b))
//
//
// int factor(ll n){
//     int  res =0;
//     for (int i=2; i*i <= n;i++){
//         while (n%i==0){
//             res++;
//             n /= i;
//         }
//     }
//     if (n>1) res++;
//     return res;
// }

int factor(long long n) {
    int  factorization = 0;
    for (int d : {2, 3, 5}) {
        while (n % d == 0) {
            factorization++;
            n /= d;
        }
    }
    static array<int, 8> increments = {4, 2, 4, 2, 4, 6, 2, 6};
    int i = 0;
    for (long long d = 7; d * d <= n; d += increments[i++]) {
        while (n % d == 0) {
            factorization++;
            n /= d;
        }
        if (i == 8)
            i = 0;
    }
    if (n > 1)
        factorization++;
    return factorization;
}


void solve(){
    // omega trivial
    ll a,b,k;
    cin >> a >> b >> k;
    if (a > b) swap(a,b);
    ll l = k;
    ll g = __gcd(a,b);
    if (a != b){
        if (k == 1 && b % a != 0){ // special case -> only one move 
            cout << "NO" << endl;
            return;
        }
        ll one = a/g;
        ll two = b/g;
        int c1 = factor(one);
        int c2 = factor(two);
        int tot = c1+c2;
        if (tot >=k){
            cout << "YES" << endl; // we can just go down to gcd easily
            return;
        }
        l -= tot;
    } else{
        if (a==b && k ==1){
            cout << "NO" << endl;
            return;
        }
    }
    // l -> number of moves left
    int c3 = factor(g)*2;
    if (l <= c3) cout << "YES" << endl;
    else cout << "NO" << endl;

};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
