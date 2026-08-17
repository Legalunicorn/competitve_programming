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

// I got mislet with DP, this is just MATH + GREEDY 
// optimal: choose a final kindom and stuff with it 
// then the rest is just calculation using prefix usm 
//
// you are from 0, and the capital must be conquered in a specific order right 
// 1,2,3,4,5 
// i dont think there is a way to conquer 1, 3 ,2 etc 
// the order is fixed, but the current capital to jump from is now 
// when we conquer (1), or any capital 
// we can choose to jump to any ohter ! 
// opt1 : 
// 1. jump + conquer 
// 2. stay + conquer 
// if jump, jump where? it need not be the closest to the next to conqueryu rigth ? 
// what if we jump with i + 1 AND i +2 in mind, to some place in between so that cost is reduced 
// maybe this is math im not sure 
// gap of 1 and 5 >>  2 and 3 
//
// we can do this backward right ? since the order is fixed 
// conquer the last LAST guy, but from WHERE? 
// some linearity 
// partial_
partial_su
void solve(){
    
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
} zn
