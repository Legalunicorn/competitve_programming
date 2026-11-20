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


// -> any query is O(1), we dont even need to cache or update
// -> for update 
// we just need to add to a whole segment 
// i think lazy prop segtree is valid 


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

	// T q(int qlow, int qhigh, int low, int high, int pos){
	// 	if (qlow<= low && qhigh>=high) return tree[pos];
	// 	if (qlow> high || qhigh < low) return INVALID;
	// 	int mid = low+(high-low)/2;
	//        return combine(
	//            q(qlow,qhigh,low,mid,2*pos+1),
	//            q(qlow,qhigh,mid+1,high,2*pos+2)
	//                );
	// }
	// void up(int low, int high, int pos, int idx, T val){
	//        // == =val or +=val 
	//        if (low == high){
	//            tree[pos] = val;
	//            return;
	//        }
	//        int mid = (low+high)/2;
	//        if (idx<=mid) up(low,mid,2*pos+1,idx,val);
	//        else up(mid+1,high,2*pos+2,idx,val);
	//        tree[pos] = combine(tree[2*pos+1], tree[2*pos+2]);
	// }

    void rup(int qlow, int qhigh, int low, int high, int pos, int v){
        if (qlow <= low && qhigh >= high) tree[pos] += v;
        else if (qlow > high || qhigh < low) return;
        else {
            int mid = low + (high - low) /2;
            rup(qlow, qhigh, low, mid, 2*pos+1, v);
            rup(qlow, qhigh, mid+1, high, 2*pos+2, v);
        }
    }
    // pos 
    int get(int low, int high, int pos, int idx) {
        if (low == high) return tree[pos];
        int mid = low + (high - low) / 2;
        if (idx <= mid) return tree[pos] + get(low, mid, 2 * pos + 1, idx);
        else return tree[pos] + get(mid+1, high, 2 * pos +2, idx);
    }


public:
    // === set invalid based on context == 
    SegTree(int size, T invalid = numeric_limits<T>::min()){
		n = size;
        INVALID = 0;
      	tree.resize(4*n,INVALID);
    }
	void build(vector<T>& a){ build(0,n-1,0,a); }
    void update(int l, int r, int v) { rup(l, r, 0, n - 1, 0, v );}
    T query(int idx) { return get(0, n-1, 0, idx);}

	//T query(int qlow, int qhigh){ return q(qlow,qhigh,0,n-1,0);}
	//void update(int idx, T val){up(0,n-1,0,idx,val);}
};


void solve(){
    int n,q;
    cin >> n >> q;
    SegTree<int> st(n);
    vi a(n);
    for (auto& z:a) cin >> z;
    while(q--){
        int id; cin >> id;
        if (id == 1) {
            int l, r; cin >> l >> r;
            st.update(l-1, r-1, 1);
        } else {
            int x; cin >> x;
            int ups = min(3, st.query(x-1));
            debug(a[x-1], x, ups);
            int curr = a[x-1];
            for (int k = 0; k < ups; k++){
                int sum  =0;
                while(curr){
                    sum += curr % 10;
                    curr /= 10;
                }
                curr = sum;
            }
            cout << curr << endl;
        }
    }
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
