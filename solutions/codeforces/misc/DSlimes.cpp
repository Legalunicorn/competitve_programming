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

void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    vl pfs = a, sfs = a;
    vl dback(n), dfront(n);
    for (int i = 1; i < n; i++){
        if (a[i] != a[i-1]){
            dback[i] = 1;
            dfront[i] = 1;
        }
    }
    for (int i = 1;i < n;i++) {
        dback[i] += dback[i-1];
        pfs[i] += pfs[i-1];
    }
    for (int i = n-2; i >=0; i--) {
        dfront[i] += dfront[i+1];
        sfs[i]+=sfs[i+1];
    }
    vl res(n);
    auto get_sum = [&](int l, int r) -> ll{
        if (l > r) swap(l,r);
        return pfs[r] - (l>0? pfs[l-1]:0);
    };
    auto get_diff = [&](int l, int r) -> ll{
        if (l>r) swap(l,r);
        return dback[r] - (l>0 ? dback[l-1]:0);
    };
    for (int i = 0; i < n; i++){
        if (i-1>=0 && a[i-1] > a[i] || i+1<n && a[i+1]>a[i]){
            res[i] = 1;
            continue;
        }
        // left side
        ll evl = INF;
        {
            int l = 0, r = i-2;
            while(l<=r){
                int m = (l+r)/2;
                ll dc = get_diff(m+1,i-1);
                ll sum = get_sum(m,i-1);
                if (dc>0 && sum>a[i]){
                    evl = min(evl, (ll)abs(i-m));
                    l = m + 1;
                } else r = m -1;
            }
        }
        {
            int l = i+2, r = n-1;
            while(l<=r){
                int m =(l+r)/2;
                ll dc = get_diff(i+2,m);
                ll sum = get_sum(i+1,m);
                if(dc>0 && sum>a[i]){
                    evl = min(evl, (ll)abs(m-i));
                    r = m -1;
                } else l = m +1;
            }
        }
        if (evl == INF) evl = -1;
        res[i] = evl;
    }
    for (auto& r: res) cout << r << " ";
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
    while(T--) solve();
    return 0;
}
