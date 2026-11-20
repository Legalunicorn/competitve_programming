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
  string n,m;
  cin >> n >> m;
  if (m.size() == 1){
    cout << n << endl;
    return;
  }
  if (m.size() <= n.size()){
    string res;
    int p = n.size() - m.size() + 1;
    res += n.substr(0, p);
    res += ".";
    res += n.substr(p);
    // cout << res << endl;
    // delete training zeros 
    int l = res.size();
    debug(p);
    debug(res);
    for (int i = res.size() -1; i >= p ;i --){
      if (res[i] != '0'){
        debug(res[i],i);
        l = i;
        break;
      }
    }
    debug(l);
    if (l > p){
      cout << res.substr(0,l+1) << endl;
    } else{
      cout << n.substr(0,p) << endl;
    }

    return;
  }

  string ex = "0.";
  int more = m.size() - n.size() -1;
  for (int i = 0; i < more; i++) ex += "0";
  ex += n;
  cout << ex << endl;

  // 1. figure out wher the dog is 
  // 2. if m.size() <= n.size() 
  // we can insert the decision 
  // if m = 1, do nothing 
  // if m.size <= n.size insert dot 
  // else 
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
