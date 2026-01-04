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

// Makke a general segmet tree first to understand the concept 
// then we can try to make a tmeplate later 
// RANGE SUM + RANGE SET 

template<class T>
struct SegTree{
    const T NO_SET = -1; // unsettable value
    int n;
    vector<T> tree,lazy;

    T combine(T a, T b){
        return a+b;
    }

    SegTree(int sz, int def = 0){
        n = sz;
        tree.assign(4*n,def);
        lazy.assign(4*n,NO_SET); // 0? idk what to set this 
    }

    void build(int pos, int low, int high, vector<T>& a){
        if (low==high){
            tree[pos] = a[low];
            return;
        }
        int mid = (low+high)/2;
        build(2*pos+1,low,mid,a);
        build(2*pos+2,mid+1,high,a);
        tree[pos] = combine(tree[2*pos+1], tree[2*pos+2]);
    }

    void push(int pos, int l, int r){
        if (lazy[pos] == NO_SET || l==r) return;
        int mid = (l+r)/2;
        T x = lazy[pos];
        tree[2*pos+1] = (mid-l+1)*x;
        lazy[2*pos+1] = x;
        tree[2*pos+2] = (r-mid)*x;
        lazy[2*pos+2] = x;
        lazy[pos] = NO_SET;
    }
    // Range set 
    void update(int pos, int qlow, int qhigh, int low, int high, T val){
        if (qlow <= low && qhigh >= high){
            lazy[pos] = val;
            tree[pos] = (high-low+1)*val;
            return;
        }
        if (high < qlow || low > qhigh) return;
        push(pos, low, high);
        int mid = (low+high)/2;
        update(2*pos+1, qlow,qhigh, low,mid, val);
        update(2*pos+2, qlow,qhigh, mid+1,high, val);
        tree[pos] = combine(tree[2*pos+1], tree[2*pos+2]);
    }
    //Range sum query
    T query(int pos, int qlow, int qhigh, int low ,int high){
        if (qlow <= low && qhigh >= high){
            return tree[pos];
        }
        if (qlow > high || qhigh < low) return 0; // return nothing as SUM 
        push(pos,low, high);
        int mid = (low+high)/2;
        T left = query(2*pos+1,qlow,qhigh,low,mid);
        T right = query(2*pos+2,qlow,qhigh,mid+1,high);
        return combine(left,right);

    }
};

void solve(){
    int n,q;
    cin >> n >> q;



    // vvi queries(q);
    // vi ans(q);
    // for (int i=0;i<q;i++){
    //     int l,r; cin >> l >> r; 
    //     queries[i] = {l,r,i};
    // }
    // sort(all(queries));
    // debugm(queries);
    // int st = queries[0][0]; // Left most Left 
    // int r = queries[0][1];
    // for (int i=0;i<q;i++){
    //     r = max(queries[i][1], r);
    //     cerr << "new r: " << r << endl;
    //     int white = n - (r - st +1);
    //     ans[queries[i][2]] = white;
    //
    // }
    // for (int i=0;i<q;i++) cout << ans[i] << endl;


    // i think offline queries and sorting migth cut it 
    // if we sort by lower Left,
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
