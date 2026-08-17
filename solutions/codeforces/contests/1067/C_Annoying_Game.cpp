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



int tc  = 0;
void solve(){
    tc++;
    int n,k;
    cin >> n >> k;
    vl a(n),b(n);
    for (auto& z:a) cin >>z;
    for (auto& z:b) cin>> z;
        
    
    ll res = a[0];
    if (k%2==1) res+=b[0];
    vl left(n), right(n);

    // left[i] = prefix[i] - min_prefix
    left[0] = a[0];
    ll pf = a[0];
    ll min_pf = min(0LL,a[0]);
    for (int i=1; i<n; i++){
        pf += a[i];
        left[i] = pf - min_pf;
        min_pf = min(min_pf, pf);
    }

    // right[i] = suffix[i] - min_suffix;
    right[n-1] = a[n-1];
    ll sf = a[n-1];
    ll min_sf = min(0LL,a[n-1]);
    for (int i=n-2;i>=0;i--){
        sf += a[i];
        right[i] = sf - min_sf;
        min_sf = min(min_sf, sf);
    }
    // debugv(left);
    // debugv(right);

    
    for (int i=0;i<n;i++){
        ll evl = a[i];
        if (k%2==1) evl+=b[i];
        if (i>0)  evl += max(0LL,left[i-1]);
        if (i+1<n) evl += max(0LL,right[i+1]);
        res = max(res,evl);

        
    }
    // if (tc==199){
    //     string db = to_string(k);
    //     db += "|";
    //     for (auto x : a) {
    //         db += to_string(x);
    //         db += ".";
    //     }
    //     db += "||";
    //     for (auto x:b){
    //         db += to_string(x);
    //         db +=  ".";
    //     }
    //     db += "*****";
    //     cout << db;
    //     return;
    // }

    cout << res << endl;
};


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("file.in","r",stdin);
    // freopen("file.out","w",stdout);
    int T =1;
    cin >> T; 
    auto start1 = high_resolution_clock::now();
    while(T--){
        solve();
    }
    auto stop1 = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop1-start1);
    cerr << "Time: " << duration.count() / 1000 << " ms" << endl;
    return 0;
}