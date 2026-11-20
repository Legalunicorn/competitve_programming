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
    int n,q;
    cin >> n >> q;
    vi a(n);
    for (auto& z:a) cin >> z;
    vi pf(n);
    pf[0] = a[0];
    for (int i=1; i<n; i++) pf[i] = a[i] + pf[i-1];
    // if two "0"s are seperated by a distance more than "3" 
    // that means eveyrthing in the middle is 1 
    // if we remove all those "1"s, then the zeros will be closer 
    // so the max cost is 3 per operation ( but im sure it reduces to 2)
    // o x x o x 
    // say its seperated by 2 "x", then the cost of removing those "x" is 1 
    // then we get o o .. . 
    // with now a cost of 1 
    // i think only max of 1 operation is cost "2"? 
    // we just need to check if the entire sequence is alternating, if so do a +1 
    // how do we check though maybe if a[i] = a[i-1] we do some counter 
    // then we do a prefix sum for that as well 
    // we only need to check from L+1 until r if its tru 
    vi same(n);
    for (int i=1;i<n;i++){
        if (a[i]==a[i-1]) same[i] = 1;
    }
    for (int i=1;i<n;i++) same[i] += same[i-1];

    while(q--){
        int l,r;
        cin >> l >> r;
        l--; r--; 
        int len = r - l + 1;
        int sum = pf[r] - (l>0? pf[l-1]: 0);
        if (len%3!=0 || sum%3!=0){
            cout << -1 << endl;
            continue;
        }
        int cost = len/3; 
        int dup = same[r] - same[l]; // minus L inclusive 
        if (dup==0){ // alternative 
            cost++;
        }
        cout << cost << endl;
    }
    

};


/*
1. the sum of the array must be divisible by 3 
2. the sum of the subarray mnust be divisible by 3 

then weneed to compute the cost 

q is 1 indexed

we must sum the costs 
if we can greedily proof that the cost is minimised somehow 



*/

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
