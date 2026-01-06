#include <bits/stdc++.h>
#include <queue>
#include <random>
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
    int n,k;
    cin >> n >> k; 
    vi a(n);
    for (auto& z:a) cin >> z;
    ll res = 0;
    // SparseTable<int> st(n);
    // st.build(a);
    //
    // simulate as last element 
    // for (int m = 0; m < n;m++){
    //     priority_queue<typename Tp>
    //     if (m==0){
    //         // find top k to the right of a[i]
    //     }
    //
    // }
    //

    // vpi b(n);
    // for (int i=0;i<n;i++){
    //     int x; cin >> x;
    //     a[i] = x;
    //     b[i] = {x,i};
    // }
    // // if k = 1, the
    //
    // sort(b.;


    // this should be greedy, we just need to check who CANNOT BE last for final k+1 



    // ll res = 0; // MAX SCORE 
    // vi a(n);
    // for (auto& z:a) cin >> z;
    // // if (tc==100){
    // //     string s;
    // //     for (auto&z:a) s = s + to_string(z) +"_";
    // //     cout << s << endl;
    // //     return;
    // // }
    // sort(a.rbegin(),a.rend());
    // for (int i=0;i<k+1;i++) res +=a[i];
    // cout << res << endl;
    // // its not possible to force an element to be the last 
    // // try every color as the last element; 
    // // 1 2 2 1 
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
