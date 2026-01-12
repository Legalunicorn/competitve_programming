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
    int n;
    cin >> n;
    string s;
    cin >> s;
    int r = 0, d = 0;
    for (char c: s){
        if (c=='R') r++;
        else d++;
    }
    debug(s,r,d);
    // we remove the next guys eligibiityto vote 
    // if "D" the, remove x next Rs etc 
    // use a vectorbool to maintainthe count maybe 
    vb dead(n,false);
    int d_gone = 0, r_gone = 0;
    string curr = s, next = "";
    int ff = 0;
    while(r >0  && d > 0){
        // ff++;
        debug(curr,next);
        int x = curr.size();
        for (int i=0;i<x;i++){
            debug(r_gone,d_gone);
            if (r==0 || d==0) break;
            if (curr[i] =='R'){
                if (r_gone>0){
                    debug(1);
                    r_gone--;
                    r--;
                } else{
                    debug(2);
                    next += curr[i];
                    d_gone++;
                }
            } else{ // == D 
                if (d_gone>0){
                    debug(3);
                    d_gone--;
                    d--;
                } else{
                    debug(4);
                    next += curr[i];
                    r_gone++;
                }
            }
        }
        curr = next;
        next = "";
    }
    if (r) cout << "R" << endl;
    else cout << "D"  << endl;
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
