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
    string s;
    cin >> s; 
    // 10e6 
    // we can maintain a stack of positions 
    int n = s.size();
    stack<int> lower,upper;
    vb gone(n,false);
    for (int i=0;i<n;i++){
        debug(i);
        debug(lower.size(), upper.size());
        char c = s[i];
        if (c=='b'){
            if (!lower.empty()) {
                int t = lower.top(); lower.pop();
                gone[t] = true;
            }
        } else if (c=='B'){
            if (!upper.empty()){
                int t  = upper.top(); upper.pop();
                gone[t] = true;
            }
        } else {
            int v = c - 'a';
            debug(s[i],v);
            if (v>=0){
                lower.push(i);
            } else{
                upper.push(i);
            }
        }
    }
    string ans;
    for (int i=0;i<n;i++){
        if (s[i]!='b' && s[i]!='B' && !gone[i]) ans+= s[i];
    }
    cout << ans << endl;
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
