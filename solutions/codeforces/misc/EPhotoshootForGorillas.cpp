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

// you have to place the heavier gorillas 
// int the region they get counted the most 
// how many times does each cell get count in a k * k square 
// if we can get the counts, then sort them 
// then we fill in the gorillas and sum the product 
// that should be the answer 
// i thin kwe can calcualt ethe movement of row and col 

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    int w; cin >> w;
    vl a(w);
    for (auto& z:a) cin >> z;
    int N = n*m;
    vl score(N,0);
    int id =0;
    vvi temp(n, vi (m,67));
    for (int i=0;i<n;i++){
        for (int j=0;j<m;j++){
            int l = max(0, j - k + 1 );
            int r = min(m-1, j + k - 1);
            int w = r - l + 1;
            int dx = w - k + 1; 

            int u = max(0, i - k + 1);
            int d = min(n-1, i + k - 1);
            int h = d - u + 1;
            int dy = h - k + 1 ;
            debug(i,j, dx, dy);
            debug(l,r,u,d);
            score[id++] = ((ll)dx*dy);
            temp[i][j] = (ll)dx*dy;
        }
    }
    debug(temp);
    sort(a.rbegin(),a.rend());
    sort(score.rbegin(),score.rend());
    debug(score);
    ll ans = 0;
    for (int i=0; i < w; i++){
        ans += a[i]*score[i];
    }
    cout << ans << endl;
    //
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
