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

// maiintag seggty tree 
// of [1,N] freq
//
// then i just count sum from [x, N] each time i want to find 
//
// IDEA: 
// 1. offset count how many eps will include themsleves
// 1. cap elements to N +5 
// 2. sort ranges, but include the idex inside 
// 3. process ranges ad insert to st as needed 
// 4. 


// ==== check combine function, update funciton, and default tree value 
template<class T>
struct SegTree{
private:
    int n;
    vector<T> tree;
	T INVALID;
    // === Change === 
    T combine(T p, T q){
        return p + q;
    }
	void build(int low, int high, int pos, vector<T>& a){
		if (low==high){
			tree[pos] = a[low];
			return;
		}
		int mid = (high+low)/2;
		build(low,mid,2*pos+1,a);
		build(mid+1,high,2*pos+2,a);
		// check
        tree[pos] = combine(tree[2*pos+1],tree[2*pos+2]);
	}

	T q(int qlow, int qhigh, int low, int high, int pos){
		if (qlow<= low && qhigh>=high) return tree[pos];
		if (qlow> high || qhigh < low) return INVALID;
		int mid = low+(high-low)/2;
        return combine(
            q(qlow,qhigh,low,mid,2*pos+1),
            q(qlow,qhigh,mid+1,high,2*pos+2)
                );
	}
	void up(int low, int high, int pos, int idx, T val){
        // == =val or +=val 
        if (low == high){
            tree[pos] += val;
            return;
        }
        int mid = (low+high)/2;
        if (idx<=mid) up(low,mid,2*pos+1,idx,val);
        else up(mid+1,high,2*pos+2,idx,val);
        tree[pos] = combine(tree[2*pos+1], tree[2*pos+2]);
	}
public:
    // === set invalid based on context == 
    SegTree(int size, T invalid = numeric_limits<T>::min()){
		n = size;
		// INVALID=invalid;
        INVALID = 0;
      	tree.resize(4*n,INVALID);
    }
	void build(vector<T>& a){ build(0,n-1,0,a); }
	T query(int qlow, int qhigh){ return q(qlow,qhigh,0,n-1,0);}
	void update(int idx, T val){up(0,n-1,0,idx,val);}
};

void solve(){
    ll n;
    cin >> n;
    vl  a(n);
    SegTree<ll> st(n+5, 0);
    for (auto &z: a) cin >> z;
    ll offset = 0;
    ll res =0;
    for (int i = 0;i < n; i++){
        a[i]--;
        a[i] = min(a[i], n-1LL);
        // limiting to n-1
        if (a[i] >= i) offset++;
    }
    
    vpl b(n);
    for (int i = 0; i < n; i++){
        b[i] = {a[i], i};
    }
    sort(all(b));
    ll added = 0;
    for (int i = 0; i < n; i++){
        ll p = b[i].F;
        while(added <= p){
            debug(i, a[added]);
            st.update(a[added], 1);
            added++;
        }
        ll low = b[i].S;
        ll tot = st.query(low, n+1);
        res += tot;
    }
    ll v = (res-offset)/2;
    cout << v << endl;
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
