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

// i feel like we can data structure spam this shit 
// with binary search and set 
//
// NOTE: cases 
// 1. Left Point , Map<length, freq>  
// 2. Right end point, Map<Length, freq> 
//
// overlapping case 
// 1. Left end point: 
//      -> find the largestest right endpopint <= dist 
//      1a) fits length exactly 
//          -> find ANYTHING that start after Li, and end BEFORE b[i], this is sufficent condition 
//          -> check if {l,r} count is 2 just in case 
//      1b) does not fit the length exactly 
//          find the larfest RIGHT -> LEFT endpoint <= dist 
//          endsure both distance >= dist;
//
// data strucutures for search  
// 1. a sorted list of endpoints 
// 2. Map<int, Map<int,int> 
// Map<int, set<int>> 
//
//
// mai nchallenge now 
// find any range from [l,r] 

// how do we find between {l,r} 
// we need to show there exist two segments between [l,r] 
//
//
//
// can we use PIE ? 
// let  A = start after S 
// let  B = end before T 
//
// A U B 
//
//
// we can just care about the SHORTEST cloth for each start 
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
    int n,m;
    cin >> n >> m;
    vpi a(m),b(m);
    for (int i = 0; i < m; i++) {
        cin >> a[i].F >> a[i].S;
        // b[i].F = a[i].S;
        // b[i].S = a[i].F;
    }
    sort(all(a));
    // sort(all(b)); 
    debug(a);
    map<pi,int> mp;
    map<int,set<int>> left, right;
    vi ll(n+1), rr(n+1);
    // left, right as an array 
    for (auto& p: a){
        int l = p.F, r = p.S;
        mp[{l,r}]++;
        int d = r - l + 1;
        left[l].insert(d);
        right[r].insert(d);
    }
    for (int i = 1; i <= n;i++){
        // if (!left[i].empty()) ll[i] = i +*left[i].begin();
        if (!left[i].empty()) ll[i] = i + (*left[i].begin())-1;
        else ll[i] = n*10;
    }
    SparseTable<int> spr(n+1);
    spr.build(ll);

    int q; cin >> q;
    debug(left);
    debug(right);
    debug(ll);


    while(q--) {
        // cerr << endl;
        int s,t; cin >> s >> t;
        debug(s,t);
        int d = t - s + 1;
        if (mp[{s,t}] > 1){
            cout << "Yes" << endl;
            continue;
        } else if (mp[{s,t}] == 1){
            // find the MIN REACH FROM L, AND {L+1, T}
            if (ll[s] < t){
                cout << "Yes" << endl;
                debug("1");
                continue;
            }
            if (s+1 > t){
                cout << "No" << endl;
                continue;
            }
            int xx  = spr.query(s+1,t);
            if (xx <= t) cout << "Yes" << endl;
            else cout << "No" << endl;
            debug("2");
            continue;

        }

        if (left[s].empty() || right[t].empty()){
            cout << "No" << endl;
                debug("3");
            continue;
        }

        auto it1 = left[s].upper_bound(d);
        auto it2 = right[t].upper_bound(d);
        if (it1!=left[s].begin() && it2!=right[t].begin() ){
            it1--;
            it2--;
            int tot = *it1 + *it2;
            // debug(*it1, *it2);
            if (tot >= d) cout << "Yes" << endl;
            else cout << "No" << endl;
            debug("4", tot,d);
        } else cout << "No" << endl;
        debug("5");

    }


    // answer queries 
};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    // cin >> T; 
    while(T--){
        solve();
    }
    cerr << " == END ==" << endl;
    return 0;
}
