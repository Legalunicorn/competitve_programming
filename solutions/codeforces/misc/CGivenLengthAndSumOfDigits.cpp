#include <bits/stdc++.h>
#include <cstddef>
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
    int m,s;
    cin >> m >> s;
    int s2 = s;
    if (s == 0){
        if (m > 1) cout << "-1 -1" << endl;
        else cout << "0 0" << endl;
        return;
    } else if (m*9 < s){
        cout << "-1 -1" << endl;
        return;
    }

    //the min should just be the reverse of the max
    //actually not true since we cannot count leading zeros 
    //lets try to build the min: 
    //from right to left we greedily fill the digits, but the right most digit must hasve a one 
    vi a(m);
    a[0] = 1;
    s--;
    for (int i = m-1; i>=0; i--){
        int delta = 9 - a[i];
        int mn = min(delta, s);
        s -= mn;
        a[i] += mn;
        if (s == 0) break;
    }
    string r1;
    for (auto& x: a) r1 += (char)(x+'0');

    vi b(m);
    // largest string 
    for (int i =0; i < m; i++){
        int mn = min(9,s2);
        s2 -= mn;
        b[i] += mn;
        if (s2==0) break;
    }
    string r2;
    for (auto& x:b) r2 +=(char)(x+'0');

    cout << r1 << " " << r2 << endl;
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
