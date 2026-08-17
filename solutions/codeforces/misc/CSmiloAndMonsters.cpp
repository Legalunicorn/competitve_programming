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

// i think we can greedily proof that we should save x until its max balanaced

void solve(){
    int n;
    cin >> n;
    vl a(n);
    for (auto& z:a) cin >> z;
    sort(all(a));
    int  j = n-1;
    ll sum = 0;
    ll res = 0;
    // save up until we can compleleted kill last 
    int i = 0;
    debug(a);
    while(i <= j) {
        debug(i,j,sum,res, a[i], a[j]);
        if (i == j) {
            if (sum == a[i] || a[i] == 1){
                res++;
                break;
            }
            //debug()
            ll mid = (a[i] + sum) / 2;
            ll dist = mid - sum;
            debug(a[i], sum ,mid, dist);
            a[i] -= dist;
            a[i] -= mid;
            res += dist;
            res ++;
            if (a[i] > 0) res++;
            break;
        } else {
            ll need = a[j] - sum;
            if (a[i] < need) {
                res += a[i];
                sum += a[i];
                a[i] = 0;
                i++;
            } else{
                // take "need" from a[i];
                res += need;
                a[i] -= need;
                a[j] = 0;
                res++;
                sum = 0;
                j--;
                if (a[i] == 0) i++;
            }
        }
    }
    // while(i <= j){
    //     debug(i,j,sum,res);
    //     if (i == j){
    //         int mid = (sum + a[i]) / 2;
    //         int delta = mid - a[i];
    //         res += delta;
    //         sum += delta;
    //         a[i] -= delta;
    //         a[i] -= sum;
    //         if (a[i] > 0) res++;
    //         debug(res, sum,a[i], mid);
    //         //res += (mid - a[i]);
    //         //res += (mid - a[i] + 1);
    //         break;
    //         // sum, a[i] 
    //         //int mid = (sum + a[i]) /2;
    //         //res += (a[i] - mid + 1);
    //         //break;
    //     }
    //     ll need = a[j] - sum;
    //     debug(need, a);
    //     if (a[i] < need){
    //         res += a[i];
    //         sum += a[i];
    //         i++;
    //     } else {
    //         res += need;
    //         res ++;
    //         j--;
    //         sum = 0;
    //         a[i] -= need;
    //         if (a[i] == 0) i++;
    //     }
    // }

    cout << res << endl;
    cerr << endl;


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
