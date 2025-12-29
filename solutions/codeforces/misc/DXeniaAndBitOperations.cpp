/*
 __  __     __     ______     ______     ______   
/\ \_\ \   /\ \   /\  == \   /\  __ \   /\  ___\  
\ \  __ \  \ \ \  \ \  __<   \ \ \/\ \  \ \ \____ 
 \ \_\ \_\  \ \_\  \ \_\ \_\  \ \_____\  \ \_____\
  \/_/\/_/   \/_/   \/_/ /_/   \/_____/   \/_____/

  */

#include <bits/stdc++.h>

using namespace std;
using namespace chrono;

// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
// using namespace __gnu_pbds;
// template <class T> using ordered_set = tree<T, null_type,
// less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// template <class T> using ordered_multiset = tree<T, null_type,
// less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

//alias 
using ll = long long;
using ull = unsigned long long; 
using ld = double; 
using pii = pair<int,int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vvvi = vector<vvi>;
using vl = vector<ll>;
using vvl = vector<vl>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using vvpi = vector<vpi>;
using vb = vector<bool>;
using vvb = vector<vb>;


// constants 

constexpr ll INF = 4e18;
constexpr ld EPS = 1e-9;
constexpr ll MOD = 1e9+7;
constexpr double PI = 3.14159265358979323846;


// macros
#define endl '\n' 
#define F first
#define S second 
#define all(x) begin(x), end(x)
#define pb push_back
#define MP make_pair
#define MIN(a) *min_element(all(a));
#define MAX(a) *max_element(all(a));
#define sortU (a) sort(all(a)),(a).erase(unique(all(a)),(a).end())

// === Debug macros , to add a general function and replace this gunk
#define debugv(vec) cerr << #vec << " = ["; for (size_t i = 0; i < (vec).size(); ++i) { cerr << (vec)[i]; if (i + 1 < (vec).size()) cerr << ", "; } cerr << "]\n";
#define debugm(mat) do { cerr << #mat << " = [\n"; for (size_t i = 0; i < (mat).size(); ++i) { cerr << "  ["; for (size_t j = 0; j < (mat)[i].size(); ++j) { cerr << (mat)[i][j]; if (j + 1 < (mat)[i].size()) cerr << ", "; } cerr << "]\n"; } cerr << "]\n"; } while (0)

//variables and functoins
const vvi dirs = {{-1,0},{1,0},{0,-1},{0,1}};
const vector<char> dir_char = {'U','D','L','R'};
vector<char> vowels = {'a','e','i','o','u'};
string make_lower(const string& t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return tolower(c); }); return s; }
string make_upper(const string&t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return toupper(c); }); return s; }
bool is_vowel(char c) {return c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i';}


// ==== check combine function, update funciton, and default tree value 
template<class T>
struct SegTree{
private:
    int start_op;
    int n;
    vector<T> tree;
	T INVALID;
    // === Change === 
    T combine(T p, T q, int op){
        if (op==1) return p ^ q;
        else return p | q;
    }
	void build(int low, int high, int pos, vector<T>& a, int op){
		if (low==high){
			tree[pos] = a[low];
			return;
		}
		int mid = (high+low)/2;
		build(low,mid,2*pos+1,a, 1 - op);
		build(mid+1,high,2*pos+2,a, 1 - op);
		// check
        tree[pos] = combine(tree[2*pos+1],tree[2*pos+2], op);
	}

	T q(int qlow, int qhigh, int low, int high, int pos, int op){
		if (qlow<= low && qhigh>=high) return tree[pos];
		if (qlow> high || qhigh < low) return INVALID;
		int mid = low+(high-low)/2;
        return combine(
            q(qlow,qhigh,low,mid,2*pos+1, 1 - op),
            q(qlow,qhigh,mid+1,high,2*pos+2, 1 - op),
            op
        );
	}
	void up(int low, int high, int pos, int idx, T val, int op){
        // == =val or +=val 
        if (low == high){
            tree[pos] = val;
            return;
        }
        int mid = (low+high)/2;
        if (idx<=mid) up(low,mid,2*pos+1,idx,val, 1 - op);
        else up(mid+1,high,2*pos+2,idx,val, 1 - op);
        tree[pos] = combine(tree[2*pos+1], tree[2*pos+2], op);
	}
public:
    // === set invalid based on context == 
    SegTree(int size, int start,  T invalid = numeric_limits<T>::min()){
        start_op = start;
		n = size;
		INVALID=invalid;
      	tree.resize(4*n,INVALID);
    }
	void build(vector<T>& a){ build(0,n-1,0,a, start_op); }
	T query(int qlow, int qhigh){ return q(qlow,qhigh,0,n-1,0,start_op);}
	void update(int idx, T val){up(0,n-1,0,idx,val, start_op);}
};

void solve(){
    int nbase,m;
    cin >> nbase >> m; 
    int n = (int)pow(2,nbase);
    vl a(n);
    for (auto& z:a) cin >> z;
    int start = (nbase % 2 ==1 ) ? 0 : 1;
    
    SegTree<ll> st(n,start, 0);
    st.build(a);
    while(m--){
        int p;
        ll b;
        cin >> p >> b;
        st.update(p-1,b);
        cout << st.query(0, n-1) << endl;
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
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}
