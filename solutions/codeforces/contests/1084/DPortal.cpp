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


// TWO portals 
// lex order scream greedy 
// split into segments 
// LEFT MID RIGHT 
// we can rotate MID as we like 
// p1 R to L 
// p2 L to R 
// these are for middle rotation s 
//
//
//
// 
// p1 L tR 
// p2 R to L
//
// 1. record the MIN of the middle part 
//
// actually we can kind of insert the rotated part where where betwene left and right 
//


void solve(){
    int n;
    cin >> n;
    int x,y;
    cin >> x >> y;
    vi a(n);
    for (auto& z:a) cin >> z;
    vi lr;
    for (int i = 0; i < x; i++) lr.pb(a[i]);
    for (int i = y; i < n; i++) lr.pb(a[i]);

    vi mid;
    for (int i = x; i < y; i++){
        mid.pb(a[i]);
    }
    // find the min and rotate
    if (mid.size() == 0){
        for (auto& z: lr) cout << z << " ";
        cout << endl;
    } else{
        int p = 0;
        for (int i = 0; i < mid.size(); i++){
            if (mid[i] < mid[p]) p = i;
        }
        vi mid2;
        for (int i = p; i < mid.size(); i++) mid2.pb(mid[i]);
        for (int i = 0; i < p; i++) mid2.pb(mid[i]);

        
        // insert mid2 between l2 
        if (lr.size() == 0){
            for (auto& z: mid2) cout << z << " ";
            cout << endl;
        } else{
            // insert 
            bool done = false;
            for (int i = 0; i < lr.size(); i++){
                if (mid2[0] < lr[i] && !done){
                    done = true;
                    for (auto & z: mid2) cout << z << " ";
                }
                cout << lr[i] << " ";
            }
            if (!done){
                for (auto&z :mid2) cout << z << " ";
            }
            cout << endl;
        }

    }



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
    return 0;
}
