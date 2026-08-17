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
    vi a(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    map<int, pi> ma;
    map<int, pi> mb;
    int same = 0;
    for (int i = 0; i < n; i++){
        if (a[i] == b[i]) same++;
        ma[a[i]] = {i, b[i]};
        //mb[b[i]] = {i, a[i]};
    }
    bool mm = false;

    for (int d = 1; d <= n; d++){
        int v = ma[d].S;
        int u = ma[v].S;
        if (u != d) mm = true;
    }
    debug(ma, mm ,same, n);
    if (mm || (n%2==0 && same>0) || (n%2==1 && same !=1)){
        cout << -1 << endl;
        return;
    }
    vpi swaps;
    for (int i = 0; i < n/2; i++){
        int j = n - i - 1;
        if (a[i] == b[i]) j = n/2;
        int x = a[i], y = b[i];
        if (a[j] == y) continue;
        debug(i,j, x, y, ma[y].F);
        int pos = ma[y].F;
        swaps.pb({pos+1, j+1});
        ma[y].F = j;
        ma[a[j]].F = pos;
        swap(a[pos],a[j]);
        swap(b[pos],b[j]);
    }
    cout << swaps.size() << endl;
    for (auto& p: swaps){
         cout << p.F << " " << p.S << endl;
    }
    cerr << endl;

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
