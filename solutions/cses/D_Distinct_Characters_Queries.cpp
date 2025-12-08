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
    int n;
    vvi tree;

    SegTree(int n, vi& a){
        this->n = n;
        tree = vvi(4*n,vi(27,0));
        build(0,n-1,0,a);
    }

    void combine(int pos,vi& left, vi& right){
        int unique = 0;
        for (int i=0;i<26;i++){
            tree[pos][i] = left[i] + right[i];
            if (tree[pos][i]==1) unique++;
        }
        tree[pos][26] = unique;
        // return tree[pos];

    }


    
    void build(int low , int high ,int pos, vi& a){
        if (low==high){
            tree[pos][a[low]] =1;
            tree[pos][26] = 1; //1 unique value 
            return;
        }
        int mid = (low+high)/2;
        build(low,mid,2*pos+1,a);
        build(mid+1,high,2*pos+2,a);
        combine(pos,tree[2*pos+1],tree[2*pos+1]);
    }

    vi query(int qlow,int qhigh, int low, int high, int pos){
        if (qlow>high || qhigh<low) return vi(27,0);
        if (qlow<=low && qhigh>=high) return tree[pos];
        int mid = (low+high)/2;
        vi l = query(qlow,qhigh,low,mid,2*pos+1);
        vi r = query(qlow,qhigh,mid+1,high,2*pos+2);
        // return combine(pos,l,r);
        vi res(27,0);
        int uni = 0;
        for (int i=0;i<26;i++){
            res[i] = l[i] + r[i];
            if (res[i]==1) uni++;
        }
        res[26] = uni;
        return res;
    }

    void update(int low,int high, int pos, int idx,int x){
        if (low==high){
            tree[pos] = vi(27,0);
            tree[pos][x]++;
            tree[pos][26]=1;
            return;
        }
        int mid = (low+high)/2;
        if (idx<=mid) update(low,mid,2*pos+1,idx,x);
        else update(mid+1,high,2*pos+2,idx,x);
        combine(pos,tree[2*pos+1],tree[2*pos+2]);
    }
};


void solve(){
    string s; cin >> s;
    int q; cin >> q;

    int n = s.size();
    vi a(n);
    for (int i=0;i<n;i++) a[i] = s[i]-'a';
    SegTree tree(n,a);

    while(q--){
        int a; cin >> a ;
        if (a==1){
            int pos ; cin >> pos;
            char c ; cin >> c;
            tree.update(0,n-1,0,pos-1,(int)(c-'a'));
        } else{
            int l,r; cin >> l >> r;
            vi evl = tree.query(l-1,r-1,0,n-1,0);
            cout << evl[26] << endl;
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