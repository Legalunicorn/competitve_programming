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
  int h,w,n,m;
  cin >> h >> w >> n >> m;
  // image dim, kernam dim

  vvi g(h, vi(w));
  vvi f(n, vi(m));
  for (auto& x: g){
    for (auto& y: x) cin >> y;
  }
  for (auto& x: f){
    for (auto& y: x) cin >> y;
  }
  debug(g,f);
  // flip f both ways 
  // flip rows 
  for (int i = 0; i < n; i++){
    for (int j = 0; j < m/2; j++){
      swap(f[i][j], f[i][m - j - 1]);
    }
  }
  for (int j = 0; j < m; j++){
    for (int i = 0; i < n/2; i++){
      swap(f[i][j], f[n - i -1][j]);
    }
  }
  debug(g,f);

  for (int i = 0; i < h - n + 1; i++){
    for (int j = 0; j < w - m + 1; j++){
      int s = 0;
      for (int x = 0; x < n; x++){
        for (int y = 0; y < m; y++){
          s += g[i+x][j+y] * f[x][y];
        }
      }
      cout << s;
      if (j  + 1 < w - m + 1) cout << " ";
    }
    if (i  + 1< h - n + 1) cout << endl;
  }


  // what the hell is convolution 
  // this is just brute force no ? 
  //

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
