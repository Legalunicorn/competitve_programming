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
using vll = vector<vl>;
using pi = pair<int,int>;
using vvpi = vector<vector<pi>>;
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
vector<char> vowels = {'a','e','i','o','u'};
string make_lower(const string& t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return tolower(c); }); return s; }
string make_upper(const string&t) { string s = t; transform(all(s), s.begin(), [](unsigned char c) { return toupper(c); }); return s; }
bool is_vowel(char c) {return c == 'a' || c == 'e' || c == 'u' || c == 'o' || c == 'i';}




void solve(){
    int n;
    cin >> n;

    vvi dp(n,vi(3,-1));
    //there is only 3 states 
    //this is a wrong approach
    /*
    this means there there is no gap of more than len 1 
    */
    function<int(int,int)> go = [&](int i, int state){
        cerr << i << "  " << state <<endl;
        if (i>n) return 0;
        if (i==n) {
            if (state==0) return 1;
            else return 0;
        }
        if (dp[i][state]!=-1) return dp[i][state];

        int res =0; 
        if (state==0){ // 1,2,3
            res = res + go(i+1,1) % MOD;
            res = res + go(i+1,2) % MOD;
            res = res + go(i+2,0) % MOD;
        } else if (state==1){
            res = res + go(i+1,0) % MOD;
        } else if (state==2){
            res = res + go(i+1,0) % MOD;
        }
        return dp[i][state] = res;
    };
    cerr << endl;

    int res = go(0,0);
    cout << res << endl;
};
/*

i feel like my current approach is missing alot of values,
unlike i made the bott-up values accumulative then it will work

current approach: from one state, increment either, or both if possible
, the issue is that im no

acutually there is only 4 states
0 0 

0 1 

1 0 

1 1 

then we try to fill up all columns, but this stilll look like a n^2 approach
or is it? 

initial idea:
-> given (i) fill up every left and right block one by one 
i += all their values 

but actually 
we only make a few calls 
i=! 



lets build the block up to down
we that compute the remaining empty heights of lane 1 and lane 2 

dp[n][n] -> too slow n^2 

what if we do
dp[n] -> 
*/


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

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