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


// if im not wrong 
// we just just slide a window excluding the x people we cant control 
// then from our window we choose k+1 from the left, k+1 from the right 
// we need the max, lets just assume we use a sparse table 
// then our ans is this max 
// almong all answer, we find the mind 
//

template<class T>
struct SparseTable{
public:
    // Modify this part
    // This Sparse table is for IDEMPOTENT relations only O(1)
    // For non-idempotent just use a segment tree for O(log n) performance
    T combine(T a, T b){
        return max(a,b); //
    }

    SparseTable(int size){
        n = size;
        logPow.resize(n+1,0);
        for (int i=2;i<=n;i++) logPow[i] = logPow[i/2]+1;
        while((1<<LOG)<+n) LOG++;
        st.resize(n, vector<T>(LOG));
    }

    void build(vector<T>& arr){
        for (int i=0; i<n; i++){
            st[i][0] = arr[i];
        }
        for (int j=1; j<LOG; j++){
            for (int i=0; i + (1<<j) - 1 < n; i++){
                T a = st[i][j-1];
                T b = st[i+(1<<(j-1))][j-1];
                st[i][j] = combine(a,b);
             }
        }
    }
    
    T query(int l, int r){
        int k = logPow[r-l+1];
        T a = st[l][k];
        T b = st[r-(1<<k)+1][k];
        return combine(a,b);
    }
private:
    vector<vector<T>> st;
    int LOG = 20;
    int n;
    vector<int> logPow;
};


// m-th person to choose 
// k to control 
// n - m + k;
// misread: the k people must lock in their choice before knowing 
// what the other people choose 
// maybe its optimal to control the first k people then 
//
//


// LOOKed at editorial: 
// mono deque / segment tree required to sub n^2 
// othewise n^2 is allowed!! 
//
// we have to brute force all strategies 
// for all x (your strat) + for all y 

void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vl a(n);
    for (auto& z:a) cin >> z;
    k = min(k, m -1);
    // first k choices -> n - k windows side 
    int w = n - k;
    //second window 
    int q = n - k - (m - 1 - k);
    debug(w,q);
    ll res = 0;
    for (int l = 0; l + w - 1 <n; l++){
        // l is our window 
        ll local_res = INF;
        debug(l, l+w-1);
        for (int i=l; i + q -1 <= l + w - 1; i++ ){
            int left = i, right = i + q- 1;
            debug(left,right);
            ll evl = max(a[left],a[right]);
            local_res = min(local_res,evl);
        }
        res = max(res,local_res);
        // debug(l, l+w-1);
        // ll local_res = INF; 
        // for (int i  =  0; i+1< q; i++){
        //     int left = l + i, right = l + i + q - 1;
        //     debug(left,right);
        //     ll evl = max(a[left],a[right]);
        //     local_res = min(local_res, evl);
        // }
        // debug(local_res);
        // res = max(res,local_res);
        // now we need a y window within 
    }
    cout << res << endl;


}



// void solve(){
//     int n,m,k;
//     cin >> n >> m >> k;
//     vi a(n);
//     for (auto& z:a) cin >> z;
//     debug(n,m,k);
//     int w = min(n, n - m + k + 1);
//     if (w==0){
//         int res = MIN(a);
//         cout << res << endl;
//         return;
//     }
//     int res = INT_MAX;
//     SparseTable<int> st(n);
//     debug(w);
//     st.build(a);
//     for (int i =0; i + w - 1<n;i++){
//         debug(i, i+w-1);
//         int l = i;
//         int l2 = min(n-1,i+k);
//         int r = i + w - 1;
//         int r2 = max(0, r-k);
//         int mx = max(st.query(l,l2), st.query(r2,r) );
//         res = min(res,mx);
//     }
//     debug(" === ");
//     cout << res << endl;
//
// };

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
