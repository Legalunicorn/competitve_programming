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

void solve(){
    ll a,b,c;
    cin >> a >> b >> c;
    // t , u take out first 
    ll res = 0;
    int mn = min(a,c);
    a -= mn;
    c -= mn;
    res += 4LL * mn;

    if (a == 0 && b == 0 && c == 0){
        cout << res << endl;
        return;
    } else if (c == 0){

        // C IS ZERO 
        // your min logic is wrong 

        ll b2 = b * 2;
        ll v = min(a, b2);
        ll mn = v/2;

        b -= mn;
        a -= mn * 2;


        res += 7 * mn;


        if (a == 0){
            res += 3 * b;
            a = 0;
            b = 0;
        } else if (b == 0) {
            int am = a-1;
            int x = 3 + 2 * am;
            res += x;
            a = 0; 
            b = 0;
        } else{
            res += 5;
            res += (b-1) * 3;
        }
    } else {
        res += 3 * (b + c);
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
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
