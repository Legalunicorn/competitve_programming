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

// TAG_TO_REVIEW
// "Easy" was a lie 
// I gave in an look at the solution, took a while to digest but it makes sense  
//
// LEAERNING POINT: 
// the key idea is bounds, pigeon hole principle etc, 
// n = 12, so the amount of different strings u can get is small (2^n)
// this captures the brute force idea technically, but we reduce the limits of the brute force 
// for 1. every pair of strings, 2. every possible k (less than 100)
// I have had both the idea to use XOR, as well as k=0 to k = 100, but didnt piece anything together 
//
// Summarised idea
// 1. for every subset -> there is an associated WU value 
// 2. for every initial string -> there is a count, so we change the size of input to (2^n)
// 3. for every possible input, we can match against all other pairs (2^n * 2^n) and get the score 
// 4. ignore scores above MAX_K, otherwise for its k score, we add the number of string 
// 5. so now for  input we know the amount of pairs for each score k = 0 to k = MAX 
// 6. do the prefix sum to get the cummulative score for k and all k smaller 
// 7. answer the queries 

void solve(){
    int n,m,q; 
    cin >> n >> m >> q;
    int TOTAL = (1 << n);
    int KMAX = 100;
    // wu valis 
    vi vals_wu(n);
    for (auto& z: vals_wu) cin >> z; 

    vi wu_score(TOTAL);
    for (int i= 0; i<TOTAL; i++){
        for (int j =0; j<n;j++) if ( (i>>j) & 1) wu_score[i] += vals_wu[j];
    }

    // get freuency 
    vi mfreq(TOTAL);
    for (int i =0; i<m; i++){
        string s;
        cin >> s; 
        int val = 0;
        for (int j=0; j<n; j++){
            if (s[j]=='1') val += (1<<j);
        }
        mfreq[val]++; // new instance
    }
    int full = (1<<n)-1;
    vvi prefix(TOTAL, vi(KMAX+1)); // 0 -> 100 
    for (int a = 0; a < TOTAL ; a++){
        for (int b =0; b < TOTAL; b++ ){
            int opp = a ^ b;
            int score = wu_score[full] - wu_score[opp];  
            if (score <= KMAX) prefix[a][score] += mfreq[b];
        }
        for (int i=1; i<=KMAX; i++) prefix[a][i] += prefix[a][i-1];
    }

    // now we read in the inputs 
    while (q--){
        string t;
        int k;
        cin >> t >> k;
        // convert t to substrgins 
        int val = 0;
        for (int i=0; i<n; i++) if (t[i]=='1') val += (1 << i);
        int ans = prefix[val][k];
        cout << ans << endl;
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
