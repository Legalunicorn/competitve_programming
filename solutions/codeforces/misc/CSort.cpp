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
    int n,q;
    cin >> n >> q;
    vvi g(n, vi(26)), f(n,vi(26));
    string a,b;
    cin >> a >> b;
    for (int i = 0; i< n; i++){
        int c = a[i]-'a';
        g[i][c]++;
        int x = b[i]-'a';
        f[i][x]++;
    }

    for (int j = 0; j < 26;j ++){
        for (int i = 1; i < n; i++){
            g[i][j] += g[i-1][j];
            f[i][j] += f[i-1][j];
        }
    }

    while(q--){
        int l,r;
        cin >> l >> r;
        l--, r--;
        vi x(26), y(26);
        int evl = 0; 
        for (int c = 0; c < 26; c++){
            int one = g[r][c] - (l-1>=0? g[l-1][c]: 0);
            int two = f[r][c] - (l-1>=0? f[l-1][c]: 0);
            int diff = abs(one - two);
            evl += diff;

        }
        evl /=2; 
        cout << evl << endl;
    }
    
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
