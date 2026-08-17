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


// find the sum of f(C) over all subarrays 
// 1. we can identify all pain points from c1 
//



template<class T>
struct SparseTable{
public:
    // Modify this part
    // This Sparse table is for IDEMPOTENT relations only O(1)
    // For non-idempotent just use a segment tree for O(log n) performance
    T combine(T a, T b){
        return min(a,b); //
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


void solve(){
    int n;
    cin >> n;

    map<ll,int> mp;

    vl a(n);
    for (auto& z:a) cin >> z;

    int last = -1;
    // between the last generation of previous 
    // and now 
    // there cannot be any smaller numbers! 
    
    // fuck it just minst 
    SparseTable<ll> st(n);
    st.build(a);

    vl pt(n);

    for (int i = 0; i <n; i++){
        ll prev = a[i]-1;
        if (mp.count(prev) && st.query(mp[prev], i) >= prev && mp[prev]>=last){
            mp[a[i]] = i;
        } else {
            pt[i] = 1;
            last = i;
            mp[a[i]] = i;
        }
    }

    ll p = 0;
    vl b(n);
    for (int i = 0; i <n; i++){
        if (pt[i]) p++;
        b[i] = p;
    }
    debug(b);
    for (int i = 1 ; i < n; i++){
        b[i] += b[i-1];
    }
    debug(b);
    ll tot  = 0;
    for (int i = 0; i < n; i++){
        ll q = b[n-1] - (i>0 ? b[i-1]:0LL);
        if (pt[i]){
            tot += q;
        } else {

        }
        debug(i,q);
    }

    // maybe try a different angle 
    // the min is alwasy 1 
    // idk how to enfroce that 
    // if p[i] = 1 
    // 

    // ll tot = 0;
    // ll res = 0;
    // debug(pt);
    // for (int i = 0; i < n; i++){
    //     if (pt[i]) { 
    //         res = res + (i) + 1;
    //     } else {
    //         res ++;
    //     } 
    //     tot += res;
    //     debug(i,res,tot);
    // }
    // cout << tot << endl;
    // cerr << endl;
    //

    // there is some pattern i dont know how to aggregate the sum yet 



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
