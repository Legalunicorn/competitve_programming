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
// data structure ok 
// point update search
// what is the range query? 
// we want to query all numbers NOT -1
// 
// we want to compute the numbre of distinct, that is NOT -1
//  we can use small to large merging tree
// it might TLE 
// so we can optimize in some way? 
// like we just maintain a set of maxsize 2 

//
// struct node{
//     int n1 = 0;
//     bool valid = true;
//     // positive values only
//     bool temp = -5;
//     // -3 for range
//     int val = -3;
// };
//
// struct nn{
//     // int val = -1;
//     // bool valid = false;
//     set<ll> st;
//     // bool is1 = true;
//     // int temp = -5;
// };
//
// ==== check combine function, update funciton, and default tree value 
template<class T>
struct SegTree{
private:
    int n;
    vector<T> tree;
	T INVALID;
    // === Change === 
    T combine(T p, T q){
        auto& s1 =p;
        auto& s2= q;
        T res;
        if (s1.size() > s2.size()){
            for (auto z: s1){
                if (z != -1) res.insert(z);
                if (res.size()>1) return res;
            }
            res = s1;
            for (auto& z: s2) {
                if (z == -1) continue;
                res.insert(z);
                if (res.size()>1) return res;
            }
        } else{
            for (auto& z: s2){
                if (z != -1) res.insert(z);
                if (res.size()>1) return res;
            }
            for (auto& z:s1) {
                if (z == -1) continue;
                res.insert(z);
                if (res.size() > 1) return res;
            }
        }
        return res;
    }

	void build(int low, int high, int pos, vector<ll>& a){
		if (low==high){
			// tree[pos] = a[low];
            // tree[pos].val = a[low];
            if (a[low] != -1) tree[pos] = {a[low]};
            else a[low] = {};
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

	void up(int low, int high, int pos, int idx, ll val){
        if (low == high){
            if (val == -1) tree[pos] = {};
            else tree[pos] = {val};
            return;
        }
        int mid = (low+high)/2;
        if (idx<=mid) up(low,mid,2*pos+1,idx,val);
        else up(mid+1,high,2*pos+2,idx,val);
        tree[pos] = combine(tree[2*pos+1], tree[2*pos+2]);
	}
public:
    // === set invalid based on context == 
    SegTree(int size){
		n = size;
        INVALID = set<ll>();
		// INVALID=invalid;
      	tree.resize(4*n,INVALID);
    }
	void build(vector<ll>& a){ build(0,n-1,0,a); }
	T query(int qlow, int qhigh){ return q(qlow,qhigh,0,n-1,0);}
	void update(int idx, ll val){up(0,n-1,0,idx,val);}
};

void solve(){
    int n,q;
    cin >> n >> q;
    vl a(n);
    for (auto& z:a) cin >> z;
    SegTree<set<ll>> sg(n);
    sg.build(a);
    while(q--){
        ll id, x,y;
        cin >> id >> x >> y;
        if (id == 1){
            sg.update(x-1,y);
        } else{
            set<ll> e = sg.query(x-1,y-1);
            if (e.size()<=1) cout << "Yes" << endl;
            else cout << "No" << endl;
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
