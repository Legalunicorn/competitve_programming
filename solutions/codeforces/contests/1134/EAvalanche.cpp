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


// NOTE: think about the end state: 
// 0 0 0 1 0 0 0 0 -> doesnt end the game
// 1 1 1 0 0 0 0 0 -> this bullshit happens 
// the only way the game ends is 
// 1 0 0 0 0 0 0 
// or perhaps 
// x 0 0 0 0 0 0      trivial -> pairtiy wins
// x y 0 0 0 0 0      trivial -> sum of pairty wins 
//  this is div4 it has to be simple 
//
//  invaraints? 
//  does the pairity of k matters? its tricky when k gets cut off at the prefix 
//
//  guess: 
//  1. ideally to start then we just ocunt hte pairty at the end, no idea why 
//  can we proof?  i think the order of moves does not matter



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
		INVALID=0ll;
      	tree.resize(4*n,INVALID);
    }

    void upp(int qlow, int qhigh, int low ,int high, int pos, int val){
        if (qlow <= low && qhigh >= high){
            debug(qlow,qhigh, pos, val);
            tree[pos]+=val;
            return;
        }
        if (qlow > high || qhigh < low) return;
        int mid = low+(high-low)/2;
        upp(qlow, qhigh, low, mid, 2*pos+1, val);
        upp(qlow, qhigh, mid+1, high, 2*pos+2, val);
        //tree[pos] = combine(tree[2*pos+1], tree[2*pos+2]);
    }
    T qq(int low, int high, int pos, int idx){
        if (low ==high) return tree[pos];
        int mid = (low+high)/2;
        if (idx <= mid)  return tree[pos] + qq(low, mid, 2*pos+1, idx);
        else return tree[pos]+qq(mid+1, high, 2*pos+2, idx);
    }

	void build(vector<T>& a){ build(0,n-1,0,a); }
	T query(int qlow, int qhigh){ return q(qlow,qhigh,0,n-1,0);}
	void update(int idx, T val){up(0,n-1,0,idx,val);}
};


void solve(){
    int n,k;
    cin >> n >> k;
    vl a(n);
    for (auto& z:a) cin >> z;
    ll s = 0;
    SegTree<ll> sg(n, 0ll);
    // sg.build(a);
    for (int i = 0; i < n; i++) sg.upp(i,i,0,n-1,0,a[i]);
    ll moves = 0;
    debug(a);
    for (int i = 0; i < n; i++) cerr << sg.qq(0,n-1, 0, i) << " ";
    cerr << endl;
    for (int i = n-1; i > 0; i--){
        ll score = sg.qq(0, n-1, 0, i);
        score %= 2;
        moves += score;
        moves %= 2;
        int j = max(0, i-k);
        debug(i, score, j, i-1);
        sg.upp(j, i-1, 0, n-1, 0, score);
    }
    for (int i = 0; i < n; i++) cerr << sg.qq(0,n-1, 0, i) << " ";
    //y cerr << endl;
    ll x = sg.qq(0,n-1,0,0);
    debug(x);
    // cerr << endl;
    if (x % 2 == 0){
        if (moves % 2 == 1) cout << "Alice" << endl;
        else cout << "Bob" << endl;
    } else {
        if (moves % 2 == 1) cout << "Bob" << endl;
        else cout << "Alice" << endl;
    }
    // if (x % 2 == 0 ) cout << "Bob" << endl;
    // else cout << "Alice" << endl;
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
