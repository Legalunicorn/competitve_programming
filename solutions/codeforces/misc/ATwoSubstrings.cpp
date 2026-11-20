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
    // we have to digit the string right 
    // why cannot use pref[i][0] -> store AB, 
    int n = s.size();
    vb p_ab(n), p_ba(n), s_ab(n), s_ba(n);
    for (int i=1;i<n;i++){
        if (s[i-1] =='A' && s[i] == 'B' ) p_ab[i] = true;
        if (s[i-1] =='B' && s[i] == 'A') p_ba[i] = true;
    }
    for (int i = 1;i<n;i++){
        p_ab[i] = p_ab[i] || p_ab[i-1];
        p_ba[i] = p_ba[i] || p_ba[i-1];
    }
    for (int i = n -2; i >= 0; i--){
        if (s[i] =='A' && s[i+1] == 'B') s_ab[i] = true;
        if (s[i] =='B' && s[i+1] == 'A') s_ba[i] = true;
    }
    for (int i = n -2; i>= 0; i --){
        s_ab[i] = s_ab[i] || s_ab[i+1];
        s_ba[i] = s_ba[i] || s_ba[i+1];
    }
    for (int i = 1; i+1<n;i++){
        if (p_ab[i] && s_ba[i+1] || p_ba[i] && s_ab[i+1]){
            cout << "YES" << endl;
            return;
            
        }
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
