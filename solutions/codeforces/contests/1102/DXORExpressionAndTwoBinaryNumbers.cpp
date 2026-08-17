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


// the only values we need are 
// a 
// b 
// a ^ b 
// then we need to count how many of each appear 
// NOTE: if k is small like k = 1,2 we just brute force this shit 


void solve(){
    int n, k;
    cin >> n >> k;
    string x,y;
    cin >> x >> y;
    string z;
    for (int i = 0; i < n; i++){
        if (x[i] == y[i]) z += "0";
        else z+="1";
    }
    pi one = {0,0}, two = {0,0}, three = {0,0};
    for (char c: x) {
        if (c == '0') one.F++;
        else one.S++;
    }
    for (char c: y){
        if (c == '0') two.F++;
        else two.S++;
    }
    for (char c: z){
        if ( c == '0') three.F++;
        else three.S++;
    }

    if (k  == 1){
        ll res = one.F * one.S + two.F * two.S + three.F * three.S;
        cout << res << endl;
        return;
    }
    
    // start after 1 operation 
    ull a = 1;
    ull b = 1;
    ull axorb = 1;
    ull ab = 0;
    for (int op = 2; op <= k; op++){
        a += axorb;
        b += axorb;
        ll _ab = ab;
        ab = 2 * axorb;
        axorb += _ab;
    }
    ull res = 0;
    res += a * one.F * one.S;
    res += b * two.F * two.S;
    res += axorb * three.F * three.S;
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
