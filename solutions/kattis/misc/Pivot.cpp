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
  vi a(n);
  for (auto& z:a) cin >> z;
  if (n == 1){
    cout << 1  << endl;
    return;
  }
  // distinct 
  // we just need to check that max left < curr AND curr < min right ;
  vi l(n), r(n);
  l[0] = a[0];
  for (int i = 0; i < n; i++){
    l[i] = max(a[i], l[i-1]);
  }
  r[n-1] = a[n-1];
  for (int i = n - 2; i >= 0 ; i --){
    r[i] = min(a[i], r[i+1]);
  }
  int res = 0;

  for (int i = 0; i < n; i++){
    if (i == 0){
      if (r[1] > a[i]) res++;
    } else if (i == n -1){
      if (l[n-2] < a[i]) res++;
    } else{
      if (l[i-1] < a[i] && a[i] < r[i+1]) res++;
    }
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
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
