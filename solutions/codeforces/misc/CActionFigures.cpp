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
// i think we can process backwards
// then use exchange argument on which guy was the sacrifice, 
//
// start from day N, buy all from [1, n-1] and n is free, 
// we arbitaraily take that "1" was the other purchase so that n is discounted 
//
// then as we process left, 
// if we see a "0", we can swap places with "1" as the cost, and use the current one as cost
// thus keep track of 
// - how mnay guys need a replacemenet 
// - up to who were they using as replacemenet
//
// is there need to considet day[0]? 
// if its open buy 

void solve(){
    ll n;
    string s;
    cin >> n >> s;
    ll tot = n * (n + 1) / 2;
    int need = 0, next =  0;
    // there is no need to consider day[0] right? 
    for (int i = n -1; i >= 0; i--){
        if (next >= i) break;

        if (s[i] == '0') {
            // we must pay with this guy;
            if (need > 0) {
                need--;
                next--;
            } // else 
        } else {
            next++;
            need++;
            tot -= (i+1);
            // if (next < i){
            //     next++;
            //     need++;
            //     tot -= (i+1); // this is now free
            // } 
        }
    }
    cout << tot << endl;


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
