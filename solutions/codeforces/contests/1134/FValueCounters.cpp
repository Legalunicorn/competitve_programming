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


// NOTE:
// sum is zero 
// perhaps we can sort of greedy assign left to right
// ie.
// b1 = -5 means "1" has net tie + 5 elements greater than it to the right 
// b1 =  5 means "1" has net tie + 5 elements less than it to the right
//
// im possible when we conside net time = 0, and value makes no snese 
// we need to construct P, most likely by sorting or swapping 
// we also need to consider the range of "net ties" allowed 
//
// Permutatoin 
// -> 1 to 1 
// 
// actually b_0 and b_n are quite forcing 
// b_0 -(n-1) to 0 
// it tells the exact position of "1"
//
//
//
// we know "1" we know "n" 
// know we go to "2" and "n-1" 
//
// as we go, we have inserted SOME values
// it makes sense but i have no idea how to query this 
// we have score S 
// then we need to S + delta added = V
// V = net position
//
//
// how do we calculate delta? 
// query: 

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a)cin >> z;
    vi p(n,-1);
    if (a[0] > 0 || a[n-1] < 0){
        cout <<-1 << endl;
        return;
    }
    // insert 1 and n 
    // conceptually.
    p[n-1-abs(a[0])] = 1;
    int sp = n-1-abs(a[0]);
    if (sp<0 || sp >= n) {
        cout << -1 << endl;
        return;
    }
    p[n-1-abs(a[0])] = 1;
    int ep = a[n-1];
    if (ep < 0 || ep >= n){
        cout << - 1 << endl;
        return;
    }
    if (p[a[n-1]]!=-1){
        cout << -1 << endl;
        return;
    } else p[a[n-1]] = n;
    // p[a[n-1]]
    

    // 1 -> -(n-1), 0 
    
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
