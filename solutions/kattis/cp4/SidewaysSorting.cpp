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

void solve(int r, int c){
    vector<string> g(r);

    auto chk = [&](int i, int j) -> bool{
        string s1, s2;
        for (int x = 0; x < r ; x++){
            s1 += tolower(g[x][i]);
            s2 += tolower(g[x][j]);
        }
        debug(s1,s2);
        debug(s1 > s2);
        cerr << endl;
        return s1 > s2;
    };


    int n = c;
    for (auto& z: g) cin >> z;
    for (int i = 0; i  < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (chk(j, j+1)){
                // swap i with j 
                string t;
                for (int x = 0; x < r; x++){
                    t += g[x][j];
                    g[x][j] = g[x][j+1];
                }
                for (int x = 0; x < r; x++){
                    g[x][j+1] = t[x];
                }
            }
        }
    }

    for (auto& z: g){
        cout << z << endl;
    }
    cout << endl;
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int r,c;
    // cin >> T; 
    while(cin >> r >> c && r){
        solve(r ,c);
    }
    cerr << " == END ==" << endl;
    return 0;
}
