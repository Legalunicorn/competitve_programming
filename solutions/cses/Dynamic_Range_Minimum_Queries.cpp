#include <bits/stdc++.h>
#include <chrono>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
using namespace chrono;
using namespace __gnu_pbds;

//template 
// distinct - pbds 
template <class T> using ordered_set = tree<T, null_type,
less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// 
template <class T> using ordered_multiset = tree<T, null_type,
less_equal<T>, rb_tree_tag,tree_order_statistics_node_update>;

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



struct SegTree{
    vi tree;
    int n;
    SegTree(int n){
        tree = vi(n*4,INT_MAX);
        this-> n = n;
    }
    void build(int l,int r, int p, vi&a){
        if (l==r) {
            tree[p] = a[l];
            return;
        }
        int m = (l+r)/2;
        build(l,  m,2*p+1,a);
        build(m+1,r,2*p+2,a);
        tree[p] = min(tree[2*p+1],tree[2*p+2]);
    }

    int query(int ql, int qh, int l, int r, int p){
        if (ql>r || qh<l) return INT_MAX;
        if (ql<=l && qh>=r) return tree[p];
        int m = (l+r)/2;
        return min(
            query(ql,qh,l,  m,2*p+1),
            query(ql,qh,m+1,r,2*p+2)
        );
    }

    void update(int l, int h, int p, int i, int x){
        if (l==h){
            tree[p] = x;
            return;
        }
        int m = (l+h)/2;
        if (i<=m) update(l,  m,2*p+1,i,x);
        else      update(m+1,h,2*p+2,i,x);
        tree[p] = min(tree[2*p+1],tree[2*p+2]);
    }

};
void solve(){
    cerr << (2^4^5) << endl;
    int n,q;
    cin >> n >> q;
    vi a(n);
    for (int&z: a) cin >> z;
    SegTree tree(n);
    tree.build(0,n-1,0,a);
    while(q--){
        int z;
        cin >> z;
        if (z==1){
            int k,u; cin >> k >> u;
            tree.update(0,n-1,0,k-1,u);
        } else{
            int l,r; cin >> l >> r;
            cout << tree.query(l-1,r-1,0,n-1,0) << endl;
        }
    }

};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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