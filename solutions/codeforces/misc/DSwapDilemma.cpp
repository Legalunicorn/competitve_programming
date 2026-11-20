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


// ==== check combine function, update funciton, and default tree value 
template<class T>
struct SegTree{
private:
    int n;
    vector<T> tree;
	T INVALID;
    // === Change === 
    T combine(T p, T q){
        return p+q;
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
		INVALID=0;
      	tree.resize(4*n,INVALID);
    }
	void build(vector<T>& a){ build(0,n-1,0,a); }
	T query(int qlow, int qhigh){ return q(qlow,qhigh,0,n-1,0);}
	void update(int idx, T val){up(0,n-1,0,idx,val);}
};
void solve(){
    int n;
    cin >> n;
    int mx = 0;
    map<int,int> mp;
    vi a(n), b(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    for (int i = 0; i < n; i++){
        mp[a[i]]++;
        mx = max(mp[a[i]],mx);
    }
    for (int i = 0; i < n ;i++){
        mp[b[i]]--;
    }
    for (auto& [p,v]: mp){
        if (v != 0){
            cout << "NO" << endl;
            return;
        }
    }
    if (mx > 1){
        cout << "YES" << endl;
        return;
    }
    // all unique in this case its some parity thing 
    // i wanted to use seg tree but its 104 test cases
    // a[i] = 1-e5
    // we can rebase the values from 1 to n to cheat
    // the segtree -> count the number of bubble downs needed
    // the answer should be like
    // bubble sort: how many swaps? they must have the same pairyr 
    // i feel like this is too complex of an approach even tho it works
    vi vals;
    for (auto & z:a) vals.pb(z);
    sort(all(vals));
    mp.clear();
    for (int i = 0; i < n; i++){
        mp[vals[i]] = i;
    }
    for (int i = 0; i < n; i++){
        a[i] = mp[a[i]];
        b[i] = mp[b[i]];
    }
    SegTree<ll> st(n+5);

    auto check = [&](vi& c) -> ll {
        ll ans =0;
        SegTree<ll> st(c.size()+5);
        // how to counter inversions? 
        // left to right 
        // as i sweep i want to count
        for (int i= 0; i < n;i++){
            int x = c[i];
            ll c = st.query(0,x);
            ans+=c;
            st.update(x,1);
        }
        return ans%2;

    };
    ll one = check(a), two = check(b);
    if (one == two) cout << "YES" << endl;
    else cout << "NO" << endl;
    cerr << endl;
    

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
