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


/*
1. count number of palindromes ending at i, as ci 
2. sum nnumber of palindromes ending at i, as si
3. if j<i, then the answer should be si - s_{j-1}


(1) can be done in n^2
(2) O(n) or together with (1)

then we process the queries accordingly 

c a a a b a 
1 2 4 7 8 10
0 1 2 3 4 5 

query 1 1 : 0 
query 4:1 3:0 == 7 correct
query 3: 2 - 3 //  1 :  2 == a[2] - a[0] = 

*/

void solve(){
    string s;
    cin >> s;
    int n = s.size();
    int q;
    cin >> q;
    vvi a(n+1,vi(n+1)), dp(n+1,vi(n+1));
    for (int i =0; i<n; i++){
        for (int j=0;j<n;j++){
            int l = i-j;
            int r = i+j;
            if ((l<0) || (r>=n) || (s[l]!=s[r])) break;
            else {
                a[l+1][r+1] = 1;
            }
        }
        for (int j=0;j<n;j++){
            int l = i-j, r = i+j+1;
            if ((l<0) || (r>=n) || (s[l]!=s[r])) break;
            else {
                a[l+1][r+1] = 1;
            }
        }

    }

    for(int i=1;i<=n;i++){
        for (int j=1; j<=n;j++){
            dp[i][j] =   dp[i-1][j] + dp[i][j-1] - dp[i-1][j-1] + a[i][j];
        }
    }

    while(q--){
        int l,r;
        cin >> l >> r;
        ll sum = dp[r][r];
        sum -= dp[l-1][r];
        sum -= dp[r][l-1] ;
        sum += dp[l-1][l-1];
        cout << sum << endl;

    }    



};
/*

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