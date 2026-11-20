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
// using namespace __gnu_pbds;
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
//template/ template <class T> using ordered_set = tree<T, null_type,
// less<T>, rb_tree_tag,tree_order_statistics_node_update>;
// // 
// template <class T> using ordered_multiset = tree<T, null_type,
// less_e

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


void solve(){
    int n,m,k;
    cin >> n >> m >> k;
    vl a(n);
    for( auto& z:a) cin >> z; 
    vi diff(m+5);
    vvi ops(m, vi(3));
    for (int i=0; i<m; i++){
        int l,r,d;
        cin >> l >> r >> d;
        l--; r--;
        ops[i]  = {l,r,d};
    }
    // debugm(ops);
    for (int i=0; i<k; i++){
        int x,y; cin >> x >> y;
        diff[x-1]++;
        diff[y]--; 
        // operations x...y plus one
    }
    for (int i=1; i<=m;i++) diff[i] += diff[i-1];
    // now how do we apply each operation? 
    // we know its K factor 
    vl delta(n+5); // second diff 
    for (int i=0; i<m; i++){
        int times = diff[i]; // multiplier factor 
        ll val = ops[i][2]*(ll)times;
        delta[ops[i][0]] += val;
        delta[ops[i][1]+1] -= val; // difference array
    }
    // materialise the delta 
    for (int i =1; i<n; i++) delta[i] += delta[i-1];
    // debugv(delta);
    // debugv(diff);
    // add to a;
    for (int i = 0; i < n; i++) {
        a[i] += delta[i];
        cout << a[i] << " ";
    }
    cout << endl;
};

/*
x to y queries? 


each query in a bunch of effects, which is a difference array of effects in a sense 
what if we prefix sum on the difference array 
then use y-x to get the prefix ?
m operations 
0..1..2..m-1, m 

actually no. 
how about we just compute how many times each operate was called. 
so we use a differnece array to represent how many times an operation was summosed 
then we perform each operation one by one multiplied by the times it was called 
using another differn

*/ 

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
