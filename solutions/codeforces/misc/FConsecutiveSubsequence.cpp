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
    int n;
    cin >> n;
    map<int,int> mp;
    int res = 0;
    int head = 0;
    // we need to print the index 
    map<int,vi> pos;

    // hard to figure out indexes on the fly 
    // how about we store all index then use binary search

    // i need to propagate the indexes 
    for (int i = 0; i < n; i++){
        int x ; cin >> x;
        pos[x].pb(i+1);
        mp[x] = mp[x-1]+1;
        if (mp[x] > res){
            res = mp[x];
            head = x;
        }
    }
    cout << res << endl;
    int far = -1;

    // im so stupui
    for (int i = head-res+1; i <= head; i++){
        vi& x = pos[i];
        int p = *upper_bound(all(x), far);
        cout << p << " ";
        far = p;
    }
    cout << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}

