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
// we must delete on segment, [L,R] -> it has a start and end 
// we can try each element as a start L, or as R 
//
// suppose we preprocess the score pre[i] (no deletion)
// say we delete and get post[i] 
// if we delete [L,R] inclusive post[R+1] = pre[L-1] 
// if post[i] < pre[i] pointless, we end up with a worst score, unless that is forced 
// if post[i] == pre[i], we get the same result 
// if post[i] > pre[i], we can only get better result, so its optimal that post[R], we just set it to max(pre[0,R-1]) 
// but then we still need to simulate what the final result is 
// let d  = post[i] - pre[i];
// the max answer is post[n-1] + d, but its higly possible the score degrades 
// if pre[i] MINUS, post[i] MINUS 100% 
// if pre[i] SAME,  post[i] MINUS or SAME 
// if pre[i] PLUS,  pos[i]  anything can happen
// note: the rating will never go positive 
//   unless we can calculate the rating changes purely based on perf suffi [r..n]
//   binary search? no 
//   not predictable
//
//   can we perhaps combine the stuff? 
//   for each [i] we store post[i], 
//   then we proces the results from left to right, any anytime curr < pos[i], we reset it to post[i];
//
// what if we fix L instead dont make sense? we still have to predict


void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin>> z;
    vi b(n);
    int score = 0, mx = 0;
    // how do we force at least one delete? 
    // n = 3
    // [3,3,3]
    // 1 2 3 
    // the max score cannot be n then 
    // is this sufficient to guarantee there was one delete? 
    // what if optimal = n-1? 
    // if we force one delete ... its still n-1?
    for (int i = 0; i < n;i++){
        if (score < a[i]) score++;
        else if (score > a[i]) score--;
        mx = max(mx, score);
        b[i] = mx;
    }
    debug(a,b);
    int cur = 0;
    for (int i = 0; i < n; i++){
        if (cur < a[i]) cur++;
        else if (cur > a[i]) cur--;
        cur = max(cur, b[i]); // makes no sense
    }
    cur = min(n-1, cur);
    cout << cur << endl; 
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
