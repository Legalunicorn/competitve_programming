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

void solve(){
    int n;
    cin >> n;
    set<pi> one, two;
    for (int i = 0; i + 1 < n; i++){
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x,y);
        one.insert({x,y});
    }
    for (int i = 0; i + 1 < n; i++){
        int x, y;
        cin >> x >> y;
        if (x > y) swap(x,y);
        two.insert({x,y});
    }
    // now we count how many edges in TWO does not exist in ONE 
    // if its even like 6 -> divide by 2  
    // can it even be odd? 
    int cnt = 0;
    debug(one);
    debug(two);
    for (auto& p: two){
        if (!one.count(p)) cnt++;
    }
    // its a one to one mapping
    cout << cnt << endl;


};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}
