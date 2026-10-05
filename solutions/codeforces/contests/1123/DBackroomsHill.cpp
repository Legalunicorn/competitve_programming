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
#define S second  , 
#define all(x) begin(x), end(x)
#define rall(x) rbegin(x), rend(x)
#define pb push_back
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));

const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
constexpr ll INF = 4e18; 
constexpr ld EPS = 1e-9; 
constexpr ll MOD = 1e9+7;


// pairty problem 
// naigve solution is to try for eahk 
// try each element to be the PEAK 
//
// strictly increase, then strinctly decrease
// a number can only appears twice at most
// the max number can only appear once 
// we have to place the max number somewqhere 
// the MIN element must be at the base 
//
//
// maybe we isolate the case where there is no peak, its jut increasing -> sort both odd/even position
// -> 
//
// consolidate
// 1. it is DISTINCT 
// 2.just sayu its a permmitation omg pmo 
//
// 3. the sorted odd/even cannot differ by one
//
// x o x o x o x o 
// not even true 
// maybe its some dubm shit 
// 1. try "1" on the left (if possible)
// 2. try "1" on the right if (possib)E


void solve(){
    int n;
    cin >> n;
    vi a(n);
    for(auto&z:a) cin >> z;
    vi odd, even;
    for (int i = 0; i < n;i++){
        if (i%2==0) odd.pb(a[i]);
        else  even.pb(a[i]);
    }
    sort(all(odd));
    sort(all(even));
    
    bool isodd;
    if (odd[0] == 1) isodd = true;
    else isodd = false;
    if (n%2==1 && !isodd){
        cout << "NO" << endl;
        return;
    }
    int es = even.size(), os = odd.size();
    int ep = 0, op = 0;
    vb eused(even.size());
    vb oused(odd.size());
    int left = n;
    int last = 0;
    debug(a);
    vi te;
    // construct increse
    while(left > 0){
        bool found = false;
        if (isodd){
            while(op < os){
                if (odd[op] > last){
                    found = true;
                    oused[op] = true;
                    last = odd[op];
                    te.pb(last);
                    left--;
                }
                op++;
                if (found) break;
            }
        } else{
            while(ep < es){
                if (even[ep] > last){
                    found = true;
                    eused[ep] = true;
                    last = even[ep];
                    te.pb(last);
                    left--;
                }
                ep++;
                if (found) break;
            }
        }
        if (!found) break;
        isodd = !isodd;
    }
    debug(te, ep, es, left);
    ep = es - 1;
    op = os - 1;
    while(left >0){
        bool found = false;
        if (isodd){
            while(op >= 0){
                if (!oused[op] && odd[op] < last){
                    found = true;
                    oused[op] = true;
                    last = odd[op];
                    te.pb(last);
                    left--;
                }
                op--;
                if (found) break;
            }
        } else{
            while(ep >= 0){
                if (!eused[ep] && even[ep] < last){
                    found = true;
                    eused[ep] = true;
                    last = even[ep];
                    te.pb(last);
                    left--;
                }
                ep--;
                if (found) break;
            }
        }
        if (!found) break;
        isodd = !isodd;
    }
    debug(te, ep, es, left);
    debug(even);
    debug(odd);
    cerr << endl;
    if (left <= 0) cout << "YES" << endl;
    else cout << "NO" << endl;



    

    // NOTE:
    // if "n" is odd, can only start from ODD 


    // permutation 100%
    // bool valid = true;
    // for (int i = 1; i < odd.size(); i++){
    //     if (odd[i] - odd[i-1] == 1)  valid= false;
    // }
    // for (int i =1; i < even.size();i++){
    //     if (even[i] - even[i-1] ==1) valid = false;
    // }
    // debug(a, valid);
    // debug(odd);
    // debug(even);
    // cerr << endl;
    // if (valid) cout << "YES" << endl;
    // else cout << "NO" << endl;
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
