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
// 
// for EACH divisor 
//  -> [ ... ] [...] [... ]
//  we still need to find if there is some magic number that can make all elements equal when modulus 
//  say we have [0, 2 ] or [3,4] ie. we want them to be equal? the only option is that 
//  i think this should be quite easy? if two numbers are not equal, in the same k distance apaart
//  the modulunus must be some gcd right? M = gcd(...) = x, then we collect all the gcd's 
//  the gcd of all the gcd  must be  >= 2??? 
//  im very confused 
//  [m1 ,m2, m3 ,m4 ] 
//  its just gcd of everything >= 1?>


// its possible for a set of values to all be "1" 
// then its okay we can exclude them
// where did u even get your gcd idea from hello? 
// this is modulus 
// the idea should be quite siple 
// we just need every element to be k distance apart
// where k >= 1

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    int g = a[0];
    int res = 0;
    for (int d = 1; d <= n; d++){
        if (n%d!=0) continue;
        int k = n/d;
        int evl = 0;
        for (int i = 0; i < d; i++){
            vi b;
            for (int j = i; j < n; j+=d){
                b.pb(a[j]);
            }
            sort(all(b)); // is this even needed
            // b is sorted then we need to check the distance 
            int g = 0;
            for (int i = 1 ; i < b.size(); i++){
                if (b[i]!=b[i-1]) g = __gcd(g, b[i]-b[i-1]);
            }
            evl = __gcd(evl ,g);
            if(a[5]==6 && d ==1) debug(b);
        }
        if (a[5] == 6) debug(d, evl);
        if (evl != 1) res++;
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
