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
// ai = ai - gcd(ai,x);
// x = gcd(ai,x)
// ans += gcd(ai,x);
//
//
// think divisibility, 
// gcd is rarely above max prime factorization
// 
// x is only decreasing
//
// we can sort maybe? and do take not tkae, but it counts the gcd in the dp 
// so thats hard
// actually its simple? if u take, and jump top the next [position youre greater than or equal to]

// 1. X is non-increasing 
// 2. a[i] is decreasing 
// 3. anything is a multiple of a[i], we can steal all of it 
// 4. after ooperation x = g, a divisor of a[i]
// 5. if initially, gcd(ai, x) = 1, we can never use it 
//
// 1. anything a multiple of x we can steal it all (this seems like a mssive hint)
// if we can make x -> some divisor of ai, we can steal ai
//
// x = gcd(x, u)
// gcd(x,u) is always a divisor of "x" 
// x = 6, 
// can we get both 2, 3? 
// no because they are coprime 
//
// x = 24
// d = 2, 3, 4, 6, 8 , 12 
// can we go from 24 -> 6 -> 4 ? its possible 
// 6 -> can kill 18, 4 cant
//
// if gcd(ai,x) = 1, it will always be 1 
//consider first sweep of gcd 
//
//
//1. consider sweep of gcd values 
//2. sort them 
//3 BUG: missingw transition from one gcd to another, idk if poissible:w
// NOTE: x is divisible by ALL the possible gcd initially 
// i think the problem can be converted to IDK, dp? 
//
// im missing the transitions 
// might be some goofy brute force hidden as solution 
//
// 1. initial gcd, i believe this is relevant 
// map gcd -> SUM 
//
// NOTE
// 1. a number only haws ~ sqrt(n) divisors,
// 2. in realisity its like 200 max divisle 40,000
//
// 6 -> 2, 2->6
// 
//
// 6 5 4 3 2 
// 6 -> divisor 6 is possibe l
//
// gcd(6, 3m) >= 3 
// can only divide log times 
// can  x = gcd(x, ...)
//      x = gcd(x,....)
//



set<int> factor(int n){
    set<int> res;
    for (int i=2; i*i <= n;i++){
        while (n%i==0){
            res.insert(i);
            n /= i;
        }
    }
    if (n>1) res.insert(n);
    return res;
}



void solve(){   
    ll n,x;
    cin >> n >> x;
    set<int> st = factor(x);
    vl a(n);
    for (auto& z:a) cin >> z;
    ll res = 0ll;
    for (auto& p: st){
        ll evl = 0;
        for (int i = 0; i < n; i++){
            if (a[i]%p==0) evl+=a[i];
        }
        res = max(res,evl);
    }
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
