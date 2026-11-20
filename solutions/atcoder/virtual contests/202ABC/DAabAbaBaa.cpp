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


// 1. find the totla number of permutations 
// 2. divide and conquer or something like that 
// 3. how do we choose between "a" and "b"
// 



void solve(){
    // A, B <+ 30 
    // 2 ^ 60 possibilities which is to oslow to brute force 
    int a,b;
    ll k;
    cin >> a >> b >> k;
    int n = a+b;
    vvl dp(31, vl(31)); // dp[i][j] => how many ways to form a string with i "a"s and j "b"s
    // dp[0][0] = 1; // empty sequence
    // dp[1][0] = 1;
    // dp[0][1] = 1; 
    for (int i=0;i<31;i++) dp[i][0] = 1;
    for (int j=0;j<31;j++) dp[0][j] = 1;
    for (int i = 1; i < 31; i++){
        for (int j =1; j < 31; j++){
            dp[i][j] = dp[i-1][j] + dp[i][j-1];
        }
    }

    // now we need to build the string up and decide which character to use 
    // a, b 
    string s;
    cerr << dp[a][b] << endl;
    for (int i=0;i<n;i++){
        // cerr << s << endl;
        // cerr << "k: " << k << endl;
        // cerr << a << ":" << b << "  >> " << dp[a][b] << endl;
      
        if (a==0){
            cerr << "hit" << endl;
            s += "b";
            continue;
        } 
        if (b==0){
            s += "a";
            continue;
        }

        if (k <= dp[a-1][b]){ // (a-1,b) has more than k options 
            // we have ot use 
            s += "a";
            a--;
        } else {
            s += "b";
            k -= dp[a-1][b];
            b--; 
        }
    }
    cout << s << endl;

    
};
/*
my logic assume any number of a and b 
i split in half because its half "a" half "b"
but that is not always true 



dp[i][a][b]

1) aabb

2) abab

3) abba

4) baab

5) baba

6) bbaa

   we can dp 
   [i][a_left][b_left] 
   = 60 * 30 * 30 ind the number of vertices u that satisfy all of the following conditions:

   what do we want to dp again.. 
   the max order or some shit 


*/


int main(){

    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("shuffle.in","r",stdin);
    // freopen("shuffle.out","w",stdout);
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
