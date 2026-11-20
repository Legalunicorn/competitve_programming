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



// + - - - + 
// 1 0 -2 -2 -1 
//
// but -3 is not included 
// the range is [1, -2], which has height = 3 
//
// if we isolate p 
// okay i think for correctness is okay 
// because we demand "p" is included we can extend out 
//
// then if we exclude p 
// there are at most w rangess of {-1, 1} 
// maybe its about storing max and min to the right 

pi range(vi& a, int l, int r){
    int low = 0, high = 0, n = a.size(), cnt = 0;
    vi pt(n);
    // vpi temp(n);
    for (int i = l; i <= r; i++){
        cnt += a[i];
        pt[i] = cnt;
        low = min(low, pt[i]);
        high = max(high, pt[i]);
        // low = min(low, cnt);
        // high = max(high, cnt);
        // temp[i] = {low,high};
    }
    pi res = {low, high};
    // pi res = {0,0};
    pi t = {pt[r], pt[r]};
    for (int i = r; i >= l; i--){
        res.F = min(res.F, t.F - pt[i]);
        res.S = max(res.S, t.S - pt[i]);
        t.F = min(t.F, pt[i]);
        t.S = max(t.S, pt[i]);
        debug(t);
    }
    // res.F = min(res.F, )

    debug(pt);
    debug(a,l,r, res);
    return res;
    // temp[r] = {0,0};
    // for (int i = r-1; i >=l;i--){
    //
    //     temp[i].F = min(temp[i+1].F, temp[i].F);
    //     temp[i].S = max(temp[i+1].S ,temp[i].S);
    // }
    // cnt = 0;
    // pi res = temp[r];
    // for (int i = l; i <= r; i++){
    //     cnt += a[i];
    //     debug(cnt, temp[i].F - cnt, temp[i].S- cnt);
    //     res.F = min(res.F, temp[i].F - cnt);
    //     res.S = max(res.S, cnt - temp[i].S);
    // }
    // debug(temp);
    // debug(a,l,r,res);
    // return res;
 
}

void solve(){
    // at most one, if we cant find its OK
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    int p = -1;
    for (int i = 0; i < n; i++) if (a[i] != 1 && a[i] != -1) p = i;
    set<int> st;
    if (p == -1){
        pi evl  = range(a, 0, n-1);
        for (int i = evl.F; i <= evl.S; i++) st.insert(i);
        // int mn = 0, mx = 0;
        // int cnt = 0;
        // for (int i = 0; i <n ;i++){
        //     cnt+=a[i];
        //     mn = min(mn,cnt);
        //     mx = max(cnt, mx);
        // }
        // for (int i = mn; i <=mx;i++) st.insert(i);
    } else{
        pi left = range(a, 0, p-1);
        pi right = range(a, p+1, n-1);
        for (int i = left.F; i<=left.S;i++) st.insert(i);
        for (int i = right.F; i<=right.S;i++) st.insert(i);
        debug(a,left,right);

        int mn = 0, mx = 0, cnt  =0; 
        for (int i = p-1; i >=0; i--){
            cnt +=a[i];
            mn = min(mn, cnt);
            mx = max(mx, cnt);
        }
        int mx2 = 0, mn2 = 0, cnt2 = 0;
        for (int i = p+1; i < n;i++){
            cnt2 += a[i];
            mn2 = min(mn2,cnt2);
            mx2  = max(mx2, cnt2);
        }
        int fmn = mn + mn2;
        int fmx = mx + mx2;
        debug(fmn,fmx);
        for (int i = fmn; i <= fmx;i++) st.insert(a[p]+i);
        // int low = min(mn,mn2);
        // int high = max(mx,mx2);
        // debug(mn,mn2, mx,mx2);
        // debug(fmn,fmx,low,high);
        // for (int i = fmn; i <= fmx;i++) st.insert(a[p] + i);
        // for (int i = low; i <= high;i++) st.insert(i);
    }
    debug(a);
    debug(st);
    cerr << endl;
    cout << st.size() << endl;
    for (auto& s: st) cout << s << " ";
    cout << endl;
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
