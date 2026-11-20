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
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;

void solve(){
    // vector<string> g(2);
    // for (auto& z:g) cin >> z;
    // set<char> ok;
    // ok.insert('D');
    // ok.insert('A');
    // for (int i =0 ;i  < 2; i++){
    //     for (int j =0 ; j < 2; i++){
    //         if (j==1){
    //             set<char> j 
    //         }
    //     }
    // }
    string s,t;
    cin >> s >> t;
    debug(s,)
    if (s == "AD" || s =="DA" || t =="AD"  || t =="DA") {
        cout << "Yes" << endl;
        return;
    }
    if ((s[0]=='D' && t[0]=='A') || (s[0]=='A' && t[0]=='D')){
        cout << "Yes" << endl;
        return;
    }
    if ((s[1]=='D' && t[1]=='A') || (s[1]=='A' && t[1]=='D')){
        cout << "Yes" << endl;
        return;
    }
    cout << "No" << endl;



};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--) solve();
    return 0;
}
