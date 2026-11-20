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
// our query just has to figure out how many of each type of gems are inside the range 
// 6 types is fixed 
// Q1: change gem type 
// Q2: change type valye 
// Q3: query sum [L,R]
//
// why cant we just use 6 segment trrees? abit overkill
// wait im deadass though
// just use six segments tree update 0 or 1 as present not presnet


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
            tree[pos] = val;
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
		INVALID=invalid;
      	tree.resize(4*n,INVALID);
    }
	void build(vector<T>& a){ build(0,n-1,0,a); }
	T query(int qlow, int qhigh){ return q(qlow,qhigh,0,n-1,0);}
	void update(int idx, T val){up(0,n-1,0,idx,val);}
};


void solve(){
    int n,q;
    cin >> n >> q;
    vector<SegTree<ll>> sts(6, SegTree<ll>(n, 0ll));
    vi curr(n);
    map<int,int> mp;
    for (int i = 1; i <= 6; i++){
        ll x; cin >> x;
        mp[i-1] = x;
    }
    string t; cin >> t;
    for (int i = 0; i < n; i++){
        int v = t[i]-'0'-1;
        debug(i, v);
        curr[i] = v; // type v 
        sts[v].update(i, 1);
    }
    for (int i = 0; i < q; i++){
        int id,a,b;
        cin >> id >> a >> b;
        if (id == 1){
            a--,b--;
            // replace a-th gem wih type "b"
            int prev = curr[a], nxt = b;
            sts[prev].update(a, 0);
            sts[nxt].update(a, 1);
            curr[a] = nxt;
        } else if (id == 2){
            a--;
            mp[a] = b; // new value
        } else {
            a--, b--;
            ll ans = 0ll;
            for (int i = 0; i < 6; i++){
                ll cnt = sts[i].query(a,b);
                debug(i, cnt);
                ans += cnt * mp[i];
            }
            cout << ans << endl;
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
    // cin >> T; 
    while(T--) solve();
    return 0;
}
