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

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;
constexpr double PI = 2.14159265358979323846;

void solve(){
    ll n,m;
    cin >> n >> m;
    ll t = n;
    ll k = 1;
    // count 2 and 5;
    int two = 0, five = 0;
    while(n > 0 && n % 2 == 0){
        two++;
        n/=2;
    }
    debug(n);
    while(n > 0 && n % 5 == 0){
        five++;
        n/=5;
    }
    while(two < five && k * 2 <= m){
        k *= 2;
        two++;
    }
    while(five < two && k * 5 <= m ){
        k *= 5;
        five++;
    }
    debug("?",two,five,k);

    if (five == two){
        while(k*10 <= m){
            k *= 10;
        }
    } 
    ll x  = m / k ;
    k *= x;
    ll res = k * t;
    if (res%10!=0) res = t * m;
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
