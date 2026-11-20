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


// the answewr is 2 only when ites forcs
//
void solve(){
    int n;
    string s;
    cin >> n >> s;
    if (n == 1){
        cout << 1 << endl;
        return;
    }
    if (n == 2){
        if (s[0] == s[1]) cout << 1 << endl;
        else cout << 2 << endl;
        return;
    }
    int flips = 0;
    for (int i = 1; i < n; i++) {
        if (s[i] != s[i-1]) flips++;
    }
    if (flips == 0){
        cout << 1 << endl;
        return;
    }
    if (flips == 1){
        cout << 2 << endl;
        return;
    }
    cout << 1 << endl;
    return;


    // 3 is not an edge case 
    // 00111
    // we want to eliminatae all the same 
    // u stupid as long as it alternates more than 1 
    //

    // if (n == 3){
    //     bool bad = false;
    //     if (s[0] == s[1] && s[1] != s[2]){
    //         cout << 2 << endl;
    //         return;
    //     }
    //     if (s[1] == s[2] && s[0] != s[1]){
    //         cout << 2 << endl;
    //         return;
    //     }
    //     cout << 1 << endl;
    //     return;
    // }
    //


    // 0 or 1 only 
    // min possible length of s? 
    // can we always pick palin
    // the answer is always 1 or 2 
    // any size more than 3 can be reduced 
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
