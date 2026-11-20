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

// o o o x o x o o o x o x o o o 
void solve(){
    vi a(3);
    for (auto& z:a) cin >> z;
    sort(all(a));
    if (a[0] == 1){
        cout << "YES" << endl;
        return;
    }
    if (a[0] == 2 && a[1] == 2){
        cout << "YES" << endl;
        return;
    }
    if (a[0] == a[1] && a[1] == a[2] && a[2] == 3){
        cout << "YES" << endl;
        return;
    }
    if (a[0] == 2 && a[1] == 4 && a[2] == 4){
        cout << "YES" << endl;
        return;
    }
    cout << "NO" << endl;
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
