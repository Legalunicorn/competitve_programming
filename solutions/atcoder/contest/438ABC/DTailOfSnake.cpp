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

// interesting problem 
// its like a segment that is also split 
// its continuous 
// wait we have to use the whole array 
// we just have to find the "cut"
// if we can pivot of something like the middle segment 
// there are two split pints 
//
// X and Y 
//
// if we fix X, can we find the best Y? 
// maybe its dp 
//
// let dp[x] be the best value from BC[x: N]
// lets compute suffix sum of B and C first 
// then we can probably greedy the best value? 
// no, new cell can be all C, we can just leave a buffer to force take B 
void solve(){
    int n;
    cin >> n;
    vi a(n),b(n),c(n);
    for (auto& z:a) cin >> z;
    for (auto& z:b) cin >> z;
    for (auto& z:c) cin >> z;
    if (n==3){
        cout << a[0]+b[1]+c[2] << endl;
        return;
    }
    ll res = 0;
    vvl dp(n, vl(2));
    dp[n-1][0] = c[n-1];
    dp[n-1][1] = -100000000;
    dp[n-2][0] = c[n-2] + c[n-1];
    dp[n-2][1] = b[n-2] + c[n-1];

    ll c_sum = c[n-2] + c[n-1];
    for (int i = n-3; i >=2; i--){
        c_sum += c[i];
        dp[i][1] = max((dp[i+1][0] + b[i]), dp[i+1][1] + b[i] );
        dp[i][0] = c_sum;
    }

    ll a_sum = a[0];
    for (int x = 1; x < n-1; x++){
        ll evl  = a_sum + b[x] + max(dp[x+1][0],dp[x+1][1]);
        res = max(res,evl);
        a_sum += a[x];
    }
    cout << res << endl;
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
