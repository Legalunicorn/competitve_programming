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
// the max must obviously be at the side 
// the only shapes alloed is 
// - up slope 
// - down slope 
// - "V" shape 
//
// we can just simulation the v shapre and shift the pivot point 
// or we can treat as 3 separate cases 
// (1) -> LIS 
// (2) -> LDS 
// (3) for each element LIS(i) + LDS(i) - 1



// NOTE: 
// max LIS over all elements 
// max LDS over all elements 
//
// V shape: 
// -> LDS from both direction


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

void solve(){
    int n;
    cin >> n;
    vi a(n);
    for (auto& z:a) cin >> z;
    for (int i = 0; i < n; i++) a[i]--;
    SparseTable<int> st(n);
    st.build(a);
    vi pos(n);
    for (int i = 0; i < n; i++){
        pos[a[i]-0] = i;
    }
    auto go = [&](auto& go, int i, int j)->int{
        if (i >= j) return 0;
        int mx = st.query(i,j);
        int m = pos[mx];
        int evl = n;
        evl = min(evl, j - m + go(go, i, m-1));
        evl = min(evl, m - i +go(go, m+1,j ));
        return evl;
    };
    int res = go(go, 0,n-1);
    cout << res << endl;
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
