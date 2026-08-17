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


int tc = 0;
void solve(){
    tc++;
    int n,k;
    cin >> n >> k;
    string s,t;
    cin >> s >> t;
    // if (tc==31){
    //     string db = s+":"+t;
    //     cout << db << endl; 
    //     return;
    // }
    if (n>=6){
        sort(all(s));
        sort(all(t));
        cout << (s==t ? "YES" : "NO") << endl;
        return;
    }
    if (n <= 3){
        cout << (s == t ? "YES": "NO") << endl;
        return;
    } else if (n == 4){
        bool cond = true;
        if (s[1] != t[1] || s[2] != t[2]) cond = false;
        vector<char> t1 = {t[0],t[3]};
        vector<char> t2 = {s[0],s[3]};
        sort(all(t1));
        sort(all(t2));
        if (t1 != t2) cond = false;
        cout << (cond ? "YES":"NO") << endl;
    } else if (n == 5){
        bool cond = true;
        if (s[2] != t[2]) cond = false;
        vector<char> t1 = {t[0],t[1],t[3],t[4]};
        vector<char> t2 = {s[0],s[1],s[3], s[4]};
        sort(all(t1));
        sort(all(t2));
        if (t1 != t2) cond = false;
        cout << (cond ? "YES":"NO") << endl;
    }
    // else if (n==6) {
    //     bool cond = true;
    //     if (s[2] != t[2]) cond = false;
    //     vector<char> t1 = {t[0],t[1],t[3],t[4],t[5]};
    //     vector<char> t2 = {s[0],s[1],s[3], s[4],s[5]};
    //     sort(all(t1));
    //     sort(all(t2));
    //     if (t1 != t2) cond = false;
    //     cout << (cond ? "YES":"NO") << endl;
    // }
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
