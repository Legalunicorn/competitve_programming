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

// N =- 50 
// IMPOSSible = -1? 
// we need the sum to somehow be disivile by all its elements 
// elemens unioque 
// this is very interesting. 
// n <= 50 is ok 
// can we just brute force a bunch of numbners 
// fuck this TN 
//
// sum -> prime factorization? 
// 2, 4, 8, 16? 
// nah 
// think in bits?
// contribute to sum AND is also a divisor? .. 
// the number we use have some property?..
// comprime? 
// no. 
// suppose i take some number and prime factorize it. 
// what if its just a multipleicaiton of primes 
// 2 , 3 ,5 , 7 , 11, 13  = 6 primes 
// can i split this into sums 
// actually prime factors dontr work. 50 prime factors is too large 
// NOTE: 
// n <= 50, we can try to figure out the answer on by one lol 
// n = 2, what is the solution?> 
// wait its not even possible for n = 2 
// because one number 

// BUG: there is no -1 in the examples?.. 
//

// n = 3> 
// {1,2,3}
// wht so special about 6 ? 
// sum of primes = what the fuck is this 
//
// we cant use adajceny number besides {1,2} 
// powers of 2 bull shit 
// 16 - 1 = 8 + 4 + 2 + 1 
// 15 = 

void solve(){
    int n;
    cin >> n;
    if (n == 1){
        cout << 1 << endl;
        return;
    }
    if (n == 2){
        // pretty sur ethere is no solution 
        //  proof: one number will be more than half, and neitehr are equal 
        cout << -1 << endl;
        return;
    }
    // this so du,lmbb
    vl res = {1,2,3};
    while(res.size() < n){
        res.pb(res.back()*2LL);
    }
    for (auto& r: res) cout << r << " ";
    cout << endl;



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
