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
    string s;
    cin >> s;
    int a = 0, b = 0;
    for (char c: s){
        if (c=='(') a++;
        else b++;
    }
    if (a!=b){
        cout << -1 << endl;
        return;
    }
    // if the numbers are equal its obiously possible to color 
    // the max is 2? 
    vi res(n, 1);
    int cnt = 0;
    for (int i = 0; i < n; i++ ){
        if (s[i] == '(') {
            cnt ++;
            if (cnt <= 0) res[i] = 2;
        } else {
            cnt --;
            if (cnt < 0) res[i] = 2;
        }
    }
    int cnt1 = 0;
    for (auto& z:res) if (z ==1) cnt1++;
    if (cnt1==0){
        for (int i = 0; i < n; i++) res[i]--;
    }
    set<int> st(all(res));
    cout << st.size() << endl;
    for (auto& z: res) cout << z << " ";
    cout << endl;
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
