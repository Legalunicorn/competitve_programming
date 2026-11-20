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


vector<string> split(string& s, char delim){
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while(getline(tokenStream, token, delim)) tokens.push_back(token);
    return tokens;
}

void solve(){
    int n;
    cin >> n;
    vector<vector<int>> g(n);
    vector<string> a;
    for (int i = 0; i < n;i++){
        string name; cin >> name;
        a.pb(name.substr(0, name.size()-1));
        string x,y;
        cin >> x >> y;
        vector<string> sp = split(x, '-');
        vi xx;
        debug(sp);
        for (auto& s: sp){
            if (s == "upper") xx.pb(1);
            else if (s=="middle") xx.pb(0);
            else xx.pb(-1);
        }
        reverse(all(xx));
        while(xx.size() < 11) xx.pb(0);
        g[i] = xx;
    }
    vector<pair<vector<int>, string>> p(n);
    for (int i = 0; i < n; i++) {
        p[i].F = g[i]; p[i].S = a[i];}
    // sort(all(p));
    sort(all(p), [&](const auto& p, const auto& q){
            if (p.F != q.F){
            return p.F > q.F;
            }
            return p.S < q.S;
        // for (int i = 0; i < min(p.F.size(), q.F.size()); i++){
        //     if (p.F[i] < q.F[i]) return true;
        //     else if (p.F[i] > q.F[i]) return false;
        // }
        // if (p.F.size() < q.F.size()) return true;
        // if (p.F.size() > q.F.size()) return false;
        //
        //
        // return false;
        // return p.S > q.S;
        // if (p.F == q.F){
        //     return p.S > q.S;
        // } else{
            // return p.F >  q.F;
        // }
    });
    for (int i = 0; i < n; i++) cout << p[i].S << endl;
    for (int i = 0; i < 30; i++) cout << "=";
    cout << endl;
    // for (auto& z:g) cin >> z;
    // for (int i)
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    while(T--) solve();
    return 0;
}
