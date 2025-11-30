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

    every ki produces a delta.
    compute prefix sum to compute delta from k0...kn

    take in "n" possible intermediate values 
    an intermediate value can be at any possible position,
    and the position indicates the delta sum, resulting in the 
    initial score

    however each position that produces a initial score, must also procide k scores 
    given by k deltas. and the remaining intermediate values must all be inside these set of values 

    naive is (k,n)^3 which will TLE 

    1. we can get all possible starting positions
    2. we must flag a starting position in O(1)

    - either prunning
    - some form of precomptation
    - another observation 

    - every intermediate is a "truth" value 
    k =  5 
    n = 2 

    the max answer is k,
    1. extrac every initial using one of the N as a base 
    2. for every possible initial, run through the deltas
        - each run should hit all N values then add to the asnwer;

*/
void solve(){
    int k,n; 
    cin >> k >> n;
    vl a(k),b(k);
    for (int i=0;i<k;i++){
        ll x; cin >> x;
        b[i] = x;
        if (i==0) a[i] = -x;
        else a[i] = a[i-1] - x;
    }
    set<ll> ns;
    for (int i=0;i<n;i++){
        ll z; cin >> z;
        ns.insert(z);
    }
    int s = *ns.begin();
    int res = 0;
    set<int> pot;
    for (int i=0;i<k;i++){
        // cerr << s+a[i] << endl;
        pot.insert(s+a[i]);
    }
    // cerr << endl << endl;
    for (ll p : pot){
        // cerr << "p: " << p << endl;
        // run through and make sure all in NS are hit 
        set<ll> hits;
        ll curr = p;
        for (int i=0;i<k;i++){
            curr += b[i];
            // cerr << curr << " ";
            if (ns.count(curr)) hits.insert(curr);
        }
        // cerr << endl;
        if (hits.size()==n) res++;
    }
    cout << res << endl;

};



int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    // freopen("input.in","r",stdin);
    // freopen("output.out","w",stdout);


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