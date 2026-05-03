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
  vi a(2*n);
  for (auto& z:a) cin >> z;
  // a[0] is the top 
  // we just do as asked greedily 
  stack<int> s1, s2;
  reverse(all(a));
  for (auto& z:a) s1.push(z);
  int res = 0; 
  while(!s1.empty()){
    if (s2.empty()){
      res++;
      s2.push(s1.top());
      s1.pop();
      if (s1.empty()){
        cout << "impossible" << endl;
        return;
      }
      if (s1.top() == s2.top()){
        res++;
        s1.pop();
        s2.pop();
      }
    } else{
      if (s1.top() == s2.top()){
        s1.pop();
        s2.pop();
        res++;
      } else{
        s2.push(s1.top());
        s1.pop();
        res++;
      }
    }
  }
  if (s1.empty() && s2.empty()){
    cout << res << endl;
  } else cout << "impossible" << endl;
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
