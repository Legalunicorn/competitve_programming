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

// NOTE: 
// im not looking for the best score
// im looking for the best distance 
// score = a[i] - a[j] ,   j < i 
// any score >= 0 is ok
// so from all the score >= 0, i need the one with smallest index 
// i feel like i can do some lame shit with sgt 
//
// query looks like 
// insert (sum, index)
// query  
//  for all sums <= Q, return the min index 
//
//  vanoes >= -n 
//  i can shift by +n 
//  the range os now from 
//  [0, 3n]
//  i can story this in segment tree 
//  this i can use a min seg tree


// ==== check combine function, update funciton, and default tree value 
template<class T>
struct SegTree{
private:
    int n;
    vector<T> tree;
	T INVALID;
    // === Change === 
    T combine(T p, T q){
        return min(p,q);
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
            // tree[pos] = val;
            tree[pos] = min(tree[pos], val);
            return;
        }
        int mid = (low+high)/2;
        if (idx<=mid) up(low,mid,2*pos+1,idx,val);
        else up(mid+1,high,2*pos+2,idx,val);
        tree[pos] = combine(tree[2*pos+1], tree[2*pos+2]);
	}
public:
    // === set invalid based on context == 
    SegTree(int size, T invalid = numeric_limits<T>::max()){
		n = size;
		INVALID=invalid;
      	tree.resize(4*n,INVALID);
    }
	void build(vector<T>& a){ build(0,n-1,0,a); }
	T query(int qlow, int qhigh){ return q(qlow,qhigh,0,n-1,0);}
	void update(int idx, T val){up(0,n-1,0,idx,val);}
};



void solve(){
    string s;
    cin >> s;
    set<char> v = {'a','e','i','o','u', 'A', 'E', 'I', 'O', 'U'};
    int n = s.size();
    vi a(n);
    for (int i = 0; i < n; i++){
        if (v.count(s[i])) a[i] = -1;
        else a[i] = 2;
    }
    // int shift = n;
    SegTree<int> st(n * 3 + 5);
    st.update(n, -1);
   for (int i = 1; i < n; i++) a[i] += a[i-1];
    int res = 0;
    int cnt = 0;
    debug(a);
    for(int i = 0; i < n; i++){
        int t = a[i];
        int low = st.query(0, t + n);
        debug(t,i, low);
        if (low <= i){
            int evl = i - low;
            if (evl > res){
                res = evl;
                cnt = 1;
            } else if (evl == res){
                cnt++;
            }
        }
        debug(res,cnt);
        st.update(t + n, i);
    }
    if (res == 0){
        cout << "No solution" << endl;
        return;
    } else cout << res << " " << cnt << endl;
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
